#Makefile for wavedrawer3d

CC = g++ 
CFLAGS = -O3 -Wall -Wextra -pedantic -std=c++0x
CLIBS = -lboost_thread `libpng-config --ldflags` 
INCLUDES = `libpng-config --cflags` 
#-I/usr/include/boost
BUILDDIR = ../build/
TARGETNAME =wavedrawer3d
TARGET = $(BUILDDIR)$(TARGETNAME)
OBJECTS = $(BUILDDIR)divide_string.o $(BUILDDIR)draw.o $(BUILDDIR)point3d.o $(BUILDDIR)stimulator.o $(BUILDDIR)main.o $(BUILDDIR)settings.o $(BUILDDIR)help.o


# link target:
$(TARGET): $(OBJECTS) 
	@if test ! -d $(BUILDDIR) ; then mkdir $(BUILDDIR); echo "created $(BUILDDIR)" ; fi
	$(CC) $(CFLAGS) $(CLIBS) $(OBJECTS) -o $@


$(BUILDDIR)%.o: %.cpp 
	@if test ! -d $(BUILDDIR) ; then mkdir $(BUILDDIR); echo "created $(BUILDDIR)" ; fi
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


#object files

$(BUILDDIR)divide_string.o: divide_string.hpp

$(BUILDDIR)draw.o: draw.hpp

$(BUILDDIR)main.o: draw.hpp settings.hpp

$(BUILDDIR)point3d.o: point3d.hpp divide_string.hpp

$(BUILDDIR)settings.o: settings.hpp

$(BUILDDIR)stimulator.o: stimulator.hpp divide_string.hpp

$(BUILDDIR)help.o: help.hpp

#works only on unix:
clean:
	rm $(BUILDDIR)*.o

DOKUDIR =../doku/

doku:
	@if test ! -d $(DOKUDIR) ; then mkdir $(DOKUDIR); echo "created $(DOKUDIR)" ; fi
	