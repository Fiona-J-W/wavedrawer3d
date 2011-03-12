#ifndef __divide_string_cpp__
#define __divide_string_cpp__

#include "divide_string.hpp"

#include <cstdlib>

using namespace std;

vector<double> divide_string(
		string str,
		unsigned int number_of_values,
		char divider /* default: ':' */
	){
	vector<double> values;
	size_t divider_old = -1;
	size_t divider_new = -1;
	bool end_of_string = false;
	for(unsigned int i = 0; i < number_of_values; i++) {
		divider_old = divider_new;
		divider_new = str.find(divider, divider_old + 1);
		if(end_of_string) {
			values.push_back(0);
		} else {
			values.push_back(atof(str.substr(divider_old + 1, divider_new - divider_old - 1).c_str()));
		}
		if(divider_new == str.npos) { end_of_string = true; }
	}
	return values;
}

#endif
