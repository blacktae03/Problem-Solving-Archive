#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;

    cin >> k;

    for(int i = 1; i <= 2*k-1; i+=2) {
        for(int j = 0; j < k-i/2-1; j++) cout << " ";
        for(int p = 0; p < i; p++) cout << "*";
        cout << '\n';
    }

    for(int i = 2*k-3; i >= 1; i-=2) {
        for(int j = 0; j < k-i/2-1; j++) cout << " ";
        for(int p = 0; p < i; p++) cout << "*";
        cout << '\n';
    }
}