// v2 다 시간초과 떠서 다시
// v3는 1024랑 pile 순열이랑 순서 바꿔서 해봐야겠다. ㅈ도 소용없죠?
// v2에서 tilt함수 없애기 전으로 다시 바꿈.
// v4는 tilt 하나로 기울기 다 처리 + perm 추가 해봄.. 이것도 아님.
// 지금 상황 정답에 제일 가까운건 v3.

#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define Z get<2>(cur)

bool brd[5][5][5];
int dist[1024*120][5][5][5]; // 0으로 초기화 된 상태에서 별도로 무언가를 하지 않기 때문에 시작점에 한 번 더 들어가기는 하나, 미묘한 차이라서 그냥 놔둠. -1로 초기화하는 게 bfs의 관점에서만 바라보면 더 안전한 방법임.
// 아니 근데 이렇게 하면 어차피 다 0으로 초기화하는 시간복잡도랑 다시 초기화하는 시간복잡도랑 같아서 의미 없을 거 같긴함.
queue<tuple<int, int, int>> Q;
int ans = -1;
int pile[5] = {0, 1, 2, 3, 4};
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
int perm = -1;

void tilt(int z) { // 시계방향으로 90도 회전
    bool dummy[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dummy[j][4-i] = brd[z][i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            brd[z][i][j] = dummy[i][j];
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
        int brute = i;
        
        for (int j = 0; j < 5; j++) {
            int tmp = brute % 4;
            brute /= 4;
            
            for (int k = 0; k < tmp; k++) tilt(j); // tmp가 0이면 회전 x, 1이면 한 번 회전 ...
        }

        do {
            perm++;
            // if (perm == 1024*120 - 1) cout << perm << '\n'; // 다 도는뎅;;
            for (int j = 0; j < 5; j += 4) {
                for (int k = 0; k < 5; k += 4) {
                    if (!brd[pile[0]][j][k] || !brd[pile[4]][4-j][4-k]) continue;
                    
                    Q.push({0, j, k});
                    
                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        
                        for (int dir = 0; dir < 6; dir++) {
                            int nx = X + dx[dir];
                            int ny = Y + dy[dir];
                            int nz = Z + dz[dir];
                            
                            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
                            if (!brd[pile[nx]][ny][nz] || dist[perm][pile[nx]][ny][nz] > 0) continue;
                            
                            Q.push({nx, ny, nz});
                            dist[perm][pile[nx]][ny][nz] = dist[perm][pile[X]][Y][Z] + 1;
                        }
                    }
                    
                    if (dist[perm][pile[4]][4-j][4-k]) {
                        if (ans < 0) ans = dist[perm][pile[4]][4-j][4-k];
                        else ans = min(ans, dist[perm][pile[4]][4-j][4-k]);
                    }
                    
                    // for (int distx = 0; distx < 5; distx++) {
                    //     for (int disty = 0; disty < 5; disty++) {
                    //         fill(dist[distx][disty], dist[distx][disty]+5, 0);
                    //     }
                    // } // 원상복구
                    // // 이거를 줄여야하나????? 아 미치겠네 다 줄였는데
                }   
            }
        } while (next_permutation(pile, pile+5));

        brute = i;
        
        for (int j = 0; j < 5; j++) {
            int tmp = brute % 4;
            brute /= 4;
            pile[j] = j;// 원상복구
            if(tmp == 0) continue;
            for (int k = 0; k < 4-tmp; k++) tilt(j); // 원상복구
        }    
        
    }

    cout << ans;
}