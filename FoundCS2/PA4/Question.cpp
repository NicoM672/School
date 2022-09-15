//
// Author: Robert Maldonado
// Collaborators: None
// Date: 10/20/2020
// Assignment Number: 4
// CS 2308 Fall 2020
//
//This file writes all of the function definitions that Question.h declares.
#include "Question.h"

//***********************************************************
// Blank Question Function
//
// No Perams
// Returns :
//***********************************************************
Question::Question(){
  Stem = " ";
  for(int i = 0; i < 4;i++){
    Answers[i] = " ";
  }
  Key = 'X';
}

//***********************************************************
// Question Constructor
//
//string question, string array of answers, char key
// Returns : takes all input, and puts it into class variables.
//***********************************************************
Question::Question(string q, string ans[],char k){
  Stem = q;
  for(int i = 0; i < 4;i++){
    Answers[i] = ans[i];
  }
  Key = k;
}

//***********************************************************
// Set stem function
//
//string question
// Returns : Directly sets the Stem to the string given.
//***********************************************************
void Question::setStem(string question){
  Stem = question;
}

//***********************************************************
// Set answers function
//
//string array[]
// Returns : Directly sets the Answers[] to the answers given.
//***********************************************************
void Question::setAnswers(string a[]){
  for(int i = 0; i < 4;i++){
    Answers[i] = a[i];
  }
}

//***********************************************************
// Set char function
//
//char key
// Returns : Directly sets the Key to the char given.
//***********************************************************
void Question::setKey(char key){
  Key = key;
}

//***********************************************************
// Swap question function
//
//int num1 & num2
// Returns : Switches the questions of the numbers given.
//***********************************************************
void Question::swapAnswers(int num1, int num2){
  int a = 0;
  int b = 1;
  int c = 2;
  int d = 3;

  string temp = " ";

  if(num1 == 0 && num2 == 1){
    temp = Answers[a];
    Answers[a] = Answers[b];
    Answers[b] = temp;
    if(Key == 'B'){
      Key = 'A';
    }
    else if(Key == 'A'){
      Key == 'B';
    }
  }
  else if(num1 == 2 && num2 == 3){
    temp = Answers[c];
    Answers[c] = Answers[d];
    Answers[d] = temp;
    if(Key == 'C'){
      Key = 'D';
    }
    else if(Key == 'D'){
      Key = 'C';
    }
  }
}

//***********************************************************
// get Answer Function
//
//int i
// Returns : outputs the answer in the array Answers[i].
//***********************************************************
string Question::getAnswer(int i){
  return Answers[i];
}

//***********************************************************
// get Stem function
//
//No perams
// Returns : returns the question stored in Stem.
//***********************************************************
string Question::getStem(){
  return Stem;
}

//***********************************************************
// get Key Function
//
//No perams
// Returns : returns the char stored in the Key variable.
//***********************************************************
char Question::getKey(){
  return Key;
}

//***********************************************************
// ask function
//
//No Perams
// Returns : Returns the an entire question on one string.
//***********************************************************
string Question::ask(){
  string temp = Stem;

  temp = temp + "\n" + "A. " + Answers[0] + "\n" + "B. " + Answers[1] + "\n" + "C. " + Answers[2] + "\n" + "D. " + Answers[3] + "\n";

  return temp;
}
