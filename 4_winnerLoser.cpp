#include <bits/stdc++.h>
using namespace std;

void findwinner(int a[], int l, int h, int *win, int *worst) {
    int mid;

    if (l == h) {
        *win = l;
        *worst = l;
    } else if (l == h - 1) {
        if (a[l] > a[h]) {
            *win = l;
            *worst = h;
        } else {
            *win = h;
            *worst = l;
        }
    } else {
        mid = (l + h) / 2;

        findwinner(a, l, mid, win, worst);
        int win1 = *win;
        int worst1 = *worst;

        findwinner(a, mid + 1, h, win, worst);
        int win2 = *win;
        int worst2 = *worst;

        if (a[*win] < a[*worst]) {
            *win = win1;
        } else {
            *win = win2;
        }

        if (a[worst1] < a[worst2]) {
            *worst = worst1;
        } else {
            *worst = worst2;
        }
    }
}

int main() {
    int a[100], i, n, win, worst;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    findwinner(a, 0, n - 1, &win, &worst);
    cout << "Winner " << win + 1 << endl;
    cout << "Worst Player " << worst + 1 << endl;
    return 0;
}