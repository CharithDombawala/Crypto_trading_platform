#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"

int main()
{
    MerkelMain app{};
    app.init();

}


//          double price = 5319.450228
//          double amount = 0.0020075
//          std::string timestamp{"2020/03/17 17:01:24.884492"};
//          std::string product{"ETH/BTC"};
//          OrderBookType orderType=OrderBookType::ask;

//      std:: vector<double> prices;
//      std:: vector<double> amounts;
//      std:: vector<std::string> timestamps;
//      std:: vector<std::string> products;
//      std:: vector<OrderBookType> orderTypes;

//          while(true)
//          {
//              printMenu();
//              int userOption = getUserOption();
//              processUserOption(userOption);
//          }
//          return 0;

//      std::vector<OrderBookEntry> orders;


//      OrderBookEntry order1{1000777,
//                          0.02,
//                          "2020/03/17 17:01:24.884492",
//                          "ETH/BTC",
//                          OrderBookType::bid};

//      orders.push_back(order1);

//      OrderBookEntry order2{99889,
//                          0.03,
//                          "2020/03/17 17:01:24.99492",
//                          "ETH/USDT",
//                          OrderBookType::bid};

//      orders.push_back(order2);

//      std::cout<<"The price is "<< orders[0].price<< std::endl;
//      std::cout<<"The price is "<< orders[1].price<< std::endl;


// }
