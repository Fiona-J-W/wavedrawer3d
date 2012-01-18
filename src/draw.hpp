#ifndef __draw_hpp__
#define __draw_hpp__

#include "settings.hpp"

#include <string>

///calculate the data based on settings and write them to the given file
void draw(settings S);

///create the filename
std::string get_filename(std::string file, unsigned int i = 1, unsigned int number_of_pics = 1);



#endif
