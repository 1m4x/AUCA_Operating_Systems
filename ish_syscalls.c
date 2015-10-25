#include "ish_syscalls.h"

long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
#if defined(__i386__) || defined(__x86_64__)
    #if defined(__APPLE__)
        #if defined(__x86_64__)

        #elif defined(__i386__)

        #endif
    #elif defined(__linux__)
        #if defined(__x86_64__)
			long result;
			__asm__ volatile (
					"movq &0, %%rax;"
					"syscall"
					:"=a" (result)
			);
			return result;
        #elif defined(__i386__)

        #endif
    #endif
    return -1;
#elif defined(__arm__) || defined(__aarch64__)
    #if defined(__APPLE__)
        #if defined(__aarch64__)

        #elif defined(__arm__)

        #endif
    #elif defined(__linux__)
        #if defined(__aarch64__)

        #elif defined(__arm__)

        #endif
    #endif
    return -1;
#else
    return -1;
#endif
}

void ish_exit(int status) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				__asm__ volatile (
					"movq &60, %%rax;"
					"syscall"
				);
			#elif defined(__i386__)

			#endif
		#endif
		return -1;
	#elif defined(__arm__) || defined(__aarch64__)
		#if defined(__APPLE__)
			#if defined(__aarch64__)

			#elif defined(__arm__)

			#endif
		#elif defined(__linux__)
			#if defined(__aarch64__)

			#elif defined(__arm__)

			#endif
		#endif
		return -1;
	#else
		return -1;
	#endif
}

int ish_chdir(const char *path)
{
		#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq &80, %%rax;"
						"syscall"
						:"=a" (result)
				);
				return result;
			#elif defined(__i386__)

			#endif
		#endif
		return -1;
	#elif defined(__arm__) || defined(__aarch64__)
		#if defined(__APPLE__)
			#if defined(__aarch64__)

			#elif defined(__arm__)

			#endif
		#elif defined(__linux__)
			#if defined(__aarch64__)

			#elif defined(__arm__)

			#endif
		#endif
		return -1;
	#else
		return -1;
	#endif
}

int ish_stat(const char *path, void *buf) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq &4, %%rax;"
						"syscall"
						:"=a" (result)
				);
				return result;
			#elif defined(__i386__)

			#endif
		#endif
		return -1;
	#elif defined(__arm__) || defined(__aarch64__)
		#if defined(__APPLE__)
			#if defined(__aarch64__)

			#elif defined(__arm__)

			#endif
		#elif defined(__linux__)
			#if defined(__aarch64__)

			#elif defined(__arm__)

			#endif
		#endif
		return -1;
	#else
		return -1;
	#endif
}