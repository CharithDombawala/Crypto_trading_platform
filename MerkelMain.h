#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
    public:
        MerkelMain();
        void init();
    private:    
        void loadOrderBook();
        void printMenu();
        int  getUserOption();
        void InvalidInput();
        void printHelp();
        void printMarketstats();
        void enterAsk();
        void enterBid();
        void printwallet();
        void gotoNextTimeframe();
        void processUserOption(int userOption);

        OrderBook orderBook{"DataSet.csv"};
        std::vector<OrderBookEntry> orders;

};