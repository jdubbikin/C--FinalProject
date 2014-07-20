//
//  Rollerdex.cpp
//  JamesWood_Project_rolodex
//
//  Created by James Wood 柯杰。 on 7/11/14.
//  Copyright (c) 2014 James Wood 柯杰。. All rights reserved.
//

#include "Rolodex.h"

/*
Rolodex::Rolodex()
{
    m_listItem = new Rolodex;
    
    
}
*/
/*
template < class TYPE >
Rolodex< TYPE >::Rolodex()
{
    list< TYPE > m_rolodex;
}
 
template < class TYPE >
Rolodex< TYPE >::~Rolodex()
{}
*/



/**
 add(Card& card) takes a Card object as a parameter (by ref is more efficient), adds it to the STL 
 container member (in the appropriate spot  so the cards are kept in alphabetical order by 
 [last name, first name]), and sets it as the 'current card' in the Rolodex by setting the STL 
 iterator member to point at the Card just added..
 *
 */

void Rolodex::add( Card ref, Rolodex rolodexToUse )
//void Rolodex < TYPE > ::add( string first, string last)
{
    list<Card>::iterator iter = rolodexToUse.m_rolodexList.begin();
    
    rolodexToUse.m_rolodexList.insert(iter, ref);
    
    //rolodexToUse.m_rolodex = m_rolodex;
    
    // m_rolodex.sort();
    
}

/**
 remove() removes the current card from the Rolodex's STL container, returns it, and makes the 
 following card the 'current' card. If the last card in the STL container is removed, the 'current' 
 card should be set to the first card in the container (i.e. wraps around).
 *
 */



/**
 getCurrentCard() returns the current Card (actually, a copy of it).
 *
 */

/*
void Rolodex::getCurrentCard()
{}
*/


/**
 flip() updates the current card position to the next Card in the Rolodex's STL container, and 
 returns that Card. If at the last card in the container, it wraps around to the first card.
 *
 */



/**
 search(const std::string& lastname, const std::string& firstname)  finds the requested card and 
 sets it as the current card and returns true indicating the search found a card.  If no exact 
 matching card is found,  the card that immediately follows the lookup name is displayed and set as 
 the current position (e.g. if "H" is entered as the last name, the first card with a last name 
 following "H" in alphabetical order is displayed) and it returns true.  If there is no following 
 card,  the current position remains unchanged and false is returned.
 */



/**
 show(ostream& os) takes an ostream as a parameter. It iterates through all the cards in the STL 
 container from beginning to end, invoking each card's show() method, and passing the ostream 
 parameter. The Rolodex show() doesn't do any actual output - it just iterates through the 
 collection and requests each card to display its contents by calling its show() member function. 
 The current card remains unchanged.
 *
 *
 */
