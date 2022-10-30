
#include <iostream>

using namespace std;

class Base
{
    public:
 //   Base(){cout<<"Base"<<endl;}
    virtual void fun()=0;
};
class Derived1 : public Base
{
    public:
    Derived1(){cout<<"Derived1"<<endl;}
    void fun(){};
};
class Derived2 : public Base
{
    public:
    Derived2(){cout<<"Derived2"<<endl;}
    void fun(){};
};
class Derived3 : public Base
{
    public:
    Derived3(){cout<<"Derived3"<<endl;}
    void fun(){};
};

void func(Base *b){
    
    Derived1 *d1 = static_cast<Derived1*>(b);
    cout<<"func"<<d1<<endl;
    
}
int main()
{
    cout<<"Hello World"<<endl;
 //   Base *b = new Base();
    Base *b1 = new Derived1;
    Base *b2 = new Derived2();
    Base *b3 = new Derived3();
    func(b2);
   return 0;
}
o/p

#include <iostream>

using namespace std;

class Base
{
    public:
 //   Base(){cout<<"Base"<<endl;}
    virtual void fun()=0;
};
class Derived1 : public Base
{
    public:
    Derived1(){cout<<"Derived1"<<endl;}
    void fun(){};
};
class Derived2 : public Base
{
    public:
    Derived2(){cout<<"Derived2"<<endl;}
    void fun(){};
};
class Derived3 : public Base
{
    public:
    Derived3(){cout<<"Derived3"<<endl;}
    void fun(){};
};

void func(Base *b){
    
    Derived1 *d1 = static_cast<Derived1*>(b);
    cout<<"func"<<d1<<endl;
    
}
int main()
{
    cout<<"Hello World"<<endl;
 //   Base *b = new Base();
    Base *b1 = new Derived1;
    Base *b2 = new Derived2();
    Base *b3 = new Derived3();
    func(b2);
   return 0;
}
