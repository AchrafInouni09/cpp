#include "Base.h"




// srand(time(0));



int main()
{
    std::srand(std::time(NULL));
    Base *b = Base::generate();


    Base::identify(*b);

    delete b;
    return (0);
}