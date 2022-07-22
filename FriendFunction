/******************************************************************************
Author: Somanath J
Proof of Concept: friend function 
Language C++
*******************************************************************************/

#include <iostream>

class ClassA
{
    private:
    int a;
    int geta(){return a;};
    friend int FriendFun(ClassA);
    
    public:
    ClassA(int a):a(a){};
};

int FriendFun(ClassA a)
{
    return a.geta();
}


int main()
{
    ClassA objA(10);
    std::cout<<"Private value for Class A is "<<FriendFun(10);
    return 0;
}
