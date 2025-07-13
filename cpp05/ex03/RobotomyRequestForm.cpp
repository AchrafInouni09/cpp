#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
Form (target, 72 , 45) , _target (target) { std::srand(std::time(NULL));}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
Form (other) , _target (other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator= ( RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return (*this);
}

std::ostream &operator<< (std::ostream &os, const RobotomyRequestForm &robot)
{
    (void)robot;
    return os;
}

RobotomyRequestForm::~RobotomyRequestForm () {}

void RobotomyRequestForm::execute(const Bureaucrat &b) const
{
    if (!Get_Signed_Status())
        throw (UnsignedForm());

    if (b.get_grade() > Get_grade_for_execute())
        throw (GradeTooLowException());


    std::cout << "take some noise bro vnnnnnnnn\n\n";

    int i = std::rand() % 2 + 1;

    if (i == 1)
        std::cout << _target  << " has been robotomized successfully 50\% of the time\n";
    else
        std::cout << "the robotomy failed\n";
}