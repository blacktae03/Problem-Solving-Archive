#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> D[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N == 1) {cout << 0 << ' ' << 1; return 0;}
    
    D[2] = {1, 1};
    D[3] = {1, 1};

    for (int i = 4; i <= N; i++) {
        D[i] = {D[i-1].first+1, i-1}; 
        if (i % 3 == 0 && D[i/3].first < D[i].first-1) D[i] = {D[i/3].first+1, i/3};
        if (i % 2 == 0 && D[i/2].first < D[i].first-1) D[i] = {D[i/2].first+1, i/2};
    }

    cout << D[N].first << '\n';

    while(N > 1) {
        cout << N << ' ';
        N = D[N].second;
    }
    cout << N;
}