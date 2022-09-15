//
// Author: Robert Maldonado
// Collaborators: None
// Date: 10/20/2020
// Assignment Number: 4
// CS 2308 Fall 2020
//
// Driver to test the Question class.
#include<iostream>
#include<fstream>
#include<string>
#include "Question.h"
using namespace std;

//***********************************************************
// storeValue
//
// Perams: Question Array[] and counter for array
// returns: takes input from file, and feeds it into the class Question array.
//***********************************************************
void storeValue(Question q[], int &counter){
  //Temp variables
  string question;
  string answers[4];
  char key;
  string spacer;
  ifstream qfile;
  qfile.open("questions.txt");

  while(!qfile.eof()){
      getline(qfile,question);
      for(int i = 0; i < 4; i++){
        getline(qfile,answers[i]);
      }
      qfile >> key;
      getline(qfile,spacer);
      q[counter].setStem(question);
      q[counter].setAnswers(answers);
      q[counter].setKey(key);
      counter++;
  }
  qfile.close();
}

//Main function for project, displays all of the project
int main() {
    Question q[6];
    int counter = 0;
    storeValue(q,counter);
    char userin[5];
    int userscore = 0;

    for(int i = 0; i < 5;i++){
      q[i].swapAnswers(0,1);
      q[i].swapAnswers(2,3);
    }
    for(int i = 0; i < 5; i++){
      cout << i+1 <<". " << q[i].ask();
      cout << "Your answer (enter the letter): ";
      cin >> userin[i];
      cout << endl;
    }

    cout << "Answers: " << endl;
    for(int i = 0; i < 5; i++){
      cout << q[i].getKey() << " ";
    }
    cout << endl << endl;
    if(userin[0] == 'A' || userin[0] == 'a')
    {
      userscore++;
    }
    if(userin[1] == 'D' || userin[1] == 'd'){
      userscore++;
    }
    if(userin[2] == 'C' || userin[2] == 'c'){
      userscore++;
    }
    if(userin[3] == 'A' || userin[3] == 'a'){
      userscore++;
    }
    if(userin[4] == 'A' || userin[4] == 'a'){
      userscore++;
    }
    cout << "Your score out of 5: " << userscore << endl;

    return 0;
}
