#include <bits/stdc++.h>
using namespace std;

int N, P, Q;
unordered_map<int, pair<int, int>> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;

    M[N] = {N/P, N/Q};
    int fst = N/P, snd = N/Q;
    while(!fst && !snd) {
        M[fst] = {fst/P, fst/Q};
        M[snd] = {snd/P, snd/Q};
        fst /= P, snd /= Q;
    }

    vector<pair<int, pair<int, int>>> V(M.begin(), M.end());
    sort(V.begin(), V.end());

    for (auto p : V) {
        if(p.second.first == 0) p.second.first = 1;
        if(p.second.second == 0) p.second.second = 1;
        
    }
}