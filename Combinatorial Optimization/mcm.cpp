#include<bits/stdc++.h>
using namespace std;

const int N = 500;
const int INF = 1e9 +5;

int s [N][N];
int m [N][N];

int mcm(int p[],int n){
	n--;
	for (int i=1;i<=n;i++){
		m[i][i] = 0;
	}
	
	for (int l=2;l<=n;l++){
		for (int i=1;i<=n-l+1;i++){
			int j = i + l - 1;
			m[i][j] = INF;
			for (int k=i; k<=j-1; k++){
				int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if ( q < m[i][j] ){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

    return m[1][n];
}

void print_optimal_path(int i, int j){
	if (i == j) {
		cout << " A" << i;
		return;
	}
	else {
		cout << "(";
		print_optimal_path(i,s[i][j]);
		print_optimal_path(s[i][j] + 1, j);
		cout << ")";
	}
}
		
int main (){
    freopen("mcm.txt", "r", stdin);

	int n;
	cin>> n;
	int p[n];
	
	for (int i=0;i<n;i++) cin >> p[i];
	
	cout<<"The minimum cost is:" <<mcm(p,n)<<endl;
	
    cout<<"The order is: ";
    print_optimal_path(1,n-1);
	
    return 0;
}
