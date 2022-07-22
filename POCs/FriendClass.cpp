/******************************************************************************
Author: Somanath J
Proof of Concept: friend class
Language C++

Notes: Friend class declaration can be present in anywhere in class
If any class instance variables are private but as per new req any new class wants to 
access private data members of existing class then we can use friend class
friend class declaration is not bidirectinal
*******************************************************************************/

#include <iostream>

class ClassA
{
    private:
    int a;
    friend class ClassB;
    
    public:
    ClassA(int a):a(a){};
    
};

class ClassB
{
 
 public:
 ClassB(){};
  int getClassBPrivate(ClassA A)
  {
       return A.a;
  }
};

int main()
{
    ClassA objA(10);
    ClassB objB;
    std::cout<<"Private value for Class A is "<<objB.getClassBPrivate(objA);
    return 0;
}
