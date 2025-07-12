#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"
#include <cstdlib>
#include <ctime>


class RobotomyRequestForm : public AForm
{
    private : 
        std::string _target;


    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm (const RobotomyRequestForm & other);
        RobotomyRequestForm & operator= ( RobotomyRequestForm & other);
        friend std::ostream & operator<< (std::ostream &os, const RobotomyRequestForm &robot);
        void execute (const Bureaucrat &b) const;
        virtual ~RobotomyRequestForm() ;

};

# endif