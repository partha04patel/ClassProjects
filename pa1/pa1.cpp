/*
Created by Parth on 9/18/2017.
UFID: 9138-1758
 COP3503: Programming Assignment 1
*/

//This includes the header file which contains all the methods for generating the magic squares, calculating sums
//of rows, columns, and diagonals, and printing the arrays.

#include "pa1.h"

//main method simply takes in the correct numerical input then calls the MagicSquare
// function if the number falls within the given parameters.

int main () {
    int size = 0;
    std::cout<<"Enter the size of a magic square: ";
    std::cin>>size;

    if ((size % 2 != 0) && (size >= 3) && (size <=15)) {
        MagicSquare(size);
    }
    else {
        std::cout<<"Please enter an odd number between 3 and 15.";
    }
    return 0;
}






