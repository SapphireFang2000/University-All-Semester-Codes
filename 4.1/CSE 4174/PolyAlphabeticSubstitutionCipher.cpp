//POLYALPHABATIC CIPHER
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string plainText, cipherText, key;

    cout << "Plain Text: ";
    cin >> plainText;
    cout << "Key: ";
    cin >> key;

    int j=0;

    for(int i=key.length(); i<plainText.length(); i++)
    {
        if(j==key.length())
        {
            j=0;
        }

        key+=key[j];
        j++;
    }

    for(int i=0; i<plainText.length(); i++)
    {
        cipherText += (((plainText[i] - 'a') + (key[i] - 'a'))%26) + 'a';
    }

    transform(cipherText.begin(), cipherText.end(), cipherText.begin(), ::toupper);
    
    cout << "Cipher Text: " << cipherText << endl;

    return 0;
}

/*
Enter the Plain Text: wearediscoveredsaveyourself
Enter the Key: deceptive
Cipher Text: ZICVTWQNGRZGVTWAVZHCQYGLMGJ
*/
