#include "Form.h"
// #include "Bureaucrat.h"

Form::Form(const std::string name, const int  sign_grade, const int execute_grade) :
_name(name), _IsSigned(false), _grade_for_signing(sign_grade), _grade_for_execute(execute_grade)
{
    if (_grade_for_execute < 1 || _grade_for_signing < 1) throw (GradeTooHighException());

    if (_grade_for_execute > 150 || _grade_for_signing > 150) throw (GradeTooLowException());
}

std::ostream &operator<< (std::ostream &os, const Form & frm)
{
    // os << form._name << std::endl;
    os <<  "name : "  <<  frm.GetName() <<  ", signing grade : " << 
        frm.Get_grade_for_signing() << ", grade execute : " << frm.Get_grade_for_execute() 
        << ", signing status : " << frm.Get_Signed_Status()<< ".\n";
    return (os);
}

Form::Form (const Form &other) : 
_name(other._name) ,_IsSigned(other._IsSigned) , _grade_for_signing(other._grade_for_signing), _grade_for_execute(other._grade_for_execute) {}

Form & Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_IsSigned = other._IsSigned;
    }
    return (*this);
}

// const std::string GetName() const ;
//     bool Get_Signed_Status() const ;

const std::string &Form::GetName()   const        {return (_name);}
bool Form::Get_Signed_Status()    const          {return (_IsSigned);}
int Form::Get_grade_for_signing() const     {return (_grade_for_signing);}
int Form::Get_grade_for_execute() const     {return (_grade_for_execute);}


void Form::beSigned(Bureaucrat &b)  throw (GradeTooLowException)
{
    if (b.get_grade() > _grade_for_signing)
        throw (GradeTooLowException());
    _IsSigned = true;
}

Form::~Form() {}

// exceptions:

Form::GradeTooLowException::GradeTooLowException() 
{
    _msg = "Grade Too Low 1-150";
}
Form::GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}

const char *Form::GradeTooLowException::what() const throw()
{
    return (_msg.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw () {}

//

Form::GradeTooHighException::GradeTooHighException() 
{
    _msg = "Grade Too High 1-150\n";
}
Form::GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}

const char *Form::GradeTooHighException::what() const throw()
{
    return (_msg.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw () {}


// just for testing 
void Form::execute (const Bureaucrat &b, std::string _target) const
{
    if (!Get_Signed_Status())
        throw (UnsignedForm());
        
    if (b.get_grade() > Get_grade_for_execute())
        throw (GradeTooLowException());

    std::cout << _target <<" has been pardoned by Zaphod Beeblebrox" << "\n";
}

Form::UnsignedForm::UnsignedForm() :  _msg("unsigned form") {}
Form::UnsignedForm::UnsignedForm(std::string msg) : _msg(msg) {}

const char *Form::UnsignedForm::what() const throw () 
{
    return (_msg.c_str());
}

Form::UnsignedForm::~UnsignedForm() throw () {}