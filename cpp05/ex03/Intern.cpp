#include "Intern.h"


void to_upper_string (std::string &s)
{
    if (s.empty())
        return ;
    for (int i = 0; i < (int)s.length(); i++)
    {
        s[i] = std::toupper(s[i]);
    }
}


Form * Intern::_Create_Presidential_Form(std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form * Intern::_Create_Robotomy_Form(std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form * Intern::_Create_Shrubery_Form(std::string target)
{
    return (new ShrubberyCreationForm(target));
}



Form *Intern::makeForm(std::string form, std::string target) 
{
    // robotomy , Presidential Pardon , Shrubbery Creation

    std::string formNames[] = {"robotomy", "Presidential", "Shrubbery"};
    Form * (Intern::*formCreators[])(std::string) = {&Intern::_Create_Robotomy_Form, &Intern::_Create_Presidential_Form, 
                                                        &Intern::_Create_Shrubery_Form};

    to_upper_string(form);
        for (short i = 0; i < 3 ; i++)
        {
            to_upper_string(formNames[i]);
            if (form.find(formNames[i]) != std::string::npos)
            {
                std::cout << "Intern creates " << form << " form" <<  std::endl;
                return (this->*formCreators[i])(target);
            }
        }
    std::cout << "Error : cannot create " << form << std::endl;
    return (NULL);
}