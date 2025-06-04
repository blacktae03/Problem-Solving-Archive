// 시간초과 떠서 다시

#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define Z get<2>(cur)

bool brd[5][5][5];
int dist[5][5][5]; // 0으로 초기화 된 상태에서 별도로 무언가를 하지 않기 때문에 시작점에 한 번 더 들어가기는 하나, 미묘한 차이라서 그냥 놔둠. -1로 초기화하는 게 bfs의 관점에서만 바라보면 더 안전한 방법임.
queue<tuple<int, int, int>> Q;
int ans = -1;
int pile[5] = {0, 1, 2, 3, 4};
int tilt[5];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
int idx[4][5][5] =
{
    {
        { 0, 1, 2, 3, 4 },
        { 5, 6, 7, 8, 9 },
        { 10, 11, 12, 13, 14 },
        { 15, 16, 17, 18, 19 },
        { 20, 21, 22, 23, 24 }
    },
    {
        { 20, 15, 10, 5, 0 },
        { 21, 16, 11, 6, 1 },
        { 22, 17, 12, 7, 2 },
        { 23, 18, 13, 8, 3 },
        { 24, 19, 14, 9, 4 }
    },
    {
        { 24, 23, 22, 21, 20 },
        { 19, 18, 17, 16, 15 },
        { 14, 13, 12, 11, 10 },
        { 9, 8, 7, 6, 5 },
        { 4, 3, 2, 1, 0 }
    },
    {
        { 4, 9, 14, 19, 24 },
        { 3, 8, 13, 18, 23 },
        { 2, 7, 12, 17, 22 },
        { 1, 6, 11, 16, 21 },
        { 0, 5, 10, 15, 20 }
    }
}; // idx[tilt[i]][j][k] / 5 , 


// void tilt(int z) { // 시계방향으로 90도 회전
//     bool dummy[5][5];

//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             dummy[j][4-i] = brd[z][i][j];
//         }
//     }

//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             brd[z][i][j] = dummy[i][j];
//         }
//     }
// }

// void reverse_tilt(int z) { // 반시계방향으로 90도 회전
//     bool dummy[5][5];

//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             dummy[4-j][i] = brd[z][i][j];
//         }
//     }

//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             brd[z][i][j] = dummy[i][j];
//         }
//     }
// }


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
        // for (int j = 0; j < 5; j++) {
        //     for (int k = 0; k < 5; k++) {
        //         for (int l = 0; l < 5; l++) {
        //             brd2[j][k][l] = brd[j][k][l]; // brd2에 원래 주어진 미로 복사.
        //         }
        //     }
        // } 이것도 줄여볼까... 이래도 안되네

        int brute = i;
        
        for (int j = 0; j < 5; j++) {
            tilt[j] = brute % 4;
            brute /= 4;
            
            // for (int k = 0; k < tmp; k++) tilt(j); // tmp가 0이면 회전 x, 1이면 한 번 회전 ...
        } // tilt를 없애야하는 지경에 이르렀네;;
        
        do { // 쌓는 경우의 수
            // for (int xx = 0; xx < 5; xx++) {
            //     for (int j = 0; j < 5; j++) {
            //         for (int k = 0; k < 5; k++) {
            //             brd3[xx][j][k] = brd2[pile[xx]][j][k]; // 쌓는 경우의 수에 따라 다르게 brd3에 복사하기
            //         }
            //     }
            // } 왜 없애도 똑같지..
            
            for (int xx = 0; xx < 5; xx += 4) {
                for (int j = 0; j < 5; j += 4) {
                    for (int k = 0; k < 5; k += 4) {
                        if (!brd[pile[xx]][idx[tilt[pile[xx]]][j][k]/5][idx[tilt[pile[xx]]][j][k]%5] || !brd[pile[4-xx]][idx[tilt[pile[4-xx]]][4-j][4-k]/5][idx[tilt[pile[4-xx]]][4-j][4-k]%5]) continue;
                        
                        Q.push({xx, j, k});
                        dist[pile[xx]][idx[tilt[pile[xx]]][j][k]/5][idx[tilt[pile[xx]]][j][k]%5] = 0;
                        
                        while(!Q.empty()) {
                            auto cur = Q.front(); Q.pop();
                            
                            for (int dir = 0; dir < 6; dir++) {
                                int nx = X + dx[dir];
                                int ny = Y + dy[dir];
                                int nz = Z + dz[dir];
                                
                                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
                                if (!brd[pile[nx]][idx[tilt[pile[nx]]][ny][nz]/5][idx[tilt[pile[nx]]][ny][nz]%5] || dist[pile[nx]][idx[tilt[pile[nx]]][ny][nz]/5][idx[tilt[pile[nx]]][ny][nz]%5] > 0) continue;
                                
                                Q.push({nx, ny, nz});
                                dist[pile[nx]][idx[tilt[pile[nx]]][ny][nz]/5][idx[tilt[pile[nx]]][ny][nz]%5] = dist[pile[X]][idx[tilt[pile[X]]][Y][Z]/5][idx[tilt[pile[X]]][Y][Z]%5] + 1;
                            }
                        }
                        
                        if (dist[pile[4-xx]][idx[tilt[pile[4-xx]]][4-j][4-k]/5][idx[tilt[pile[4-xx]]][4-j][4-k]%5]) {
                            if (ans < 0) ans = dist[pile[4-xx]][idx[tilt[pile[4-xx]]][4-j][4-k]/5][idx[tilt[pile[4-xx]]][4-j][4-k]%5];
                            else ans = min(ans, dist[pile[4-xx]][idx[tilt[pile[4-xx]]][4-j][4-k]/5][idx[tilt[pile[4-xx]]][4-j][4-k]%5]);
                        }
                        
                        for (int distx = 0; distx < 5; distx++) {
                            for (int disty = 0; disty < 5; disty++) {
                                fill(dist[distx][disty], dist[distx][disty]+5, 0);
                            }
                        } // 원상복구
                        // 이거를 줄여야하나????? 아 미치겠네 다 줄였는데
                    }
                }
            }
            
        } while (next_permutation(pile, pile+5)); // bfs 쓰면서 미로 되는지, 최단거리 되는지 판단하기.
        
        for (int j = 0; j < 5; j++) pile[j] = j;// 원상복구

        // brute = i;
        
        // for (int j = 0; j < 5; j++) {
        //     int tmp = brute % 4;
        //     brute /= 4;
            
        //     for (int k = 0; k < tmp; k++) reverse_tilt(j); // 원상복구
        // }    
    }

    cout << ans;
}