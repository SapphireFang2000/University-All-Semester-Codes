#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n,a[50],frame[10],check[10],no,k;

	cout << "Number of Page References: ";
    cin>>n;

	cout << "Reference String: ";
    for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
    
	cout << "Number of Memory Page Frame: ";
    cin>>no;

    for(i=0;i<no;i++)
	{
        frame[i]= -1;
        check[i]=0;
    }

    int count1=0,track=0,available,p=0;

    for(int i=0;i<n;i++)
	{
        available=0;
        for(int j=0;j<no;j++)
		{
            if(frame[j]==a[i])
			{
                available=1;

                for(int k=0;k<no;k++)
				{
                    if(check[k]>check[j])
					{
                        check[k]--;
                    }
                }
                check[j]=no;
                break;
            }
        }

        if(available==0)
		{
            if(p<=no-1)
			{
                frame[p]=a[i];
                check[p]=p+1;
                p++;
                count1++;
            }
            else
			{
                for(int j=0;j<no;j++)
				{
                    if(check[j]==1)
					{
                        frame[j]=a[i];
                        for(int k=0;k<no;k++)
						{
                            if(check[k]>check[j])
							{
                                check[k]--;
                            }
                        }
                        check[j]=no;

                        count1++;
                        break;
                    }
                }

            }
        }
    }
    cout <<"Number of page fault using Least Recently Used Page replacement Algorithm: "<< count1 << endl;

	double rate = ((double)count1/n)*100;
	cout << "Page Fault Rate: " << rate << "%" << endl;
}

/*
Number of Page References: 22
Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
Number of Memory Page Frame: 3
*/
