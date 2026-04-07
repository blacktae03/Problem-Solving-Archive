#include <bits/stdc++.h>
using namespace std;
#define X sharks[num].first
#define Y sharks[num].second
#define NUM tmp[sharks[num].first][sharks[num].second].first
#define DIR tmp[sharks[num].first][sharks[num].second].second

pair<int, int> brd[4][4], tmp[4][4];
pair<int, int> sharks[25]; // 물고기 위치
int score, ans;
int dx[9] = {0,-1,-1,0,1,1,1,0,-1}; // 1~8만 유효값
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};

void move() {
    for (int num = 1; num <= 16; num++) {
        if (NUM == 0) continue;

        for (int d = 0; d < 8; d++) { // 마지막에 8까지 더해주면 원상태로 복구 가능
            int dir = DIR + d;
            dir -= (dir > 8) ? 8 : 0;
            int nx = X + dx[dir];
            int ny = Y + dy[dir];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if (tmp[nx][ny].first == 20) continue;

            DIR = dir;
            swap(tmp[X][Y], tmp[nx][ny]);
            if (tmp[X][Y].first == 0) sharks[NUM] = {nx, ny};
            else swap(sharks[NUM], sharks[tmp[nx][ny].first]);
            break;
        }
    }
}

void restore() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i][j] = brd[i][j];
            sharks[brd[i][j].first] = {i, j};
        }
    }

    score = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> brd[i][j].first >> brd[i][j].second;
            sharks[brd[i][j].first] = {i, j};
            tmp[i][j] = brd[i][j];
        }
    }

    cout << "nice input :)\n";

    for (int T = 0; T < 3*3*3*3*3*3*3*3*3*3*3*3*3*3*3*3; T++) {
        score += tmp[0][0].first;
        swap(sharks[20], sharks[tmp[0][0].first]);
        tmp[0][0].first = 20; // 20은 상어를 의미

        int brute = T;

        for (int i = 0; i < 16; i++) {
            move();

            int num = 20;
            int mv = brute % 3;
            brute /= 3;

            int nx = X + dx[DIR] * (mv+1);
            int ny = Y + dy[DIR] * (mv+1);

            if ((nx < 0 || nx >= 4 || ny < 0 || ny >= 4) || (tmp[nx][ny].first == 20 || tmp[nx][ny].first == 0)) {
                score = 0;
                break;
            }

            score += tmp[nx][ny].first;
            tmp[nx][ny].first = 20;
            tmp[X][Y] = {0, 0};
        }

        ans = max(ans, score);
        restore();
    }

    cout << ans;
}