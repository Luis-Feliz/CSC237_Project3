/****************************************************************/
/*   Filename:       WordCList.h                                */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/

#ifndef WORDCLIST_H
#define WORDCLIST_H
#include <iostream>
#include <string>
#include "WordList.h"

using namespace std;

class WordCList : public WordList {

public:

    //Constructor
    WordCList();

    virtual void parseIntoList(ifstream &inf);

    virtual void printIteratively();

    virtual void printRecursively();

    virtual void printPtr();



        

private:

        //variables
        //CLinkedList<WordData> TheWords[10]
};

#endif
