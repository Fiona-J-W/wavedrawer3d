#include "settings.hpp"

#include <cstdlib>
#include <string>


using namespace std;

settings::settings(){
	width=0;
	height=0;
	propagation_speed=0;
	number_of_pics=1;
	
}

settings::settings(int argc, char **argv){
	///init variables:
	string tempstr;
	///set some defaults:
	width=0;
	height=0;
	propagation_speed=0;
	number_of_pics=1;
	///analyse the programs parameters:
	for(int i=1;i<argc;++i){
		tempstr=argv[i];
		if(tempstr.substr(0,2)=="-w"){
			width=atoi(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-h"){
			height=atoi(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-n"){
			number_of_pics=atoi(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-v"){
			propagation_speed=atof(tempstr.substr(2).c_str());
		}
		else if(tempstr.substr(0,2)=="-f"){
			file=tempstr.substr(2);
		}
		else if(tempstr.substr(0,2)=="-P"){
			points.push_back(point(tempstr.substr(2)));
		}
	}
	
}