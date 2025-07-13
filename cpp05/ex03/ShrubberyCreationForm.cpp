#include "ShrubberyCreationForm.h"


ShrubberyCreationForm::ShrubberyCreationForm (std::string target) : 
Form (target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &other) : 
Form (other), _target(other._target) {}


ShrubberyCreationForm   & ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{   
    if (this != &other)
    {
       _target = other._target;
    }
    return (*this);
}

std::ostream &operator << (std::ostream &os, const ShrubberyCreationForm &frm)
{
    (void)frm;
    return os;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

bool ShrubberyCreationForm::Write_Ascii_tree() const
{
    std::ofstream file ((_target + "_shrubbery").c_str());

    if (!file.is_open())
    {
        std::cerr << "cannot open " << _target + "_shrubbery .\n";
        return (false);
    }
    
    file << "       /\\\n";
    file << "      /  \\\n";
    file << "     /++++\\\n";
    file << "    /  ()  \\\n";
    file << "    /      \\\n";
    file << "   /~`~`~`~`\\\n";
    file << "     ||||\n";
    file << "     ||||\n";
    file.close();


    return (true);
}

void ShrubberyCreationForm::execute(const Bureaucrat & b) const
{

    if (!Get_Signed_Status())
        throw (UnsignedForm());
    
    if (b.get_grade() > Get_grade_for_execute())
    {
        throw (GradeTooLowException());
    }
    Write_Ascii_tree();
}

