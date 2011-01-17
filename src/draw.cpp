#ifndef __draw_cpp__
#define __draw_cpp__

#include "draw.hpp"
#include "libpicture.hpp"

#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

void draw(settings S) {
	picture pic(S.width, S.height);
	double time_between_pics = 1.0 / S.number_of_pics, time = 0, total_elongation = 0;
	unsigned int number_of_stimulators = S.stimulators.size();
	string filename;
	point3d current_point;

	for(unsigned int i = 1; i <= S.number_of_pics; i++) {
		for(unsigned int x = 1; x <= S.width; x++) {
			for(unsigned int y = 1; y <= S.height; y++) {
				total_elongation = 0;
				current_point.set((int)x - ((int)S.width + 1) / 2, -((int)y - ((int)S.height + 1) / 2), 0);
				for(unsigned int stimu = 0; stimu < number_of_stimulators; stimu++) {
					total_elongation += S.stimulators[stimu].get_elongation(current_point, time, S.propagation_speed) / number_of_stimulators;
				}
				pic.set_pix(x, y, color_rgb(255 * (total_elongation + 1) / 2));
			}
		}
		filename = get_filename(S.file, i, S.number_of_pics);
		cout << "drawing " << filename << endl;
		pic.draw_bmp(filename);

		time += time_between_pics;
	}
}

string get_filename(string file, unsigned int i, unsigned int number_of_pics) {
	if(i > number_of_pics) {
		throw out_of_range("get_filename(): invalid parameters: i > number_of_pics");
	}

	unsigned int pos = file.find(".bmp");
	if(pos == 0 or file == "") {
		throw invalid_argument("get_filename(): a filename must be specified");
	} else if(pos != file.npos) {
		file.erase(pos);
	}


	unsigned int digits = 0;
	if(number_of_pics != 1) {
		while(number_of_pics >= 1) {
			digits++;
			number_of_pics /= 10;
		}
		char *formatstring = new char[digits + 1];
		sprintf(formatstring, "%0*i", digits, i);
		file += formatstring;
		delete formatstring;
		formatstring = NULL;
	}

	file += ".bmp";
	return file;
}

#endif
