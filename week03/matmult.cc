#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;

#include <math.h>
#include <stdlib.h>

void readArr(int, int, double **);
void multArrs(int, double **, int, double **, int, double **);

int main(int argc, char *argv[])
{
  int ar = atoi(argv[1]);
  int ac = atoi(argv[2]);
  int br = atoi(argv[3]);
  int bc = atoi(argv[4]);

  if (ac != br)
  {
    cerr<< "Matrix dimensions mismatch; exiting.\n";
    exit(-1);
  }

  // reserve space for the three arrays
  double **A = new double*[ar];	// each el. of this points to a row of A
  for (int i = 0; i < ar; i++)
    A[i] = new double[ac];	// a row of 'ac' floats

  double **B = new double*[br];
  for (int i = 0; i < br; i++)
    B[i] = new double[bc];	// a row of 'bc' floats

  double **C = new double*[ar];
    for(int i=0; i<ar; i++){
   C[i] = new double[bc];
}

  // now that sufficient storage is allocated, start reading from kbd

  readArr(ar, ac, A);
  readArr(br, bc, B);

  multArrs(ar, A, bc, B, ac, C);

  // now print out answer, nice and plainly
//DOUBLE FOR NEEDED HERE
//PRINT IT OUT SPACE BETWEEN EACH NUMBER
//NEW LINE NEEDED WHEN IT HITS THE END OF THE ROWS
// WILL ALWAYS END UP BEING THE SIZE AS ROWS OF MAT A AND COL OF MAT B

	for (int i = 0; i < ar; i++) {
		for (int j = 0; j < bc; j++)	std::cout<<C[i][j]<<" ";
	std::cout<<"\n";
	}
	

}

// read from kbd into this array, row by row
//  for a total of r x c entries;
//  WARNING: space for array must have been reserved beforehand


void readArr(int r, int c, double **arr)
{

 // code for reading in r rows of c elements each goes here
//DOUBLE FOR SAME AS IN PREVIOUS LAB IN FIRST SEM

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){

                std::cin>> arr[i][j];
        }
     }
}


void multArrs(int ar, double **A, int bc, double **B, int br, double **C)
{
  // multiplication here
	// FIGURE OUT THE DOUBLE FOR 
	// MULTIPLY  IN  MATRIX A POS R X 
	// BY MATRIX B POS X C
  

		// MATRIX A 1,2 [1 2]
		// MATRIX B 2,4	[3 4 5 6]
	//			[7 8 9 10]

	//(1*3) + ( 2*7)
	// (1*4) + (2 * 8)
	

	for (int r = 0; r<ar; r++) {

		 for (int c=0; c<bc; c++){
			C[r][c]= 0;

			for(int x=0; x < br; x++){
//				C[r][c] = 2; debugging
				C[r][c] += A[r][x]*B[x][c];
			}

		}

	}



}
