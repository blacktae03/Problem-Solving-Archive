#include <bits/stdc++.h>
using namespace std;

int N, M;
int C[500050];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C, C+N);

    cin >> M;
    while(M--) {
        int tmp; cin >> tmp;
        cout << binary_search(C, C+N, tmp) << ' ';
    }
}