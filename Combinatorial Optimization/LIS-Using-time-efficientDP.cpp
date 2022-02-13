#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
#define ninf -100
int a[N];
vector<int> L;
int L_index[N];
int previous[N];

void timeEfficientDP(int n){
    L_index[0] = -1;
    previous[0] = -1;
    L.push_back(ninf);

    for(int i=1; i<=n; i++){
        if(L.back()< a[i]){
            L.push_back(a[i]);
            L_index[L.size()-1] = i;  // L length is size-1 as we take index 0 as base case(-1)
            previous[i] = L_index[L.size()-2]; // so lenth er previous hobe size-2
        }
        else{
            int s=0, h=L.size(), m;
            while(s<h){
                m = (s+h)/2;
                if(L[m]<a[i]){
                    s = m+1;
                }
                else{
                    h = m;
                }
            }
            L[s]=a[i];
            L_index[s] = i;
            previous[i] = L_index[s-1]; 
        }
    }

    return;
}

void printLIS(int n){
   if(previous[n] == -1){
       cout<<a[n]<<" ";
       return;
   }
   printLIS(previous[n]);
   cout<<a[n]<<" ";
}

int main(void){
    freopen("lisUsingTimeEfficientDP.txt", "r", stdin);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>a[i];
    
    timeEfficientDP(n);
    cout<<"LIS length is: "<<L.size()-1<<endl; // L length is size-1 as we take index 0 as base case(-1)
    cout<<"LIS sequence is: ";
    printLIS(n);

    return 0;
}