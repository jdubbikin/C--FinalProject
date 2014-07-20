/**
 The main() function defines and loads the Rolodex object with the starting data (by adding a 
 series of Cards to it), and then accepts interactive requests that act on the Rolodex. For each 
 interactive command, main() invokes one or more member functions on the Rolodex object. For 
 example, you might implement the interactive commands as follows:
 
 list - displays the entire Rolodex. It can call Rolodex::show(...) to display the all the rolodex 
 cards.
 
 view -  displays the card at the current position in the rolodex. It can call 
 Rolodex::getCurrentCard(), then call Card::show(...) on the returned Card.
 
 flip - updates the current roledex position to the next card, and displays it. Flipping past the 
 last card wraps around to the first card. It can call Rolodex::flip() to get the next Card, then 
 call Card::show(...) on it.
 
 add - adds a new card to the rolodex. Prompts for each field value, reads them, and creates a new 
 Card object with the information, then calls Rolodex::add(...) to add the new Card to the rolodex 
 (which puts it in the correct position).
 
 remove - removes the card at the current position. It first calls Rolodex::getCurrentCard() , calls 
 Card::show(...) on the returned card to display it as part of the confirmation prompt, and if 'yes'
 is entered to remove it, it calls Rolodex::remove() to remove the Card from the rolodex.
 
 search - finds and displays a card, and makes it the current position in the rolodex. This command 
 prompts for the last name and first name for searching. If a matching card is found, it is 
 displayed and is set as the current position. It calls Rolodex::search(...) and checks the boolean 
 return value to see if a card was found.
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include "Card.h"
#include "Rolodex.h"

using namespace std;

void loadBaseRolodexData( Rolodex );
bool controlPanel( Rolodex );
void addCard( Rolodex );

// void testCard();
// template < typename T > void printList( const list< T > & listRef);
// void view( Card cardToShow );

int main(int argc, const char * argv[])
{
    Rolodex(theRolodex);
    
    //bool runAgain = true;
    
    cout << "Welcome to Rolodex " << endl << "------------------\n" << endl;
    
    loadBaseRolodexData( theRolodex );
    
    
    controlPanel( theRolodex );
    controlPanel( theRolodex );
    controlPanel( theRolodex );
    
    /*
    while (runAgain)
    {
        runAgain = false;
        runAgain = controlPanel( theRolodex );
        
    }
      */
    

    return 0;
}

void loadBaseRolodexData( Rolodex rolodexToUse)
{
    Card *theCard1 = new Card("Tony", "Hanson");
    theCard1->setFullAddress("12 E. st. NY, NY 33333");
    theCard1->setPhoneNumber("555-9999");
    theCard1->setOccupation("Writer");
    
    Card *theCard2 = new Card("Jon", "Smyth");
    theCard2->setFullAddress("CMU Computer Servises, Pittsberg, PA");
    theCard2->setPhoneNumber("555-1324");
    theCard2->setOccupation("Computer Hardware");
    
    Card *theCard3 = new Card("Alonzo", "Heard");
    theCard3->setFullAddress("123 Anyplace Ave, Malden. MA");
    theCard3->setPhoneNumber("555-5678");
    theCard3->setOccupation("Mechanic");
    
    Card *theCard4 = new Card("Jen", "Reyes");
    theCard4->setFullAddress("325 Oak Rd, Willmington MA");
    theCard4->setPhoneNumber("555-4950");
    theCard4->setOccupation("Graphic Artist");
    
    Card *theCard5 = new Card("Alen", "Lupine");
    theCard5->setFullAddress("1 Begelow Av, Lawrence MA");
    theCard5->setPhoneNumber("555-7654");
    theCard5->setOccupation("Vet");
    
    Card *theCard6 = new Card("Jewel", "Proverb");
    theCard6->setFullAddress("34 Washington St, Walthham MA");
    theCard6->setPhoneNumber("555-3333");
    theCard6->setOccupation("Landscaper");
    
    Card *theCard7 = new Card("Paul", "Revere");
    theCard7->setFullAddress("45 Commonwealth Av Boston MA");
    theCard7->setPhoneNumber("555_1776");
    theCard7->setOccupation("Radical Revolutionary");
    
    Card *theCard8 = new Card("Adolf", "Coors");
    theCard8->setFullAddress("Boston MA");
    theCard8->setPhoneNumber("555-2337");
    theCard8->setOccupation("Beer Manufacturer");
    
    Card *theCard9 = new Card("Seymore", "Papert");
    theCard9->setFullAddress("MIT");
    theCard9->setPhoneNumber("555-1111");
    theCard9->setOccupation("Lego Professor");
    
    Card *theCard10 = new Card("Fred", "Milton");
    theCard10->setFullAddress("12 Freadom Way, Nashua, NH");
    theCard10->setPhoneNumber("555-9981");
    theCard10->setOccupation("Sales");
    
    rolodexToUse.Rolodex::add( *theCard1, rolodexToUse );
    rolodexToUse.Rolodex::add( *theCard2, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard3, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard4, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard5, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard6, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard7, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard8, rolodexToUse  );
    rolodexToUse.Rolodex::add( *theCard9, rolodexToUse );
    rolodexToUse.Rolodex::add( *theCard10, rolodexToUse  );
    
}

bool controlPanel( Rolodex theRolodex)
{
    int nextTask;
    
    
    cout << "please pick a function: " << endl <<
    "add  = 1 " << endl <<
    "exit = 7 " << endl;
    
    cin >> nextTask;
    
    switch (nextTask)
    {
        case 1:
            addCard( theRolodex );
            return true;
            break;
            
        case 7:
            return false;
            break;

            
        default:
            return false;
            break;
            
    }
}

void addCard( Rolodex rolodexToUse )
{
    string tempFirst, tempLast, city, state, zip, occupation, phoneNum, address;
    
    bool addAnother = true;
    
    while (addAnother)
    {
        cout << " Enter first name" << endl;
        cin >> tempFirst;
        cout << "Enter last name" << endl;
        cin >> tempLast;
        
        Card *theCard = new Card(tempFirst, tempLast);
        
        
        
        cout << " Enter occupation" << endl;
        cin >> occupation;
        
        theCard->setOccupation(occupation);
        
        cout << " Enter phone number" << endl;
        cin >> phoneNum;
        
        theCard->setPhoneNumber(phoneNum);
        
        cout << " Enter address :" << endl;
        cin >> address;
        
        theCard->setFullAddress(address);
        
        
        rolodexToUse.Rolodex::add( *theCard, rolodexToUse  );
        /*
         string address;
         cout << "Enter Address " << endl;
         cin >> address;
         */
        
        cout << "Do you wish to add another card? enter 1 for yes and other for no.  " << endl;
        int goAgain;
        cin >> goAgain;
        
        if (goAgain != 1 )
            addAnother = false;
        
        
    }
    
}















/*

template < typename T > void printList( const list< T > & listRef)
{
    if ( listRef.empty() )
    {
        cout << "List is empty.";
    }
    else
    {
        ostream_iterator< T > output( cout, " ");
        //copy( listRef.begin(), listRef.end(), output );
    }
}
*/