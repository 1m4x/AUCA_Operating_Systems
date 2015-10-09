# COM 341, Operating Systems
### Practice Task #1, System Calls

#### Initial Steps
1. Clone a remote repository. Don not forget to specify your last name. The password is your university ID.

   `git clone ssh://<surname>@auca-g30a.toksaitov.xyz:2222/~/task_01.git`

   Students without Linux machines should use the following commands to use the auca-g30a server.

   `ssh -p 2222 <surname>@auca-g30a.toksaitov.xyz`

   `git clone task_01.git task_01`

3. Go into the newly created directory `cd task_01`.

In this task you need to perform several system calls on the x86-64 architecture on Debian Linux. The calls are `read`, `chdir`, `exit`, `stat`, `fork`, `execve`, `waitpid`, and `write`. You have sources of a simple shell that uses the following calls through the system library. Your task is to implement your own functions `ish_read`, `ish_chdir`, `ish_exit`, `ish_stat`, `ish_fork`, `ish_execve`, `ish_waitpid`, `ish_write` in `ish_syscalls.h` to perform the calls to the kernel directly. By doing that, you will remove the dependency on the system library for the shell. Don not forget to change all function calls in `ish.c`.

#### Managing Sources and Executables
* Edit the code.

  `nano ish.c`

* Build your shell.

  `make`

* Test your shell by starting the `ls` executable from it with different flags and parameters.

  `./ish` and `/bin/ls` and `/bin/ls -l /bin`; press *CTRL+C* to exit

* Remove all compiled files.

  `make clean`

#### Submitting Your Work

1. Create a new snapshot of your work with an appropriate description.

   `git commit -am "Implement system calls <system call name>, <another system call name>..."`

2. Submit your work.

   `git push`

