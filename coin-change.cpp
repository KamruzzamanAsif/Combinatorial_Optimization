#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
#define inf 1e8
int coins[N];
int d[N];

// bottom up approach
int findMinimumCoins(int n, int k)
{
    d[0] = 0; // base case
    for(int i=1; i<=n; i++)
        d[i] = inf;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(coins[j] <= i)
            {
                d[i] = min(d[i], 1 + d[i - coins[j]]);
            }
        }
    }

    return d[n];
}

int main() {
  freopen("coinChange.txt", "r", stdin);
  int n;
  cin>>n;
  int k;
  cin>>k;

  for(int i=0; i<n; i++)
    cin>>coins[i];
  
  cout<<"The minimum coins needed is: "<<findMinimumCoins(k,n);

  return 0;
}