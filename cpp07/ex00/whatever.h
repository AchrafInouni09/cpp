#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T>


class Whatever 
{

    public:
        Whatever() {}
        Whatever(const Whatever &other)
        {
            *this = other;
        }
        Whatever &operator=(const Whatever &other)
        {
            if (this != &other)
            {

            }
            return *this;
        }
        ~Whatever() {}

        T const &min(T const &a, T const &b)
        {
            return (a < b ? a : b);
        }
        T const &max(T const &a, T const &b)
        {
            return (a > b ? a: b);
        }
        void swap(T &a, T &b)
        {
            T temp = a;
            a = b;
            b = temp;
        }
};

#endif