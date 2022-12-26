#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fs;
    char ch;
    string data = "", line;

    fs.open("D:/SEMESTER VII/NS Lab/ToInfect/file.txt", ios::in);

    if (!fs.is_open())
    {
        cout << "Unable to open the file";
        exit(0);
    }

    //read the original content of the file
    while (getline(fs, line))
        data += line +"\n";

    fs.close();

    int i, key;
    cout << "1. Infect file\n2.Disinfect File\nChoose an option: ";
    cin >> i;

    fs.open("D:/SEMESTER VII/NS Lab/ToInfect/file.txt", ios::out);

    cout << "\nContent before modification:\n"
                << data;

    switch (i)
    {
        case 1:
            key = 2;
            break;

        case 2:
            key = -2;
            break;

        default:
            cout<<"Invalid input";
            exit(0);
    }

    //modify the file content
    for (int i = 0; i < data.length(); i++)
            if(data[i] != '\n')
                data[i] = char(data[i] + key);

    cout << "\n\nContent after modification:\n"
         << data;
    fs << data;

    fs.close();

    return 0;
}



/*
OUTPUT:

1. Infect file
2.Disinfect File
Choose an option: 1

Content before modification:
Contents:
Pretty Good Privacy - S/MIME - IP Security Overview - IP Security Architecture - Authentication Header -
Encapsulating Security Payload - Web Security Considerations - Secure Socket Layer and Transport Layer
Security - Secure Electronic Transaction(SET)


Content after modification:
Eqpvgpvu<
Rtgvv{"Iqqf"Rtkxce{"/"U1OKOG"/"KR"Ugewtkv{"Qxgtxkgy"/"KR"Ugewtkv{"Ctejkvgevwtg"/"Cwvjgpvkecvkqp"Jgcfgt"/
Gpecruwncvkpi"Ugewtkv{"Rc{nqcf"/"Ygd"Ugewtkv{"Eqpukfgtcvkqpu"/"Ugewtg"Uqemgv"Nc{gt"cpf"Vtcpurqtv"Nc{gt
Ugewtkv{"/"Ugewtg"Gngevtqpke"Vtcpucevkqp*UGV+




1. Infect file
2.Disinfect File
Choose an option: 2

Content before modification:
Eqpvgpvu<
Rtgvv{"Iqqf"Rtkxce{"/"U1OKOG"/"KR"Ugewtkv{"Qxgtxkgy"/"KR"Ugewtkv{"Ctejkvgevwtg"/"Cwvjgpvkecvkqp"Jgcfgt"/
Gpecruwncvkpi"Ugewtkv{"Rc{nqcf"/"Ygd"Ugewtkv{"Eqpukfgtcvkqpu"/"Ugewtg"Uqemgv"Nc{gt"cpf"Vtcpurqtv"Nc{gt
Ugewtkv{"/"Ugewtg"Gngevtqpke"Vtcpucevkqp*UGV+


Content after modification:
Contents:
Pretty Good Privacy - S/MIME - IP Security Overview - IP Security Architecture - Authentication Header -
Encapsulating Security Payload - Web Security Considerations - Secure Socket Layer and Transport Layer
Security - Secure Electronic Transaction(SET)
*/