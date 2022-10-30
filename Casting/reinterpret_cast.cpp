
#include <iostream>

using namespace std;

class Base
{
    public:
    Base(){cout<<"Base"<<endl;}
};
class Derived1
{
    public:
    Derived1(){cout<<"Derived1"<<endl;}
    void fun(){};
};
void func(Base *b){
    
    Derived1 *d1 = reinterpret_cast<Derived1*>(b);
    cout<<"func"<<d1<<endl;
    
}
int main()
{
    cout<<"Hello World"<<endl;
    Base *b1 = new Base();
    func(b1);
   return 0;
}
o/p
Hello World
Base
func0x563f6a6a82c0
