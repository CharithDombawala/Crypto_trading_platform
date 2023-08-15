
#include <iostream>
using namespace std;

class Bird
{

public: 
    void fly()
    {
        cout << "Bird flies" << endl;
    }
};

class Parrot: public Bird
{
 //this is okay
};

class Ostrich : public Bird
{
//this is wrong. Ostrich cant fly :(.
};

int main()
{
    Bird* b = new Parrot();
    b->fly();
    b = new Ostrich();
    b->fly();
}

