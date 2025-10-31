#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    private : 
        std::string dbFile;
        std::string inputFile;
public:
    BitcoinExchange(std::string dbFile, std::string inputFile);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInput();

private:
    std::map<std::string, float> _db;
    void loadDatabase();
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value, float &out) const;
    std::string getClosestDate(const std::string &date) const;
};

#endif
