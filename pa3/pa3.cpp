//
// Created by Parth on 11/9/2017.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include "pa3.h"

int main () {

    //Initializing stack: this will be to count loop depth of code in text file.
    Stack loops;

    //Take in file name: name should be complete path to text file!
    std::string inputFileName;
    std::fstream inputFile;
    std::cout << "Please enter the name of the input file: " << std::endl;
    std::cin >> inputFileName;
    inputFile.open(inputFileName);

    std::string text;
    std::string fileContent;
if (inputFile.is_open()) {
    //This ensures that program is executed only if file is successfully opened, and runs program per line of text in the file.
    while (getline(inputFile, fileContent)) {
        //If words For or Begin found, have boolean for respective word be true.
        if (fileContent.find("FOR") != fileContent.npos)
            loops.forLoop = true;
        if (fileContent.find("BEGIN") != fileContent.npos) {
            loops.push("BEGIN");
            loops.beginWord = true;
            if (loops.nestedLoop && loops.parenthesis) {
                loops.loopCount++;
                //Ensures loopCount and loop stay the same.
                if (loops.loopCount > loops.loop)
                    loops.loop = loops.loopCount;

            }
            else if (loops.parenthesis && !loops.nestedLoop) {
                if (loops.loopCount > loops.loop)
                    loops.loop = loops.loopCount;

                loops.nestedLoop = true;
                loops.loopCount = 0;
                loops.loopCount++;
            }
            if (loops.parenthesis == false)
                loops.parenthesis = true;
        }
        if (fileContent.find("END") != fileContent.npos) {
                        loops.endWord = true;
            loops.pop();
            loops.nestedLoop = false;
        }


        if (fileContent.find("+") != fileContent.npos)
            loops.ASign = true;
        if (fileContent.find("/") != fileContent.npos)
            loops.flash = true;
        if (fileContent.find("=") != fileContent.npos)
            loops.equals = true;
        if (fileContent.find("++") != fileContent.npos)
            loops.increment = true;
        if (fileContent.find("-") != fileContent.npos)
            loops.SSign = true;
        if (fileContent.find("*") != fileContent.npos)
Z           loops.MSign = true;
        if (fileContent.find("/") != fileContent.npos)
            loops.DSign = true;
        if (fileContent.find(",") != fileContent.npos)
            loops.comma = true;
        if (fileContent.find(";") != fileContent.npos)
            loops.semicolon = true;

        //If one of the parentheses not found, method then executed to see if error is pushed back or not.
        if (fileContent.find("(") != fileContent.npos || fileContent.find(")") != fileContent.npos)
            verifyParentheses(fileContent, fileErrors, loops.parenthesis);

        //Reads data from input string and then pushes data into vectors.
        verifyIdentifiers(fileContent, identifiers);
        verifyConstants(fileContent, constants);
        verifyErrors(fileErrors, fileContent);
    }


    if (inputFile.fail()) {
        std::cout << "Error: File cannot be opened.";
        return 1;
    }
    loops.counter = loops.getMaximum();

    if (loops.getSize() == 0 && loops.loopCount > loops.loop)
        loops.loop= loops.loopCount;

    if (loops.getSize() > 0 && loops.getMaximum() != 0)
        loops.counter = loops.getMaximum() - loops.getSize();


    if (loops.getCurrent() < 0 && loops.getMaximum() != 0)
        loops.counter = loops.getMaximum() + loops.getCurrent();

    if (loops.counter < loops.loop && loops.loop > 0)
        loops.counter = loops.loop;

    std::cout << "The depth of nested loop(s) is " << loops.counter << std::endl;

    //Depending on values of member variables of loop stack, program will print out the Keywords and all the other important data to the console.
    std::cout << "Keywords: ";
    if (loops.forLoop)
        std::cout << "FOR ";
    if (loops.beginWord)
        std::cout << "BEGIN ";
    if (loops.endWord)
        std::cout << "END";

    std::cout << "\nIdentifiers: ";
    for (int i = 0; i < identifiers.size(); i++)
        std::cout << identifiers[i] << " ";

    std::cout << "\nConstants: ";
    for (int i = 0; i < constants.size(); i++)
        std::cout << constants[i] << " ";

    std::cout << "\nOperators: ";
    if (loops.ASign)
        std::cout << "+ ";
    if (loops.DSign)
        std::cout << "/ ";
    if (loops.SSign)
        std::cout << "- ";
    if (loops.increment)
        std::cout << "++ ";
    if (loops.MSign)
        std::cout << "* ";
    if (loops.equals)
        std::cout << "= ";


    std::cout << "\nDelimiters: ";
       if (loops.comma)
        std::cout << ", ";
    if (loops.semicolon)
        std::cout << "; ";

    if (loops.endWord == false)
        fileErrors.push_back("END");

    std::cout << "\nSyntax Error(s): ";
    if (fileErrors.size() < 2)
        std::cout << "\tNA";
    for (int i = 0; i < fileErrors.size(); i++)
            std::cout << fileErrors[i] << " ";




}
    inputFile.close();
    return 0;
    }












