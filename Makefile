CFLAGS  = -O3 -D ISH_USE_STDLIB=1 -std=gnu99
LDFLAGS =

TARGET  = ish
OBJECTS = ish.o ish_utilities.o ish_syscalls.o

.PHONY : all clean

all : $(TARGET)

$(TARGET) : $(OBJECTS)

$(OBJECTS) : %.o : %.c

clean :
	rm -rf $(TARGET) $(OBJECTS)

