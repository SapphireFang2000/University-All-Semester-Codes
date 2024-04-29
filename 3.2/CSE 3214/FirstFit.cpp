#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
	cout << "Enter the Number of Memory Holes: ";
    cin >> m;

    int mem[m];
	cout << "Memory Holes: ";
    for(int i=0;i<m;i++)
	{
        cin >> mem[i];
    }

	cout << "Enter the Number of Memory Request: ";
    cin >> n;

    int req[n];
	cout << "Memory Request: ";
    int frag=0;
    for(int i=0;i<n;i++)
	{
        cin >> req[i];
    }

    int table[m][n];
    for(int i=0;i<m;i++)
	{
        for(int j=0;j<n;j++)
		{
            table[i][j]=-2;
        }
    }

    int col=0;
    bool check;
    for(int i=0;i<n;i++)
	{
        check=false;
        for(int j=0;j<m;j++)
		{
            if(req[i]<=mem[j])
			{
                check=true;
                mem[j]-=req[i];
                break;
            }
        }
        if(check==true)
		{
			for(int row=0,j=0;j<m;j++)
			{
				table[row++][col]=mem[j];
			}
        	col++;
        }
        if(check==false)
		{
            for(int i=0;i<m;i++)
			{
                frag+=mem[i];
            }
            break;
        }
    }

	cout << "Memory Allocation Step by Step:" << endl;
    for(int i=0;i<n;i++)
	{
        cout << req[i] << "\t";
    }
    cout<<endl;
    for(int i=0;i<m;i++)
	{
        for(int j=0;j<n;j++)
		{
            cout << table[i][j] << "\t";
        }
        cout<<endl;
    }
    if(frag>0)
	{
        cout << "External Fragmentation = " << frag << endl;
    }
}

/*
Enter the Number of Memory Holes: 5
Memory Holes: 50 200 70 115 15
Enter the Number of Memory Request: 10
Memory Request: 100 10 35 15 23 6 25 55 88 40
*/
