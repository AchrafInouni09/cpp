#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Form.h"
#include <fstream>


class ShrubberyCreationForm : public Form
{

    private:

        std::string _target;
        bool Write_Ascii_tree() const;

    public : 

        ShrubberyCreationForm (std::string target);
        ShrubberyCreationForm (const ShrubberyCreationForm &frm);
        ShrubberyCreationForm & operator= (const ShrubberyCreationForm &other);
        friend std::ostream &operator << (std::ostream &os, const ShrubberyCreationForm &frm);
        
        virtual void execute (const Bureaucrat &b) const;
        virtual ~ShrubberyCreationForm()  ;

};


#endif