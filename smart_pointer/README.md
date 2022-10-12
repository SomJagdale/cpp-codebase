###Smart pointer implementation

###Auto Pointer 
Example of Auto Pointer 
#include <iostream>
#include <memory>
using namespace std;
  
class A {
public:
    void show() { cout << "A::show()" << endl; }
};
int main()
{
    // p1 is an auto_ptr of type A
    auto_ptr<A> p1(new A);
    p1->show();
  
    // returns the memory address of p1
    cout << p1.get() << endl;
  
    // copy constructor called, this makes p1 empty.
    auto_ptr<A> p2(p1);
    p2->show();
  
    // p1 is empty now
    cout << p1.get() << endl;
  
    // p1 gets copied in p2
    cout << p2.get() << endl;
  
    return 0;
}

Why is auto_ptr deprecated?
It takes ownership of the pointer in a way that no two pointers should contain the same object. Assignment transfers ownership and resets the rvalue auto pointer to a null pointer. Thus, they can’t be used within STL containers due to the aforementioned inability to be copied.

####Unique pointer

#####shared pointer

