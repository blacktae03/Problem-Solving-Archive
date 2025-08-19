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

        if (enterOrLeave == "enter") S.insert(who);
        else S.erase(who);
    }

    // for (auto name : S) V.push_back(name);
    vector<string> ans(S.begin(), S.end()); // 우와 이런 방법이 ㅋㅋ
    sort(V.begin(), V.end(), greater<>());
    for (auto name : V) cout << name << '\n';
}