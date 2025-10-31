#include <iostream>

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;



template <typename T>

int easy_find (T &container, int value)
{
    typename T::iterator it = std::find (container.begin(), container.end(), value);

    if (it ==  container.end())
    {
        cout << " error asat \n";
        return -1;
    }
    return *it;
}

int main ()
{
    vector <int> v_nb;
    for (int i = 4; i > 0 ; i--)
    {
        v_nb.push_back(i);
    }


    // for (vector<int>::iterator it = v_nb.begin(); it != v_nb.end(); ++it)
    // {
    //     cout << *it << endl;
    // }

    // sort (v_nb.begin(), v_nb.end());
    // cout << endl;

    // for (vector<int>::iterator it = v_nb.begin(); it != v_nb.end(); ++it)
    // {
    //     cout << *it << endl;
    // }


    cout << numeric_limits<int>::max() << endl;

    // cout << distance(v_nb.begin(), --(v_nb.end())) << endl;

    // cout << easy_find (v_nb, 10) << endl;




    return (0);
}