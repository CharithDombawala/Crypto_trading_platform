#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>


class CSVReader
{
    public:
      CSVReader();
      static std::vector<std::string> tokenise(std::string csvLine,char separator);
      static OrderBookEntry stringToOBE(std::string price,
                                        std::string amount,
                                        std::string timestamp,
                                        std::string product,
                                        OrderBookType OrderBookType);
                                        
      static std:: vector<OrderBookEntry> readCSV(std::string csvFile);

    private:
      static OrderBookEntry stringToOBE(std::vector<std::string> strings);
};