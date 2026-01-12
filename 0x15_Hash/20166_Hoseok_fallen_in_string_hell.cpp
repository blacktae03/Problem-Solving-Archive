#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string brd[13];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
unordered_map<string, unordered_set<string>> um;
string god[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) cin >> brd[i];

    for (int i = 0; i < K; i++) {
        string str; cin >> str;
        god[i] = str;
        um[str].insert({-1, -1});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            // for (int k = 0; k < 4; k++) {
                //     for (int dir = 0; dir < 8; dir++) {
                    //         int nx = i + dx[dir];
                    //         int ny = j + dy[dir];
                    
                    //         if (nx < 0) nx = N-1;
                    //         else if (nx >= N) nx = 0;
                    //         if (ny < 0) ny = N-1;
                    //         else if (ny >= N) ny = 0;
                    
                    //         tmp += brd[i][j];
                    //         if (um.find(tmp) != um.end()) um[tmp]++;
                    
                    //     }
                    // }
                    // int k = 0;
            for (int k = 0; k < 8*8*8*8; k++) {
                string tmp = "";
                string route = "";

                int nx = i, ny = j;
                tmp += brd[nx][ny];
                
                route += '0' + nx;
                route += '0' + ny;
                
                if (um.find(tmp) != um.end()) um[tmp].insert(route);

                int brute = k;
                
                for (int l = 0; l < 4; l++) {
                    int dir = brute % 8;
                    nx += dx[dir];
                    ny += dy[dir];
                    
                    if (nx < 0) nx = N-1;
                    else if (nx >= N) nx = 0;
                    if (ny < 0) ny = M-1;
                    else if (ny >= M) ny = 0;

                    route += '0' + nx;
                    route += '0' + ny;
                    
                    tmp += brd[nx][ny];
                    if (um.find(tmp) != um.end()) um[tmp].insert(route);
                    
                    brute /= 8;
                }
            }
        }
    }

    for (int i = 0; i < K; i++) cout << um[god[i]].size()-1 << '\n';
}