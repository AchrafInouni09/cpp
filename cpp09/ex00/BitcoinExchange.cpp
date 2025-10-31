#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(std::string dbFile, std::string inputFile)
{
    this->dbFile = dbFile;
    this->inputFile = inputFile;
    loadDatabase();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static void trimString(std::string &s) {
    const char *ws = " \t\n\r";
    std::size_t start = s.find_first_not_of(ws);
    if (start == std::string::npos) 
    {
        s.clear();
        return;
    }
    std::size_t end = s.find_last_not_of(ws);
    s = s.substr(start, end - start + 1);
}

void BitcoinExchange::loadDatabase() {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
            trimString(date);
            trimString(valueStr);
            float value = std::atof(valueStr.c_str());
            _db[date] = value;
        }
    }
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{   
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3) return false;
    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31) return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, float &out) const
{
    char *end;
    double v = std::strtod(value.c_str(), &end);
    if (*end != '\0') return false;
    if (v < 0)
    {
        out = v;
        return false;
    }
    if (v > 1000)
    {
        return false;
    }
    
    out = static_cast<float>(v);
    return true;
}

std::string BitcoinExchange::getClosestDate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _db.upper_bound(date);
        if (it == _db.begin()) {
            return "";
        }
        --it;
        return it->first;
}

void BitcoinExchange::processInput() {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string line;
    std::getline(file, line);
        while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, valueStr;

        if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
        {
            trimString(date);
            trimString(valueStr);

            float value;
            if (!isValidDate(date)) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!isValidValue(valueStr, value))
            {
                if (valueStr.empty() || valueStr.find_first_not_of("0123456789.-") != std::string::npos)
                    std::cout << "Error: bad input => " << date << std::endl;
                else if (value < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else
                    std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            std::string closest = getClosestDate(date);
            if (closest.empty()) {
                std::cout << "Error: bad input => " << date << ":" << std::endl;
                continue;
            }
            float rate = _db.find(closest)->second;
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}
