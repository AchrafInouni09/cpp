#include "PhoneBook.h"

clsPhoneBook::clsPhoneBook()
{
    _ContactCount = 0;
    _i = 0;
}

void   clsPhoneBook::Add()
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

void    clsPhoneBook::Search()
{          
    std::string index;

    std::cout << std::setw(10) << "index" << "|"
                  << std::setw(10) << "first name" << "|"
                  << std::setw(10) << "last name" << "|"
                  << std::setw(10) << "nickname" << "|\n";

    _PrintfContactsRecords();
    if (!_ContactCount)
        return;
    std::cout << "\nEnter index to display: ";
    if (!std::getline(std::cin, index))
    {
        std::cout << "\nEOF detected, returning to main menu\n";
        return;
    }
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

// pv membres;

std::string clsPhoneBook::_ReadString(std::string Message)
{
    std::string s;
    std::cout << Message << "\n";
    std::cin.ignore();
    std::getline(std::cin , s);
    return (s);
}

void clsPhoneBook::_PrintString(std::string Msg)
{
    std::cout << Msg;
}
clsContact clsPhoneBook::_ReadContactInfo()
{
    std::string Firstname = _ReadString("enter first name : ");
    std::string LastName = _ReadString("enter last name : ");
    std::string NickName = _ReadString("enter Nick name : ");
    std::string PhoneNumber = _ReadString("enter phone number : ");
    std::string Secret = _ReadString("enter Secret : ");
    return (clsContact(Firstname, LastName, NickName, PhoneNumber, Secret));
}
void clsPhoneBook::_Print_N_char(std::string s, int n)
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

void    clsPhoneBook::_PrintfContactRecord(int i)
{
        std::cout << i << std::setw(12) << "|"; std::setw(12);
        _Print_N_char(Contacts[i].GetfirstName(), 8);  
        std::cout  << "|"; _Print_N_char(Contacts->GetLastName(), 8); std::setw(12);
        std::cout << "|";
        _Print_N_char(Contacts[i].getnickName(), 8); std::setw(12);
        std::cout << "\n"; // trim right;
}
std::string formatField(std::string field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void    clsPhoneBook::_PrintfContactsRecords()
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
            std::cout << std::setw(10) << i << "|"
                      << std::setw(10) << formatField(Contacts[i].GetfirstName()) << "|"
                      << std::setw(10) << formatField(Contacts[i].GetLastName()) << "|"
                      << std::setw(10) << formatField(Contacts[i].getnickName()) << "|\n";
        }
    }
}

void    clsPhoneBook::_Print_Info(clsContact Contact)
{
    std::cout << Contact.GetfirstName() << "\n";
    std::cout << Contact.GetLastName() << "\n";
    std::cout << Contact.getnickName() << "\n";
    std::cout << Contact.GetPhoneNb() << "\n";
    std::cout << Contact.getDarkSecret() << "\n";
}
int	clsPhoneBook::is_int(std::string s)
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

unsigned long long	clsPhoneBook::ft_atoi(const char *nptr)
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