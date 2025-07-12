#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include <fstream>


class ShrubberyCreationForm : public AForm
{

    private:

        std::string _target;
        bool Write_Ascii_tree() const;

    public : 

        ShrubberyCreationForm (std::string target);
        ShrubberyCreationForm (const ShrubberyCreationForm &frm);
        ShrubberyCreationForm & operator= (const ShrubberyCreationForm &other);
        friend std::ostream &operator << (std::ostream &os, const ShrubberyCreationForm &frm);
        
        void execute (const Bureaucrat &b) const;
        virtual ~ShrubberyCreationForm()  ;

};


#endif