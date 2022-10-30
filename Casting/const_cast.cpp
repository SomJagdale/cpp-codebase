
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
