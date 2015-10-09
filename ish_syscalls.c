#include "ish_syscalls.h"

/*
    Function Calling Convention

    On x86 (Linux, BSD, Mac OS X) arguments are passed on the stack and pushed
    from right to left.

        buffer_size is pushed first
        the buffer pointer is pushed next
        file_descriptor is pushed last

    Result is returned in the eax register.

    On x86-64 (Linux, BSD, Mac OS X) the first six integer or pointer
    arguments are passed in registers rdi, rsi, rdx, rcx, r8, and r9.

       file_descriptor goes to rdi
       the buffer pointer goes to rsi
       buffer_size goes to rdx

    Result is returned in the rax register.

    ---
    Kernel Calling Convention

    Refer to slides from Practice #2.
*/
long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    /*
        // AT&T/UNIX GCC Inline Assembly Sample

        static const char Argument[] =                   // C constants
            "some data";
        static const unsigned long Another_Argument =
            sizeof(Argument);

        long result;                                     // a C variable

        __asm__ __volatile__ (
            "op-code<length suffix> %%source_register, %%destination_register\n\t"
            "op-code<length suffix> $source_immediate, %%destination_register\n\t"
            // ...
            "op-code<length suffix> %<argument number>, %%destination_register\n\t"
            "op-code"
            : "=a" (result)                              // output argument/s
            : "D" ((unsigned long) file_descriptor),     // input arguments
              "S" (buffer),
              "d" (buffer_size),
              "r" (Argument), "r" (Another_Argument)
            : "%used register", "%another used register" // clobbered registers
        );

        // `__asm__` and `__volatile__` could also be written as
        // `asm`     and `volatile`.

        // The `volatile` modifier tells the compiler not to remove or reorder
        // the inlined assembly block during the compiler optimization step.

        // <length suffixes>
        //     'b'    'w'     's'     'l'     'q'
        //      8 bit  16 bit  16 bit  32 bit  64 bit  integers
        //                     32 bit  64 bit          floating point numbers

        // Argument numbers go from top to bottom, from left to right
        // starting from zero.
        //
        //     result           : %<argument number> = %0
        //     file_descriptor  : ...                = %1
        //     buffer           :                    = %2
        //     buffer_size      :                    = %3
        //     Argument         :                    = %4
        //     Another_Argument :                    = %5

        // The first quoted letter before the argument in brackets is a
        // register constraint. It tells the compiler to provide the
        // argument through that register.
        //
        // On X86/-64 the following register constraints are possible
        // +---+--------------------------+
        // | r :   any register           |
        // +---+--------------------------+
        // | a :   %rax, %eax, %ax, %al   |
        // | b :   %rbx, %ebx, %bx, %bl   |
        // | c :   %rcx, %ecx, %cx, %cl   |
        // | d :   %rdx, %edx, %dx, %dl   |
        // | S :   %rsi, %esi, %si        |
        // | D :   %rdi, %edi, %di        |
        // +---+--------------------------+
        //
        // https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html
    */

    return -1;
}

/*
    int ish_chdir(const char *path)
    {
        // ...
    }

    ...
*/
