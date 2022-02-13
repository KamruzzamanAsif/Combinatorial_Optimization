#include <bits/stdc++.h>
#include<iostream>
using namespace std;

const int minf = -1e8;
const int N=100;
int r[N], s[N];

void cutRod(int p[], int n){
    r[0]=0;
    for(int j=1; j<=n; j++){
        int q = minf;
        for(int i=1; i<=j; i++){
            if(q<p[i]+r[j-i]){
                q=p[i]+r[j-i];
                s[j]=i;
            }
            r[j]=q;
        }
    }
}

void printSolution(int p[], int n){
    int max_p=0;
    cout<<"The optimal cutting lengths of a rod of length "<<n<<" are: "<<endl;
    while(n>0){
        cout<<"one length of "<<s[n]<<" "<<" ->>> price: "<<p[s[n]]<<endl;
        max_p += p[s[n]];
        n= n-s[n];
    }
    cout<<"->>>Total maximum price: "<<max_p<<endl;
}

int main(){
    int n;
    freopen("rodCutting.txt", "r", stdin);
    cin>>n;
    int price[n+1];

    for(int i=1; i<=n; i++)
        cin>>price[i];
    
    cutRod(price,n);
    printSolution(price,n);

    return 0;
}