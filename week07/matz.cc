
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>


using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using std::string;

float epsilon = 0;

void printingAns(float);
int main(int argc, char *argv[]) {

	if (argc > 1 && string(argv[1]) == "-e")
		epsilon = fabs(strtod(argv[2], 0));
	
	//string line;
	printingAns(epsilon);
	
	//cout<<"\n\n\n"<<epsilon<< "\n\n\n";

}



void printingAns(float epsilon){
	string line;
	
	while (getline(cin, line))
	{
		std::istringstream lstream(line) ;
		//int zeros =0;
		int x = 0;
		int j=0;
		double val;
		
		// peel off values in this line, one at a time
		int position = 0;
		while (lstream>> val)
		{
		x++;
		
	// check if val is 0, etc.
		if(val ==0 || abs(val) <= epsilon) {
		//	zeros++;
		} else {
			position = j + 1;
			//x++;
			cout<<x<<" "<<val<<" ";
		}
		position++;
	
	
	
	
		}
		
		cout<<"\n";
		
	}

}
