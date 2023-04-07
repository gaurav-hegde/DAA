/*
1. Make main function to take in input of text and pattern
2. Make a function search with parameters text, pattern and q
3. set m = length of pattern, n = length of text, i, j, p = 0, t = 0, h = 1
4. run a loop to get hash value h = (h * d) % q
5. run a loop to get hash value of pattern p = (d * p + pat[i]) % q and text t = (d * t + txt[i]) % q
6. run a loop (n - m) to check if p == t then run a loop to check if individual characters match
7. if j == m then print the position using i + 1 set flag = 1
8. if i < n-m then set t = (d * (t - txt[i] *h) + txt[i+m]) % q if t < 0 then set t = t + q
*/

#include <bits/stdc++.h>
using namespace std;

#define d 256

int flag = 0;

void search(char pat[], char txt[], int q) {
    int m = strlen(pat);
    int n = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "String found in position " << i + 1 << endl;
                flag = 1;
            }
        }

        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            if (t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {
    char txt[100], pat[100];
    int n, m;
    int q = INT_MAX;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> txt[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> pat[i];
    }

    search(pat, txt, q);
    if (flag == 0) {
        cout << "No match found";
    }
    return 0;
}