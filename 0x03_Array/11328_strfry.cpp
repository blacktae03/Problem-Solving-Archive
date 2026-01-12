#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    bool pos = true;
    string a, b;
    int aphb[26] = {0,};

    cin >> N;

    for (int i = 0; i < N; i ++) {
        pos = true;
        int aphb[26] = {0,};
        cin >> a >> b;
        for (auto c:a) aphb[c-'a']++;
        for (auto c:b) aphb[c-'a']--;
        for (auto n : aphb) if (n!=0) pos = false;

        if (pos) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}