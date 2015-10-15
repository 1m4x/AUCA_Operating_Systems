# COM 341, Operating Systems
### Practice Task #1, System Calls

#### Initial Steps

1. Clone a remote repository. Do not forget to specify your last name.
   The password is your university ID.

   `git clone ssh://<surname>@auca-g30a.toksaitov.xyz:2222/~/task_01.git`

   Students without Linux machines should use the following commands to
   use the auca-g30a server

   `ssh -p 2222 <surname>@auca-g30a.toksaitov.xyz`

   `git clone task_01.git task_01`

   To get the most recent changes during next classes use the following
   command

   `git pull origin master`

   Be prepared to resolve merge conflicts.

3. Go into the newly created directory `cd task_01`.

In this task you need to perform a number of system calls on the x86-64
architecture on Debian Linux. The calls are `read`, `chdir`, `exit`,
`stat`, `open`, `creat`, `dup2`, `close`, `fork`, `execve`, `waitpid`,
and `write`. You have sources of a simple shell that uses the following
calls through the system library. Your task is to implement your own
functions `ish_read`, `ish_chdir`, `ish_exit`, `ish_stat`, `ish_open`,
`ish_creat`, `ish_dup2`, `ish_close`, `ish_fork`, `ish_execve`,
`ish_waitpid`, `ish_write` in `ish_syscalls.c` and `ish_syscalls.h`
to perform the calls to the kernel directly. By doing that, you will
remove dependencies on the system library for the shell. Do not
forget to change all function calls in `ish.c`.

#### Managing Sources and Executables

* Edit the code. Add functions and respective implementations for
  every system call in files `ish_syscall.h` and `ish_syscall.c`.
  Change the system call name in `ish.c` to the newly implemented
  function in `ish_syscall.h` (e.g., change `read` to `ish_read`).

  `nano ish_syscalls.h`
  `nano ish_syscalls.c`
  `nano ish.c`

* Build or rebuild the shell.

  `make`

* Test the shell by typing builtin commands such as `cd` and `exit`
  or different program names such as `ls` or `date` with an absolute
  path to the executable or without it, with parameters or without
  them. You can add standard input or output redirection symbols such
  as `<` or `>` for every program and provide the input or output
  file names after them. In order to execute the builtin commands
  or programs press `Enter`.

```
    ./ish
    /bin/ls
    /bin/ls -l /etc
```
  press `CTRL+C` to exit

```
    ./ish
    cd
    ls
    exit
```

```
    ./ish
    date
    exit
```

```
    ./ish
    cd /tmp
    ls /bin > listing.txt
    cat < listing.txt
    exit 1
```

* Remove compiled files.

  `make clean`

#### Submitting Your Work

1. Create a new snapshot of your work with an appropriate description.

   `git commit -am "Implement system calls <system call name>, ..."`

2. Submit your work.

   `git push origin master`
