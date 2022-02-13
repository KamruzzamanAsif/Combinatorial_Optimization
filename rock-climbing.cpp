#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
#define inf 1e8
int c[N][N];
int a[N][N];
int n, m;

void printPath(int i, int j){
    if(i==0 || j==0 || j==m+1)
        return;

    if(a[i-1][j-1]<=a[i-1][j] && a[i-1][j-1]<=a[i-1][j+1])
        printPath(i-1, j-1);
    else if(a[i-1][j]<=a[i-1][j-1] && a[i-1][j]<=a[i-1][j+1])
        printPath(i-1, j);
    else if(a[i-1][j+1]<=a[i-1][j-1] && a[i-1][j+1]<=a[i-1][j])
        printPath(i-1, j+1);
    
    cout<<c[i][j]<<" ";
}

void rockClimbing(){
    for(int j=0; j<=m; j++)
        a[0][j]=0;
    
    for(int i=0; i<=n; i++){
        a[i][0]= inf;
        a[i][m+1]= inf;
    }
    
    // bottom up approach
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j]=c[i][j]+min(a[i-1][j-1], min(a[i-1][j],a[i-1][j+1]));
        }
    }

    // now take the minimum value from the top level and
    // using its index print the path
    int index = 1;
    int temp = a[n][1];
    for(int j=2; j<=m; j++){
        if(a[n][j]<temp){
            temp = a[n][j];
            index = j;
        }
    }
    cout<<"The best path is: ";
    printPath(n, index);

    return;
}

int main(void){
    freopen("rockClimbing.txt", "r", stdin);
    
    //int n, m; are made global
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>c[i][j];
        }
    }

    rockClimbing();

    return 0;
}