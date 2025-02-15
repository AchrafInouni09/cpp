#include "Contact.h"


clsContact::clsContact()
{
    std::cout << "Contact default constructor called" << std::endl;
}

clsContact::clsContact(std::string firstName, std::string LastName,
              std::string Nickname, std::string PhoneNumber ,std::string Secret) : 
    
      _FirstName(firstName),
      _LastName (LastName),
      _PhoneNumber (PhoneNumber),
      _NickName(Nickname),
      _DarkestSecret (Secret)
{
    std::cout << "Contact constructor called" << std::endl;
}

short   clsContact::is_correct()
{
    if (_FirstName == "" || _LastName == "" || _NickName == ""
        || _PhoneNumber == "" || _DarkestSecret == "")
            return  (0);
    return (1);
}

std::string clsContact::GetfirstName()
{
  return (_FirstName);
}
std::string clsContact::GetLastName()
{
  return (_LastName);
}
std::string clsContact::getnickName()
{
  return (_NickName);
}
std::string clsContact::GetPhoneNb()
{
  return (_PhoneNumber);
}
std::string clsContact::getDarkSecret()
{
  return (_DarkestSecret);
}




