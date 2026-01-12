#include <bits/stdc++.h>
using namespace std;

int N;
int need[6];
int T, S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < 6; i++) cin >> need[i];

    cin >> T >> S;

    int tcnt = 0;

    for (int i = 0; i < 6; i++) {
        tcnt += need[i] / T;
        if (need[i] % T) tcnt++;
    }
    
    cout << tcnt << '\n' << N/S << ' ' << N%S;

    
}