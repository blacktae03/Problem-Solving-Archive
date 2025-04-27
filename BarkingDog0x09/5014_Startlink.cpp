#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    D *= -1;
    
    int bldg[F+1];
    fill (bldg, bldg+F+1, -1);
    
    queue<int> Q;
    Q.push(S);
    bldg[S] = 0;
    int dx[2] = {U, D};
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        for (int k = 0; k < 2; k++) {
            int nx = cur + dx[k];
            
            if (nx < 1 || nx > F) continue;
            if (bldg[nx] >= 0) continue;
            
            bldg[nx] = bldg[cur] + 1;
            Q.push(nx);
        }
    }
    if (bldg[G] >= 0) cout << bldg[G];
    else cout << "use the stairs";
}