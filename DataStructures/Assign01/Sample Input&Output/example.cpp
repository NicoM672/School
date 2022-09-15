#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(){
  int largest;
  int smallest;
  bool counter = true;

  while(counter == true)
  {
    int number;
    cout << "Enter a number : ";
    cin >> number;
    if(!number)
    {
      counter = false;
    }
    else
    {
      if(number < smallest || smallest == NULL)
        smallest = number;
      else if(number > largest || largest == NULL)
        largest = number;
    }
  }
  cout << "Smallest number : " << smallest << endl;
  cout << "Largest number : " << largest << endl;
}
