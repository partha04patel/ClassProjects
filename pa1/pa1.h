//
// Created by Parth on 9/29/2017.
//

#ifndef UNTITLED1_PA1_H
#define PA1_H

#include <iostream>

//This method goes through the elements of a given 2D array and prints the elements to the console,
// creating a new line after each row
void printMatrix (int **magicSquare, int dimension, int number) {
    std::cout<<"Magic Square # "<<number<<" is: " << "\n";
    for (int i = 0; i < dimension; i ++) {
        std::cout<<"\n";
        for (int j = 0; j < dimension; j ++) {
            std::cout<<magicSquare[i][j]<<"\t";
        }
    }
    std::cout<<"\n";
}
//This method sums each column of a given 2D array by adding all elements with the same column index.
void sumOfColumns (int ** magicSquare, int dimension) {
    std::cout << "\nChecking the sums of every column: ";
    for (int columnIndex = 0; columnIndex < dimension; columnIndex++) {
        int columnTotal = 0;
        for (int x = 0; x < dimension; x++) {
            columnTotal += magicSquare[x][columnIndex];
        }
        std::cout <<columnTotal<<"\t";
    }
}
//This method sums each rows of a given 2D array by adding all elements with the same row index.
void sumOfRows(int ** magicSquare,int dimension) {
    std::cout << "\nChecking the sums of every row: ";
    for (int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        int rowTotal = 0;
        for (int x = 0; x < dimension; x++) {
            rowTotal += magicSquare[rowIndex][x];
        }
        std::cout << rowTotal<<"\t";
    }
}
//This method sums each diagonal of a given 2D array by adding all elements whose indices are either the same value,
// and the ones whose horizontal indices and vertical vertices have the greatest numerical difference.
void sumOfDiagonals(int ** magicSquare, int dimension) {
    std::cout<<"\nChecking the sums of every diagonal: ";
    int diagonalTotal1 = 0;
    int diagonalTotal2 = 0;
    for (int x = 0; x < dimension; x++) {
        for (int y = 0; y < dimension; y++) {
            if (x == y) {
                diagonalTotal1 += magicSquare[x][y];
            }
            if (x==(dimension-1-y)) {
                diagonalTotal2 += magicSquare[x][y];
            }
        }
    }
    std::cout<<diagonalTotal1<<"\t";
    std::cout<<diagonalTotal2<<"\n"<<std::endl;
}
/*This is the method that creates the 5 magic squares. First, two 2D arrays are created. Both are used throughout the
//method, but since magic squares 2 through 5 are transformations of the first magic square, a copy of the first matrix
is needed so that the magicSqare that gets sent to printMatrix doesn't overwrite itself during assignment statements.
 */
void MagicSquare (int dimension) {
    int **magicSquare = new int *[dimension];
    for (int i = 0; i < dimension; i++) {
        magicSquare[i] = new int[dimension];
    }
    int **tempMatrix = new int *[dimension];
    for (int i = 0; i < dimension; i++) {
        tempMatrix[i] = new int[dimension];
    }
    for (int x = 0; x < dimension; x++) {
        for (int y = 0; y < dimension; y++) {
            //This formula is an algorithm to fill up magic squares of an odd order:
            // https://en.wikipedia.org/wiki/Magic_square#Method_for_constructing_a_magic_square_of_odd_order
            magicSquare[x][y] = (dimension * ((x+1 + y+1 - 1 + (dimension / 2)) % dimension)) + ((x+1 + (2 * (y+1)) - 2) % dimension) + 1;
            tempMatrix[x][y] = magicSquare[x][y];
        }
    }
    printMatrix(magicSquare, dimension, 1);
    sumOfRows(magicSquare, dimension);
    sumOfColumns(magicSquare, dimension);
    sumOfDiagonals(magicSquare, dimension);

    //The second matrix simply is the first matrix with the rows and columns transposed.
    for (int x = 0; x < dimension; x++) {
        for (int y = 0; y < dimension; y++) {
            magicSquare[x][y] = tempMatrix[y][x];
        }
    }
    printMatrix(magicSquare, dimension, 2);
    sumOfRows(magicSquare, dimension);
    sumOfColumns(magicSquare, dimension);
    sumOfDiagonals(magicSquare, dimension);

    //The third matrix is the second matrix with the rows and columns transposed once more, and the rows are in reverse order.
    for (int x = 0; x < dimension; x++) {
        for (int y = 0; y < dimension; y++) {
          magicSquare[x][y] = tempMatrix[x][dimension - 1 - y];
        }
    }
    printMatrix(magicSquare, dimension, 3);
    sumOfRows(magicSquare, dimension);
    sumOfColumns(magicSquare, dimension);
    sumOfDiagonals(magicSquare, dimension);

    //The fourth matrix simply is the third matrix with the rows and columns transposed.
    for (int x = 0; x < dimension; x++) {
        for (int y = 0; y < dimension; y++) {
            magicSquare[x][y] = tempMatrix[y][dimension - 1 - x];
        }
    }
    printMatrix(magicSquare, dimension, 4);
    sumOfRows(magicSquare, dimension);
    sumOfColumns(magicSquare, dimension);
    sumOfDiagonals(magicSquare, dimension);

//The fifth matrix is the fourth matrix with the rows and columns transposed once more, and the rows are reversed.
    for (int x = 0; x < dimension; x++) {
        for (int y = 0; y < dimension; y++) {
            magicSquare[x][y] = tempMatrix[x][dimension - 1 - y];
            magicSquare[x][y] = tempMatrix[dimension - 1 -x][y];
        }
    }
    printMatrix(magicSquare, dimension, 5);
    sumOfRows(magicSquare, dimension);
    sumOfColumns(magicSquare, dimension);
    sumOfDiagonals(magicSquare, dimension);
/*
  This section of the program deletes the two dynamic arrays, because in reality, the 2D array is simply
  an array of arrays of pointers. Thus, the memory addresses pointing to the numbers of the magic squares need
  to be deleted by hand when the program ends.
     */
for (int i = 0; i < dimension; i++) {
    delete[] magicSquare[i];
    delete[] tempMatrix[i];
}
    delete[] magicSquare;
    delete[] tempMatrix;
}
#endif //UNTITLED1_MAGICSQUARE_H
