#include <bits/stdc++.h>
using namespace std;

int N;
unordered_set<string> S;
vector<string> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string who, enterOrLeave;
        cin >> who >> enterOrLeave;

        if (enterOrLeave == "enter") V.push_back(who);
        else V.erase(remove(V.begin(), V.end(), who), V.end());
    }

    // for (auto name : S) V.push_back(name);

    sort(V.begin(), V.end(), greater<>());

    for (auto name : V) cout << name << '\n';
}
// 시간초과 뜨네 ㄷㄷ;