#Makefile for wavedrawer3d

CC = g++
CFLAGS = -O3 -Wall -Wextra -pedantic

TARGET = wavedrawer3d
OBJECTS = color.o divide_string.o draw.o libpicture.o point.o point3d.o stimulator.o main.o settings.o

# link target:
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@


%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@


#object files
color.o: color.hpp

divide_string.o: divide_string.hpp

draw.o: draw.hpp libpicture.hpp

libpicture.o: libpicture.hpp

main.o: draw.hpp settings.hpp

point.o: point.hpp

point3d.o: point3d.hpp divide_string.hpp

settings.o: settings.hpp

stimulator.o: stimulator.hpp divide_string.hpp


#header files
draw.hpp: settings.hpp

libpicture.hpp: color.hpp point.hpp

settings.hpp: stimulator.hpp

stimulator.hpp: point3d.hpp

#works only on unix:
clean:
	rm *.o
