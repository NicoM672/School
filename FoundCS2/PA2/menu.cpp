// This program displays a menu and asks the user to make a
// selection. A do-while loop repeats the program until the
// user selects item 4 from the menu.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

   // Constants for membership rates
   const double ADULT = 40.0,
                CHILD = 20.0,
                SENIOR = 30.0;

   // Variables
   int choice;       // Menu choice
   int months;       // Number of months
   double charges;   // Monthly charges

   // Set up numeric output formatting.
   cout << fixed << setprecision(2);

   do
   {
      // Display the menu.
      cout << "\n\t\tHealth Club Membership Menu\n\n"
           << "1. Standard Adult Membership\n"
           << "2. Child Membership\n"
           << "3. Senior Citizen Membership\n"
           << "4. Quit the Program\n\n"
           << "Enter your choice: ";
      cin >> choice;

      // Validate the menu selection.
      while (choice < 1 || choice > 4)
      {
         cout << "Please enter a valid menu choice: ";
         cin >> choice;
      }

      // Validate and process the user's choice.
      if (choice != 4)
      {
         // Get the number of months.
         cout << "For how many months? ";
         cin >> months;

         // Respond to the user's menu selection.
         switch (choice)
         {
            case 1:
                charges = months * ADULT;
                break;
            case 2:
                charges = months * CHILD;
                break;
            case 3:
                charges = months * SENIOR;
         }

         // Display the monthly charges.
         cout << "The total charges are $"
              << charges << endl;
      }
   } while (choice != 4);
   return 0;
}
