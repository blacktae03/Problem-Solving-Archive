#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;

    cin >> k;

    for(int i = 1; i <= k; i++) {
        for(int p = 0; p < i; p++) cout << "*";
        for(int j = 0; j < 2*(k-i); j++) cout << " ";
        for(int p = 0; p < i; p++) cout << "*";
        cout << '\n';
    }

    for(int i = k-1; i >= 1; i--) {
        for(int p = 0; p < i; p++) cout << "*";
        for(int j = 0; j < 2*(k-i); j++) cout << " ";
        for(int p = 0; p < i; p++) cout << "*";
        cout << '\n';
    }
}