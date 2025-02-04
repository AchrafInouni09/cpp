#include <iostream>

using namespace std;



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
    B b;

    b.name = "aCHARF";
    b.Show();

    return (0);
}