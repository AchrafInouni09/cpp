#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include "Contact.h"
#include <string.h>
#include <cstdio>

class clsPhoneBook
{
    private :
        clsContact Contacts[8];
        int _ContactCount;
        int _i;

        std::string _ReadString(std::string Message)
        {
            std::string s;
            std::cout << Message << "\n";
            std::cin >> s;
            return (s);
        }

        void _PrintString(std::string Msg)
        {
            std::cout << Msg;
        }
    
        clsContact _ReadContactInfo()
        {
            std::string Firstname = _ReadString("enter first name : ");
            std::string LastName = _ReadString("enter last name : ");
            std::string NickName = _ReadString("enter Nick name : ");;
            std::string PhoneNumber = _ReadString("enter phone number : ");;
            std::string Secret = _ReadString("enter Secret : ");;
            return (clsContact(Firstname, LastName, NickName, PhoneNumber, Secret));
        }

        void _Print_N_char(std::string s, int n)
        {
            short i = 0;
            
            while (s[i] && i <= n)
            {
                std::cout << s[i];
                i++;
            }
            if (s[i] && s[i + 1])
                std::cout << ".";
            else
                std::cout << s[i];
        }

        void    _PrintfContactRecord(int i)
        {
                std::cout << i << "|" ;
                _Print_N_char(Contacts[i].GetfirstName(), 8);
                std::cout  << "|" ; _Print_N_char(Contacts->GetLastName(), 8);
                std::cout << "|";
                _Print_N_char(Contacts[i].getnickName(), 8);
                std::cout << "\n"; // trim right;
        }
        void    _PrintfContactsRecords()
        {
            if (_ContactCount == 0)
            {
                std::cout << "no contact availaible\n";
                return;
            }
            for (short i = 0; i <= _ContactCount; i++)
            {
                _PrintfContactRecord(i);
            }
        }

    public :

        clsPhoneBook()
        {
            _ContactCount = 0;
            _i = 0;
        }
        void   Add()
        {
            clsContact Contact = _ReadContactInfo();
            if (Contact.is_correct())
            {
                if (_i == 7)
                    _i = 0;
                Contacts[_i] = Contact;
                if (_ContactCount != 8)
                    _ContactCount++;
                _PrintString("Contact Added Success\n");
            }
            else
                printf("something wrong\n\n");

        }
        void    Search()
        {          
                _PrintfContactsRecords();
                //_PrintContactInfo(index);
        }
};



#endif