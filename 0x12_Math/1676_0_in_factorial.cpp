#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ans += n / 125;
    ans += n / 25;
    ans += n / 5;
    // while(n) {
    //     ans += n/5;
    //     n/=5;
    // } sol : 개크랙이네 ㄷㄷ;
    cout << ans;
}