#include "AForm.h"


AForm::AForm(const std::string name, const int  sign_grade, const int execute_grade) :
_name(name), _IsSigned(false), _grade_for_signing(sign_grade), _grade_for_execute(execute_grade)
{
    if (_grade_for_execute < 1 || _grade_for_signing < 1) throw (GradeTooHighException());

    if (_grade_for_execute > 150 || _grade_for_signing > 150) throw (GradeTooLowException());
}


const std::string &AForm::GetName()   const        {return (_name);}
bool AForm::Get_Signed_Status()    const          {return (_IsSigned);}
int AForm::Get_grade_for_signing() const     {return (_grade_for_signing);}
int AForm::Get_grade_for_execute() const     {return (_grade_for_execute);}


void AForm::beSigned(Bureaucrat &b)  throw (GradeTooLowException)
{
    if (b.get_grade() > _grade_for_signing)
        throw (GradeTooLowException());
    _IsSigned = true;
}



AForm::~AForm() {}

// exceptions:

AForm::GradeTooLowException::GradeTooLowException() 
{
    _msg = "Grade Too Low 1-150";
}
AForm::GradeTooLowException::GradeTooLowException(std::string msg) : _msg(msg) {}

const char *AForm::GradeTooLowException::what() const throw()
{
    return (_msg.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw () {}

//

AForm::GradeTooHighException::GradeTooHighException() 
{
    _msg = "Grade Too High 1-150\n";
}
AForm::GradeTooHighException::GradeTooHighException(std::string msg) : _msg(msg) {}

const char *AForm::GradeTooHighException::what() const throw()
{
    return (_msg.c_str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw () {}


AForm::UnsignedForm::UnsignedForm() :  _msg("unsigned form") {}
AForm::UnsignedForm::UnsignedForm(std::string msg) : _msg(msg) {}

const char *AForm::UnsignedForm::what() const throw () 
{
    return (_msg.c_str());
}

AForm::UnsignedForm::~UnsignedForm() throw () {}