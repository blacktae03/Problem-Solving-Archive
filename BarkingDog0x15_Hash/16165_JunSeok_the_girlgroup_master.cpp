#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, vector<string>> G;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while(N--) {
        string grp; cin >> grp;
        int mbr; cin >> mbr;
        while (mbr--) {
            string who; cin >> who;
            G[grp].push_back(who);
        }
        sort(G[grp].begin(), G[grp].end());
    }

    while(M--) {
        string whoOrWhere; cin >> whoOrWhere;
        bool kind; cin >> kind;

        if (!kind) {
            for (string name : G[whoOrWhere]) cout << name << '\n';
        }
        else {
            for (auto p : G) {
                if (find(p.second.begin(), p.second.end(), whoOrWhere) != p.second.end()) {
                    cout << p.first << '\n';
                    break;
                }
            }
        }
    }
}