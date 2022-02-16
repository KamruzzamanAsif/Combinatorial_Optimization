#include <iostream>
using namespace std;

// this function will just return if there exist at least one subset
// that's sum is equal to given sum.
// [NOTE: This program won't print all possible subsets]
bool isSubsetSum(int set[], int n, int sum)
{
	bool subset[n + 1][sum + 1];

	// Base case: when sum is 0, the answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;


	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Table filling in bottom up approach
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
		}
	}

	return subset[n][sum];  // return the last element(true/false) of the table
}


int main()
{
    freopen("sumOfSubsets.txt", "r", stdin);
    int n, sum;
    cin>>n>>sum;

	int set[n];
    for(int i=0; i<n; i++)
        cin>>set[i];

	if (isSubsetSum(set, n, sum) == true)
		cout <<"Yes! a subset/ some subsets exists with given sum";
	else
		cout <<"No! no subset exists with given sum";
	return 0;
}

