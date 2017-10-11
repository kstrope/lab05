# variable definitions
CC     = g++
CFLAGS = -g
LIBS   =

# target to build "all"
all: Hash.exe

# target for building Inserting 
Hash.exe: Hash.o main.o
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

# dependencies for the objects
Hash.o: Hash.cpp Hash.h
main.o: main.cpp Hash.cpp

# target to clean up extra files
clean:
	${RM} Hash.exe *.o 

# generic target to compile a .cpp file to a .o file with the same name
.cpp.o:
	${CC} ${CFLAGS} -c $<

