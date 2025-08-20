#include <bits/stdc++.h>
using namespace std;

int T, n;
unordered_map<string, unordered_set<string>> M[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while(T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;
            M[T][kind].insert(name);
        }

        int ans = 1;
        for (auto p : M[T]) ans *= p.second.size()+1;
        ans--;
        cout << ans << '\n'; // 아.. 깜빡하고 \n 안넣어서 v2까지 쳐 만들고 자빠졌네 ㅋㅋ
    }
}