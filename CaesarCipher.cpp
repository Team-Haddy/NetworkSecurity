#include <bits/stdc++.h>
//#include "windows.h"
using namespace std;

void printMessage(string type)
{
    cout << type << " the message";
    for (int i = 0; i < 5; i++)
    {
        //Sleep(100 * (i + 1));
        cout << ".";
    }
}

int main()
{
    int k;
    string pt, ptt;
    cout << "Enter the message to be encrypted : ";
    cin >> pt;
    ptt = pt;

    transform(pt.begin(), pt.end(), pt.begin(), ::tolower);

    cout << "\nEnter the key (Integer) : ";
    cin >> k;
    k %= 26;
    system("cls");
    printMessage("Encrypting");
    //Encryption Algorithm
    for (int i = 0; i < pt.size(); i++)
    {
        int temp = k + pt[i];
        ptt[i] = char(temp);

        if (temp > 122)
            temp -= 26;

        pt[i] = char(temp);
    }

    cout << "\nEncrypted Text (Cipher text) : " << pt << "\n";

    printMessage("Decrypting");
    //Decryption Algorithm
    for (int i = 0; i < pt.size(); i++)
        ptt[i] -= k;

    cout << "\nDecrypted Text (Plain text) : " << ptt << "\n";
}