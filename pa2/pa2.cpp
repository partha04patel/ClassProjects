#include <iostream>
#include "main.h"


int main() {
    std::cout << "Would you like the best or worst fit algorithm? Please type either 'best or 'worst'."<<std::endl;
    std::string algorithm;
        std::cin >> algorithm;
    //makes sure that algorithm type is valid.
    while ((algorithm != ("worst")) && (algorithm != ("best"))) {
        std::cout << "Invalid algorithm type, try again." << std::endl;
        std::cin >> algorithm;
    }
        std::cout << "Using " << algorithm << " fit algorithm." << std::endl;

       std::cout << "1. Add Program\n2. Kill Program\n3. Fragmentation\n4. Print Memory\n5. Exit" << std::endl;

    //initializing the linked list structure.
    ProgramList programList;
       int input;
       std::string programName;
       int programSize;
    do {
       std::cout << "Choice - ";
       std::cin >> input;

       switch (input) {
           case 1:
               std::cout<<"Program Name - ";
               std::cin>>programName;

               std::cout<<"Program Size (KB) - ";
               std::cin>>programSize;
               int neededMemory;
            //checks that program size is actually valid.
               if (programSize <= 0)
                    std::cout<<"Error: Invalid Program Size."<<std::endl;

            //calculating how many pages are needed to store program.
               if (programSize % 4 == 0)
                    neededMemory = (programSize/4);

               if (programSize % 4 != 0)
                   neededMemory = ((programSize/4) + 1);

               programList.AddProgram(programName,neededMemory, algorithm);
                break;
           case 2:
               std::cout<<"Program Name - ";
               std::cin>>programName;
               programList.KillProgram(programName);
               break;
           case 3:
               programList.Fragmentation();
               break;
           case 4:
              programList.PrintMemory(programList);
               break;
           case 5:
           std::cout<<"Exiting Program."<<std::endl;
               break;
           default:
               std::cout << "Try Again.\n";
               break;
       }
   } while (input!=5);
        //making sure input for choice is valid.
        return 0;
}
