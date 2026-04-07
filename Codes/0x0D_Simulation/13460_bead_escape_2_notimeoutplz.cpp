#include <bits/stdc++.h>
using namespace std;

// 아 90프로에서 시간초과 떴다 개자살 마렵네 진짜
// 안뜨게 고쳐보자....... 씹
// 와 tilt 내 반복수 국한으로 줄이고 hole 변수 안쓰니까 통과 와..

int R, C, ans = 11;
string brd[11], brd2[11];

char tilt(int dir) {
    int wall = 0;
    bool hole = 0;
    bool red = 0, blue = 0;

    if (dir == 0) { // 왼쪽으로 기울였을 때
        for (int i = 1; i < R-1; i++) {
            wall = 0;

            for (int j = 1; j < C-1; j++) {
                if (brd[i][j] == '#' || brd[i][j] == 'O') wall = j;

                else if (brd[i][j] == 'R' || brd[i][j] == 'B') {
                    if (brd[i][wall] == 'O') {
                        if (brd[i][j] == 'R') red = 1;
                        else blue = 1;
                    }
                    
                    else {
                        if (++wall == j) continue;
                        else {
                            brd[i][wall] = brd[i][j];
                            brd[i][j] = '.';
                        }

                    }
                }
            }

            if (red && !blue) return 'R';
            if (blue) return 'B';
        }
    }

    if (dir == 1) { // 오른쪽으로 기울였을 때
        for (int i = 1; i < R-1; i++) {
            wall = C-1;
            
            for (int j = C-2; j > 0; j--) {
                if (brd[i][j] == '#' || brd[i][j] == 'O') wall = j;

                else if (brd[i][j] == 'R' || brd[i][j] == 'B') {
                    if (brd[i][wall] == 'O') {
                        if (brd[i][j] == 'R') red = 1;
                        else blue = 1;
                    }
                    
                    else {
                        if (--wall == j) continue;
                        else {
                            brd[i][wall] = brd[i][j];
                            brd[i][j] = '.';
                        }

                    }
                }
            }

            if (red && !blue) return 'R';
            if (blue) return 'B';
        }
    }

    if (dir == 2) { // 위쪽으로 기울였을 때
        for (int i = 1; i < C-1; i++) {
            wall = 0;

            for (int j = 1; j < R-1; j++) {
                if (brd[j][i] == '#' || brd[j][i] == 'O') wall = j;

                else if (brd[j][i] == 'R' || brd[j][i] == 'B') {
                    if (brd[wall][i] == 'O') {
                        if (brd[j][i] == 'R') red = 1;
                        else blue = 1;
                    }
                    
                    else {
                        
                        if (++wall == j) continue;
                        else {
                            brd[wall][i] = brd[j][i];
                            brd[j][i] = '.';
                        }

                    }
                }
            }

            if (red && !blue) return 'R';
            if (blue) return 'B';
        }
    }

    if (dir == 3) { // 아래쪽으로 기울였을 때
        for (int i = 1; i < C-1; i++) {
            wall = R-1;

            for (int j = R-2; j > 0; j--) {
                if (brd[j][i] == '#' || brd[j][i] == 'O') wall = j;

                else if (brd[j][i] == 'R' || brd[j][i] == 'B') {
                    if (brd[wall][i] == 'O') {
                        if (brd[j][i] == 'R') red = 1;
                        else blue = 1;
                    }
                    
                    else {
                        
                        if (--wall == j) continue;
                        else {
                            brd[wall][i] = brd[j][i];
                            brd[j][i] = '.';
                        }

                    }
                }
            }

            if (red && !blue) return 'R';
            if (blue) return 'B';
        }
    }

    return 0;
}
// 왼쪽으로 기울이기를 기준으로 움직이는 방법 :
// 1. 각 행 마다 벽이나 구멍이 등장하면 벽의 열 좌표를 저장. (구멍이 등장하면 hole = true)
// 2. 구슬을 발견하면 그 구슬을 벽 좌표 다음 위치로 이동
// 3. 그 구슬의 좌표를 다시 벽 좌표로 업데이트 (구슬이 같은 행에 위치할 경우 구슬도 벽의 역할을 하기 때문)
// 4. 4^10 == 1048576 번 반복 * 64 * 10 = 10억인데? 아 ㅈ댓다...
// + 굳이 회전 시키지 말고 그냥 곧이 곧대로 구현해보자. 회전하는 게 더 시간 복잡도나 직사각형일 때 구현도 복잡해지는 듯.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        cin >> brd2[i];
    }

    for (int T = 0; T < 1<<(2*10); T++) {
        int brute = T;

        for (int i = 0; i < R; i++) {
            brd[i] = brd2[i];
        }

        for (int i = 1; i <= 10; i++) {
            int dir = brute % 4;
            brute /= 4;

            char suc = tilt(dir);

            if (suc == 'R') ans = min(ans, i);
            if (suc != 0) break;
        }
    }

    if (ans > 10) cout << -1;
    else cout << ans;
}