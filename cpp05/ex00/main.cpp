#include <iostream>
#include "Bureaucrat.h"



using namespace std;



int main ()
{
    cout << "hello world .\n";
    // Bureaucrat emp1;

    try 
    {
        Bureaucrat emp ("Hamada", 0);
        {
            cout << emp;
        }
        Bureaucrat emp1 ("Achraf", 1);
        {
            cout << emp1;
        }

        emp = emp1;
        cout << emp;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        cout << "exception catched : " << e.what ();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        cout << "exception catched : " << e.what ();
    }
    catch (const exception &e)
    {
        cout << "system exception catched : " << e.what ();
    }
    
    // std::terminate();
    // return ( -1);
    
    return (0);
}