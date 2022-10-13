#include <bits/stdc++.h>
#include<Windows.h>
#define MAX 2
using namespace std;

void waitPrint(string type)
{

    cout << type << " the message";
    for (int i = 0; i < 5; i++)
    {
        Sleep(250 * (i + 1));
        cout << ".";
    }
}

int main()
{
    string pt, key;
    cout << "Enter the message to be encrypted : ";
    cin >> pt;
    int k[MAX][MAX], pMatrix[MAX][pt.length()/MAX];

    if (pt.length() % 2)
        pt += 'z';
    transform(pt.begin(), pt.end(), pt.begin(), ::tolower);

    cout << "Enter the key : ";
    cin >> key;
    int counter = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            k[i][j] = (int)key[counter++]-97;
        }
    }


    cout<<"\n\nPlain text in matrix form: \n";
    counter = 0;
    for(int i=0; i<MAX;i++){
        for(int j=0; j<pt.length()/MAX; j++){
            pMatrix[i][j] = (int) pt[counter++]-97;
            cout<<pMatrix[i][j]<<'\t';
        }
        cout<<'\n';
    }

    int res[MAX][pt.length()/MAX], temp[MAX][pt.length()/MAX];
    for(int i=0; i<MAX; i++){
        for(int j=0; j<pt.length()/2; j++){
            res[i][j] = 0;
            for(int c=0; c<MAX; c++){
                res[i][j] += k[i][c] * pMatrix[c][j];
            }
            temp[i][j] = res[i][j];
            res[i][j] %= 26;
        }
    }

    cout<<"\n\nEncrypted Matrix: \n";
    for(int i=0; i<MAX; i++){
        for(int j=0; j<pt.length()/2; j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n\nEncrypted text: \n";
    for(int i=0; i<MAX; i++)
        for(int j=0; j<pt.length()/2; j++)
            cout<<char(res[i][j]+97);


    int d = (k[0][0]*k[1][1])-(k[0][1]*k[1][0]);
    int adj[MAX][MAX];
    adj[0][0]=k[1][1];
    adj[1][1]=k[0][0];
    adj[0][1]=-k[0][1];
    adj[1][0]=-k[1][0];

    // for(int i=0; i<MAX; i++){
    //     for(int j=0; j<MAX; j++){
    //         adj[i][j] /= d;
    //     }
    // }

    int dres[MAX][pt.length()/MAX];
    for(int i=0; i<MAX; i++){
        for(int j=0; j<pt.length()/2; j++){
            dres[i][j] = 0;
            for(int c=0; c<MAX; c++){
                dres[i][j] += adj[i][c] * temp[c][j];
            }
            dres[i][j] /= d;
        }
    }


    cout<<"\n\nDecrypted Matrix: \n";
    for(int i=0; i<MAX; i++){
        for(int j=0; j<pt.length()/2; j++){
            cout<<dres[i][j]<<"\t";
        }
        cout<<"\n";
    }

    cout<<"\n\nDecrypted Text: \n";
    for(int i=0; i<MAX; i++)
        for(int j=0; j<pt.length()/2; j++)
            cout<<char(dres[i][j]+97);

}