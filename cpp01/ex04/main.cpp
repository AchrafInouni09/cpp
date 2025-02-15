
#include "file_map.h"

// using namespace std;

int main(int argc, char  **argv)
{
    if (argc != 4)
    {
        std::cout << "error ./a.out filename s1 s2" << std::endl;
        return (1);
    }
    FileMap  file(argv[1], argv[2], argv[3]);
    file.PrintFileContent();

    file._ReplaceInFile();
    // cout << "######################" << endl;
    file.PrintFileContent();

    return (0);
}