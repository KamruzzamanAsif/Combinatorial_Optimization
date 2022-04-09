#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define base 10
#define primeNumber 101

void rabinKarp(char pattern[], char text[]) {

    int m = strlen(pattern);
    int n = strlen(text);

    
    int p = 0; // pattern er hash value er jonno
    int t = 0; // text er(every m char er) has value er jonno
    int offset = 1;


    // calculate the offset value
    for (int i = 0; i < m - 1; i++)
        offset = (offset * base) % primeNumber;


    // Calculate hash value for pattern and text(first m characters)
    for (int i = 0; i < m; i++) {
        p = (base * p + pattern[i]) % primeNumber;
        t = (base * t + text[i]) % primeNumber;
    }


    // Now the main loop to Find the match
    for (int i = 0; i <= n - m; i++) {

        // if the hash values are same then find the similarity char by char
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                break;
            }

            if (j == m){
                cout << "Pattern is found at position: " << i + 1 << endl;
            }   
        }
            
        // calculate the next hash value of the text(tarporer m char er jonno)
        if (i < n - m) {
            t = (base * (t - text[i] * offset) + text[i + m]) % primeNumber;

            // text er hash value jodi negative hoy tahole
            if (t < 0){
                t = (t + primeNumber);
            }
        }
    }
}

int main(void) {

    char text[] = "ABCCDDAEFGCDDAH";
    char pattern[] = "CDD";

    rabinKarp(pattern, text);

    return 0;
}