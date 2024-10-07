#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include "Contact.h"
#include <string.h>
#include <cstdio>
#include <iostream>
#include <iomanip>

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
            std::cin.ignore();
            std::getline(std::cin , s);
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
            std::string NickName = _ReadString("enter Nick name : ");
            std::string PhoneNumber = _ReadString("enter phone number : ");
            std::string Secret = _ReadString("enter Secret : ");
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
                std::cout << i << std::setw(12) << "|"; std::setw(12);
                _Print_N_char(Contacts[i].GetfirstName(), 8);  
                std::cout  << "|"; _Print_N_char(Contacts->GetLastName(), 8); std::setw(12);
                std::cout << "|";
                _Print_N_char(Contacts[i].getnickName(), 8); std::setw(12);
                std::cout << "\n"; // trim right;
        }
        void    _PrintfContactsRecords()
        {
            if (_ContactCount == 0)
            {
                std::cout << "no contact availaible\n";
                return;
            }
            else
            {
                for (short i = 0; i < _ContactCount; i++)
                {
                    _PrintfContactRecord(i);
                }
            }
            
        }
        void    _Print_Info(clsContact Contact)
        {
            std::cout << Contact.GetfirstName() << "\n";
            std::cout << Contact.GetLastName() << "\n";
            std::cout << Contact.getnickName() << "\n";
            std::cout << Contact.GetPhoneNb() << "\n";
            std::cout << Contact.getDarkSecret() << "\n";
        }

        int	is_int(std::string s)
        {
	        int	i;

	        i = 0;
	        while (s[i])
	        {
		        if (!((s[i] <= '9' && s[i] >= '0') || s[i] == '-' || s[i] == '+'))
			        return (0);
		        i++;
	        }
	        return (1);
        }
    
    unsigned long long	ft_atoi(const char *nptr)
    {
	    unsigned long long	result;
	    int					i;
	    int					sign;

	    i = 0;
	    result = 0;
	    sign = 1;
	    while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
		    i++;
	    if (nptr[i] == '-' || nptr[i] == '+')
	    {
		    if (nptr[i] == '-')
			sign *= -1;
		    i++;
	    }
	    while (nptr[i] >= '0' && nptr[i] <= '9')
	    {
		    result = result * 10 + (nptr[i] - 48);
		    if (result > 9223372036854775807 && sign == 1)
			    return (-1);
		    else if (result > 9223372036854775807 && sign == -1)
			    return (-1);
		    i++;
	}
	    return (result * sign);
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
                _i++;
                _PrintString("Contact Added Success\n");
            }
            else
            {
                printf("something wrong\n\n");
            }
                

        }
        void    Search()
        {          
            std::string index;

            _PrintfContactsRecords();
            if (!_ContactCount)
                return;
            std::cout << "Enter Contact Index : ";
            std::cin >> index;

            if (!is_int(index))
            {
                std::cout << "Wrong index\n";
                return;
            }
            int i = ft_atoi(&index[0]);
            if (i > 8 || i < 0 || i >= _ContactCount)
            {
                std::cout << "Wrong index\n";
                return;
            }
            _Print_Info(Contacts[i]);
        }
};

// std::string s;
// s.erase(s.find_last_not_of(" \n\r\t")+1);

#endif