#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
int a[N];
int lis[N];
int previous[N];

void printLIS_length(int max_length){   
    cout<<"LIS length is: "<<max_length<<endl;   
}

void printLIS_sequence(int x){
    if(previous[x]==-1) return;
    printLIS_sequence(previous[x]);
    cout<<a[x]<<" ";
    return;
}

void LIS_naiveDP(int n){
    //initialization
    a[0]=0;
    lis[n]={0};
    previous[0]=-1;

    int max_length = 0;
    int max_index = 0;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(a[i]>a[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
                previous[i]=j;
            }
        }
        if(lis[i]>max_length){
            max_length = lis[i];
            max_index = i;
        }
    }

    printLIS_length(max_length);
    cout<<"LIS sequence: ";
    printLIS_sequence(max_index);

    return;
}


int main(void){
    freopen("lisUsingNaiveDP.txt", "r", stdin);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>a[i];
    

    LIS_naiveDP(n);

    return 0;
}