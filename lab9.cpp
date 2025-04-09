/*
Program will input 2 matrices from a file, with 2 ints telling
the size of the matrix, and a 0 or 1 indicating integer matrices or
double-precision matrices respectively. The program will store matrix data
into a matrix class, and then perform operations on the matrices.
*/

#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

class Matrix{
    private:
        int size; //Variable to hold size of the matrix
        int typeFlag; //Variable to hold type of the matrix (0 for int, 1 for double)
        void* matrix; //Pointer to hold the matrix data (int or double)
        string fileName; //Variable to hold name of the input file
        ifstream inFile; //Input file stream to read the matrix from the file
        void readFile(){    //Function to read the matrix from the file
            inFile >> size; //Read the size of the matrix from the file
            inFile >> typeFlag; //Read the type of the matrix from the file
            if (typeFlag == 0){ //If the matrix is of type int
                int **intMatrix = new int*[size]; //Allocate memory for the matrix
                for(int i = 0; i < size; i++){
                    intMatrix[i] = new int[size]; //Allocate memory for each row of the matrix
                }
                matrix = intMatrix; //Set the matrix pointer to the allocated memory
            } else { //If the matrix is of type double
                double **doubleMatrix = new double*[size]; //Allocate memory for the matrix
                for(int i = 0; i < size; i++){
                    doubleMatrix[i] = new double[size]; //Allocate memory for each row of the matrix
                }
                matrix = doubleMatrix; //Set the matrix pointer to the allocated memory
            }

            //Start reading in Values to the matrix
            for (int i = 0; i < size; i++){         //Loop to read in the matrix from the file
                for (int j = 0; j < size; j++){         //Loop to read in the matrix from the file
                    if (typeFlag == 0){ //If the matrix is of type int
                        inFile >> ((int**)matrix)[i][j]; //Read in the matrix from the file
                    } else { //If the matrix is of type double
                        inFile >> ((double**)matrix)[i][j]; //Read in the matrix from the file
                    }
                }
            }
        
        }; 
    public:
        Matrix(string fileName){ //Constructor to initialize the matrix to either int or double depending on typeFlag
            this->fileName = fileName; //Set the name of the input file
            this->inFile.open(fileName); //Open the input file
            readFile(); //Call the function to read the matrix from the file
        }; 
    };
    
    int main(){

        return 0; //Exit the program
    }