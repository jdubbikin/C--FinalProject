
/** ---------------------------------------------------------------------------------------------
 * Homework:          Assignment Rolodex Project.
 * Name:              James Wood
 * Class:             intro to Java
 * Class:             90.268-061 - C++ Programming
 * Date:              07/26/2014
 * File Name:         Rolodex.h
 *
 * Discription:       This program emlates a rolodex card organizer
 *                    Card Class hold the individual card infomation
 *                    Rolodex Class holds a STL list<Card> that organizes the individual cards.
 *
 *
 * Referances:        (1) C++ How To Program eighth edition.
 *                    By: Paul Deitel, Harvey Deitel
 *                    Deitel publishing
 *                    ISBN-13: 978-0-13-266236-9
 *
 * ----------------------------------------------------------------------------------------------*/

/**
 The Rolodex class manages a collection of Card objects. It must have a data member that is an STL 
 container class to hold the set of rolodex Card objects (i.e. not a C/C++ array, but an STL Vector,
 List, etc), and an associated STL iterator object to reference the 'current' Card. The STL 
 container used must be able to handle the case of duplicate names (e.g.  two of Jim Smith, etc).  
 The Rolodex member functions just manage the STL collection of Cards, and may have parameters or 
 return values that are a Card object. The Rolodex class does not have code to read data for new 
 cards, or printing Cards. Data input is done by code in main() and Card objects are passed into 
 and out of the Rolodex object. Displaying cards is done by the Rolodex code calling the Card's
 display member function, passing an ostream for it to display on. Some of your Rolodex member 
 functions might include the following :
 *
 
 
 You create a list of Card objects. When added to the list, the Card is copied (by copy ctor), so 
 no pointers needed.
 list < Card > mCards; // container for cards
 7:21 PM
 list < Card > :: iterator mCurrentPos; // current card position
 7:22 PM
 Those would be the data members needed in Rolodex. The list container, and the iterator that 
 always references the current card.
 
 
 Yes, just a local iterator object for that function.
 for ( list < Card > :: iterator iter = mCards.begin ( ) ; iter != mCards.end ( ) ; iter++ )
 
 
 
 So inside the for loop to show the rolodex, you use the -> operator on the iterator to call the 
 Card's show function
 iter -> show ( os ) ;
 7:48 PM
 where os is the ostream parameter that was passed to Rolodex::show, and then it passes it into 
 Card::show
 
 
 
 
 The parameter type for add must be a const Card &. Thus, if you want to invoke methods on the 
 parameter Care inside add ( ), then they must be const methods
 So, functions that don't modify the object's state are best marked as const member functions.
 7:56 PM
 When passing objects as parameters, best is by const ref unless the function actually needs to 
 change the parameter object.
 
 
 
 
 The flip ( ) function needs to move the current card iteator to the next card, and wrap around 
 if it hits the end.
 So it needs to increment the iterator, then compare it to end ( ) to see if its gone off the end 
 of the list. If so, it needs to set the iterator to begin ( ) to 'wrap around' to the beginning.
 8:00 PM

 
 */

#ifndef __JamesWood_Project_rolodex__Rolodex__
#define __JamesWood_Project_rolodex__Rolodex__

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include "Card.h"

using namespace std;

class Rolodex
{
public:
    Rolodex(){};
    ~Rolodex(){};
    void add( Card );
    Card getCurrentCard();
    void remove( Rolodex &);
    void show();
    void flip( Rolodex * );
    bool searchList( const string &, const string & );
    
    
    
private:
    struct m_sort_cards;
    list< Card > m_rolodexList;
    list < Card > :: iterator m_CurrentPos;
    
    
    };

#endif /* defined(__JamesWood_Project_rolodex__Rolodex__) */

