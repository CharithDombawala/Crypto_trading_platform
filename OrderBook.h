#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
      public:
     
        /** constructor,reading csv data file */ 
        OrderBook(std::string filename);
        /** returnvector of all known products in teh dataset*/
        std::vector<std::string> getKnownProducts();
        /* *return vector of Orders accounting to the sent filters*/
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                                std::string product,
                                                std::string timestamp);

        std::string getEarliestTime();
        std::string getNextTime(std::string timestamp);

        void insertOrder(OrderBookEntry& order);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

      private:
         std::vector<OrderBookEntry> orders;
};