#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"


 MerkelMain::MerkelMain()
{


}


void MerkelMain::init()
{  
   loadOrderBook();  
   int input;
   while(true)
   {    
       printMenu();
       input = getUserOption();
       processUserOption(input);

   }
}

void MerkelMain:: loadOrderBook(){
     

     OrderBookEntry order1{1000777,
                         0.02,
                         "2020/03/17 17:01:24.884492",
                         "ETH/BTC",
                         OrderBookType::bid};
     orders.push_back(order1);

     OrderBookEntry order2{99889,
                         0.03,
                         "2020/03/17 17:01:24.99492",
                         "ETH/USDT",
                         OrderBookType::bid};
     orders.push_back(order2);
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
      std::cout<< "OrderBook contains : "<<  orders.size() << " entries" <<std::endl;
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
