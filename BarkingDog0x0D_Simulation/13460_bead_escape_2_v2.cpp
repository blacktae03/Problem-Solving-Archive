// 2048 hard도 이런 방식으로 하면 되지 않을까 싶네요
#include <bits/stdc++.h>
using namespace std;

int r, c, ans = 11;
string brd[11];
pair<int, int> idx[4][11][11];
queue<char> bead;

char play(int tilt) {
    bool esc = 0;
    if (tilt % 2) swap(r,c);
    for (int i = 1; i < r-1; i++) { // 100
        bool warning = 0;
        for (int j = 1; j < c; j++) {
            int wall = 0;
            
            if (brd[idx[tilt][i][j].first][idx[tilt][i][j].second] == 'O') warning = 1;
            
            if (brd[idx[tilt][i][j].first][idx[tilt][i][j].second] == '#') {
                int put = 1;
                while(!bead.empty()) {
                    char cur = bead.front(); bead.pop();
                    if (warning) {
                        if (cur == 'B') return 'B';
                        else esc = 1;
                    }
                    brd[idx[tilt][i][wall+put].first][idx[tilt][i][wall+put].second] = cur;
                    put++;
                }
                if (esc) return 'R';
                wall = j;
            }
            
            else if (brd[idx[tilt][i][j].first][idx[tilt][i][j].second] == 'R' || brd[idx[tilt][i][j].first][idx[tilt][i][j].second] == 'B') {
                bead.push(brd[idx[tilt][i][j].first][idx[tilt][i][j].second]);
                brd[idx[tilt][i][j].first][idx[tilt][i][j].second] = '.';
            }
        }
    }
    
    if (tilt % 2) swap(r,c);
    

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> brd[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            idx[0][i][j] = {i, j};
            idx[1][j][r-1-i] = {i, j};
            idx[2][r-1-i][c-1-j] = {i, j};
            idx[3][c-1-j][i] = {i, j};
        }
    }

    for (int tmp = 0; tmp < 1<<(2*10); tmp++) { // 1<<2*10 == 4^10 == 1048576
        char win = 0;
        int brute = tmp;
        
        for (int tmp2 = 0; tmp2 < 10; tmp2++) { // 1048576 * 10 * 500
            int tilt = brute % 4;
            brute /= 4;

            win = play(tilt);

            if (win == 'R') ans = min(ans, tmp2+1);
            if (win != 0) break;
        }
    }

    cout << ans;

    // 왼쪽으로 기울인다면, 첫번째 행 가장 왼쪽부터 살핀다. 벽이면, 그 좌표를 임시로 저장한다. 구슬이라면, 그 좌표 또한 따로 저장한다. 또다른 벽이 나오면, 벽 좌표는 초기화한다. 초기화하기 전에, 이미 저장된 구슬 좌표들을 벽 바로 옆으로 밀어준다.
    // 그 구슬의 열이 오기 직전까지 살피면서 벽이나 구슬을 발견하면 limit 변수에다가 그 좌표를 넣는다.
    // 그 좌표+1에 구슬을 넣는다.
}