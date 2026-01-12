#include <bits/stdc++.h>
using namespace std;

int N, hc, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    N--;
    ans++;

    while(true) {
        if (N <= 0) break;
        hc += 6;
        N -= hc;
        ans++;
    }
    
    cout << ans;
}