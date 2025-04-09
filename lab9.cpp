/*
Program will input 2 matrices from a file, with 2 ints telling
the size of the matrix, and a 0 or 1 indicating integer matrices or
double-precision matrices respectively. The program will store matrix data
into a matrix class, and then perform operations on the matrices.
*/

#include <iostream> 
#include <fstream> 
#include <string>
#include <iomanip> //For setting precision of double output

using namespace std;

class Matrix{
    private:
        int size; //Variable to hold size of the matrix
        int typeFlag; //Variable to hold type of the matrix (0 for int, 1 for double)
        int** intMatrix; //Pointer to hold int data if applicable
        double** doubleMatrix; //Pointer to hold double data if applicable
        
        void createMatrix(){    //Function to read the matrix from the file
            if (typeFlag == 0){ //If the matrix is of type int
                intMatrix = new int*[size]; //Allocate memory for the matrix
                for(int i = 0; i < size; i++){
                    intMatrix[i] = new int[size]; //Allocate memory for each row of the matrix
                }
            } else { //If the matrix is of type double
                doubleMatrix = new double*[size]; //Allocate memory for the matrix
                for(int i = 0; i < size; i++){
                    doubleMatrix[i] = new double[size]; //Allocate memory for each row of the matrix
                }
            }
        };
    public:
        Matrix(int size, int typeFlag){ //Constructor to initialize the matrix to either int or double depending on typeFlag
            this->size = size; //Set the size of the matrix
            this->typeFlag = typeFlag; //Set the type of the matrix
            intMatrix = nullptr; //Initialize intMatrix to nullptr(Suggested by ChatGPT)
            doubleMatrix = nullptr; //Initialize doubleMatrix to nullptr(Suggested by ChatGPT)
            createMatrix(); //Call the function to create the matrix
        }; 

        void fillMatrix(ifstream& inFile){ //Function to fill the matrix with data from the file
            if (typeFlag == 0){ //If the matrix is of type int
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        inFile >> intMatrix[i][j]; //Read the matrix data from the file
                    }
                }
            } else { //If the matrix is of type double
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        inFile >> doubleMatrix[i][j]; //Read the matrix data from the file
                    }
                }
            }
        };

        void printMatrix(){ //Function to print the matrix to the console
            if (typeFlag == 0){ //If the matrix is type int
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        cout << intMatrix[i][j] << " "; //Print the matrix data to the console
                    }
                    cout << endl; //Print a new line after each row of the matrix
                }
            } else { //If the matrix is of type double
                cout << fixed << setprecision(2); //Set the precision for double output
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        cout << doubleMatrix[i][j] << " "; //Print the matrix data to the console
                    }
                    cout << endl; //Print a new line after each row of the matrix
                }
            }
        };

        Matrix operator+(Matrix& otherMatrix){ //Function to add two matrices
            Matrix result(size, typeFlag); //Create a result matrix of the same size and type
            if (typeFlag == 0){ //If the matrix is of type int
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        result.intMatrix[i][j] = intMatrix[i][j] + otherMatrix.intMatrix[i][j]; //Add the two matrices
                    }
                }
            } else { //If the matrix is of type double
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        result.doubleMatrix[i][j] = doubleMatrix[i][j] + otherMatrix.doubleMatrix[i][j]; //Add the two matrices
                    }
                }
            }

            return result; //Return the result matrix
        }

        Matrix operator*(Matrix& otherMatrix){
            Matrix result(size, typeFlag); //Create a result matrix of the same size and type
            if (typeFlag == 0){ //If the matrix is of type int
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        result.intMatrix[i][j] = 0; //Initialize the result matrix to 0
                        for(int k = 0; k < size; k++){
                            result.intMatrix[i][j] += intMatrix[i][k] * otherMatrix.intMatrix[k][j]; //Multiply the two matrices
                        }
                    }
                }
            } else { //If the matrix is of type double
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        result.doubleMatrix[i][j] = 0.0; //Initialize the result matrix to 0.0
                        for(int k = 0; k < size; k++){
                            result.doubleMatrix[i][j] += doubleMatrix[i][k] * otherMatrix.doubleMatrix[k][j]; //Multiply the two matrices
                        }
                    }
                }
            }

            return result; //Return the result matrix
        }

        void sumDiagonals(){
            double mainDiagSum = 0.0; //Variable to hold the sum of the main diagonal
            double secDiagSum = 0.0; //Variable to hold the sum of the secondary diagonal

            if (typeFlag == 0){ //If the matrix is of type int
                for(int i = 0; i < size; i++){
                    mainDiagSum += intMatrix[i][i]; //Sum the main diagonal
                    secDiagSum += intMatrix[i][size - i - 1]; //Sum the secondary diagonal
                }
            } else { //If the matrix is of type double
                for(int i = 0; i < size; i++){
                    mainDiagSum += doubleMatrix[i][i]; //Sum the main diagonal
                    secDiagSum += doubleMatrix[i][size - i - 1]; //Sum the secondary diagonal
                }
            }
            
            cout << "Sum of the main diagonal: " << mainDiagSum << endl; //Print the sum of the main diagonal
            cout << "Sum of the secondary diagonal: " << secDiagSum << endl; //Print the sum of the secondary diagonal
        }

        void swapMatrixRows(){ //Function to swap two rows of the matrix
            int row1, row2; //Variables to hold the row numbers to swap
            cout << "Enter the two rows to swap (0 to " << size - 1 << "): "; //Ask user for the two rows wanting to swap
            cin >> row1 >> row2; //Get the two rows from the user

            if(row1 < 0 || row1 >= size || row2 < 0 || row2 >= size){ //Check if the rows are valid
                cout << "Invalid row numbers." << endl; //Print error message
                return; //Return from the function
            }
            if (typeFlag == 0){ //If the matrix is of type int
                for(int j = 0; j < size; j++){
                    int temp = intMatrix[row1][j]; //Temporary variable to hold the value of the first row
                    intMatrix[row1][j] = intMatrix[row2][j]; //Swap the two rows
                    intMatrix[row2][j] = temp; //Swap the two rows
                }
            } else { //If the matrix is of type double
                for(int j = 0; j < size; j++){
                    double temp = doubleMatrix[row1][j]; //Temporary variable to hold the value of the first row
                    doubleMatrix[row1][j] = doubleMatrix[row2][j]; //Swap the two rows
                    doubleMatrix[row2][j] = temp; //Swap the two rows
                }
            }
            cout << "Matrix after swapping rows: " << endl; //Print the matrix after swapping the rows
            printMatrix(); //Print the matrix after swapping the rows
        }

        void swapMatrixColumns(){
            int col1, col2; //Variables to hold the column numbers to swap
            cout << "Enter the two columns to swap (0 to " << size - 1 << "): "; //Ask user for the two columns wanting to swap
            cin >> col1 >> col2; //Get the two columns from the user

            if(col1 < 0 || col1 >= size || col2 < 0 || col2 >= size){ //Check if the columns are valid
                cout << "Invalid column numbers." << endl; //Print error message
                return; //Return from the function
            }
            if (typeFlag == 0){ //If the matrix is of type int
                for(int i = 0; i < size; i++){
                    int temp = intMatrix[i][col1]; //Temporary variable to hold the value of the first column
                    intMatrix[i][col1] = intMatrix[i][col2]; //Swap the two columns
                    intMatrix[i][col2] = temp; //Swap the two columns
                }
            } else { //If the matrix is of type double
                for(int i = 0; i < size; i++){
                    double temp = doubleMatrix[i][col1]; //Temporary variable to hold the value of the first column
                    doubleMatrix[i][col1] = doubleMatrix[i][col2]; //Swap the two columns
                    doubleMatrix[i][col2] = temp; //Swap the two columns
                }
            }
            cout << "Matrix after swapping columns: " << endl; //Print the matrix after swapping the columns
            printMatrix(); //Print the matrix after swapping the columns
        }

        ~Matrix(){ //Destructor to free the allocated memory for the matrix
            if (typeFlag == 0){ //If the matrix is of type int
                for(int i = 0; i < size; i++){
                    delete[] intMatrix[i]; //Delete each row of the matrix
                }
                delete[] intMatrix; //Delete the matrix itself
            } else { //If the matrix is of type double
                for(int i = 0; i < size; i++){
                    delete[] doubleMatrix[i]; //Delete each row of the matrix
                }
                delete[] doubleMatrix; //Delete the matrix itself
            }
        };
    };

    int main(){
        string filename; //Variable to hold name of the input file
        int size; //Variable to hold the size of the matrix
        int typeFlag; //Variable to hold the type of the matrix (0 for int, 1 for double)
        cout << "Enter the name of input file: " << endl; //Ask user for name of input file
        cin >> filename; //Get name of input file from user

        ifstream inFile(filename); //Open the input file
        if (!inFile) { //Check if the file opened successfully 
            cout << "Error opening file." << endl; //Print error message
            return 1; //Return from the function
        }

        inFile >> size; //Read the size of the matrix from first line of the file
        inFile >> typeFlag; //Read the type of the matrix from the file
        Matrix matrix1(size, typeFlag); //Create a matrix with given size and typeFlag
        matrix1.fillMatrix(inFile); //Fill the matrix with data from the file

        Matrix matrix2(size, typeFlag); //Create a second matrix with given size and typeFlag
        matrix2.fillMatrix(inFile); //Fill the second matrix with data from the file
        
        //cout << "Matrix 1: " << endl; //Print the first matrix to the console
        //matrix1.printMatrix(); 
        //cout << "Matrix 2: " << endl; //Print the second matrix to the console
        //matrix2.printMatrix(); 

        //cout << "Addition of the two matrices: " << endl; 
        //(matrix1 + matrix2).printMatrix(); //Print the result of addition

        //cout << "Multiplication of the two matrices: " << endl; //Print the result of multiplication
        //(matrix1 * matrix2).printMatrix(); //Print the result of multiplication

        //matrix1.sumDiagonals(); //Call the function to sum the diagonals of the first matrix
        //matrix2.sumDiagonals(); //Call the function to sum the diagonals of the second matrix

        //matrix1.swapMatrixRows(); //Call the function to swap rows of the first matrix
        matrix1.swapMatrixColumns(); //Call the function to swap columns of the first matrix
        
        return 0; //Exit the program
    }