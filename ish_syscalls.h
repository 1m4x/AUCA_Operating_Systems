#ifndef ISH_SYSCALLS_H
#define ISH_SYSCALLS_H

/*
    Practice Task #1

    Implement the following system calls for x86-64 architecture

        `ish_read`
        `ish_chdir`
        `ish_exit`
        `ish_stat`
        `ish_fork`
        `ish_execve`
        `ish_waitpid`
        `ish_write`

    Documentation

        `man syscall`
        `man syscalls`
        `man 2 <system call name>`

    x86/x86-64 System Call Tables

        `syscall_32.tbl`
        `syscall_64.tbl`

        https://github.com/torvalds/linux/tree/master/arch/x86/entry/syscalls
*/

long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     );

/*
    int ish_chdir(const char *path);
    ...
*/

#endif
