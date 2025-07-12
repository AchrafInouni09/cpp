# ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form
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

    Form (const std::string name, const int  sign_grade, const int execute_grade);
    Form (const Form &other);
    Form & operator=(const Form &other);
    ~Form();

    const std::string &GetName() const;
    bool Get_Signed_Status() const ;
    int Get_grade_for_signing() const ;
    int Get_grade_for_execute() const;
    void   beSigned(Bureaucrat &b)  throw (GradeTooLowException);
    
    //just for testing next exercice
    void execute (const Bureaucrat &b, std::string target) const;
    

    friend std::ostream &operator<< (std::ostream &os, const Form &form);
    
};


# endif