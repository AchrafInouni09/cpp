# ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
// #include "exceptions.h"
// #include "Form.h"

class Form;

class Bureaucrat
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


    public :
        Bureaucrat (const std::string &name, int grade);
        Bureaucrat (const Bureaucrat & other);
        Bureaucrat & operator=(const Bureaucrat &other);
        int get_grade() const throw();
        const std::string get_name() const throw();
        void    Increment()  throw (GradeTooHighException);
        void    Decrement()  throw (GradeTooLowException);
        virtual ~Bureaucrat() throw();
        
        void executeForm(Form const & form) const;
        void    signForm(Form &form);
    private :
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<< (std::ostream &os, const Bureaucrat &b);


# endif