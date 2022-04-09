#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100
int prefixArray[N];

void buildPrefixArray(char* pat, int m)
{
	// length of the previous longest prefix suffix
	int len = 0;

	prefixArray[0] = 0; // prefixArray[0] is always 0

	// the loop calculates prefixArray[i] for i = 1 to m-1
	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			len++;
			prefixArray[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = prefixArray[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				prefixArray[i] = 0;
				i++;
			}
		}
	}
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int m = strlen(pat);
	int n = strlen(txt);

	// Preprocess the pattern (calculate lps[] array)
	buildPrefixArray(pat, m);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < n) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == m) {
			printf("Found pattern at index %d \n", i - j);
			j = prefixArray[j - 1];
		}
		// mismatch after j matches
		else if (i <n && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = prefixArray[j - 1];
			else
				i = i + 1;
		}
	}
}


int main(void)
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";

	KMPSearch(pat, txt);

	return 0;
}
