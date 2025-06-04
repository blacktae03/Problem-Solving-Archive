#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define Z get<2>(cur)

bool brd[5][5][5], brd2[5][5][5], brd3[5][5][5];
int dist[5][5][5];
queue<tuple<int, int, int>> Q;
int ans = -1;
int pile[5] = {0, 1, 2, 3, 4};
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

void tilt(int z) { // 시계방향으로 90도 회전
    bool dummy[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dummy[j][4-i] = brd2[z][i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            brd2[z][i][j] = dummy[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> brd[i][j][k];
            }
        }
    }
    
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) {
                    brd2[j][k][l] = brd[j][k][l]; // brd2에 원래 주어진 미로 복사.
                }
            }
        }

        int brute = i;
        
        for (int j = 0; j < 5; j++) {
            int tmp = brute % 4;
            brute /= 4;
            
            for (int k = 0; k < tmp; k++) tilt(j); // tmp가 0이면 회전 x, 1이면 한 번 회전 ...
        }
        
        do { // 쌓는 경우의 수
            for (int xx = 0; xx < 5; xx++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        brd3[xx][j][k] = brd2[pile[xx]][j][k]; // 쌓는 경우의 수에 따라 다르게 brd3에 복사하기
                    }
                }
            }
            
            for (int xx = 0; xx < 5; xx += 4) {
                for (int j = 0; j < 5; j += 4) {
                    for (int k = 0; k < 5; k += 4) {
                        if (!brd3[xx][j][k] || !brd3[4-xx][4-j][4-k]) continue;
                        
                        Q.push({xx, j, k});
                        
                        while(!Q.empty()) {
                            auto cur = Q.front(); Q.pop();
                            
                            for (int dir = 0; dir < 6; dir++) {
                                int nx = X + dx[dir];
                                int ny = Y + dy[dir];
                                int nz = Z + dz[dir];
                                
                                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
                                if (!brd3[nx][ny][nz] || dist[nx][ny][nz] > 0) continue;
                                
                                Q.push({nx, ny, nz});
                                dist[nx][ny][nz] = dist[X][Y][Z] + 1;
                            }
                        }
                        
                        if (dist[4-xx][4-j][4-k]) {
                            if (ans < 0) ans = dist[4-xx][4-j][4-k];
                            else ans = min(ans, dist[4-xx][4-j][4-k]);
                        }

                        for (int distx = 0; distx < 5; distx++) {
                            for (int disty = 0; disty < 5; disty++) {
                                fill(dist[distx][disty], dist[distx][disty]+5, 0);
                            }
                        } // 원상복구
                    }
                }
            }
            
        } while (next_permutation(pile, pile+5)); // bfs 쓰면서 미로 되는지, 최단거리 되는지 판단하기.

        for (int j = 0; j < 5; j++) {
            pile[j] = j;
            for (int k = 0; k < 5; k++) {
                fill(dist[j][k], dist[j][k]+5, 0);
            }
        } // 원상복구
    }

    cout << ans;
}