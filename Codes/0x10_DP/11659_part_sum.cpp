#include <bits/stdc++.h>
using namespace std;

int D[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int M; cin >> M;

    for (int i = 1; i <= N; i++) {
        int tmp; cin >> tmp;
        D[i] = D[i-1] + tmp;
    }

    for (int i = 1; i <= M; i++) {
        int st, en; cin >> st >> en;
        cout << D[en] - D[st-1] << '\n';
    }
}