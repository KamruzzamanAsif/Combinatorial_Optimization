#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define inf 1e8
#define N 100
int p[N];
int m[N][N];
int s[N][N];


int lookUpChain(int i, int j){
    if(m[i][j]<inf){
        return m[i][j];
    }

    if(i==j){
        m[i][j]=0;
    }
    else{
        for(int k=i; k<=j-1; k++){
            int q = lookUpChain(i,k)+lookUpChain(k+1,j)+ p[i-1]*p[k]*p[j];
            if(q<m[i][j]){
                m[i][j] = q;
                s[i][j] = k;
            }
        }
    }

    return m[i][j];
}

void printOrder(int i, int j){
    if (i == j) {
        cout << " A" << i << " ";
        return;
	}
	else {
		cout << "(";
		printOrder(i,s[i][j]);
		printOrder(s[i][j] + 1, j);
		cout << ")";
	}

}

int main(void){
    freopen("mcm-memoized.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>p[i];
    
    n = n-1; // n = lengeth(p)-1
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            m[i][j]=inf;
        }
    }

    cout<<"The minimum cost is: "<<lookUpChain(1,n)<<endl;

    cout<<"The optimal multiplicaiton order is: ";
    printOrder(1,n);

    return 0;
}