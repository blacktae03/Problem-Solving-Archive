#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, string> um;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string site, pass;
        cin >> site >> pass;
        um[site] = pass;
    }

    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;
        cout << um[site] << '\n';
    }
}