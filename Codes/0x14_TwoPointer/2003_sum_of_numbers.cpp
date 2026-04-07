#include <bits/stdc++.h>
using namespace std;

unsigned int N, M, ans;
int A[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    int st = 0, en = 0;
    int sum = 0;

    while(en < N || sum >= M) {
        if (sum >= M) {
            if (sum == M) ans++;
            sum -= A[st++];
        }
        else sum += A[en++];
    }

    cout << ans;
}