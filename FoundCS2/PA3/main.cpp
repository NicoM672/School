//
// Author: Robert Maldonado
// Collaborators: None
// Date: 10/5/2020
// Assignment Number: 3
// CS 2308 Fall 2020
//
/*This program implements pointers and dynamic memory allocation to
test the five functions below*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void showArray(int* array, int size);
int *duplicateArray (int *arr, int size);

//***********************************************************
// Findlast function.
//
// Perams: array,int,int
// returns: the last occurance of the target element.
//***********************************************************
int findLast(int *array, int size, int targetValue){
    int result = -1;
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) == targetValue){
            result = i;
        }
    }
    return result;
}

//***********************************************************
// Fibonacci Function.
//
// Perams: int , int
// returns: this function updates the current and next fib numbers with the
// next ones in the sequence.
//***********************************************************
void nextFibonacci(int *fibCurr, int *fibNext){
    int fibPrev = *fibNext - *fibCurr;
    *fibNext += *fibCurr;
    *fibCurr += fibPrev;
}

//***********************************************************
// Repeat Function.
//
// Perams: array,int,int
// returns: takes an array of integers, its size and a number N. Creates a
// new array that is N times bigger than an input array and fills
// the new array with values of an input array cyclically repeated N times.
//***********************************************************
int *repeat(int *array, int size, int n){
    int newSize = size * n;
    int *newArray = new int[newSize];
    int r = 0;
    for (int i = 0; i < newSize; ++i){
        newArray[i] = array[r++];
        if (r == size)
        r = 0;
    }
    return newArray;
}

//***********************************************************
// SwapEvenOdd function
//
// Perams: array,int
// returns: retuns new array thats the same length but with each element
// swapped with even or odd.
//***********************************************************
int *swapEvenOdd(int *array, int size){
    int *newArray = new int[size];
    int temp;

    if(size % 2 == 0) {
        temp = size;
    }else{
        temp = size - 1;
        newArray[size-1] = array[size -1];
    }

    for (int i = 0; i < temp; i++)
    {
        if (i % 2 == 0)
        {
            newArray[i] = array[i + 1];
        }else{
            newArray[i] = array[i - 1];
        }
    }
    return newArray;
}

//***********************************************************
// duplicateArray: creates a new array that contains the elements of the
//      array argument in the same order
// array: an array of ints
// size: the number of ints in the array
// returns a pointer to the new array.
//      If an invalid size is passed the function returns null.
// NOTE: it is the caller's responsibility to delete the returned array
//      when finished with it.
//***********************************************************
int *duplicateArray(int *arr, int size)
{
    int *newArray;
    if (size <= 0){
        return NULL;
    }

    newArray = new int[size];
    for (int index = 0; index < size; index++){
        newArray[index] = arr[index];
    }

    return newArray;
}

//***********************************************************
// SubArray Function.
//
// Perams: array,int,int
// returns: takes the start and length index from a test array, and
// copies those elements into another.
//***********************************************************
int *subArray(int *array, int start, int length){
    int *result = duplicateArray(array+start, length);
    return result;
}

int main() {
    int testArrayFindLast[6] = {1, 2, 3, 2, 1, 2};
    int targetValue = 1;

    int fib11 = 55, fib12 = 89;
    const int FIB12 = 89, FIB13 = 144;

    int testArrayRepeat[3] = {4, 5, 1};
    const int nRepeat = 4;
    int expectedArrayRepeat[3 * nRepeat] = {4, 5, 1, 4, 5, 1, 4, 5, 1, 4, 5, 1};

    int testArraySwapEvenOdd[7] = {1, 2, 7, 8, 23, 20, 3};
    int expectedArraySwapEvenOdd[7] = {2, 1, 8, 7, 20, 23, 3};

    int testArraySub[8] = {18, 19, 15, 16, 12, 11, 13, 14};
    const int arrayStartIdx = 3, arrayLength = 4;
    int expectedArraySub[4] = {16, 12, 11, 13};

    //Testing findLast//
    cout << "Testing findLast:" << endl;
    cout << "test data: ";

    for(int i = 0; i < 6;i++){
      cout << testArrayFindLast[i] << " ";
    }

    cout << endl;
    cout << "searching for value 1" << endl;
    cout << "result:   " << findLast(testArrayFindLast, 6, 1) << endl;
    cout << "expected: " << findLast(testArrayFindLast, 6, 1) << endl;
    cout << endl;

    //Testing nextFibonacci//
    cout << "Testing nextFibonacci:" << endl;
    cout << "test data: " << fib11 << " " << fib12 << endl;
    nextFibonacci(&fib11,&fib12);
    cout << "result:   " << fib11 << " " << fib12 << endl;
    cout << "expected: " << FIB12 << " " << FIB13 << endl;
    cout << endl;

    //Testing repeat//
    cout << "Testing repeat:" << endl;
    cout << "test data: ";
    showArray(testArrayRepeat,3);
    cout << "N = " << nRepeat << endl;
    int *temp = repeat(testArrayRepeat,3,4);
    cout << "result:   ";
    for(int i = 0 ; i < nRepeat * 3 ; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
    cout << "expected: ";
    showArray(expectedArrayRepeat,12);
    cout << endl;

    //Testing swapEvenOdd//
    cout << "Testing swapEvenOdd:" << endl;
    cout << "test data: ";
    showArray(testArraySwapEvenOdd,7);
    int *swapArray = swapEvenOdd(testArraySwapEvenOdd,7);
    cout << "result:   ";
    for(int i = 0; i < 7;i++){
      cout << swapArray[i] << " ";
    }
    cout << endl;
    cout << "expected: ";
    showArray(expectedArraySwapEvenOdd,7);
    cout << endl;

    //Testing swapEvenOdd//
    cout << "Testing subArray:" << endl;
    cout << "test data: ";
    showArray(testArraySub,8);
    cout << "start and length: " << arrayStartIdx << " " << arrayLength << endl;
    int *newsub = subArray(testArraySub,arrayStartIdx,arrayLength);
    cout << "result:   ";
    for(int i = 0; i < 4;i++){
      cout << newsub[i] << " ";
    }
    cout << endl;
    cout << "expected: ";
    showArray(expectedArraySub,4);


    return 0;
}


//***********************************************************
// showArray: displays the elements of an integer array in one line
//       separated by a space.
// array: an array of ints
// size: the number of ints in the array
//***********************************************************
void showArray (int *array, int size) {
    for (int i=0; i<size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
