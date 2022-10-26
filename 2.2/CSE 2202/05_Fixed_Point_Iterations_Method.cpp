#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int A[100],n1;


double f(int poly[], int n, double x)
{
    double result = poly[0];
    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}


double fixed_point(double x)
{
    double x_prev=x;

    for(int i=1;;i++){
        x = f(A,n1+1,x_prev);
        cout<<'\n'<<i<<"\t "<<x;
        if(abs(x-x_prev)<=0.00009) break;
        if(i==15) {cout<<"Do not converge"<<'\n'; break;}
        x_prev = x;
    }
    return x;
}

int main()
{
    double Xo;
    int i;

    cout<<"ENTER THE TOTAL NO. OF POWER:::: ";
    cin>> n1;
    cout<<"\nEnter values of coefficients:\n";
    for( i=0; i<= n1; i++)
    {
        cout<<"\nx^"<<i<<"::";
        cin >> A[n1-i];
    }
    cout<<"\nTHE POLYNOMIAL IS ::: ";
    for(int i=0;i<=n1;i++)
    {
        if(A[i]==0) continue;
        cout<<"("<<A[i]<<")"<<"x^"<<(n1-i)<<"+";
    }
    A[n1-1]=0;
    cout << "\nINTIAL: Xo---->";
    cin >> Xo;
    cout<<"\nTHE POLYNOMIAL g(x) IS ::: ";
    for(int i=0;i<=n1;i++){
        if(A[i]==0) continue;
        cout<<"("<<A[i]<<")"<<"x^"<<(n1-i)<<"+";
    }

    Xo = fixed_point(Xo);
    cout << "\n Approximate root: "<< Xo ;
    return 0;
}
