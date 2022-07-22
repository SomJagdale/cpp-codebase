#include <iostream>
using namespace std;

class B{
    int a;
    int b;
};
class A{
    int a;
    int b;
    public:
    A operator=(const A&){}
};
int main()
{
    cout << "Hello World" << endl;
    A a1;
    B b1;
    a1 = b1;
    a1=b1;
    A *ap = new A;
    B *bp = new B;
    ap=reinterpret_cast<A*>(bp);
    cout << "Hello World" << endl;

    return 0;
}
