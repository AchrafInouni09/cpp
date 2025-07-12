#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include "Bureaucrat.h"

// class Bureaucrat;


class AForm
{
    public : 
     class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException();
            GradeTooLowException (std::string msg);
            virtual const char *what() const throw ();
            virtual ~GradeTooLowException()  throw ();
        private :
            std::string _msg;
    };

    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException ();
            GradeTooHighException (std::string msg);
            virtual const char *what() const throw ();
            virtual ~GradeTooHighException()  throw ();
        private :
            std::string _msg;
    };

    class UnsignedForm : public std::exception
    {
        public :
            UnsignedForm();
            UnsignedForm(std::string msg);
            virtual const char *what () const throw ();
            virtual ~UnsignedForm() throw ();
        private :
            std::string _msg;
    };

    private : 

    const std::string   _name;
    bool                _IsSigned;
    const   int         _grade_for_signing;
    const   int         _grade_for_execute;

    public :

    AForm(const std::string name, const int  sign_grade, const int execute_grade);
    ~AForm();

    const std::string &GetName() const;
    bool Get_Signed_Status() const ;
    int Get_grade_for_signing() const ;
    int Get_grade_for_execute() const;
    void   beSigned(Bureaucrat &b)  throw (GradeTooLowException);
    virtual  void execute(Bureaucrat const & executor) const = 0;
};


#endif