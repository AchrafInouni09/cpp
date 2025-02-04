#ifndef FILE_MAP_H
#define FILE_MAP_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>


class FileMap
{
    private:
        std::string _filename;
        std::string _content;
        std::string _replace;
        std::string _to_replace;
    public:
        FileMap(std::string filename, std::string s1, std::string s2): _filename(filename),
        _replace(s1), _to_replace(s2) {};
        void PrintFileContent();
        static std::string ft_replace(std::string s ,const char *to_replace, const char *replace_with);
        void _ReplaceInFile();
        void _SaveToNewFile();
        // void replace(char to_replace, char replace_with);
};


# endif