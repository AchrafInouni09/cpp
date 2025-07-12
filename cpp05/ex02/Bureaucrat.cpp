#include "Bureaucrat.h"
#include "AForm.h"
#include "../ex01/Form.h"

Bureaucrat::Bureaucrat (const std::string &name, int grade) : 
_name (name), _grade(grade)
{
    // std::cout << "i'm in construction \n";
    if (_grade < 1) throw (Bureaucrat::GradeTooHighException());

    if (_grade > 150) throw (Bureaucrat::GradeTooLowException());
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

Bureaucrat::~Bureaucrat()  throw () {/*std::cout << "Destruction called\n";*/}

int     Bureaucrat::get_grade() const throw()
{
    return (_grade);
}
const std::string Bureaucrat::get_name() const throw ()
{
    return (_name);
}

void    Bureaucrat::Increment()  throw (Bureaucrat::GradeTooHighException)
{
    if (_grade  <= 1) throw (Bureaucrat::GradeTooHighException());   
    --_grade;
}
void    Bureaucrat::Decrement()  throw (Bureaucrat::GradeTooLowException)
{
    if (_grade  >= 150) throw (Bureaucrat::GradeTooLowException());
    ++_grade;
}

std::ostream & operator<< (std::ostream &os ,const Bureaucrat & b)
{
    // <name>, bureaucrat grade <grade>.
    os << b.get_name() << ", bureaucrat grade " << b.get_grade() << "\n";
    return (os);
}



// exceptions:

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

void     Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    if (form.Get_Signed_Status())
        std::cout << _name << " signed " << form.GetName() << std::endl;
    else
        std::cout << _name << "couldn't sign " << form.GetName() << " because  grade out of bounds\n";    
}
  
void Bureaucrat::executeForm(Form const & form) const
{
    try
    {
        form.execute(*this, "target");
        std::cout << _name <<  " executed " << form.GetName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << _name <<  " can't executed " << form.GetName() << "\n";
    }    
}
