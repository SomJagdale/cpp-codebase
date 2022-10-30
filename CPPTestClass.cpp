#include <iostream>

using namespace std;

class Test
{
    private:
        int *_number;
        
    public:
    // default Constructor 
    Test(){cout<<"default"<<endl;}
    
    // Parameterised Constructor
    Test(int *number){ _number = number;cout<<"Parameterised"<<endl;}

    // Copy Constructor
    Test(const Test& test){ _number = new int();cout<<"copy"<<endl;}
    
    // Assignment operator
    Test& operator=(const Test& test){_number=test._number;cout<<"Assignment"<<endl;return *this;}
    
    ~Test(){cout<<"Destructor"<<endl;}
};

int main()
{
    cout<<"Hello World"<<endl;

    Test t1; // default
    Test t2(new int()); // param
    Test t3(t2);// copy
    Test t4 = t2; // copy
    t4=t3;
    return 0;
}
