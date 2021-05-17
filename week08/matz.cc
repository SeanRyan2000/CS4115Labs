
#include <iostream>
#include <string>
#include <sstream>
#include <list>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::list;

#include <math.h>
#include <stdlib.h>

class nz {	    // one instance for every non-zero entry in matrix
public:
  nz(int i, double v) {	// constructor when given the two items of data
    ind = i;
    val = v;
  }
  int getInd() const { return ind; } // access to ind class member
  double getVal() const { return val; } // access to val class member
private:
  int ind;
  double val;
};

typedef list<nz> sparseRow;

double epsilon = 0.0;

int main(int argc, char *argv[])
{
  if (argc > 1 &&
      string(argv[1]) == "-e")
  {
    epsilon = fabs(strtod(argv[2], 0));
  }

  string line;
  int nzct = 0;
  list< sparseRow > rows;
  while (getline(cin, line))	// get next full line of text; NB: text
  {
    std::istringstream lstream(line) ;
    sparseRow row;
    int ind = 0;		// index of element of row
    double val;
    while (lstream>> val)	// peel off values in this line, one at a time
    {
      ind++;
      if (fabs(val) <= epsilon)
	continue;

      row.push_back(nz(ind, val));
    }
    rows.push_back(row);
    nzct += row.size();		// how many new non-zeros
  }

  //  cout<< rows.size()<< " "<< nzct<< endl;

  // now iterate through the list of lists
  list<sparseRow>::const_iterator rit; // we only want to /read/ list
  for (rit = rows.begin(); rit != rows.end(); rit++)
  {
    sparseRow row = *rit;
    //    cout<< row.size();
    // iterate over this row, only /read/
    sparseRow::const_iterator nzit;
    for (nzit = row.begin(); nzit != row.end(); nzit++)
    {
      cout<< nzit->getInd()<< " "<< nzit->getVal()<< " ";
    }

    cout<< endl;
  }
}

