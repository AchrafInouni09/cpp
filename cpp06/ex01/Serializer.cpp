#include "Serializer.h"


uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast <uintptr_t>(ptr));
}

Data  *Serializer::deserialize(uintptr_t nb)
{
    return (reinterpret_cast <Data *>(nb));
}