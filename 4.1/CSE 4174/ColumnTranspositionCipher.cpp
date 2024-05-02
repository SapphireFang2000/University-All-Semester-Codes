//Column Transposition Cipher
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string plainText;
    string key;

    cout << "Plain Text: ";
    cin >> plainText;

    cout << "Key: ";
    cin >> key;

    int len = key.length();
    char numberKey[len];

    string tempKey = key;

    sort(tempKey.begin(), tempKey.end());

    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(tempKey[i]==key[j])
            {
                numberKey[j] = (i) + '1';
            }
        }
    }

    int keyLength = key.length();
    int textLength = plainText.length();

    int numRows = textLength / keyLength;

    if (textLength % keyLength != 0) 
    {
        numRows++;
    }

    char matrix[numRows][keyLength];

    int temp = 0;

    for (int j = 0; j < numRows; j++) 
    {
        for (int i = 0; i < keyLength; i++) 
        {
            if (temp < textLength) 
            {
                matrix[j][i] = plainText[temp++];
            } 
            else
            {
                matrix[j][i] = 'x';
            }
        }
    }

    cout << "Cipher Text: ";
    for (int k = 1; k <= keyLength; k++) 
    {
        for (int i = 0; i < keyLength; i++) 
        {
            if (numberKey[i] - '0' == k) 
            {
                for (int j = 0; j < numRows; j++) 
                {
                    cout << matrix[j][i];
                }
            }
        }
    }
    cout << endl;

    return 0;
}

/*
Enter the Plain Text: meetmeaftertheparty
Enter the Key: HACK
Cipher Text: eeeetearpymmthrtftax
*/
