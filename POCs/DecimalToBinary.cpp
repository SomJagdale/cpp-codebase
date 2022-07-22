#include <iostream>

using namespace std;

int main()
{
    int result[10];
    for(int x : result)
        cout<<" "<<result[x];
    cout<<"Enter Number"<<endl;
    int n= 0, i=0 ;
    cin>>n;

    while(n != 0)
    {
        if(n == 1)
        {
            result[i]=1;
            n = 0;
        }
        else if(n%2 == 0)
        {
            n = n/2;
            result[i] = 0;
        }
        else if(n%2 != 0)
        {
            n = n/2;
            result[i]= 1;
        }
        i++ ;
    }

    cout<<"Binary Number"<<endl;

    for(int x : result)
        cout<<" "<<result[x];

    return 0;
}
