#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
    int x[5]={1,2,3,4,5};
    int y[5]={2,4,6,8,10};

    int sumx=0,sumy=0,sumxy=0,sumx2=0;
    int n=5;

    #pragma omp parallel for reduction(+:sumx,sumy,sumxy,sumx2)
    for(int i=0;i<n;i++)
    {
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumxy=sumxy+x[i]*y[i];
        sumx2=sumx2+x[i]*x[i];
    }

    float m,b;

    m=(n*sumxy-sumx*sumy)/(float)(n*sumx2-sumx*sumx);

    b=(sumy-m*sumx)/(float)n;

    cout<<"Slope = "<<m<<endl;
    cout<<"Intercept = "<<b;

    return 0;
}