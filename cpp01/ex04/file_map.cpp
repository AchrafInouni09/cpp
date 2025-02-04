#include "file_map.h"

void FileMap::PrintFileContent()
{
    std::fstream file;
    const char* f = _filename.c_str();

    file.open(f, std::ios::in);

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
}

std::string FileMap::ft_replace(std::string s ,const char *to_replace, const char *replace_with)
{   
    std::string str = s;
    size_t pos = 0;

    while ((pos = str.find(to_replace, pos)) != std::string::npos)
    {
        str.erase(pos, strlen(to_replace));
        str.insert(pos, replace_with);
    }
    return str;
}

void FileMap::_SaveToNewFile()
{
    _filename += ".replace";
    std::ofstream MyFile(_filename.c_str());
    if (MyFile.is_open())
    {
        MyFile << _content;
        MyFile.close();
    }
}

void FileMap::_ReplaceInFile()
{
    std::fstream file;
    const char* f = _filename.c_str();

    file.open(f, std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            _content += ft_replace(line, _to_replace.c_str(), _replace.c_str());
            _content += "\n";
        }
    }
    _SaveToNewFile();
}