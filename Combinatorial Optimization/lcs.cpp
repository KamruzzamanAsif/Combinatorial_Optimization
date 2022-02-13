#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define up 1
#define left 2
#define diagonal 3

int b[100][100]={0};

void lcs(string x, string y, int m, int n){
    int c[m+1][n+1]={0};
    for(int i=0; i<=m; i++) c[i][0]=0;
    for(int j=0; j<=n; j++) c[0][j]=0;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                c[i][j] = 1+c[i-1][j-1];
                b[i][j]=diagonal;
            }
            else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
                if(c[i-1][j]>=c[i][j-1])
                    b[i][j]=up;
                else
                    b[i][j]=left;
            }
        }
    }

    cout<<"LCS length: "<<c[m][n]<<endl;
    return;
}

void printLcs(string x, int i, int j){
    if(i==0 || j==0)
        return ;
    else if(b[i][j]==diagonal){
        printLcs(x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==up){
        printLcs(x,i-1,j);
    }
    else printLcs(x,i,j-1);
}

int main(void){
    freopen("lcs.txt", "r", stdin);
    string x, y;
    cin>>x;
    cin>>y;

    int m = x.length();
    int n = y.length();

    lcs(x,y,m,n);
    cout<<"LCS is: ";
    printLcs(x,m,n);

    return 0;
}