// 이게 내가 짠 정답 코드.
// v2 다 시간초과 떠서 다시
// v3는 1024랑 pile 순열이랑 순서 바꿔서 해봐야겠다. ㅈ도 소용없죠?
// v2에서 tilt함수 없애기 전으로 다시 바꿈.
// 1024                 * { (5 * 6 * 50)                    + (120 * 8 * (125 + 125)) } = 247296000 (2억 ㅅㅂ;;)
// 각 판 회전하는 경우의 수         5개의 판에 최대 6번 회전(O == 50)     모든 쌓는 경우의 수(5! = 120)에 각 꼭짓점(8)에서 시작하여 bfs 1번 + 초기화 1번
// 줄일 수 있는 것1                      최대 6번 -> 항상 4번 줄일 수 있음.                                 (4로 줄일 수 있음)        (이건 될라나 ㅅㅂ;)
// 1 -> 123904000 (1억) 와 이렇게 줄이니까 진짜 됐네 시222222발 심지어 걸린 시간도 1312ms 계산한 복잡도랑 거의 똑같애!!!!!
// 참고 : 1억 == 1초 정도 생각하면 됨. 계속 줄이고 줄이다 보면 되긴하는구나
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
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

void tilt(int z) { // 시계방향으로 90도 회전 O(50)
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

// void reverse_tilt(int z) { // 반시계방향으로 90도 회전 O(50)
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
                cin >> brd[i][j][k]; // O(125)
            }
        }
    }
    
    
    for (int i = 0; i < 1024; i++) {
        int brute = i;
        
        for (int j = 0; j < 5; j++) {
            int tmp = brute % 4; // brute & 3 이라고 멋있게 쓸 수도 있음.
            brute /= 4; // brute >>= 2 라고 멋있게 쓸 수도 있음.
            
            for (int k = 0; k < tmp; k++) tilt(j); // tmp가 0이면 회전 x, 1이면 한 번 회전 ...
        }

        do {
            for (int j = 0; j < 5; j += 4) {
                for (int k = 0; k < 5; k += 4) {
                    if (!brd[pile[0]][j][k] || !brd[pile[4]][4-j][4-k]) continue;
                    
                    Q.push({0, j, k});
                    // dist[pile[0]][j][k] = 0;
                    
                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        
                        for (int dir = 0; dir < 6; dir++) {
                            int nx = X + dx[dir];
                            int ny = Y + dy[dir];
                            int nz = Z + dz[dir];
                            
                            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
                            if (!brd[pile[nx]][ny][nz] || dist[pile[nx]][ny][nz] > 0) continue;
                            
                            Q.push({nx, ny, nz});
                            dist[pile[nx]][ny][nz] = dist[pile[X]][Y][Z] + 1;
                        }
                    }
                    
                    if (dist[pile[4]][4-j][4-k]) {
                        if (ans < 0) ans = dist[pile[4]][4-j][4-k];
                        else ans = min(ans, dist[pile[4]][4-j][4-k]);
                    }
                    
                    for (int distx = 0; distx < 5; distx++) {
                        for (int disty = 0; disty < 5; disty++) {
                            fill(dist[distx][disty], dist[distx][disty]+5, 0);
                        }
                    } // 원상복구
                    // 이거를 줄여야하나????? 아 미치겠네 다 줄였는데
                }
            }
        } while (next_permutation(pile, pile+5));

        brute = i;
        
        for (int j = 0; j < 5; j++) {
            int tmp = brute % 4;
            brute /= 4;
            
            for (int k = 0; k < (4-tmp)%4; k++) tilt(j); // 원상복구
        }    
        
    }

    cout << ans;
}