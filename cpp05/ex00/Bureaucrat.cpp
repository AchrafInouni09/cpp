#include "Bureaucrat.h"

Bureaucrat::Bureaucrat (const std::string &name, int grade) : 
_name (name), _grade(grade)
{
    std::cout << "i'm in construction \n";
    if (_grade < 1) throw (GradeTooHighException());

    if (_grade > 150) throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat (const Bureaucrat & other) : 
_name (other._name), _grade (other._grade) {}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()  throw () {std::cout << "Destruction called\n";}

int     Bureaucrat::get_grade() const throw()
{
    return (_grade);
}
const std::string Bureaucrat::get_name() const throw ()
{
    return (_name);
}

void    Bureaucrat::Increment()  throw (GradeTooHighException)
{
    if (_grade  <= 1) throw (GradeTooHighException());   
    --_grade;
}
void    Bureaucrat::Decrement()  throw (GradeTooLowException)
{
    if (_grade  >= 150) throw (GradeTooLowException());
    ++_grade;
}

std::ostream & operator<< (std::ostream &os ,const Bureaucrat & b)
{
    // <name>, bureaucrat grade <grade>.
    os << b.get_name() << ", bureaucrat grade " << b.get_grade() << "\n";
    return (os);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() 
{
    _msg = "Grade Too Low 1-150";
}
Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (_msg.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw () {}

//

Bureaucrat::GradeTooHighException::GradeTooHighException() 
{
    _msg = "Grade Too High 1-150\n";
}
Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (_msg.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw () {}
