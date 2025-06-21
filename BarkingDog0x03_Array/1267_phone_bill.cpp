#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Y = 0;
    int M = 0;
    int N, Call;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> Call; 
        Y += 10 * (Call / 30 + 1);
        M += 15 * (Call / 60 + 1);
    }

    if (Y < M) cout << "Y " << Y;
    else if (Y > M) cout << "M " << M;
    else cout << "Y M " << Y;

}