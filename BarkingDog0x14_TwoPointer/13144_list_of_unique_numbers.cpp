#include <bits/stdc++.h>
using namespace std;

long long N, ans;
int A[100010];
bool rec[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    int st = 0, en = 0;
    
    while (st < N) {
        if (rec[A[en]] || en == N) {
            ans += en - st;
            rec[A[st++]] = 0;
        }

        else {
            rec[A[en++]] = 1;
        }
    }

    cout << ans;
}