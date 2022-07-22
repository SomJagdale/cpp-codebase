#include <iostream>

using namespace std;

void fun(char *nwType)
{return ;}
int main()
{
    char nwType;
    int i;

    cout<<"DefaultChar = "<<nwType<<endl;
    cout<<"DefaultInt = "<<i<<endl;

    fun(&nwType);
    cout<<"char = "<<nwType<<endl;

    return 0;
}
