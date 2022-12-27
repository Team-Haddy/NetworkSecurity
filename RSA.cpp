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
	// Select random prime numbers
	double p = 17;
	double q = 11;

	// Find first part of public key
	double n = p * q;

	// Find second part of public key
	double e = 2; // e must be greater than one

	double phi = (p - 1) * (q - 1); // Euler's totient function
	while (e < phi)
	{
		// e must be relatively prime to and smaller than phi
		if (__gcd(int(e), int(phi)) == 1)
			break;
		else
			++e;
	}

	// Find private key
	// Choose d such that it satisfies d*e = 1 (mod phi)
	double d;
	for (double it = 1; it < phi; it++)
		if (fmod((fmod(e, phi) * fmod(it, phi)), phi) == 1 && it < phi)
		{
			d = it;
			break;
		}

	cout << "n = p*q = " << n
		 << "\nphi = (p-1) x (q-1) = " << phi
		 << "\ne = " << e
		 << "\nd = " << d << "\n";

	// Message to be encrypted
	double msg;
	cout << "Enter the message to be encrypted: ";
	cin >> msg;

	cout << "Plaintext message = " << msg;

	// Encryption c = (msg ^ e) % n
	double c = large_mod(msg, e, n);
	cout << "\nEncrypted message = " << c;

	// Decryption m = (c ^ d) % n
	double m = large_mod(c, d, n);
	cout << "\nDecrypted message = " << m;

	return 0;
}


/*
n = p*q = 187
phi = (p-1) x (q-1) = 160
e = 3
d = 107
Enter the message to be encrypted: 88
Plaintext message = 88
Encrypted message = 44
Decrypted message = 88


n = p*q = 187
phi = (p-1) x (q-1) = 160
e = 3
d = 107
Enter the message to be encrypted: 12
Plaintext message = 12
Encrypted message = 45
Decrypted message = 12


n = p*q = 187
phi = (p-1) x (q-1) = 160
e = 3
d = 107
Enter the message to be encrypted: 123
Plaintext message = 123
Encrypted message = 30
Decrypted message = 123
*/