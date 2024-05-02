#include <bits/stdc++.h>
using namespace std;

long int e, d, temp[100], m[100], en[100];

int prime(long int pr)
{
    int i, j;
    j = sqrt(pr);

    for(i = 2; i <= j; i++)
    {
        if(pr % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

long int find_d(long int e, long int phi)
{
    long int k = 1, x;

    while(1)
    {
        x= 1 + k * phi;
        if (x % e == 0)
        {
            return (x / e);
            break;
        }
        else
        {
            k++;
        }
    }
}

void find_e(long int phi, long int p, long int q)
{
    int k, flag;
    k = 0;

    for(int i = 2; i < phi; i++)
    {
        if(phi % i == 0)
        {
            continue;
        }

        flag = prime(i);

        if(flag == 1 && i != p && i != q)
        {
            e= i;
            flag = find_d(e, phi);

            if(flag > 0)
            {
                d = flag;
                k++;
            }

            break;
        }
    }
}

void printValues(long int n, long int phi, string msg)
{
    cout << endl << "Printing Key Setup Values:" << endl;
    cout << "n = " << n << endl;
    cout << "Phi(n) =  " << phi << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
}

void encrypt(long int n, string msg)
{
    long int pt, k, len, i = 0 ;

    len = msg.length();

    while(i < len)
    {
        pt = m[i];
        k = 1;

        for(int j = 0; j < e; j++)
        {
            k = k * pt;
            k = k % n;
        }

        temp[i] = k;
        en[i] = k;
        i++;
    }

    en[i] = -1;

    cout << endl << "Encrypted Message: ";

    for(i = 0; en[i] != -1; i++)
    {
        cout << en[i] <<" ";
    }

    cout << endl;
}

void decrypt(long int n)
{
    long int ct, k, i = 0, de[100];

    while(en[i] != -1)
    {
        ct = temp[i];
        k = 1;

        for(int j = 0; j < d; j++)
        {
            k = k * ct;
            k = k % n;
        }

        de[i] = k;
        i++;
    }

    de[i] = -1;

    cout << "Decrypted Message: ";

    for(i = 0; de[i] != -1; i++)
    {
        cout << (char)de[i];
    }
    cout << endl;
}

int main()
{
    long int flag, p, q, n, phi;
    string msg;

    cout << "Enter a Prime Number, P = ";
    cin >> p;

    flag = prime(p);

    if(flag == 0)
    {
        cout << "The number you have entered is not prime.";
        return 0;
    }

    cout << "Enter a Prime Number, Q = ";
    cin >> q;

    flag = prime(q);

    if(flag == 0 || p == q)
    {
        cout << "The number you have entered is not prime.";
        return 0;
    }

    cout << "Enter The Message: ";
    fflush(stdin);
    getline(cin,msg);

    for(int i = 0; i < msg.length(); i++)
    {
        m[i] = msg[i];
    }

    n = p * q;
    phi = (p - 1) * (q - 1);

    find_e(phi, p, q);
    printValues(n, phi, msg);
    encrypt(n, msg);
    decrypt(n);

    return 0;
}
