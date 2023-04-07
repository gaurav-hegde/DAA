#include <bits/stdc++.h>
using namespace std;

int flag = 0;

int* pre_kmp(char pat[]) {
    int size = strlen(pat);
    int* pie = new int[size];
    pie[0] = 0;
    int k = 0;

    for (int i = 1; i < size; i++) {
        while (k > 0 && pat[k] != pat[i]) {
            k = pie[k - 1];
        }

        if (pat[k] == pat[i]) {
            k++;
        }

        pie[i] = k;
    }
    return pie;
}

void kmp(char txt[], int m, char pat[], int n) {
    int* pie = pre_kmp(pat);
    int pos = 0;

    for (int current = 0; current < m; current++) {
        while (pos > 0 && pat[pos] != txt[current]) {
            pos = pie[pos - 1];
        }

        if (pat[pos] == txt[current]) {
            pos++;
        }

        if (pos == n) {
            cout << "Pattern found at position " << current - (n - 2);
            flag = 1;
            pos = pie[pos - 1];
        }
    }
}

int main() {
    int MAX_SIZE = 100;
    int m, n;
    char txt[MAX_SIZE], pat[MAX_SIZE];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> txt[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> pat[i];
    }

    kmp(txt, n, pat, m);

    if (flag == 0) {
        cout << "Pattern not found";
    }

    return 0;
}