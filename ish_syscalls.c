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
					"movq $0, %%rax;"
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
					"movq $60, %%rax;"
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
						"movq $80, %%rax;"
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
						"movq $4, %%rax;"
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
int ish_open(const char *pathname, int flags) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $2, %%rax;"
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
int ish_creat(const char *pathname, mode_t mode) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $85 %%rax;"
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
int ish_dup2(int oldfd, int newfd) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $33 %%rax;"
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
int ish_close(int fd) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $3 %%rax;"
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
pid_t ish_fork(void) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $57 %%rax;"
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
int ish_execve(const char *filename, char *const argv[], char *const envp[]) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $59 %%rax;"
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
pid_t ish_waitpid(pid_t pid, int *status, int options, struct rusage *rusage) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $61 %%rax;"
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
ssize_t ish_write(int fd, const void *buf, size_t count) {
	#if defined(__i386__) || defined(__x86_64__)
		#if defined(__APPLE__)
			#if defined(__x86_64__)

			#elif defined(__i386__)

			#endif
		#elif defined(__linux__)
			#if defined(__x86_64__)
				int result;
				__asm__ volatile (
						"movq $1 %%rax;"
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
