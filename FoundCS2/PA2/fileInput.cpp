// This program reads data from a file.
// The file contains a series of pairs:  a number followed by a string on
//  the next line.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    int number;
    string x, y;
    int numbers[100];
    string strings[100];
    int count = 0;

    // Open the file.
    inputFile.open("movies.txt");

    // Read the numbers and strings from the file and
    // display them.
    while (inputFile >> number)  //while the input of the next number succeeds
    {
        inputFile >>  ws;       //skips newline after the number
        getline(inputFile,y);  // reads until end of line including spaces
        cout << number << " " << y << endl;
        numbers[count] = number;
        strings[count] = y;
        count++;
    }

    //maybe add code here to output numbers and strings arrays

    // Close the file.
    inputFile.close();
    return 0;
}
