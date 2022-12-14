// File Name: QuestionTester.cpp
//// Author: Jill Seaman
// Collaborators: None
// Date: 10/10/2020
// Assignment Number:4
// CS 2308.255 & CS 5301 Fall 2020
//// Driver to test the Question class.
#include <iostream>
#include <iomanip>
using namespace std;
#include "Question.h"
int main(){
  Question q1;
  q1.setStem("What name is given to half of a Byte (4 bits)?");
  string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"};
  q1.setAnswers(q1Answers);
  q1.setKey('A');
  cout<< "q1 stem: " << q1.getStem() << endl;
  cout<< "q1 first answer: " << q1.getAnswer(0) << endl;
  cout<< "q1 last answer: " << q1.getAnswer(3) << endl;
  cout <<"q1 correct answer: " << q1.getKey() << endl;
  cout << endl;
  string q2Answers [] = {"China","India","Mexico","Australia"};
  Question q2("Which country is home to the Kangaroo?",q2Answers,'D');
  cout << q2.ask() << endl;
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(0,1);    cout << q2.ask() << endl;
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(2,3);    cout << q2.ask() << endl;
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(35,209);    cout << q2.ask() << endl;
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(1,1);    cout << q2.ask() << endl;
  cout << "correct answer: " << q2.getKey() << endl;
}/* Expected output:
q1 stem: What name is given to half of a Byte (4 bits)?
    q1 first answer: Nibble
    q1 last answer: Snippet
    q1 correct answer: A
Which country is home to the Kangaroo?
A. China
    B. India
    C. Mexico
D. Australia
correct answer: D
Which country is home to the Kangaroo?
A. India
B. China
C. Mexico
    D. Australia
correct answer: D
    Which country is home to the Kangaroo?
A. India
B. China
C. Australia
D. Mexico
correct answer: C
    Which country is home to the Kangaroo?
A. India
B. Mexico
C. Australia
D. China
correct answer: C
Which country is home to the Kangaroo?
A. India
B. Mexico
C. Australia
D. China
correct answer: C */
