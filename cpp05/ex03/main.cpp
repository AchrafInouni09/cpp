
#include <iostream>
#include "Intern.h"
#include "Form.h"
#include "PresidentialPardonForm.h"


using namespace std;



int main ()
{

    /*
        Intern someRandomIntern;
        Form* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    */

    cout << "hello world\n";

    Form frm("home", 10, 10);

    // cout << frm.GetName();

    PresidentialPardonForm pres("allo");

    frm = pres;

    cout << frm.GetName() << endl;

     Intern someRandomIntern;

    Form* rrf;

    // // (void)someRandomIntern;
    

    rrf = someRandomIntern.makeForm("shrubbery request", "Bender");

    if (!rrf)
        return 1;

    // cout << rrf->GetName();


    
    

    return (0);
}