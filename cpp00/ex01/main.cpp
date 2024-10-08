#include "PhoneBook.h"





void Program()
{   
    clsPhoneBook PhoneBook;
    std::string str = "";
    
    while (1)
    {
        std::cout << "Enter : Add, Search, Exit\n";
        std::cin >> str;

        if (str == "exit")
                return;
        else if (str == "Add")
                PhoneBook.Add();
        else if (str == "Search")
                PhoneBook.Search();
        else 
            std::cout << "wrong Command\n";
    }
}


int main()
{
    // Handle case for tmp NULL;
    Program();
    return 0;
}