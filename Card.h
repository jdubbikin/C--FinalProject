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
    void showCard( ostream & os );
    
private:
    const string m_firstName;
    const string m_lastName;
    string m_occupation;
    string m_address;
    string m_phoneNumber;
};

#endif /* defined(__JamesWood_Project_rolodex__Card__) */
