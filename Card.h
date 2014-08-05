/** ---------------------------------------------------------------------------------------------
 * Homework:          Assignment Rolodex Project.
 * Name:              James Wood
 * Class:             intro to Java
 * Class:             90.268-061 - C++ Programming
 * Date:              07/26/2014
 * File Name:         Card.h
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
 The Card class is used to represent a single Rolodex card. This class has std::string data members 
 for First name, Last name, Occupation, Address (entire address can be in one string), and Phone 
 number.  It has get/set  member functions to allow getting and setting of the member data values 
 (e.g. first name), and a show(ostream& os) function that knows how to display the card on the 
 supplied ostream parameter.  This class does not know about Rolodex functionality, it just 
 encapsulates a single card's information.
 *
 */


#ifndef __JamesWood_Project_rolodex__Card__
#define __JamesWood_Project_rolodex__Card__

#include <iostream>
//#include <ostream>
#include <sstream>
#include <string.h>

using namespace std;


class Card
{
public:
    Card();
    Card( string firstname, string lastname );
    ~Card();
    string getFirstName();
    string getLastName();
    void setOccupation( string occupation );
    string getOccupation();
    void setFullAddress( string address );
    string getFullAddress();
    void setPhoneNumber( string number );
    string getPhoneNumber();
    ostream & showCard( ostream & os );
    
private:
    const string m_firstName;
    const string m_lastName;
    string m_occupation;
    string m_address;
    string m_phoneNumber;
};

#endif /* defined(__JamesWood_Project_rolodex__Card__) */
