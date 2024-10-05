#include <iostream>
#include <cctype>

void To_Upper_Str(char *s)
{
    int i = 0;
    while (s[i])
    {   
        if (isalpha(s[i]))
            std::cout << (char)toupper(s[i]);
        else
            std::cout << s[i];
        i++;
    }
}

void    megaphone(int argc, char **argv)
{
        if (argc == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        else
        {
            int i =  1;
            while (argv[i])
            {
                To_Upper_Str(argv[i]);
                i++;
            }
        }
        std::cout << "\n";
}

int main(int argc, char  **argv)
{
    megaphone(argc, argv);
    return (0);
}