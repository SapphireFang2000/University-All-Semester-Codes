//Row Transposition CIPHER

#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string plainText, key;

    cout << "Plain Text: ";
    cin >> plainText;

    cout << "Key: ";
    cin >> key;
    
    int keyLength = key.length();
    int textLength = plainText.length();

    int numRows = textLength / keyLength;
    if (textLength % keyLength != 0) 
    {
        numRows++;
    }
    
    char matrix[numRows][keyLength];
    
    int temp = 0;
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < keyLength; j++) 
        {
            if (temp < textLength) 
            {
                matrix[i][j] = plainText[temp++];
            } 
            else 
            {
                matrix[i][j] = 'x';
            }
        }
    }

    cout << "Cipher Text: ";
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < keyLength; j++) 
        {
            int col = key[j] - '1';
            cout << matrix[i][col];
        }
    }
    cout << endl;

    return 0;
}

/*
Plain Text: thesimplestpossibletranspositions
Key: 41532
Cipher Text: stiehemslpstsopeitlbsrpnatoiisxoxsn
*/
