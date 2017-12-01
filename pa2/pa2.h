//
// Created by Parth on 10/21/2017.
//
#include <iomanip>
#include <iostream>

#ifndef MAIN_H
#define MAIN_H

//structure for a program: each node in the linked list.
struct Program {
public:
    Program *nextProgram;
    std::string programName;

    Program* getNextProgram() {
        return nextProgram;
    }
    Program( std::string name) {
         programName=name;
        nextProgram=NULL;
    }
};

//linked list structure: initializes the linked list with 32 Programs called "FREE"
struct ProgramList {
public:
    Program *firstProgram;
    Program *lastProgram;
    //This constructor is for initilaizing the linked list.
    ProgramList () {
        firstProgram = NULL;
        lastProgram = NULL;
             for (int count = 0; count < 32; count++) {
            if (firstProgram == NULL) {
              firstProgram = new Program("FREE");
              lastProgram= firstProgram;

            } else {
                lastProgram->nextProgram = new Program("FREE");
                lastProgram = lastProgram->getNextProgram();

            }
        }
    }
    //Structure called upon when program is added or destroyed since program name is required.
    ProgramList (std::string name){
        firstProgram = NULL;
        lastProgram = NULL;
        firstProgram = new Program(name);
        lastProgram = firstProgram;

    }
//This program is called when user tries to add program. Based on algorithm type, it will return the needed page to store the inputted program.
Program* Pages (std::string algorithmType, int neededMemory){
Program* outputProgram = NULL;
int minimumSize = 33;
int maximumSize= 0;

    for (Program *counter = firstProgram; counter != NULL; counter= counter->getNextProgram()) {
        int index = 0;
          if (counter->programName=="FREE"){
                Program* emptyProgram;
                for (Program* secondCounter = counter;secondCounter != NULL; secondCounter = secondCounter->getNextProgram()) {
                    if (secondCounter->programName == "FREE") {
                        emptyProgram = secondCounter;
                        index++;
                }
            }
            if (algorithmType == "best") {
                //best algorithm: we want the smallest space available that can store the program.
                if (index < minimumSize && index >= neededMemory) {
                    outputProgram = counter;
                    minimumSize = index;
                }
                counter = emptyProgram;
            }

            if (algorithmType == "worst") {
                //worst algorithm: we want the largest space available that can store the program.
                if (index > maximumSize && index >= neededMemory) {
                    outputProgram = counter;
                    maximumSize = index;


                }
                counter = emptyProgram;
            }

        }
    }
return outputProgram;
}

//will successfully added the inputted program unless program is duplicate or linked list doesn't have enough space.
void AddProgram(std::string name, int memory, std::string algorithmType) {
    int copy = memory;
    bool added = false;
    bool duplicateProgram = false;
    for (Program *counter = firstProgram; counter != NULL; counter= counter->getNextProgram()) {
        if (counter->programName == name)
            duplicateProgram = true;
    }

if (duplicateProgram) {
    std::cout<<"Error, Program " <<name<<" is already running."<<std::endl;
}

    Program *wantedSpace = Pages(algorithmType, memory);
    int size = 0;

    for (Program *counter = wantedSpace; counter != NULL; counter= counter->getNextProgram()) {
        if (counter->programName=="FREE")
            size++;
    }

if (memory > size)
    std::cout<<"Error, not enough memory for Program "<<name<<"."<<std::endl;

    for (Program *counter = wantedSpace; counter != NULL; counter= counter->getNextProgram()) {
        if (counter->programName =="FREE" && counter != NULL && memory > 0 && duplicateProgram == false && (memory < size)) {
            counter->programName = name;
            memory = memory - 1;
            added = true;
        }
    }

    if (added)
        std::cout<<"Program "<<name<<" successfully added, "<<copy<<" pages used."<<std::endl;
    else {
        std::cout<<name<<" cannot be added."<<std::endl;
    }
}

    //"kills" program by finding all pages with specific name then replacing the names of those pages with the name "FREE", will also retrun how many pages were replaced.
void KillProgram(std::string name) {
    bool programFound = false;
    int numberOfPrograms = 0;
        for (Program *counter = firstProgram; counter != NULL; counter= counter->getNextProgram()) {
        if (counter->programName == name) {
            programFound = true;
            numberOfPrograms++;
            counter->programName = "FREE";
        }
    }
    if (programFound)
        std::cout<<"Program "<<name<<" successfully killed, "<<numberOfPrograms<<" successfully reclaimed."<<std::endl;
    else
    std::cout<<"Error: Program not found."<<std::endl;
    }
//prints out the amount of free sections of the linked list.
void Fragmentation() {
    int fragmentationCount = 0;
        std::string pageName;
    for (Program *counter = firstProgram; counter != NULL; counter = counter->getNextProgram()) {

        if (counter->programName == "FREE" && pageName != "FREE") {
            fragmentationCount++;
            pageName = "FREE";
        }

        if (counter->programName != pageName)
            pageName = counter->programName;

        if (counter->getNextProgram() != NULL)
            counter = counter->getNextProgram();
    }

    std::cout << "There are "<<fragmentationCount<<" fragment(s)."<<std::endl;
}
//prints linked list in fomratted manner.
void PrintMemory(ProgramList programList) {
int index = 0;
           for (Program *counter = firstProgram; counter != NULL; counter= counter->getNextProgram()) {
               std::cout<<std::setw(8)<<counter->programName<<"  ";
                index++;
               if (index == 8) {
                   std::cout<<"\n";
                   index = 0;
               }
        }
    }
 };
#endif
