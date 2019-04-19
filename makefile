CC = g++
CFLAGS = -g
TARGET = frontEnd
HEADER = parser.h testTree.h scanner.h token.h
OBJS = main.c parser.c scanner.cpp testTree.c
.SUFFIXIES: .c .o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
.c.o:	$(HEADER)
	$(CC) $(CFLAGS) -c $<
clean:
	/bin/rm -f *.o $(TARGET)
