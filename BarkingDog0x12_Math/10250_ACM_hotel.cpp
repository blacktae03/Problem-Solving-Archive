#include <bits/stdc++.h>
using namespace std;

int T, H, W, N;
int F, D;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> H >> W >> N;

        F = (N-1) % H + 1;
        D = (N-1) / H + 1;
        cout << F << setw(2) << setfill('0') << D << '\n';
        // printf("%d%02d\n", F, D);
    }
}