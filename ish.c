#include "ish_utilities.h"
#include "ish_syscalls.h"

/*
    The maximum length of the input string
*/
static const unsigned long Max_Input_String_Length = 255;
/*
    The maximum number of program arguments
*/
static const unsigned long Max_Argument_Count = 255;
/*
    The maximum string length of the executable path
*/
static const unsigned long Max_Executable_Path_Length = 1024;

/*
    The 'HOME' environment variable that contains the path
    to the home directory of the current user
*/
static const char Environment_Variable_Home[] = "HOME";
/*
    The 'PATH' environment variable that contains a list
    of directories with executable files to search for
*/
static const char Environment_Variable_Path[] = "PATH";

/*
    The shell builtin command string to change the working directory
*/
static const char Builtin_Command_CD[] = "cd";
/*
    The shell builtin command string to exit from the shell
*/
static const char Builtin_Command_Exit[] = "exit";

/*
    Error messages
*/
static const char Fork_Error_Message[] =
    "fork failure";

/*
    ish
    An insecure silent and primitive shell
*/
int main(int argc, char **argv, char **envp)
{
    char input_string[Max_Input_String_Length + 1];
    input_string[Max_Input_String_Length] = '\0';

    /* Extract the home directory path for the current user */
    char *home = 0;
    for (char **cursor = envp; *cursor; ++cursor) {
        if (ish_cstring_starts_with_ignoring_case(
                Environment_Variable_Home,
                *cursor
            )) {
            home =
                *cursor;
            home +=
                sizeof(Environment_Variable_Home);

            break;
        }
    }

    /* Extract the list of directories where executable programs are located. */
    char *path = 0;
    for (char **cursor = envp; *cursor; ++cursor) {
        if (ish_cstring_starts_with_ignoring_case(
                Environment_Variable_Path,
                *cursor
            )) {
            path =
                *cursor;
            path +=
                sizeof(Environment_Variable_Path);

            break;
        }
    }

    /*
        `read` tries to write a fixed number of bytes into a
        buffer from a specific file descriptor.

        We read an input string on each iteration
        from the 'standard input' stream.

        `man 2 read`
    */
    while (read(0, input_string, Max_Input_String_Length) >= 0) {
        /* Mark the 'new line' character as the end of the C string. */
        ish_replace_first_character_in_cstring(
            input_string, '\n', '\0'
        );

        char *arguments[Max_Argument_Count + 1];
        arguments[Max_Argument_Count] = 0;

        /* Build a null-terminated array of arguments from the input string. */
        unsigned long argument_index = 0;
        for (char *cursor = input_string;
                cursor && argument_index < Max_Argument_Count;
                    ++argument_index) {
            arguments[argument_index] =
                ish_carve_token_in_cstring(
                    cursor,
                    ish_is_space,
                    &cursor
                );
        }
        arguments[argument_index] =
            0;

        unsigned long argument_count =
            argument_index == 0 ?
                0 : argument_index - 1;

        if (arguments[0]) {
            const char *command =
                arguments[0];

            /*
                Process builtin commands that can not be implemented as a
                separate process.
            */
            if (ish_are_cstrings_equal(
                    command,
                    Builtin_Command_CD
                )) {
                char *directory =
                    argument_count == 0 ?
                        home : arguments[1];

                if (directory) {
                    /*
                        `chdir` changes the current working directory (CWD)
                        for the calling process to the specified path. All
                        child processes will inherit the new working
                        directory from the parent.

                        `man 2 chdir`
                    */
                    chdir(directory);
                }
            } else if (ish_are_cstrings_equal(
                           command,
                           Builtin_Command_Exit
                       )) {
                int exit_status =
                    argument_count == 0 ?
                        0 : ish_get_integer_from_cstring(
                                arguments[1]
                            );

                /*
                    `exit` asks the system to unload the process with a 
                    provided status code. The status code can be received,
                    analyzed, and processed by a parent process
                    (see `waitpid`).

                    `man 2 exit`
                */
                exit(exit_status);
            } else {
                /*
                    Start a separate process.
                */

                char *executable =
                    arguments[0];

                /*
                    Check whether the specified executable exists or search
                    for it through the directories in the 'PATH' environment
                    variable.
                */

                /*
                    `stat` obtains information about a file pointed to by
                    path. Upon successful completion a value of 0 is returned.
                    Otherwise, a value of -1 is returned (e.g., the file does
                    not exist).

                    `man 2 stat`
                */
                struct stat stat_buffer;
                if (!stat(executable, &stat_buffer) == 0) {
                    executable = 0;

                    char executable_path[Max_Executable_Path_Length + 1];
                    executable_path[Max_Executable_Path_Length] = '\0';

                    if (path) {
                        for (char *cursor = path; cursor && !executable; ) {
                            char *path_token =
                                ish_get_token_in_cstring(
                                    cursor,
                                    ish_is_path_separator,
                                    &cursor
                                );

                            if (path_token) {
                                unsigned long path_index = 0;
                                while(
                                    path_index <
                                        Max_Executable_Path_Length &&
                                            *path_token &&
                                                !ish_is_path_separator(
                                                    *path_token
                                                )
                                ) {
                                    executable_path[path_index] =
                                        *path_token;

                                    ++path_index, ++path_token;
                                }

                                if (path_index <
                                        Max_Executable_Path_Length) {
                                    executable_path[path_index++] =
                                        ISH_Directory_Separator;
                                }

                                char *filename =
                                    arguments[0];

                                while(
                                    path_index <
                                        Max_Executable_Path_Length &&
                                            *filename
                                ) {
                                    executable_path[path_index] =
                                        *filename;

                                    ++path_index, ++filename;
                                }

                                executable_path[path_index] = '\0';

                                if (stat(executable_path, &stat_buffer) == 0) {
                                    executable =
                                        executable_path;
                                }
                            }
                        }
                    }
                }

                if (executable) {
                    /*
                        `fork` creates a child duplicate of the current process.

                        `man 2 fork`
                    */
                    int pid = fork(); // ~ typedef int pid_t
                    if (pid == 0) {
                        /*
                            A Process ID (PID) of zero from the `fork` call
                            means we're in the child process.
                        */

                        /*
                            `execve` substitutes the current process image with
                            the provided executable file.

                            The first parameter to `execve` is a file name with
                            the path to the executable. The next is an array of
                            arguments to the new program. The first argument
                            should be the file name of the executable (with or
                            without the path).

                            Environment variables such as `HOME` and `PATH` go
                            as the last parameter.

                            `man 2 execve`
                        */
                        execve(executable, arguments, envp);
                    } else if (pid > 0) {
                        /*
                            A positive Process ID (PID) from the `fork` call
                            means we are in the parent process.
                        */

                        /*
                            `waitpid` waits for a child process to change its
                            state (stopped, exited, terminated...).

                            The status output parameter can contain an exit
                            code or a terminating signal after the call.

                            `man 2 waitpid`
                        */
                        int child_status;
                        waitpid(pid, &child_status, 0);
                    } else {
                        /*
                            A negative value from the `fork` call means that
                            something went wrong and the child process was
                            not created.
                        */

                        /*
                            `write` tries to write a fixed number of bytes from
                            the buffer into the location specified by the file
                            descriptor.

                            We output an error message for every failed `fork`
                            system call into the 'standard error' stream.

                            `man 2 write`
                        */
                        write(
                            2, Fork_Error_Message, sizeof(Fork_Error_Message)
                        );
                    }
                }
            }
        }
    }

    return 0;
}

