#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.h"

class PresidentialPardonForm : public Form
{
    private : 
        std::string _target;


    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm (const PresidentialPardonForm & other);
        PresidentialPardonForm & operator= ( PresidentialPardonForm & other);
        friend std::ostream & operator<< (std::ostream &os, const PresidentialPardonForm &robot);
        virtual void execute (const Bureaucrat &b) const;
        virtual ~PresidentialPardonForm() ;

};

#endif