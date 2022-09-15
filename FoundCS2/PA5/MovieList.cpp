//
// Author: Robert Maldonado
// Collaborators: None
// Date: 11/05/2020
// Assignment Number: 5
// CS 2308 Fall 2020
//
//This file writes all of the function definitions that MovieList.h declares.
#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#include "MovieList.h"

//***********************************************************
// Empty List Function
//
// No Perams
// Returns :Creates empty list
//***********************************************************
MovieList::MovieList(){

  top = nullptr;

}

//***********************************************************
// MovieList Constructor
//
//None
// Returns : takes all input, and puts it into class variables.
//***********************************************************
MovieList::~MovieList(){

  MovieNode *p;
    while (!(top==nullptr)) {
        // delete the first node
        p = top;
        top = top->next;
        delete p;
    }
}

//***********************************************************
// Display Func
//
//ostream
// Returns : Displays all of the values in the linked list
//***********************************************************
void MovieList::display(ostream& out){

  MovieNode *p = top;
  int counter = 0;
    while (p!=nullptr) {
        out << counter << ": " << p->title << endl;
        p = p->next;
        counter++;
    }

}

//***********************************************************
// addtoTop Func
//
//string peram
// Returns : Adds the given titles to the top of the linked list.
//***********************************************************
void MovieList::addToTop(string title){
  MovieNode *newNode;
  newNode = new MovieNode(title,nullptr);

  if(top==nullptr){
      top = newNode;
  }
  else{
    newNode->next = top;
    top = newNode;
  }

}

//***********************************************************
// movetoBottom Func
//
//string peram
// Returns : moves the given titles to the bottom of the list
//***********************************************************
void MovieList::addToBottom(string title){
  MovieNode *newNode;
  newNode = new MovieNode(title,nullptr);

    if (top==nullptr)
        top = newNode;

    else {
        MovieNode *p = top;
        while (p->next!=nullptr) {
            p = p->next;
        }
        // now p points to the last node
        p->next = newNode;
    }

}

//***********************************************************
// Remove Func
//
//string peram
// Returns : Removes a title from the linked list
//***********************************************************
bool MovieList::remove(string title){
  MovieNode *p = top;
  MovieNode *n = top;

  while(p!=nullptr){
    if(top->title == title){
      top = top->next;
      delete p;
      return 1;
    }
    if(p->title==title)
    {
      n->next = p->next;
      delete p;
      p = p->next;
      return 1;
    }else{
      n = p;
      p = p->next;
    }
  }
  return 0;
}

//***********************************************************
// movetoPosition Func
//
//string and int peram
// Returns : Moves the chosen node to the desired position
//***********************************************************
bool MovieList::moveToPosition(string title, int position){
   MovieNode *p = top;
   MovieNode *n = nullptr;

   int counter = 0;
   while(p->next !=nullptr){
       if(p->title == title){
         top = top->next;
         delete p;
         p = top;
         counter++;
       }
       else if(counter == position){
         n = p;
         p = p->next;
         MovieNode *newNode;
         newNode = new MovieNode(title,nullptr);
         n->next = newNode;
         newNode->next = p;

         return true;
       }else{
         n = p;
         p = p->next;
         counter++;
      }
   }
   return false;
}

//***********************************************************
// movetoTop Func
//
//string peram
// Returns : Moves the desired node to the top of the list.
//***********************************************************
bool MovieList::moveToTop(string title){
    MovieNode *p = top;
    MovieNode *c = top;
    while(c->next !=nullptr){
        if(c->title == title){
            //Found the item
            p->next = c->next;
            c->next = top;
            top = c;
            return true;
        }
        p = c;
        c = c->next;
    }
    return false;
}

//***********************************************************
// nextLarger Func
//
//string Peram
// Returns : Returns the string that is next in alphabetical order.
//***********************************************************
string MovieList::nextLarger(string title){
  MovieNode *p = top;
  while(p->next !=nullptr){
      if(p->title.compare(title) == 1){
        return p->title;
      }
      p = p->next;
  }
  return "";
}

//***********************************************************
// Display Sorted Func
//
//ostream
// Returns : Displays all of the values in sorted order of the linked list.
//***********************************************************
void MovieList::displaySorted(ostream& out){
  MovieNode *p = top;
  int counter = 0;



  cout << endl;
    while (p!=nullptr) {
        out << counter << ": " << p->title << endl;
        p = p->next;
        counter++;
    }
    cout << endl;

}
