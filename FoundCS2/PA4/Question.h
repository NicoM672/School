//
// Author: Robert Maldonado
// Collaborators: None
// Date: 10/20/2020
// Assignment Number: 4
// CS 2308 Fall 2020
//
//This is the class file that declares all of the member funcs,
//and private variables
#include<iostream>
#include<string>
#include <string>

using namespace std;


//***********************************************************
// Class for Question.
//
// No perams
// returns: Sets up the variables and member functions for the class Questions
//***********************************************************
class Question        //new data type
{
private:
    string Stem;
    string Answers[4];
    char Key;

public:
    Question();
    Question(string,string[],char);

    string getStem();
    string getAnswer(int);
    string ask();
    char getKey();

    void swapAnswers(int a, int b);
    void setStem(string);
    void setAnswers(string []);
    void setKey(char);
};
