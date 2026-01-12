#include <bits/stdc++.h>
using namespace std;

int arr[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;

    for (int i = 0; i < N*M; i++) cin >> arr[i];
    for (int i = 0; i < N*M; i++) {
        int tmp; cin >> tmp;
        arr[i] += tmp;
    }
    for (int i = 0; i < N*M; i++) {
        cout << arr[i] << ' ';
        if (i % M == M-1) cout << '\n';
    }
}