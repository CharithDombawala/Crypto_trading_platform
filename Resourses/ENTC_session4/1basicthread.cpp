#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void methodA()
{
    for (int i = 0; i < 100; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<"Loop "<<i<<endl;
    }
    
}

int main()
{
    thread t1(methodA);
    thread t2(methodA);
    
    cout<<"End"<<endl;
    t1.join();
    t2.join();
}