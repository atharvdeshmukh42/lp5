#include<iostream>
using namespace std;

int main()
{
    int a[5]={1,2,3,4,5};
    int b[5]={5,4,3,2,1};
    int c[5];

    for(int i=0;i<5;i++)
    {
        c[i]=a[i]+b[i];
    }

    cout<<"Result:\n";

    for(int i=0;i<5;i++)
    {
        cout<<c[i]<<" ";
    }

    return 0;
}