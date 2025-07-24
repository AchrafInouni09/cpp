
#include "Serializer.h"

using namespace std;


int main()
{
    cout << "hello world\n";

    Data *data = new Data;

    data->nb = 42;
    data->dbl = 3.0;
    data->letter = 'C';
    data->flt = 1.0f;


    uintptr_t n = Serializer::serialize(data);

    cout << n << endl;

    Data *dt = Serializer::deserialize(n);


    cout << dt->nb  << endl;
    cout << std::fixed << setprecision(3) << dt->dbl << endl;
    cout << dt->letter << endl;
    cout <<  std::fixed << setprecision(3) << dt->flt << endl;
    

    delete data;
    return (0);
}