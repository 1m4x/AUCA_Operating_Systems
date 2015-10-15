CFLAGS  = -O3 -D ISH_USE_STDLIB=1 -std=gnu99
LDFLAGS =

TARGET  = ish
OBJECTS = ish.o                   \
          ish_shell_utilities.o   \
          ish_cstring_utilities.o \
          ish_syscalls.o

$(TARGET) : $(OBJECTS)

$(OBJECTS) : %.o : %.c ish_common.h

.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJECTS)
