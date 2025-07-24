#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <iostream>
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Form.h"
#include <cctype>


class Intern
{
    public : 

        Form *makeForm(std::string form, std::string target) ;
        
    private :
        Form * _Create_Shrubery_Form(std::string target);
        Form * _Create_Robotomy_Form(std::string target);
        Form * _Create_Presidential_Form(std::string target);
        
};

#endif