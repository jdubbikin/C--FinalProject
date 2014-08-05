/** ---------------------------------------------------------------------------------------------
 * Homework:          Assignment Rolodex Project.
 * Name:              James Wood
 * Class:             intro to Java
 * Class:             90.268-061 - C++ Programming
 * Date:              07/26/2014
 * File Name:         main.cpp
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

void loadBaseRolodexData( Rolodex & );
bool controlPanel( Rolodex );
void addCard( Rolodex & );
void listCards( Rolodex );
void viewCard( Rolodex );
void flipCard( Rolodex *);
void findCard( Rolodex );
void removeCard( Rolodex &);

// void testCard();
// template < typename T > void printList( const list< T > & listRef);
// void view( Card cardToShow );

int main(int argc, const char * argv[])
{
    
    Rolodex theRolodex;
    
    bool runAgain = true;
    
    cout << "Welcome to Rolodex " << endl << "------------------\n" << endl;
    
    cout << "\n\n\t\tLoading primary Database\n" << endl;
    
    loadBaseRolodexData( theRolodex );
    
    
    while (runAgain)
    {
        runAgain = controlPanel( theRolodex );
    }
    
    
    /*
    
    cout << controlPanel( theRolodex ) << endl;
    
    cout << controlPanel( theRolodex ) << endl;
    
    cout << controlPanel( theRolodex ) << endl;
    
    cout << controlPanel( theRolodex ) << endl;
    
    cout << controlPanel( theRolodex ) << endl;
    
    cout << controlPanel( theRolodex ) << endl;
    
    cout << controlPanel( theRolodex ) << endl;
    */
    
    
    
    return 0;
}

void loadBaseRolodexData( Rolodex & rolodexToUse)
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
    
    rolodexToUse.Rolodex::add( *theCard1 );
    rolodexToUse.Rolodex::add( *theCard2 );
    rolodexToUse.Rolodex::add( *theCard3 );
    rolodexToUse.Rolodex::add( *theCard4 );
    rolodexToUse.Rolodex::add( *theCard5 );
    rolodexToUse.Rolodex::add( *theCard6 );
    rolodexToUse.Rolodex::add( *theCard7 );
    rolodexToUse.Rolodex::add( *theCard8 );
    rolodexToUse.Rolodex::add( *theCard9 );
    rolodexToUse.Rolodex::add( *theCard10 );
    
}

bool controlPanel( Rolodex theRolodex)
{
    int nextTask;
    
    bool loopAgain = true;
    
    cout << "please pick a function: " << endl <<
    "add card = 1 " << endl <<
    "list full Rolodex = 2 " << endl <<
    "view current card = 3 " << endl <<
    "flip card = 4 " << endl <<
    "find a card = 5 " << endl <<
    "remove current card = 6 " << endl <<
    "exit program = 7 " << endl;
    
    cin >> nextTask;
    
    switch (nextTask)
    {
        case 1:
            addCard( theRolodex );
            loopAgain = true;
            break;
            
        case 2:
            listCards( theRolodex );
            loopAgain = true;
            break;
            
        case 3:
            viewCard( theRolodex );
            loopAgain = true;
            break;
        
        case 4:
            flipCard( &theRolodex );
            loopAgain = true;
            break;
            
        case 5:
            findCard( theRolodex );
            loopAgain = true;
            break;
            
        case 6:
            removeCard( theRolodex );
            loopAgain = true;
            break;
            
        case 7:
            loopAgain = false;
            break;

            
        default:
            loopAgain = false;
            break;
            
    }
    return loopAgain;
}

void addCard( Rolodex & rolodexToUse )
{
    string tempFirst, tempLast, city, state, zip, occupation, phoneNum, address;
    
    
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
        
        
    rolodexToUse.Rolodex::add( *theCard );
    
}

void listCards( Rolodex thisRolodex )
{
    thisRolodex.Rolodex::show();
}

void viewCard( Rolodex thisRolodex )
{
    thisRolodex.Rolodex::getCurrentCard();
}

void flipCard( Rolodex *thisRolodex )
{
    thisRolodex->Rolodex::flip( thisRolodex );
}

void findCard( Rolodex thisRolodex )
{
    string first, last;
    cout << "Please enter Search name:";
    
    cin >> first >> last ;
    cout << endl;

    bool found = thisRolodex.searchList(first, last);
    if (found)
    {
        cout << "Found card " << endl;
    }
    else
        cout << "Could not find the card";
}

void removeCard( Rolodex &thisRolodex)
{
    cout << "Are you sure you wish to remove this card? (yes or no) " << endl;
    thisRolodex.getCurrentCard();
    
    string doIt;
    cin >> doIt;
    if (doIt == "yes" )
        thisRolodex.remove(thisRolodex);
    
}


