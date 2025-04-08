/*
Program will input 2 matrices from a file, with 2 ints telling
the size of the matrix, and a 0 or 1 indicating integer matrices or
double-precision matrices respectively. The program will store matrix data
into a matrix class, and then perform operations on the matrices.
*/

#include <iostream> 
#include <fstream> 

class Matrix{
    private:
        int size; //Variable to hold size of the matrix
        int typeFlag; //Variable to hold type of the matrix (0 for int, 1 for double)
        void* matrix; //Pointer to hold the matrix data (int or double)
    public:
        Matrix(int size, int typeFlag){ //Constructor to initialize the matrix to either int or double depending on typeFlag
            this->size = size; //Set the size of the matrix
            this->typeFlag = typeFlag; //Set the type of the matrix
            if (typeFlag == 0){ //If the matrix is of type int
                int** intMatrix = new int*[size]; //Allocate memory for the matrix
                for(int i = 0; i < size; i++){
                    intMatrix[i] = new int[size]; //Allocate memory for each row of the matrix
                }
                matrix = intMatrix; //Set the matrix pointer to the allocated memory
            } else { //If the matrix is of type double
                double** doubleMatrix = new double*[size]; //Allocate memory for the matrix
                for(int i = 0; i < size; i++){
                    doubleMatrix[i] = new double[size]; //Allocate memory for each row of the matrix
                }
                matrix = doubleMatrix; //Set the matrix pointer to the allocated memory
            }
        }; 
    };       