#ifndef __draw_cpp__
#define __draw_cpp__

#include "draw.hpp"

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <boost/thread.hpp>

#include <png++/png.hpp>

using namespace std;

struct calc_data{
	int y;
	double time;
	unsigned int number_of_stimulators;
	settings *S;
	png::image<png::gray_pixel> *img;
};

void calc_line(calc_data data){
	double total_elongation = 0;
	point3d current_point;
	for(unsigned int x = 0; x < data.S->width; x++){
		total_elongation = 0;
		current_point.set(
			(int)x - ((int)data.S->width  + 1) / 2, //xpos, make the origin be in the middle
			(int)data.y - ((int)data.S->height + 1) / 2,//ypos, same as above
			0//z=0 
		);
		for(unsigned int stimu = 0; stimu < data.number_of_stimulators; stimu++) {
			total_elongation += data.S->stimulators[stimu].get_elongation(current_point, data.time, data.S->propagation_speed) / data.S->total_amplitude;
		}
		png::gray_pixel pix(255 * ((total_elongation + 1)/2.0));
		data.img->set_pixel(x,data.y,pix);
	}
}

void draw(settings S) {
	png::image<png::gray_pixel> img(S.width, S.height);
	double time_between_pics, time = 0;
	if(S.runtime){
		time_between_pics = S.runtime / S.number_of_pics;
	}
	else{
		time_between_pics = 1.0 / S.number_of_pics;
	}
	unsigned int number_of_stimulators = S.stimulators.size();
	string filename;
	calc_data Data;
	Data.S=&S;
	Data.img=&img;
	
	//Stuff for using threads:
	int number_of_threads=boost::thread::hardware_concurrency(), current_thread;
	vector<boost::thread*> threads;
	threads.resize(number_of_threads);
	
	Data.number_of_stimulators=number_of_stimulators;
	
	for(unsigned int i = 0; i < S.number_of_pics; i++) {//Frames
		filename = get_filename(S.file, i, S.number_of_pics);
		cout << "Calculating "<<filename<<"... "<<flush;
		Data.time=time;
		for(unsigned int y = 0; (int)y < number_of_threads&&y < S.height; y++) {
			current_thread=y;
			Data.y=y;
			threads[current_thread]=new boost::thread(calc_line,Data);
		}
		for(unsigned int y = number_of_threads; y < S.height; y++) {
			current_thread=y%number_of_threads;
			threads[current_thread]->join();
			delete threads[current_thread];
			Data.y=y;
			threads[current_thread]=new boost::thread(calc_line,Data);
		}
		
		for(int i = 0; i < number_of_threads; ++i) {
			threads.at(i)->join();
		}
		cout << "done. Drawing... "<<flush;
		img.write(filename);
		cout << "done."<< endl;
		time += time_between_pics;
	}
}

string get_filename(string file, unsigned int i, unsigned int number_of_pics) {
	if(i > number_of_pics) {
		throw out_of_range("get_filename(): invalid parameters: i > number_of_pics");
	}

	size_t pos = file.find(".png");
	if(pos == 0 or file.empty()) {
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

	file += ".png";
	return file;
}

#endif
