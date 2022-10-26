#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x[10],y[10],p[10];
    int k,f,n,i,j=1,f1=1,f2=0;


    cout<<"Enter the no. of observations\n";
    cin>>n;

    cout<<"Enter the different values of x\n";

    for(i=1; i<=n; i++)
    {
        cin>>x[i];
    }

    cout<<"Enter the corresponding values of y\n";

    for(i=1; i<=n; i++)
    {
        cin>>y[i];
    }

    f=y[1];

    cout<<"Enter the value of 'k' for f(k) evaluation\n";
    cin>>k;

    do
    {
        for(i=1; i<=n-1; i++)
        {
            p[i]=((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i]=p[i];
        }
        for(i=1; i<=j; i++)
        {
            f1 *= (k-x[i]);
        }

        f2 += (y[1]*f1);
        f1=1;
        n--;
        j++;
    }
    while(n!=1);

    f += f2;
    cout<<"f("<<k<<")="<<f;

    return 0;
}