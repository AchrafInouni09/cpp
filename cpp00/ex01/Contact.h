#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>


class clsContact
{
  private :
    std::string _FirstName, _LastName, _PhoneNumber,
                _NickName, _DarkestSecret;
  public :
    clsContact()
    {

    }
    clsContact(std::string firstName, std::string LastName,
              std::string Nickname, std::string PhoneNumber ,std::string Secret)
    {
      _FirstName = firstName;
      _LastName = LastName;
      _PhoneNumber = PhoneNumber;
      _NickName = Nickname;
      _DarkestSecret = Secret;
    }
    short   is_correct()
      {
          if (_FirstName == "" || _LastName == "" || _NickName == ""
              || _PhoneNumber == "" || _DarkestSecret == "")
              return  (0);
          return (1);
      }
    std::string GetfirstName()
    {
      return (_FirstName);
    }
    std::string GetLastName()
    {
      return (_LastName);
    }
    std::string getnickName()
    {
      return (_NickName);
    }
    std::string GetPhoneNb()
    {
      return (_PhoneNumber);
    }
    std::string getDarkSecret()
    {
      return (_DarkestSecret);
    }
      
};

#endif