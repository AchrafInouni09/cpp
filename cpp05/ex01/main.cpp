#include <iostream>
#include "Bureaucrat.h"
// #include "exceptions.h"
#include "Form.h"


using namespace std;



int main ()
{
    cout << "hello world .\n";
    try 
    {
        Form frm("Achraf", 1, 1);

        cout << frm;

        try
        {
            Bureaucrat b("Hamada",0);
            b.signForm(frm);
        }
        catch (exception &e)
        {
            std::cout << "execption  inside : " << e.what() << endl;
        }
        
        // b.Increment();

        // cout << "bureacrat grade : " << b.get_grade() << endl;

        

        cout << "signed status : " << frm.Get_Signed_Status() << "\n";
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cout << "execption : " << e.what() << endl;
    }
    catch (exception &e)
    {
        std::cout << "sys execption : " << e.what() << endl;
    }
    std::cout << "the end \n";
  
    return (0);
}