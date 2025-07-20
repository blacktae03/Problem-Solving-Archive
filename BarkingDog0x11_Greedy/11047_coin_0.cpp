#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[13];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int Ncopy = N;
    while(N--) cin >> A[N];

    for (int i = 0; i < Ncopy; i++) {
        while(K >= A[i]) {
            ans++;
            K -= A[i];
        }
    }

    cout << ans;
}