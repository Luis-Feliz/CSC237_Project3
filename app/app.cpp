/****************************************************************/
/*   Author:         Dr. Spiegel                                */
/*   Course:         CIS237                                     */
/*   Filename:       app.cpp                                    */
/*   Purpose:        This Example inputs a string and demon-    */
/*                   strates how to store it using a subclass   */
/*                   of an abstract base class that incorporates*/
/*                   virtual functions to enable polymorphism   */
/*                   If a file name is                          */
/*                   input through the command line all of the  */
/*                   options will be done automatically for the */
/*                   first line of the file                     */
/****************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "WordList.h"
#include "WordDataList.h"
//#include "WordData.h"        //app only knows about the lists!

using namespace std;

/*********************************************************************/
/*   Function Name: displayMenu()                                    */
/*                                                                   */
/*   Description: Displays the menu on the screen.                   */
/*********************************************************************/
void displayMenu();

/*********************************************************************/
/*                                                                   */
/*   Function Name: printEverything                                  */
/*                                                                   */
/*   Description: Takes in a sentence and sends it through every     */
/*                parsing and printing function                      */
/*                                                                   */
/*   Parameters:  string sentence - sent to every function           */
/*                WordDataList TheList - The array of object         */
/*********************************************************************/
void printEverything(ifstream &inf,WordList *TheList);



int main(int argc,char *argv[])
{ ifstream inf;
  WordList *TheList;
  if(argc>1) //if there was an input on the command line
    {
      inf.open(argv[1]); //try and open the file
      if (inf.fail())       //if the file does not open
        {                    //terminate
          cout<<"Sorry, the file failed to open."<<endl;
          return 0;
        }
      // printEverything(inf, TheList);
      return 0;
    }

  char selection;
  string fileName;
  cout<<"Please enter a file name:"<<endl;
  getline(cin,fileName);
  inf.open(fileName.c_str());

  if (inf.fail())       //if the file does not open
  {                    //terminate
      cout << "Sorry, the file failed to open." << endl;
      return 0;
  }
  
  // TheList is a pointer to a WordList that is pointed at a WordList subclass
  TheList = new WordDataList;
  TheList->parseIntoList(inf);  // Apply polymorphism
  while (true)
    {
      displayMenu();
      cin>>selection;
      switch(selection)
        { case '1':
            TheList->printIteratively();
            break;
          case '2':
            TheList->printRecursively();
            break;
          case '3':
            TheList->printPtr();
            break;
          case '4':
              cout << "Test 4 - undone" << endl;
               //TheList->printCirIteratively();
              break;
          case '5':
              cout << "Test 5 - undone" << endl;
                //TheList->printCirRecursively();
              break;
          case '6':
              cout << "Test 6 - undone" << endl;
                //TheList->printSTLIteratively();
              break;
          case '7':
              cout << "Test 7 - undone" << endl;
                //TheList->printSTLRecursively();
              break;
          case '8':
            cout<<"Goodbye"<<endl;
            return 0;
          default:
            cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
            break;
        }
    }
  
  return 0;
}

void displayMenu()
{
  cout<<endl;
  cout<<"How do you want to print your sentence elements?"<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1. Object Array Iterative"<<endl;
  cout<<"2. Object Array Recursive"<<endl;
  cout<<"3. Object Array Pointer Recursive"<<endl;
  cout<<"4. Circular List Iterator"<<endl;
  cout<<"5. Circular List Recursive"<<endl;
  cout<<"6. STL __________ Iterative"<<endl;
  cout<<"7. STL __________ Recursive"<<endl;
  cout<<"8. Quit"<<endl;
}

void printEverything(ifstream &inf,WordList *TheList)
{ TheList=new WordDataList;
  TheList->parseIntoList(inf);
  TheList->printIteratively();
  TheList->printRecursively();
  TheList->printPtr();
  //TheList->printCirIteratively();
  //TheList->printCirRecursively();
  //TheList->printSTLIteratively();
  //TheList->printSTLRecursively();
}