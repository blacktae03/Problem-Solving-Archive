#include <bits/stdc++.h>
using namespace std;

int T, n;
unordered_map<string, int> M[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while(T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;
            if (M[T].find(kind) != M[T].end()) M[T][kind]++;
            else M[T][kind] = 1;
        }

        int ans = 1;
        for (auto p : M[T]) ans *= p.second+1;
        ans--;
        cout << ans << '\n';
    }
}