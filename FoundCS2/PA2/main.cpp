//
// Author: Robert Maldonado
// Collaborators: None
// Date: 9/22/2020
// Assignment Number: 2
// CS 2308 Fall 2020
//
/*This program takes the data from a text file and put them into an array an displays them using functions in the program.
Also takes user in put to find specific names and id's*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//Structure for the first array we input the file from
struct Movie{
  int id;
  string name;
  string releaseDate;
  double rating;
};

//Structure for the second array for swaping the data for sortByDateRating
struct date{
  int id;
  int year;
  int month;
  int day;
  double rating;
};

//Another structure for swaping the data for sortByDateRating
struct low{
  int id;
  int year;
  int month;
  int day;
  double rating;
};

//***********************************************************
// Display Function.
//
// No perams
// returns: returns the header for table
//***********************************************************
void displayHeader(){
    cout << left
         << setw(3) << "ID"
         << setw(26) << "Name"
         << setw(12) << "Date"
         << "Rating"
         << endl;
}

//***********************************************************
// Display Function.
//
// Structure Array Peram
// returns: Returns the data set inside the array.
//***********************************************************
void displayMovie(struct Movie movie[], int SIZE){
  for (int i = 0; i < 6; i++)
  {
    cout << left
         << setw(3) << movie[i].id
         << setw(26) << movie[i].name
         << setw(12) << movie[i].releaseDate
         << movie[i].rating
         << endl;
  }
}

//***********************************************************
// Display Function.
//
// No Perams
// returns: returns the menu screen for the user.
//***********************************************************
void displayMenu(){
    cout << "\nMenu\n"
         << "1. Display movies sorted by id\n"
         << "2. Display movies sorted by release date, then rating\n"
         << "3. Lookup a release date given a name\n"
         << "4. Lookup a movie by id\n"
         << "5. Quit the Program\n"
         << "Enter your choice:\n";
}


//***********************************************************
// text File input to Array Function.
//
// Structure movies, rel, temp Perams
// Returns : Read the numbers and strings from the file and puts them into struct list movies.
//***********************************************************
void readMovies(ifstream& in, Movie movie[], int& SIZE){
  int number;
  string x, y;
  string strings[100];
  double r;
  int count = 0;

  // Open the file.


  // Read the numbers and strings from the file and
  // display them.
  while (in >> number)  //while the input of the next number succeeds
  {
      in >>  ws;       //skips newline after the number
      getline(in,y);  // reads until end of line including spaces
      movie[count].id = number;
      movie[count].name = y;
      getline(in,y);  // reads until end of line including spaces
      movie[count].releaseDate = y;
      in >> r;
      movie[count].rating = r;
      count++;
  }
 in.close();
 SIZE = count;
}


//***********************************************************
// Date & Rating sort Function.
//
// Structure movies, rel, temp Perams
// Returns : Displays the data in the text file by date in assceding order then rating.
//***********************************************************
void sortByDateRating(Movie movie[], int SIZE){
  date rel[7];
  for(int i = 0; i < 7; i++){
    stringstream geek(movie[i].releaseDate);
    int year, month, day;
    char slash;
    geek >> year >> slash >> month >> slash >> day ;
    rel[i].id = i;
    rel[i].year = year;
    rel[i].month = month;
    rel[i].day = day;
    rel[i].rating = movie[i].rating;
  }

  int count = 1;
  while(count != 0){
    for(int i = 0; i < 5;i++){
      for(int i =0; i <5;i++){
        if(rel[i+1].year < rel[i].year){
          swap(rel[i].id, rel[i+1].id);
          swap(rel[i].year, rel[i+1].year);
          swap(rel[i].month, rel[i+1].month);
          swap(rel[i].day, rel[i+1].day);
          swap(rel[i].rating, rel[i+1].rating);
        }
        else if(rel[i+1].year == rel[i].year && rel[i+1].month < rel[i].month){
          swap(rel[i].id, rel[i+1].id);
          swap(rel[i].year, rel[i+1].year);
          swap(rel[i].month, rel[i+1].month);
          swap(rel[i].day, rel[i+1].day);
          swap(rel[i].rating, rel[i+1].rating);
        }
        else if(rel[i+1].year == rel[i].year && rel[i+1].month == rel[i].month && rel[i+1].day == rel[i].day){
          if(rel[i+1].rating > rel[i].rating){
            swap(rel[i].id, rel[i+1].id);
            swap(rel[i].year, rel[i+1].year);
            swap(rel[i].month, rel[i+1].month);
            swap(rel[i].day, rel[i+1].day);
            swap(rel[i].rating, rel[i+1].rating);
          }
        }
      }
      }
      count = 0;
  }

  for (int i = 0; i < 6; i++)
  {
    int place = rel[i].id;
    cout << left
         << setw(3) << movie[place].id
         << setw(26) << movie[place].name
         << setw(12) << movie[place].releaseDate
         << movie[place].rating
         << endl;
  }

}

void sortById(Movie movie[], int SIZE){
  for(int i = 0; i < SIZE; i++)
  {
    for(int i = 0; i < SIZE; i++){
        if(movie[i+1].id < movie[i].id)
        swap(movie[i+1].id,movie[i].id);
      }
  }

  for (int i = 0; i < 6; i++)
  {
    cout << left
         << setw(3) << movie[i].id
         << setw(26) << movie[i].name
         << setw(12) << movie[i].releaseDate
         << movie[i].rating
         << endl;
  }

}

//***********************************************************
// Linear Search Function.
//
// Structure Array, string target Perams
// Returns : Uses linear search to find the name inputed by the user.
//***********************************************************
int linearSearchByName(Movie movie[], int SIZE, string targetName){
    for(int i = 0; i < SIZE; i++)
    {
      if(movie[i].name == targetName)
        return i;
    }
  return -1;
}


//***********************************************************
// Binary Search Function.
//
// Structure Array, Int size, string target Perams
// returns: Uses binary search to find the id of the movie the user inputs.
//***********************************************************
int binarySearchById(Movie movie[], int SIZE, int targetId){
  int first = 0,
      last = SIZE-1,
      middle,
      position = -1;
    while(position == -1 && first <= last) {
      middle = (first + last) / 2;
      if(movie[middle].id == targetId){
        position = middle;
      }else if(targetId < movie[middle].id){
        last = middle - 1;
      }else{
        first = middle + 1;
      }
    }
    return position;
}


//The heart of the program
int main()
{

   // Variables
   int choice;       // Menu choice
   int size=0;
   Movie movie[7];
   int num;
   ifstream inputFile;
   inputFile.open("movies.txt");
   readMovies(inputFile,movie,size);
   // Set up numeric output formatting.
   cout << fixed << setprecision(1);
   do
   {
      // Display the menu.
      displayMenu();
      cin >> choice;

      // Validate the menu selection.
      while (choice < 1 || choice > 5)
      {
         cout << "Please enter 1, 2, 3, 4, or 5:" << endl;
         cin >> choice;
      }

      // Validate and process the user's choice.
      if (choice != 5)
      {
        switch (choice)
        {
          //Displays movies in order by id number.
           case 1:
               displayHeader();
               displayMovie(movie,6);
               break;
          //Date sorting case
           case 2:
               displayHeader();
               sortByDateRating(movie,6);
               break;
          //Linear Search case.
           case 3:
           {
               cin.clear(); cin.sync();
               string targetName;
               cout << "Please enter a movie name : " << endl;
               getline(cin,targetName);
               num = linearSearchByName(movie,6,targetName);
               if(num == -1){
                 cout << "No movie found with the name : " << targetName;
               }
               else{
                 cout << "Release date of '" << movie[num].name << "' is " << movie[num].releaseDate << endl;
               }
               break;
             }

          //Binary search case.
           case 4:
           {
               int pos;
               int targetId;
               cout << "Please enter a movie id:" << endl;
               cin >> targetId;
               pos = binarySearchById(movie,6,targetId);
               if(targetId == 5){
                 cout << "No movie found with id: " << targetId << endl;
                 break;
               }
               if(pos > -1 && pos < 6)
               {
                 displayHeader();
                 cout << left
                      << setw(3) << movie[pos].id
                      << setw(26) << movie[pos].name
                      << setw(12) << movie[pos].releaseDate
                      << movie[pos].rating
                      << endl;
               }else{
                 cout << "No movie found with id: " << targetId << endl;
               }
               break;
             }
        }


      }
   } while (choice != 5);
   cout << "Exiting the program..." << endl;
   return 0;
}
