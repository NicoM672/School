// File Name: QuestionTester.cpp
//
// Collaborators: None
// Date: 10/10/2020




#include <iomanip>
using namespace std;
#include "Question.h"
int main()
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
  q2.swapAnswers(0,1);
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(2,3);
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(35,209);
  cout << "correct answer: " << q2.getKey() << endl;
  q2.swapAnswers(1,1);
  cout << "correct answer: " << q2.getKey() << endl;
}

    q1 first answer: Nibble
    q1 last answer: Snippet
    q1 correct answer: A


    B. India
    C. Mexico






    D. Australia

    Which country is home to the Kangaroo?





    Which country is home to the Kangaroo?










correct answer: C