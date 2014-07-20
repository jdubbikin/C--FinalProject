//
//  Card.cpp
//  JamesWood_Project_rolodex
//
//  Created by James Wood 柯杰。 on 7/11/14.
//  Copyright (c) 2014 James Wood 柯杰。. All rights reserved.
//

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

void Card::showCard(ostream & os)
{
    os << m_firstName << " " << m_lastName << endl <<
        m_occupation << endl <<
        m_address << endl <<
        m_phoneNumber << endl;
}






