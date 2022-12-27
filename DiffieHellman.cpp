#include <bits/stdc++.h>
using namespace std;

double large_mod(double x, double y, double z)
{
    double res = 1;
    // applying (a^b) % MOD = ((a % MOD)^b) % MOD
    while (y)
    {
        if (int(y) % 2)
            res = fmod(res * x, z);
        y /= 2;
        x = fmod(x * x, z);
    }

    return res;
}

int main()
{
    double q, alpha = 2;

    cout << "Enter a prime number to be chosen for the algorithm: ";
    cin >> q;

    cout << "\nEnter a primitive root of q to be chosen for the algorithm: ";
    cin >> alpha;

    double xa, xb;
    cout << "\nSelect Private key Xa : ";
    cin >> xa;
    cout << "\nSelect Private key Xb : ";
    cin >> xb;

    double ya = large_mod(alpha, xa, q), yb = large_mod(alpha, xb, q);
    cout << "\nPublic key Ya : " << ya
         << "\nPublic key Yb : " << yb;

    double ka = large_mod(yb, xa, q), kb = large_mod(ya, xb, q);
    cout << "\n\nSecret key calculated by user A : " << ka
         << "\nSecret key calculated by user B : " << kb;
}


/* 
OUTPUT: 

Enter a prime number to be chosen for the algorithm: 353

Enter a primitive root of q to be chosen for the algorithm: 3

Select Private key Xa : 97

Select Private key Xb : 233

Public key Ya : 40
Public key Yb : 248

Secret key calculated by user A : 160
Secret key calculated by user B : 160
*/