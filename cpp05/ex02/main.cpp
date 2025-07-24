#include "AForm.h"
#include <iostream>
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "../ex01/Form.h"

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

    try
    {
        Bureaucrat bureau ("burea", 9);

        // ShrubberyCreationForm form("home");

        Form form ("form",  10, 20);

        // bureau.signForm(form);

        cout << "status of form " << form.Get_Signed_Status() << endl;

       form.execute(bureau, "home");
    }
    catch (exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}