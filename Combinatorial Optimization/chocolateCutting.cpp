#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ninf -1e5

int a[100][100];
int price[100][100];
 
int cutChocolate(int m, int n)
{
    int x=ninf;
    int y=ninf;

    if(a[m][n] > ninf)
        return a[m][n];
 
    for(int i=1; i<=m; i++)
        x=max(x, price[i][n]+cutChocolate(m-i, n));

    for(int i=1; i<=n; i++)
        y=max(y, price[m][i]+cutChocolate(m, n-i));
    
    a[m][n] = max(x, y);
    return a[m][n];
}
 
int main(void){

    freopen("chocolateCutting.txt", "r", stdin);

    int m, n;
    cin>>m>>n;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin>>price[i][j];
        }
    }
   
    for(int i=0; i<=m; i++){
        a[i][0]=0;
    }
        
    for(int i=0; i<=n; i++){
        a[0][i]=0;
    }
        
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            a[i][j]= ninf;
        }
    }

    cout<<"Maximum revenue is: "<<cutChocolate(m, n);

    return 0;
}