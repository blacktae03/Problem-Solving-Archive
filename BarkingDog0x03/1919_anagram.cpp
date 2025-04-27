#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    int aphb[26] = {0,};
    int cnt = 0;

    cin >> a >> b;

    for (auto c : a) aphb[c-'a']++;
    for (auto c : b) aphb[c-'a']--;

    for (auto n : aphb) {
        if (n >= 0) cnt += n;
        else cnt -= n;
    }
    
    cout << cnt;
}