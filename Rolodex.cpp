/** ---------------------------------------------------------------------------------------------
 * Homework:          Assignment Rolodex Project.
 * Name:              James Wood
 * Class:             intro to Java
 * Class:             90.268-061 - C++ Programming
 * Date:              07/26/2014
 * File Name:         Rolodex.cpp
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

#include "Rolodex.h"

/**
 add(Card& card) takes a Card object as a parameter (by ref is more efficient), adds it to the STL 
 container member (in the appropriate spot  so the cards are kept in alphabetical order by 
 [last name, first name]), and sets it as the 'current card' in the Rolodex by setting the STL 
 iterator member to point at the Card just added..
 *
 */
struct Rolodex::m_sort_cards
{
    bool operator()( Card& a, Card& b )
    {
        return ( a.getLastName() < b.getLastName() );
    }
};

void Rolodex::add( Card ref )
{
    list<Card>::iterator iter = m_rolodexList.begin();
    
    m_rolodexList.insert(iter, ref);
    
    m_rolodexList.sort( m_sort_cards() );
    
    m_CurrentPos = iter;
    
}

/**
 remove() removes the current card from the Rolodex's STL container, returns it, and makes the 
 following card the 'current' card. If the last card in the STL container is removed, the 'current' 
 card should be set to the first card in the container (i.e. wraps around).
 *
 */
void Rolodex::remove(Rolodex & rolodexToUse)
{
    list<Card>::iterator temp = m_CurrentPos;
    ++m_CurrentPos;
    ostringstream os;
    getCurrentCard();
    
    
}



/**
 getCurrentCard() returns the current Card (actually, a copy of it).
 *
 */


Card Rolodex::getCurrentCard()
{
    ostringstream os;
    
    m_CurrentPos->showCard(os);
    
    cout << os.str() << endl;
    
    return *m_CurrentPos;
}

/**
 flip() updates the current card position to the next Card in the Rolodex's STL container, and 
 returns that Card. If at the last card in the container, it wraps around to the first card.
 *
 */
void Rolodex::flip( Rolodex *rolodexToUse )
{
    
    
    if (rolodexToUse->m_CurrentPos == m_rolodexList.end())
    {
        rolodexToUse->m_CurrentPos = m_rolodexList.begin();
    }
    
    rolodexToUse->m_CurrentPos++;
    
    
    rolodexToUse->getCurrentCard();
}




/**
 search(const std::string& lastname, const std::string& firstname)  finds the requested card and 
 sets it as the current card and returns true indicating the search found a card.  If no exact 
 matching card is found,  the card that immediately follows the lookup name is displayed and set as 
 the current position (e.g. if "H" is entered as the last name, the first card with a last name 
 following "H" in alphabetical order is displayed) and it returns true.  If there is no following 
 card,  the current position remains unchanged and false is returned.
 
 it = find_first_of (haystack.begin(), haystack.end(),
 needle, needle+3, comp_case_insensitive);
 
 if (it!=haystack.end())
 std::cout << "The first match is: " << *it << '\n';
 
 */
bool Rolodex::searchList(const string& firstname, const string& lastname)
{
    
    list<Card>::iterator itr = m_rolodexList.begin();
    bool found = false;
    
    
    while (!found)
    {
        if (itr->getFirstName() == firstname && itr->getLastName() == lastname)
        {
            m_CurrentPos = itr;
            found = true;
            getCurrentCard();
            
            return true;
        }
        else
        {
            itr++;
            
            if (itr == m_rolodexList.end() && found == false)
            {
                m_CurrentPos = m_rolodexList.end();
                return true;
                found = true;
            }
        }
    }
    return false;
}



/**
 show(ostream& os) takes an ostream as a parameter. It iterates through all the cards in the STL 
 container from beginning to end, invoking each card's show() method, and passing the ostream 
 parameter. The Rolodex show() doesn't do any actual output - it just iterates through the 
 collection and requests each card to display its contents by calling its show() member function. 
 The current card remains unchanged.
 *
 *
 */
void Rolodex::show()
{
    ostringstream os;
    for (list<Card>::iterator itr = m_rolodexList.begin(); itr != m_rolodexList.end(); ++itr)
    {
        itr->showCard(os);
        
    }
    cout << os.str() << endl;
}
