
#include "file_map.h"

using namespace std;

int main(int argc, char  **argv)
{
    if (argc != 4)
    {
        cout << "error ./a.out filename s1 s2" << endl;
        return (1);
    }
    FileMap  file(argv[1], argv[2], argv[3]);
    file.PrintFileContent();

    file._ReplaceInFile();
    // cout << "######################" << endl;
    file.PrintFileContent();


    // std::string s = "hello world zbi";
    // std::string s1 = "world";
    // std::string s2 = "hello" ;
    // std::string test = FileMap::ft_replace(s, s1.c_str() ,s2.c_str()) ;
    // cout << "new value : " << test << endl;
    return (0);
}