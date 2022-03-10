//Structure Sort. 

#include<bits/stdc++.h>
using namespace std;
struct Box
{
    int height;
    int width;
    int area1;
    
    Box()
    {
        ;
    }

    int area()
    {
       return (height*width);
    }
};

int main()
{
    Box arr[5];
    for(int i=0;i<5;i++)
    {
       cin >> arr[i].height >> arr[i].width;

       arr[i].area1 = arr[i].area();
       
       cout << arr[i].area1 << endl;
    }

    for(int i=0; i<4; i++)
    {
        int pos = i;
        int min = arr[i].area1;

        for(int j=i; j<5; j++)
        {
            if(arr[j].area1<min)
            {
                min = arr[j].area1;
                pos = j;
            }
        }

        Box temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }

    cout << endl << "Sorted Structure" << endl;
    for(int i = 0;i<5;i++)
    {
        cout<< arr[i].height << " * " << arr[i].width << " = " << arr[i].area1 << endl;
    }

    return 0;
}

/*
    Sample Input: (Hight Width)
                5 2
                6 3
                4 1
                4 2
                1 3

    Sample Output: (Area)
                10
                18
                4
                8
                3

                Structure Sort (Hight * Width = Area)
                1 * 3 = 3
                4 * 1 = 4
                4 * 2 = 8
                5 * 2 = 10
                6 * 3 = 18
*/