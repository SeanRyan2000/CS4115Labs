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

printingAns(float);
int main(int argc, char *argv[]) {

	if (argc > 1 && string(argv[1]) == "-e")
		epsilon = fabs(strtod(argv[2], 0));

	printingAns(epsilon);
	cout<<epsilon;


}



void printingAns(float epsilon){
	string line;
	while (getline(cin, line))
	{
		std::istringstream lstream(line) ;
	double val;
	// peel off values in this line, one at a time
	while (lstream>> val)
	{
	// check if val is 0, etc.
	}
	}
}