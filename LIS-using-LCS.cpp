#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
int a[N]; // input array
int cpy_a[N]; // another array for calculation

// lcs part
#define up 1
#define left 2
#define diagonal 3
int b[100][100]={0};

int duplicateRemover(int m){
    int k=0;
    // remove the duplicates
    for(int i=1; i<m; i++){
        if(cpy_a[i]!=cpy_a[k]){
            cpy_a[++k]=cpy_a[i];
        }
    }
    return ++k;
}

void lisUsingLcs(int m, int n){
    int c[m+1][n+1]={0};
    for(int i=0; i<=m; i++) c[i][0]=0;
    for(int j=0; j<=n; j++) c[0][j]=0;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==cpy_a[j-1]){
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

    cout<<"LIS length: "<<c[m][n]<<endl;
    return;
}

void printLIS(int i, int j){
    if(i==0 || j==0)
        return ;
    else if(b[i][j]==diagonal){
        printLIS(i-1,j-1);
        cout<<a[i-1]<<" ";
    }
    else if(b[i][j]==up){
        printLIS(i-1,j);
    }
    else printLIS(i,j-1);
}

int main(void){
    freopen("lisUsingLcs.txt", "r", stdin);

    int m;
    cin>>m; // taking array size

    for(int i=0; i<m; i++){
        cin>>a[i];
    }

    // copy the array into b
    for(int i=0; i<m; i++){
        cpy_a[i]=a[i];
    }

    sort(cpy_a,cpy_a+m); // sort the b array
    int n = duplicateRemover(m);

    // Now do LCS of a and b
    lisUsingLcs(m,n);

    cout<<"LIS sequence: ";
    printLIS(m,n);

    return 0;
}