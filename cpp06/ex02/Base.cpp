#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"


Base::~Base() {}

Base * Base::generate(void)
{
    short n = (std::rand() % 3) + 1;
    std::cout << n << std::endl;

    switch (n)
    {
        case 1:
            return (new A);
            break;
        case 2:
            return (new B);
            break;
        case 3:
            return (new C);
            break;
    }


    return (new Base);
}

void Base::identify(Base* p)
{
    A *a = dynamic_cast <A*> (p);

    if (a != NULL)
        std::cout << "yes it is A\n";

    B *b = dynamic_cast <B*> (p);

    if (b != NULL)
        std::cout << "it's :  B\n";

    C *c = dynamic_cast <C*> (p);

    if (c != NULL)
        std::cout << "it's :  C\n";
}

void   Base::identify(Base& p)
{
    A *a = dynamic_cast <A*> (&p);

    if (a != NULL)
        std::cout << "yes it is A\n";

    B *b = dynamic_cast <B*> (&p);

    if (b != NULL)
        std::cout << "it's :  B\n";

    C *c = dynamic_cast <C*> (&p);

    if (c != NULL)
        std::cout << "it's :  C\n";
}