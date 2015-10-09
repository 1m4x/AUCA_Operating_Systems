CFLAGS = -D ISH_USE_STDLIB=1 -std=c99

.PHONY : all clean

all : ish

ish : ish.o ish_utilities.o ish_syscalls.o

ish.o : ish.c

ish_utilities.o : ish_utilities.c

ish_syscalls.o : ish_syscalls.c

clean :
	rm -rf ish ish.o ish_utilities.o ish_syscalls.o

