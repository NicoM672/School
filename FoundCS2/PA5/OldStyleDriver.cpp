// File Name: TestDriver.cpp
//
// Author: Vladyslav Prokopenko
// Date: 10/26/2020
// Assignment Number: 5
// CS 2308/CS 5301 Fall 2020
// Instructor: Jill Seaman
//
// A test driver for a MovieList.
//

#include <iostream>
#include "MovieList.h"

using namespace std;

MovieList* movieQueueFromArray(const string titles[], const int SIZE){
    MovieList* movieQueue = new MovieList();
    for (int i = SIZE - 1; i >= 0; --i){
        movieQueue->addToTop(titles[i]);
    }
    return movieQueue;
}

// Worst movies ever according to https://www.imdb.com/chart/bottom
const int N_TITLES = 5;
string titles[N_TITLES] = {
        "Disaster Movie",
        "Superbabies: Baby Geniuses 2",
        "Code Name: K.O.Z.",
        "Manos: The Hands of Fate",
        "Birdemic: Shock and Terror"};
MovieList movieQueue;

int main() {

// ---------------------------------------------------------------

    cout << "Add to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Add to the bottom and to the top" << endl;
    movieQueue = MovieList();
    movieQueue.addToBottom("Manos: The Hands of Fate");
    movieQueue.addToTop("Code Name: K.O.Z.");
    movieQueue.addToBottom("Birdemic: Shock and Terror");
    movieQueue.addToTop("Superbabies: Baby Geniuses 2");
    movieQueue.addToTop("Disaster Movie");
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Remove a movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool removed = movieQueue.remove("Manos: The Hands of Fate");
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Remove the first movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    removed = movieQueue.remove("Disaster Movie");
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Try to remove a non-existing movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    removed = movieQueue.remove("Awesome Movie");
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Delete all movies (should be empty)" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    for (int i = 0; i < N_TITLES; ++i){
        movieQueue.remove(titles[i]);
    }
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Move a movie to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToTop("Code Name: K.O.Z.");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Try to move a non-existing movie to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToTop("Not even a movie");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Move a movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToPosition("Disaster Movie", 3);
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Try to move a non-existing movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToTop("NONAME");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;

// ---------------------------------------------------------------

    cout << "Test next larger: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    string nextLarger = movieQueue.nextLarger("Manos: The Hands of Fate");
    cout << "Next larger to " << "'Manos: The Hands of Fate' is " << "'" << nextLarger << "'" << endl << endl;

// ---------------------------------------------------------------

    cout << "Test next larger without next larger: ";

    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Z");
    cout << "Next larger to " << "'Z' is " << "'" << nextLarger << "'" << endl << endl;

// ---------------------------------------------------------------

    cout << "Display sorted movies" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    movieQueue.displaySorted(cout);
    cout << endl;

    return 0;
}
