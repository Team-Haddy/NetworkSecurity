#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char addr[50], ch;
    ifstream ifs;
    ofstream ofs;

    int i;

    cout << "1.Block a site \n2.Unblock sites\n\nChoose an option:";
    cin >> i;
    ofs.open("C:/Windows/System32/drivers/etc/hosts");

    switch (i)
    {
        case 1:

            if (!ofs)
                cout << "Access to the file is denied!";
            else
            {
                cout << "Enter the address to be blocked : ";
                cin >> addr;

                ofs << "\n127.0.0.1\t" << addr;
                cout << "The address " << addr << " was blocked successfully !";
            }
            break;

        case 2:
            if (!ofs)
                cout << "Access to the file is denied!";
            else
            {

                ofs << "\n127.0.0.1"
                    << "\t"
                    << "localhost";
                cout << "All websites are unblocked\n";
            }
            break;

        default:
            cout << "Invalid option!\n";
            exit(0);
    }

    ofs.close();
    cin >> ch;

    return 0;
}