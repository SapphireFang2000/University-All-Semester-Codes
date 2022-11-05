#include<bits/stdc++.h>
using namespace std;

int sum, n;
vector<int>x(1000), input(1000);

void ss(int s, int k, int r)
{
    x[k] = 1;

    if(s+input[k] == sum)
    {
        cout << endl;

        for(int i=1; i<=n; i++)
        {
            cout << input[i]<<" ";
        }
        cout << endl;

        for(int i=1; i<=n; i++)
        {
            cout << x[i] << " ";
        }
        cout<<endl;
    }
    else if(s+input[k]+input[k+1]<=sum)
    {
        ss(s+input[k], k+1, r-input[k]);
    }

    if(((s+r-input[k])>=sum) && (s+input[k+1]<=sum))
    {
        x[k] = 0;
        ss(s, k+1, r-input[k]);
    }
}

int main()
{
    int total=0;

    cout << "Enter Element Number: " << endl;
    cin>>n;

    cout << "Enter Elements: " << endl;
    input.resize(n+1);

    for(int i=1; i<=n; i++)
    {
        cin >> input[i];
        total+=input[i];
    }

    sort(input.begin(), input.end());

    for(int i=1; i<=n; i++)
    {
        cout << input[i] << " ";
    }

    cout << "\nTotal Sum: " << endl;
    cin >> sum;

    ss(0, 1, total);
    
    return 0;
}
