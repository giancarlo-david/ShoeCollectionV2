#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include "shoe.h"

using namespace std;

// Function prototypes
void createNewCollection(vector<shoe> &shoeList, int &numberOfShoes);
void importCollection(vector<shoe> &shoeList, int &numberOfShoes);
bool compareTwoShoes(shoe a, shoe b);
void sortList(vector<shoe> &list);
int errorCatcherInt(int &x);
void shoeCheck(string &x, string &y, string &z);
void printList(vector<shoe> shoeList, int numberOfShoes);
void outputList(vector<shoe> shoeList, int numberOfShoes);
void addShoe(vector<shoe> &shoeList, int &numberOfShoes);
void removeShoe(vector<shoe> &shoeList, int &numberOfShoes);

// Main function containing the main menu for user to select options
int main()
{
   /* Variable intializations for exitBool (flags if user wants to exit program) and menuChoice (holds user menu choice)
   shoeList holds the list of shoes in the form of a vector
   numberOfShoes holds the number of shoes the user wants to add
   */
   bool exitBool = false;
   int menuChoice;
   vector<shoe> shoeList;
   int numberOfShoes = 0;

   do
   {
      cout << "\tMain Menu" << endl;
      cout << "1) Create new collection\n2) Import an existing collection\n3) Exit\n\n";
      cout << "Enter the number option you would like to choose: ";
      cin >> menuChoice;

      // Switch statement to go to designated menuChoice
      switch (menuChoice)
      {
      case 1:
         createNewCollection(shoeList, numberOfShoes);
         break;
      case 2:
         importCollection(shoeList, numberOfShoes);
         break;
      case 3:
         exitBool = true;
         break;
      }

      // If statement to go on to the editing menu when there is a list that is already held by the program
      if (numberOfShoes > 0)
         break;

   } while (exitBool == false);

   // If statement to exit the program should the user want to exit from the main menu
   if (exitBool == true)
   {
      system("pause");
      exit(0);
   }

   // Editing menu for the user to access once the program contains a list of shoes
   do
   {
      cout << "\n\tEditing Menu" << endl;
      cout << "1) Add Shoe\n2) Remove Shoe\n3) Show Collection\n4) Save Collection\n5) Exit\n\n";
      cout << "Enter the number option you would like to choose: ";
      cin >> menuChoice;

      // Switch menu that calls a function based on user choice
      switch (menuChoice)
      {
      case 1:
         addShoe(shoeList, numberOfShoes);
         break;
      case 2:
         removeShoe(shoeList, numberOfShoes);
         break;
      case 3:
         printList(shoeList, numberOfShoes);
         break;
      case 4:
         outputList(shoeList, numberOfShoes);
         break;
      case 5:
         exitBool = true;
         break;
      }
   } while (exitBool == false);


   system("pause");
   exit(0);
   return 0;
}

// Function to add shoes when a collection has either been created or imported into the program
void addShoe(vector<shoe> &shoeList, int &numberOfShoes)
{
   // Gets user input of how many shoes they want to add
   int shoesToAdd;
   cout << "\nHow many shoes would you like to add?: ";
   cin >> shoesToAdd;
   errorCatcherInt(shoesToAdd);

   // For loop to add the shoes, repeats until number of shoes user wants to add is met
   for (int i = 0; i < shoesToAdd; i++)
   {
      /* Variables to hold various items
      tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
      tempShoe holds the current shoe to make it easier to add to the shoeList vector
       */
      string tempBrand, tempModel, tempColor;
      shoe tempShoe;

      // Prompts user to enter the details of the shoe
      cout << "Enter the brand of shoe #" << i + 1 << ": ";
      cin.ignore();
      getline(cin, tempBrand);
      cout << "Enter the model of shoe #" << i + 1 << ": ";
      getline(cin, tempModel);
      cout << "Enter the colorway of shoe #" << i + 1 << ": ";
      getline(cin, tempColor);

      shoeCheck(tempBrand, tempModel, tempColor);

      // Sets the properties for the temporary shoe and then adds it to the vector, then updates the count of the number of shoes
      tempShoe.setBrand(tempBrand);
      tempShoe.setModel(tempModel);
      tempShoe.setColor(tempColor);

      shoeList.push_back(tempShoe);
      numberOfShoes++;
   }

   sortList(shoeList);

   cout << "Finished adding shoes\n";
}

// Function to remove shoes when a list has been created or imported
void removeShoe(vector<shoe> &shoeList, int &numberOfShoes)
{
   // Variables declared to keep track of the number of shoes to remove and the index of each shoe that the user wants to remove
   int shoesToRemove;
   int shoeIndex;

   // Prompts the user to enter how many shoes they would like to remove
   cout << "\nHow many shoes would you like to remove?: ";
   cin >> shoesToRemove;

   errorCatcherInt(shoesToRemove);

   // For loop that iterates until it reaches the number of shoes the user wanted to remove
   for (int i = 0; i < shoesToRemove; i++)
   {
      int shoeNumber;
      cout << "Enter the number of the shoe you want to remove: ";
      cin >> shoeNumber;

      errorCatcherInt(shoeNumber);

      // Sets shoeIndex to the index of the shoe the user wants to remove, places that shoe at the end of the vector, then deletes that shoe off the vector
      shoeIndex = shoeNumber - 1;
      shoeList[shoeIndex] = shoeList.back();
      shoeList.pop_back();
      numberOfShoes--;
   }


   sortList(shoeList);
   cout << "Finished removing shoes\n";
}

// Function to create a new collection from scratch
void createNewCollection(vector<shoe> &shoeList, int &numberOfShoes)
{
   /* Variables to hold various items
   tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
   tempShoe holds the current shoe to make it easier to add to the shoeList vector
   */
   string tempBrand, tempModel, tempColor;
   shoe tempShoe;

   // Gets user input to how many shoes they want to add and checks to see if the number is correct
   cout << "\nEnter the number of shoes you would like to add: ";
   cin >> numberOfShoes;
   errorCatcherInt(numberOfShoes);

   // For loop to get user input on the details of each shoe, looping until it reaches the number of shoes wanted
   //  and adds each shoe to the shoeList vector 
   for (int i = 0; i < numberOfShoes; i++)
   {
      // Prompts the user to enter the properties of the shoe they are currently adding
      cout << "Enter the brand of shoe #" << i + 1 << ": ";
      cin.ignore();
      getline(cin, tempBrand);
      cout << "Enter the model of shoe #" << i + 1 << ": ";
      getline(cin, tempModel);
      cout << "Enter the colorway of shoe #" << i + 1 << ": ";
      getline(cin, tempColor);

      shoeCheck(tempBrand, tempModel, tempColor);

      // Sets the properties of the temporary shoe based on user input then places the temporary shoe at the end of the vector
      tempShoe.setBrand(tempBrand);
      tempShoe.setModel(tempModel);
      tempShoe.setColor(tempColor);

      shoeList.push_back(tempShoe);
   }

   sortList(shoeList);

   printList(shoeList, numberOfShoes);
}

// Function to make sure that the user entered the right number
int errorCatcherInt(int &x)
{

   char yn;
   // Do while loop that checks if the user meant to enter the number, if not then they can enter the number that they want to
   // Repeats until the user declares that the right number has been entered. 
   do
   {
      cout << "\nIs " << x << " the correct number? (Y/N): ";
      cin >> yn;

      if (yn == 'y' || yn == 'Y')
         break;

      else if (yn == 'n' || yn == 'N')
      {
         cout << "Please enter the correct number: ";
         cin >> x;
      }

      else
      {
         cout << "Enter either Y or N";
      }
   } while (yn != 'y' || yn != 'Y');

   return x;
}

// Function to check with user if the properties they entered are correct, if not the user re-enters the information
// Repeats until user is satisfied with the shoe they are entering
void shoeCheck(string &x, string &y, string &z)
{
   char yn;
   do
   {
      cout << "\nIs " << x << " " << y << " " << z << " correct (Y/N): ";
      cin >> yn;
      cout << endl;

      if (yn == 'y' || yn == 'Y')
         break;

      else if (yn == 'n' || yn == 'N')
      {
         cout << "Please enter the correct brand: ";
         cin >> x;
         cout << "Please enter the correct model: ";
         cin >> y;
         cout << "Please enter the correct colorway: ";
         cin >> z;
      }

      else
      {
         cout << "Enter either Y or N";
      }
   } while (yn != 'y' || yn != 'Y');
}

// Function that imports a collection that was previously made and saved via txt file
void importCollection(vector<shoe> &shoeList, int &numberOfShoes)
{
   string fileName, fileNameHolder;
   ifstream inputFile;

   // Prompts the user to enter the name of the file that they are trying to access
   cout << "What is the name of your saved collection? (Exclude .txt): ";
   cin.ignore();
   getline(cin, fileNameHolder);
   fileName = fileNameHolder + ".txt";

   // Try statement that checks to see if the file that the user is trying to open exists
   // If it does then it imports all the shoes that are saved within that file ore else it throws an exception
   try
   {
      cout << "Loading collection..." << endl;
      inputFile.open(fileName);

      if (inputFile.is_open())
      {
         /* Variables to hold various items
         tempBrand, tempModel, tempColor all hold the current shoe's brand, model, and color respectively
         tempShoe holds the current shoe to make it easier to add to the shoeList vector
         */
         string tempBrand, tempModel, tempColor;
         shoe tempShoe;

         while (!inputFile.eof())
         {
            string ignored;
            getline(inputFile, tempBrand, '|');
            tempShoe.setBrand(tempBrand);

            getline(inputFile, tempModel, '|');
            tempShoe.setModel(tempModel);

            getline(inputFile, tempColor, '|');
            tempShoe.setColor(tempColor);

            // Honestly not sure why I have to do this, but without it the import takes the shoes in wrong
            getline(inputFile, ignored, '\n');

            shoeList.push_back(tempShoe);
            numberOfShoes++;
         }

         printList(shoeList, numberOfShoes);
      }
      else
         throw 1;
   }

   // Catches the exception letting the user know the file they are trying to access was not found, then returns to main menu
   catch (int x)
   {
      cout << "File not found! Returning to main menu" << endl << endl;
   }
}

// Function to print out the current collection being held by the program
void printList(vector<shoe> shoeList, int numberOfShoes)
{
   cout << "\nHere is your current collection" << endl;

   for (int i = 0; i < numberOfShoes; i++)
   {
      cout << i + 1 << ") " << shoeList[i].getBrand() << " " << shoeList[i].getModel() << " " << shoeList[i].getColor() << endl;
   }
   cout << endl;
}

// Function to save the current collection being held into a txt file named by the user
// Each property is separated by the character '|' to make importing easier
void outputList(vector<shoe> shoeList, int numberOfShoes)
{
   ofstream outputFile;
   string fileNameHolder;
   string fileName;

   cout << "\nWhat would you like to name your collection? (Exclude .txt): ";
   cin.ignore();
   getline(cin, fileNameHolder);

   fileName = fileNameHolder + ".txt";

   outputFile.open(fileName);
   {
      for (int i = 0; i < numberOfShoes; i++)
      {
         outputFile << shoeList[i].getBrand() << "|" << shoeList[i].getModel() << "|" << shoeList[i].getColor() << "|" << endl;
      }
   }
   outputFile.close();
}

// Boolean function that acts as the key on how the shoe list is sorted
bool compareTwoShoes(shoe a, shoe b)
{
   if (a.getBrand() != b.getBrand())
      return a.getBrand() < b.getBrand();

   if (a.getModel() != b.getModel())
      return a.getModel() < b.getModel();

   return a.getColor() < b.getColor();
}

// Function that sorts the current list
void sortList(vector<shoe> &list)
{
   sort(list.begin(), list.end(), compareTwoShoes);
}
