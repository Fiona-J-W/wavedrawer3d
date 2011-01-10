#Makefile for libpicture

CC = g++
CFLAGS = -O3 -Wall -Wextra -pedantic

#TARGET = lib_bmp.so
TARGET = wavedrawer3d
OBJECTS = color.o libpicture.o point.o main.o settings.o

# link target:
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@


%.o:%.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@



color.o:color.hpp

point.o:point.hpp

libpicture.o:libpicture.hpp color.hpp point.hpp

main.o: libpicture.hpp color.hpp

settings.o: point.hpp

#works only on unix:
clean:
	rm *.o