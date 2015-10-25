#ifndef ISH_SYSCALLS_H
#define ISH_SYSCALLS_H

/*
    Practice Task #1

    Implement the following system calls for x86-64 architecture

        `ish_read`
        `ish_chdir`
        `ish_exit`
        `ish_stat`
        `ish_open`
        `ish_creat`
        `ish_dup2`
        `ish_close`
        `ish_fork`
        `ish_execve`
        `ish_waitpid` (implement through the `wait4` system call)
        `ish_write`

    Documentation

        `man syscall`
        `man syscalls`
        `man 2 <system call name>`

    Linux x86-64 System Call Tables

        `syscall_64.tbl`

        https://github.com/torvalds/linux/tree/master/arch/x86/entry/syscalls

    For extra points you can implement calls for other CPU architectures. You
    need to research kernel and function calling conventions on your own.

    Linux x86 System Call Tables

        `syscall_32.tbl`

        https://github.com/torvalds/linux/tree/master/arch/x86/entry/syscalls

    Linux ARMv7-A System Call Tables from Android Bionic libc

        `unistd.h`

        https://github.com/android/platform_bionic/blob/master/libc/kernel/
            uapi/asm-arm/asm

    Linux ARMv8-A System Call Tables from Android Bionic libc

        `unistd.h`

        https://github.com/android/platform_bionic/blob/master/libc/kernel/
            uapi/asm-generic
*/

long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     );

int ish_chdir(const char *path);

void ish_exit(int status);

int ish_stat(const char *path, void *buf);

#endif
