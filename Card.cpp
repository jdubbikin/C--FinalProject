/** ---------------------------------------------------------------------------------------------
 * Homework:          Assignment Rolodex Project.
 * Name:              James Wood
 * Class:             intro to Java
 * Class:             90.268-061 - C++ Programming
 * Date:              07/26/2014
 * File Name:         Card.cpp
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

#include "Card.h"

Card::Card():m_firstName(), m_lastName()
{}

Card::Card( string first, string last)
:m_firstName(first), m_lastName(last)
{}

Card::~Card()
{}

string Card::getFirstName()
{
    return m_firstName;
}

string Card::getLastName()
{
    return m_lastName;
}

void Card::setOccupation(string occupation)
{
    m_occupation = occupation;
}

string Card::getOccupation()
{
    return m_occupation;
}

void Card::setFullAddress(string address)
{
    m_address = address;
}


string Card::getFullAddress()
{
    return m_address;
}


string Card::getPhoneNumber()
{
    return m_phoneNumber;
}

void Card::setPhoneNumber(string number)
{
    m_phoneNumber = number;
}

ostream & Card::showCard(ostream & os)
{
    //string temp;
    os << m_firstName << " " << m_lastName << endl <<
        m_occupation << endl <<
        m_address << endl <<
        m_phoneNumber << endl << endl;
    //temp = os.str();
    return os;
}







