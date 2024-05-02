//Monoalphabetic_Cipher

#include<bits/stdc++.h>
using namespace std;

int main()
{
	string plainText, key;

	cout << "Plain Text: ";
	cin >> plainText;

    cout << "26 Letter Combination Key: ";
    cin >> key;

	int len = plainText.length(), temp;
	
	string encrypt;

	for(int i=0; i<len; i++)
    {
		temp = plainText[i] - 'a';
		encrypt += key[temp];
	}
	
    cout << "Cipher Text: " << encrypt << endl;

	return 0;
}

/*
Plain Text: attack
26 Letter Combination Key: QWERTYUIOPASDFGHJKLZXCVBNM
Cipher Text: QZZQEA
*/
