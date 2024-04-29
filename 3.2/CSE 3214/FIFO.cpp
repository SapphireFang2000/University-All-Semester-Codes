#include<bits/stdc++.h>
using namespace std;

int main()
{
	int framesize,frame[20];
	int len,refstring[20];
	int pagefault=0,first=0;
	int i,j;

	cout << "Number of Page References: ";
	cin >> len;

	cout << "Reference String: ";
	for(i=0;i<len;i++)
    {
		cin >> refstring[i];
    }
	cout << "Number of Memory Page Frame: ";
	cin >> framesize;

	for(i=0;i<framesize;i++)
    {
		frame[i]=-1;
    }
  
  //FIFO page replacement technique.
	for(i=0;i<len;i++)
    {
		int avail=0;

		for(j=0;j<framesize;j++)
        {
			if(frame[j]==refstring[i])
            {
				avail=1;
				break;
			}
        }
		if(avail==0)
        {
			pagefault++;
			frame[first]=refstring[i];
			if(first==framesize-1)
				first=0;
			else
				first++;
		}
	}
	cout << "Number of page fault using Least Recently Used Page replacement Algorithm: " << pagefault << endl;

    double rate = ((double)pagefault/len)*100;
	cout << "Page Fault Rate: " << rate << "%" << endl;
}

/*
Number of Page References: 22
Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
Number of Memory Page Frame: 3
*/
