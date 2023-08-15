#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

int main()
{
    int count = 0;
    mutex mtx;

    thread t1([&](){
            mtx.lock();    
            count++; 
            mtx.unlock();
    });
    thread t2([&](){   
        mtx.lock();
            count++; 
           mtx.unlock();      
    });
    
    t1.join();
    t2.join();
   
    cout<<"End"<<count<<endl;
}