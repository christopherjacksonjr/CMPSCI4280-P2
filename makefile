CC = g++
CFLAGS = -g
TARGET = frontEnd
HEADER = parser.h testTree.h
OBJS = main.c parser.c testTree.c
.SUFFIXIES: .c .o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
.c.o:	$(HEADER)
	$(CC) $(CFLAGS) -c $<
clean:
	/bin/rm -f *.o $(TARGET)
