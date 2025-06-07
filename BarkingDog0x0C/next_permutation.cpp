#include <bits/stdc++.h>
using namespace std;

int main() {
    int b[3] = {1,2,3};
    int a[5] = {0,0,1,1,1};

    do {
        for (int i = 0; i < 3; i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(b, b+3));

    cout << b[0] << b[1] << b[2];

    cout << '\n';

    do {
        for (int i = 0; i < 5; i++) {
            if (a[i] == 0)
                cout << i+1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(a, a+5));
}