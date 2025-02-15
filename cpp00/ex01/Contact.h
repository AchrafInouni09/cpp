#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>


class clsContact
{
  private :
    std::string _FirstName, _LastName, _PhoneNumber,
                _NickName, _DarkestSecret;
  public :
    clsContact();
    clsContact(std::string firstName, std::string LastName,
              std::string Nickname, std::string PhoneNumber ,std::string Secret);
    short   is_correct();
    std::string GetfirstName();
    std::string GetLastName();
    std::string getnickName();
    std::string GetPhoneNb();
    std::string getDarkSecret();
};

#endif