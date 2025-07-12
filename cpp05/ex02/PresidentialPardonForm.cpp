#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm (std::string target) : 
AForm (target, 25, 5),  _target (target) {}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm & other) : 
AForm (other),  _target(other._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator= ( PresidentialPardonForm & other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

std::ostream &operator<<  (std::ostream &os, PresidentialPardonForm & president)
{
    (void)president;
    return (os);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute (const Bureaucrat &b) const
{
    if (!Get_Signed_Status())
        throw (UnsignedForm());
        
    if (b.get_grade() > Get_grade_for_execute())
        throw (GradeTooLowException());

    std::cout << _target <<" has been pardoned by Zaphod Beeblebrox" << "\n";
}