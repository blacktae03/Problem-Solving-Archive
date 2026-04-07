#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, M, T;
    cin >> H >> M;
    cin >> T;

    H = H + (M+T) / 60;
    M = (M+T) % 60;
    H = H % 24;

    cout << H << ' ' << M;
}