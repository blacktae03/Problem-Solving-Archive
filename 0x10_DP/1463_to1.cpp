#include <bits/stdc++.h>
using namespace std;

int D[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        int dtmp = 1000000000;

        if (!(i%3)) dtmp = min(dtmp, D[i/3] + 1);
        if (!(i%2)) dtmp = min(dtmp, D[i/2] + 1);
        dtmp = min(dtmp, D[i-1] + 1);

        D[i] = dtmp;
    }

    cout << D[N];
}