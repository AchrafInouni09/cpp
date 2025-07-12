#include "AForm.h"
#include <iostream>
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

using namespace std;



int main ()
{
    // AForm frm("dizzioh", 1, 1);

    // cout << "\nName : " <<  frm.GetName() << "\n";


    // ShrubberyCreationForm frm("Achraf");
    // Bureaucrat b ("smail", 100);


    // while (b.get_grade() <= 137)
    //     b.Decrement();

    // cout <<  "b grade after decrementing "   <<  b.get_grade() << "\n";

    // cout << "target name is " << frm.GetName() << endl;

    // try
    // {
    //     if (frm.Write_Ascii_tree(b))
    //         cout << "file writed success\n";
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    Bureaucrat b("hamada", 3);
    RobotomyRequestForm robot ("Simo");

    cout << "robot name " << robot.GetName() << endl;

    // while (b.get_grade() <= 45)
    //     b.Decrement();

    cout <<  "b grade after decrementing "   <<  b.get_grade() << "\n";

    try
    {
        robot.execute(b);
    }
    catch (exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    
    
    return (0);
}