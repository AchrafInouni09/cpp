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

        std::string _ReadString(std::string Message);

        void _PrintString(std::string Msg);
    
        clsContact _ReadContactInfo();

        void _Print_N_char(std::string s, int n);

        void    _PrintfContactRecord(int i);

        void    _PrintfContactsRecords();

        void    _Print_Info(clsContact Contact);

        int	is_int(std::string s);
    
        unsigned long long	ft_atoi(const char *nptr);
    public :

        clsPhoneBook();
        void   Add();
        void    Search();
};

// std::string s;
// s.erase(s.find_last_not_of(" \n\r\t")+1);

#endif