
#include "Serializer.h"




int main()
{


    Data *data = new Data;

    data->nb = 42;
    data->dbl = 3.0;
    data->letter = 'C';
    data->flt = 1.0f;


    uintptr_t n = Serializer::serialize(data);

    std::cout << n << std::endl;

    Data *dt = Serializer::deserialize(n);


    std::cout << dt->nb  << std::endl;
    std::cout << std::fixed << std::setprecision(3) << dt->dbl << std::endl;
    std::cout << dt->letter << std::endl;
    std::cout <<  std::fixed << std::setprecision(3) << dt->flt << std::endl;
    

    delete data;
    return (0);
}