#include <iostream>

using namespace std;

#include "Harl.h"



class A
{
    public:
        string name = "name: Achraf";
    private:
        string Lastname = "LastName: Inouni";
    protected:
        int age = 20;
};

class B : protected A
{
    public:

        void Show()
        {
            cout << name << endl;
            // cout << Lastname << endl;
            cout << "Age: " << age << endl;
        }
};

int main( void )
{
    Harl harl;

    harl.complain("DEBUG");

    return (0);
}