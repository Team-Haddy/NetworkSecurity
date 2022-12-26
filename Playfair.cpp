#include <bits/stdc++.h>
using namespace std;
void block()
{
    string key;
    char a[5][5], ch;
    cout << "Enter Key : ";
    cin >> key;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int count = 0;
    bool v[25] = {false};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (!v[(int)key[count] - 97] && count < key.length())
            {
                v[(int)key[count] - 97] = true;
                a[i][j] = key[count++];
            }
            else
            {   
                ch='a';
                start:
                if (!v[(int)ch - 97])
                {
                    v[(int)ch - 97] = true;
                    a[i][j] = ch++;
                }
                else{
                    ch++;
                    goto start;
                }
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<a[i][j]<<'\t';
        }
        cout<<'\n';
    }

    string pt;
    cout<<"\n\nEnter the text to be encrypted: ";
    cin>>pt;


    if(pt.length() % 2)
        pt += 'q';

    int r1,r2,c1,c2;
    string enc = pt;
    for(int i=0; i<pt.length(); i+=2){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(a[j][k] == pt[i]){
                    r1=j;
                    c1=k;
                }else if(a[j][k] == pt[i+1]){
                    r2=j; c2=k;
                }
            }
        } 
        if(r1==r2){
            enc[i] = a[r1][(c1+1)%5];
            enc[i+1] = a[r2][(c2+1)%5];
        }

        if(c1==c2){
            enc[i] = a[(r1+1)%5][c1];
            enc[i+1] = a[(r2+1)%5][c2];
        }
        if(r1!=r2 && c1!=c2){
            enc[i]=a[r1][c2];
            enc[i+1]=a[r2][c1];
        }
    }
    cout<<enc<<"\n";
}

int main()
{
    block();
}



/*
OUTPUT:

Enter Key : test
t       e       s       a       b
c       d       f       g       h
i       j       k       l       m
n       o       p       q       r
u       v       w       x       y


Enter the text to be encrypted: hello
dbjapr




Enter Key : monarchy
m       o       n       a       r
c       h       y       b       d
e       f       g       i       j
k       l       p       q       s
t       u       v       w       x


Enter the text to be encrypted: technology
mkhyanuhpg
*/