//
// Created by Parth on 11/11/2017.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Custom Stack Class with all the necessary methods for setting and retreiving data.
class Stack {
int size = 0;
int maximum = 0;
std::vector <std::string> text;

public:
    void push(std::string text);
    void pop();
    int getCurrent();
        int getMaximum();
        int getSize();
    bool parenthesis = true;
    bool flash = false;
    bool ASign = false;
    bool SSign = false;
    bool MSign = false;
    bool DSign = false;
    bool increment  = false;
    bool equals = false;
    bool comma = false;
    bool semicolon = false;
    bool forLoop = false;
    bool beginWord = false;
    bool endWord = false;
    bool nestedLoop = true;
    int loopCount = 0;
    int loop = 0;
    int counter = 0;

};

//Here is where Stack methods are defined. Push simply inserts new element at top of the stack, above current top element.
void Stack::push (std::string element) {
text.push_back(element);
    size=size+1;
    if (size>maximum)
        size = maximum;

}

//Pop method removes top element and reduces stack size by 1.
void Stack::pop() {
if (text.size() > 0) {
    text.pop_back();
    maximum= maximum -1;
}

}

//Returns current stack size.
int Stack::getCurrent() {
    return size;
}

//Returns maximum stack size.
int Stack::getMaximum() {
    return maximum;
}
//Returns size of vector of strings.
int Stack::getSize() {
    return text.size();
}
//String vectors for storing important data, chose to use vectors due to easy access to elements, and ease with inserting and retreiving elements with iterator.
std::vector <std::string> constants;
std::vector <std::string> identifiers;
std::vector <std::string> fileErrors;

//Essentially checks for errors in parentheses in text file, and if there is inequality in number of beginning and ending parantheses, error is pushed back to fileErrors vector.
void verifyParentheses(std::string line, std::vector<std::string> &mistakes, bool &isParenthesis) {
    int endBracket = 0;
    int startBracket = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ')')
            endBracket++;
        if (line[i] == '(')
            startBracket++;
    }
    if (endBracket < startBracket)
        mistakes.push_back("(");
    if (endBracket > startBracket)
        mistakes.push_back(")");
       if (endBracket != startBracket)
        isParenthesis = false;
}

//Checks for Identifiers in a line of text: if text is lowercase, then text is pushed back to identifiers vector.
void verifyIdentifiers(std::string line,std::vector<std::string> &identifiers) {
    std::string storage = "";
    for (int i = 0; i < line.size(); i++) {
        if(islower(line[i])!=0)
            storage +=line[i];
        if(islower(line[i])==0){
            identifiers.push_back(storage);
            storage="";
        }
    }
    std::sort(identifiers.begin(),identifiers.end());
    identifiers.erase(unique(identifiers.begin(), identifiers.end()), identifiers.end());
}

//Checks if given word is a keyword. If so, method returns boolean value of false.
bool isError (std::string possibleError) {

    if (possibleError== "BEGIN"||possibleError== "END"||possibleError=="FOR") {
       return false;
    }
else
  return true;

}

//Method checks for constants in line of text: if any character in string is a digit, then that digit is pushed back to constants vector.
void verifyConstants(std::string line,std::vector<std::string> &constants) {
    std::string storage = "";
    for (int i = 0; i < line.size(); i++) {
        if (isdigit(line[i]) == 0) {
            constants.push_back(storage);
            storage = "";
        }
        if (isdigit(line[i]) != 0)
            storage += line[i];
        std::sort(constants.begin(), constants.end());
        constants.erase(unique(constants.begin(), constants.end()), constants.end());

    }
}

//Method checks for errors in words. If keyword isn't spelled right, then that mispelled word is pushed back to fileErrors vector.
void verifyErrors(std::vector<std::string> &mistakes,std::string line) {
    std::string storage = "";

    for (int i = 0; i < line.size(); i++) {
        if (isupper(line[i]) != 0)
            storage += line[i];

        if (isupper(line[i]) == 0){
            if (isError(storage))
                fileErrors.push_back(storage);

                storage = "";
        }
    }
    if(isError(storage))
        fileErrors.push_back(storage);


    std::sort(fileErrors.begin(), fileErrors.end());
    fileErrors.erase(unique(fileErrors.begin(), fileErrors.end()), fileErrors.end());
}

