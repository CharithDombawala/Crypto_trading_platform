#include <iostream>
#include <string>
#include <vector>
#include <fstream>

enum class OrderBookType{bid,ask};


std::vector<std::string> tokenise(std::string csvLine,char separator)
{
  std::vector<std::string> tokens;  
  signed int start,end;
  std::string token;

  start = csvLine.find_first_not_of(separator,0);
  do{
      end =csvLine.find_first_of(separator,start);
  if (start==csvLine.length() || start == end) break;

  if (end>=0) token = csvLine.substr(start,end-start);

  else  token = csvLine.substr(start,csvLine.length()-start);


  tokens.push_back(token);
  start = end +1;

  }while(end>0);


  return tokens;
}

int main()
{
    // std::vector<std::string> tokens;  
    // std::string s = "thing,thing1,thing2,";
    // tokens = tokenise(s,',');
    // for (std::string& t : tokens)
    // {
    //     std::cout << t << std::endl;

    // }

   std::ifstream csvFile{"DataSet.csv"};
   std::string line;
   std::vector<std::string> tokens;  
   if (csvFile.is_open())
   {
    std::cout<< "File open" << std::endl;
    while(std::getline(csvFile,line))
    {
            std:: cout << "Read Line " << line << std::endl;
            tokens = tokenise(line,',');
            if (tokens.size() !=5) 
            {
                 std::cout<< "Bad line" << std::endl;
                 continue;
            }
            try{
                std::string timestamp = tokens[0];
                std::string product = tokens[1];
                std::string ordertype = tokens[2];
                double price=std::stod(tokens[3]);
                double amount=std::stod(tokens[4]);
                std::cout << timestamp << " : " << product<<" : " << ordertype << " : " << price <<" : "<< amount <<std::endl;

            }catch(std::exception& e){
                std::cout<< "Bad float! " << tokens[3] << std::endl;
                std::cout<< "Bad float! " << tokens[4] << std::endl;
                continue;
            }
            
    }
    
    csvFile.close();
   }
   else
   {
    std::cout << "Could not open file" << std:: endl;
    
   }

    return 0;
}