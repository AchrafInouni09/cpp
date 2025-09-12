#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
    private : 
        std::string _target;


    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm (const PresidentialPardonForm & other);
        PresidentialPardonForm & operator= ( PresidentialPardonForm & other);
        void execute (const Bureaucrat &b) const;
        virtual ~PresidentialPardonForm() ;

};

    std::ostream & operator<< (std::ostream &os, const PresidentialPardonForm &robot);

#endif