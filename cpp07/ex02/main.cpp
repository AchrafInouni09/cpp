#include "Array.h"




int main (void)
{
    Array<int> nb (5);


    
    Array<int>nb2;
    
    nb2 = nb;

        try
        {

            for (int i = 0; i < 5; i++)
            {
                nb2[i] = i + 1 * 2;
            }
                
            for (int i = 0; i < 5; i++)
            {
                std::cout << nb2[i] << std::endl;
            }
                
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }



        std::cout << "nb size : "  <<  nb2.size() << std::endl;
        

    


    
}