#include <bits/stdc++.h>
using namespace std;

int N, M, cantLie;
vector<int> observers, adj[55];
vector<vector<int>> parties;
bool observers_friends[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    cin >> cantLie;

    while (cantLie--) { // 감시자 벡터에 추가 이 사람들이랑 엮인 사람이 있으면 구라 못 침.
        int v; cin >> v;
        observers.push_back(v);
    }

    while (M--) { // 파티 수 만큼 반복 차례대로 간선 하나씩 연결함.
        vector<int> tmp;
        int members; cin >> members;

        members--;
        int v1; cin >> v1;
        tmp.push_back(v1);
        
        while (members--) {
            int v2; cin >> v2;
            tmp.push_back(v2);
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
            v1 = v2;
        }

        parties.push_back(tmp);
    }

    for (auto o : observers) { // 감시자들이랑 엮인 사람들 모두 검출 : 엮인 사람은 다 observers_friends 값을 true로 바꿈.
        queue<int> Q;
        bool vis[55] = {0,};

        Q.push(o);
        observers_friends[o] = true;
        vis[o] = true;

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (auto v : adj[cur]) {
                if (vis[v]) continue;
    
                observers_friends[v] = true;
                vis[v] = true;
                Q.push(v);
            }
        }
    }

    // test output
    // for (int i = 1; i <= N; i++) cout << i << " : " << observers_friends[i] << '\n';

    int ans = 0;

    for (auto party : parties) { // party 마다 다 BFS 돌리면서 한명이라도 observer랑 엮인 사람 있으면 count 하지 않음.
        bool flag = true;
        bool vis[55] = {0,};

        queue<int> Q;
        auto member = party[0];
        Q.push(member);
        vis[member] = true;
        if (observers_friends[member]) flag = false;

        while (flag && !Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (auto part : adj[cur]) {
                if (observers_friends[part]) {
                    flag = false;
                    break;
                }
                if (vis[part]) continue;

                Q.push(part);
                vis[part] = true;
            }
            
            // if (!flag) break;
        }

        // test output
        // cout << "{ ";
        // for (auto mem : party) cout << mem << ' ';
        // cout << "} : " << flag << '\n';

        ans += flag;
    }

    cout << ans;
}