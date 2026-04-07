#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1000001], b[1000001], c[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    int len = N+M;
    int aidx = 0, bidx = 0;

    for (int i = 0; i < len; i++) {
        if (aidx >= N) c[i] = b[bidx++];
        else if (bidx >= M) c[i] = a[aidx++];
        else c[i] = a[aidx] > b[bidx] ? b[bidx++] : a[aidx++];
        
        cout << c[i] << ' ';
    }
}