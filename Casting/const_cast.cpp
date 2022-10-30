
static_const -  it removes the constness of the pointer variable 
 const_cast
const_cast is used to cast away the constness of variables. Following are some interesting facts about const_cast.
#include <iostream>

using namespace std;

void func(char *b){
    cout<<"func"<<b<<endl;
}
int main()
{
    cout<<"Hello World"<<endl;
    const char *str = "somanath";
    func(const_cast<char*>(str));
   return 0;
}
o/p
Hello World
funcsomanath
