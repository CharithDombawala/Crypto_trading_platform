#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"


 MerkelMain::MerkelMain()
{


}


void MerkelMain::init()
{  
    
   int input;
   while(true)
   {    
       printMenu();
       input = getUserOption();
       processUserOption(input);

   }
}



void  MerkelMain::printMenu()
{       
    // 1 print help
    std :: cout << "1: Print help"<< std:: endl;
    // 2 print exchange stats
    std :: cout << "2: Print exchange stats"<< std:: endl;
    // 3 make an offer
    std :: cout << "3: Make an offer"<< std:: endl;
    // 4 make a bid
    std :: cout << "4: Make a bid"<< std:: endl;
    // 5 print wallet
    std :: cout << "5: Print wallet"<< std:: endl;
    // 6 continue
    std :: cout << "6: Continue"<< std:: endl;
    
    std :: cout << "==============="<< std:: endl;
    
}

int MerkelMain::getUserOption()
{   
    int userOption ;
    std :: cout << "Type in 1-6" << std:: endl;
    std::cin >> userOption;
    std :: cout << "You chose:"<< userOption << std:: endl;
    return userOption;
}

void MerkelMain::InvalidInput()
{
  std::cout<< "invalid choice,Choose 1-6"<<std::endl;
}

void MerkelMain::printHelp()
{
std::cout << "Help - choose options from the menu" << std::endl;
std::cout << "and follow the on screen instructions." << std::endl;
}

void MerkelMain::printMarketstats()
{ 

     for(std::string const& p :orderBook.getKnownProducts())
     {

          std:: cout << "product: " << p << std::endl;
          std::vector<OrderBookEntry> entries =orderBook.getOrders(OrderBookType::ask,
                                                                 p,"2020/03/17 17:01:24.884492");
          std::cout <<"Asks seen: " << entries.size() << std::endl; 
          std::cout <<"Max ask: " << OrderBook::getHighPrice(entries) << std::endl;                                
          std::cout <<"Min ask: " << OrderBook::getLowPrice(entries) << std::endl;                                
                     
     }    
     //  std::cout<< "OrderBook contains : "<<  orders.size() << " entries" <<std::endl;
     //  unsigned int bids = 0 ;
     //  unsigned int asks = 0 ;
     //  for (OrderBookEntry& e : orders)
     //  {
     //      if (e.orderType == OrderBookType::ask)
     //      {
     //           asks ++;
     //      }
     //      if (e.orderType == OrderBookType::bid)
     //      {
     //           bids ++;
     //      }
     //  }
     //  std::cout<< "OrderBook  asks: "<<  asks << " bids: " << bids << std::endl;

}


void MerkelMain::enterAsk()
{
  std::cout<< "Make an offer - eneter thew amount"<<std::endl;
}

void MerkelMain::enterBid()
{
    std::cout<< "make a bid - enete the amount"<<std::endl;
}

void MerkelMain::printwallet()
{
    std::cout<< "Your wallet is empty"<<std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
     std::cout<< "Going to next time frame"<<std::endl;
}

void MerkelMain::processUserOption(int userOption)
{
    if ((userOption==0)||(userOption>6)) //bad input
    {
         InvalidInput();  
    }
    if (userOption==1) 
    {
         printHelp();
    }
    if (userOption==2) 
    {
         printMarketstats();
    }
    if (userOption==3) 
    {
         enterAsk();
    }
    if (userOption==4) 
    {
         enterBid();
    }
    if (userOption==5) 
    {
         printwallet();   
    }
    if (userOption==6) 
    {
         gotoNextTimeframe(); 
    }
    
}
