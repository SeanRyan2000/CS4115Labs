#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>


using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;

void readArr(int, int, double **);
void formatArr(int, int, int, double**, double **);
int totalZeros = 0;

int main(int argc, char *argv[]) {
	int ar = atoi(argv[1]);
	int ac = atoi(argv[2]);
	//int numOfCol = ac;
	int length =0;
	int totalElements = ar * ac;
 

	if(ar == 0 || ac == 0) {
		cerr << "Need to specify row- and col-count for matrix; exiting.";
		exit(-1);
	}
	
	
	
	double **A = new double*[ar];	// each el. of this points to a row of A
		for (int i = 0; i < ar; i++){
			A[i] = new double[ac];	// a row of 'ac' floats
			length = ac;
		}
	
	double **B = new double*[(ar)];
		for(int i=0; i<ar; i++){
			B[i] = new double[(ac*2+1)];
			
		}
	cout << ar << "\n";
	
	//int len = sizeof(B)/sizeof(B[0]);
	//cout << "THE SIZE OF THE ARRAY IS   " << length << "\n\n\n\n\n\n";
	
	
	

	readArr(ar, ac, A);
	formatArr(ar, ac, length, A, B);
	
	
	for (int i = 0; i < ar; i++) {
		for (int j = 0; j < ac*2+1; j++)	{
			if(j != 0 && B[i][j] == 0) {
				
				
			}else {
				std::cout<<B[i][j]<<" ";
			}
		}
			std::cout<<"\n";
	}
	cout << totalElements - totalZeros;
	
	
	
}
	

	void readArr(int r, int c, double **arr){
	 // code for reading in r rows of c elements each goes here
	//DOUBLE FOR SAME AS IN PREVIOUS LAB IN FIRST SEM
	  for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
					std::cin>> arr[i][j];
					if(arr[i][j] == 0){
						totalZeros++;
						
					}
			}
		}

		
	}
	
	
		void formatArr(int ar, int ac, int numOfCol, double **A, double **B) {
			//ANY 0 VALUE NEEDS TO BE REMOVEDfor(int i = 0; i < r; i++){
		
			//COUNT THE NUMBER OF 0 VALUES REMOVED
			
			//ZERO VALUES REMOVED - COLUMNS = NUMBER OF NON ZERO VALUES
			// POSITION OF NON ZERO VALUES EQUAL POSITION + 1 (START AT 0)
			// THEN PRINT THE ACTUAL VALUE 
			// MAX SIZE POSSIBLE IS 2x COLUMNS OF OLD ARRAY 
			//NUMBER OF ROWS + 2
			//FIRST NUMBER ALREADY PRINTED SO ONLY + 1
			//LAST NUMBER IS THE NUMBER OF NON ZERO SO NEED TO KEEP 2 COUNTS
			//COUNT FOR NUMBER IF 0's IN ROWS
			// COUNT FOR TOTAL NUMBER OF 0's
			//COULD WAIT TILL THE VERY END OF EACH ROW AND THAT COUNT + TOTAL COUNT
			//(MORE EFFICIENT(I THINK?))
			// COULD ALSO JUST INCREMENT BOTH AT SAME TIME (WORSE BUT EASIER SO I'LL GO WITH THIS)
			
			for(int i = 0; i < ar; i++){
				int zeros =0;
				int x = 0;
				for(int j = 0; j < ac; j++){
					x++;
					//int zeros = 0;
					int position = 0;
					if(A[i][j] == 0){
						zeros++;
					}
					else{
						
						position = j + 1;
						B[i][x] = position;
						x++;
						B[i][x] = A[i][j];
						
					}
						
						
						
						//at end 
						
						
						if (j == numOfCol -1){
							B[i][0] = j - zeros +1;
						}		
					
				}					
				
			}
			
			
			
		}
			
	
		
	
	
	
	
	
	
	
