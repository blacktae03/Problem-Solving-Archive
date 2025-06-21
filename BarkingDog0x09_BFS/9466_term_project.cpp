#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while(T--) {
        int c;
        cin >> c;
        c++;

        int brd[c];
        int dist[c];
        int who[c];
        fill(dist, dist+c, -1);
        fill(who, who+c, -1);
        brd[0] = 0;
        

        for (int i = 1; i < c; i++) {
            cin >> brd[i];
        }
        int cnt = 0;
        
        queue<int> Q;

        for (int i = 1; i < c; i++) {
            if (who[i] > 0 || dist[i] > -1) continue;

            Q.push(i);
            who[i] = i;
            dist[i] = 0;

            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();
                int nx = brd[cur];
                
                if (nx < 1 || nx >= c) continue;
                if (dist[nx] > -1) {
                    if (who[nx] == i) cnt += dist[cur] + 1 - dist[nx];
                    continue;
                }
                
                who[nx] = i;
                dist[nx] = dist[cur] + 1;
                Q.push(nx); 
            }

            
        }
        

        cout << c-1-cnt << '\n';
    }
}