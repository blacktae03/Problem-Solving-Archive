#include <bits/stdc++.h>
using namespace std;

int E, S, M, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> E >> S >> M;

    for (int i = E; true; i += 15) {
        int Sn = i % 28 ? i % 28 : 28;
        int Mn = i % 19 ? i % 19 : 19;

        if (Sn == S && Mn == M) {
            cout << i;
            return 0;
        }
    }
}