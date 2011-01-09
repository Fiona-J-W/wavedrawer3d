#Makefile for libpicture

CC = g++
CFLAGS = -O3 -Wall -Wextra -pedantic

#TARGET = lib_bmp.so
TARGET = test
OBJECTS = color.o libpicture.o point.o test.o

# link target:
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@


%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@



color.o:color.hpp

point.o:point.hpp

libpicture.o:libpicture.hpp color.hpp point.hpp

test.o: test.cpp libpicture.hpp color.hpp

#works only on unix:
clean:
	rm *.o