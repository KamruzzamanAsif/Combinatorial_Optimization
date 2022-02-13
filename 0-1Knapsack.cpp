#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N=100;
int weight[N];
int value[N];
int d[N][N];


int main(void){
    freopen("0-1Knapsack.txt", "r", stdin);
    int n, W;
    cin>>n>>W;

    for(int i=1; i<=n; i++){
        cin>>weight[i]>>value[i];
    }

    for(int i=0; i<=n; i++){
        d[i][0]=0;
    }

    for(int j=0; j<=W; j++){
        d[0][j]=0;
    }

    for(int i=1; i<=n; i++){
        for(int w=1; w<=W; w++){
            if(weight[i]>w){
                d[i][w] = d[i-1][w];
            }
            else{
                d[i][w] = max(value[i]+d[i-1][w-weight[i]], d[i-1][w]);
                
            }
        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<d[n][W];

    return 0;
}