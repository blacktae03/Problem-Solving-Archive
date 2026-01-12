// back tracking
#include <bits/stdc++.h>
using namespace std;
#define X sharks[num].first
#define Y sharks[num].second
#define NUM brd[sharks[num].first][sharks[num].second].first
#define DIR brd[sharks[num].first][sharks[num].second].second

pair<int, int> brd[4][4];
pair<int, int> sharks[25]; // 물고기 위치
int score, ans;
int dx[9] = {0,-1,-1,0,1,1,1,0,-1}; // 1~8만 유효값
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};

void move() {
    for (int num = 1; num <= 16; num++) {
        if (NUM == 0 || NUM == 20 || sharks[num].first == -1) continue;
        
        for (int d = 0; d < 8; d++) { // 마지막에 8까지 더해주면 원상태로 복구 가능
            int dir = DIR + d;
            dir -= (dir > 8) ? 8 : 0;
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if (brd[nx][ny].first == 20) continue;
            
            DIR = dir;
            swap(brd[X][Y], brd[nx][ny]);
            swap(sharks[NUM], sharks[brd[nx][ny].first]);
            // if (brd[X][Y].first == 0) sharks[NUM] = {nx, ny};

            cout << "---- after move of " << num << " ----\n";
    
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << brd[i][j].first << ' ' << brd[i][j].second << ' ';
                }
                cout << '\n';
            }

            break;
        }
    }
}

void restore() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            brd[i][j] = brd[i][j];
            sharks[brd[i][j].first] = {i, j};
        }
    }
    
    score = 0;
}

void bt() {
    pair<int, int> backupbrd[4][4];
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) backupbrd[i][j] = brd[i][j];
    move();

    

    // cout << "-------------------\n";
    
    // for (int i = 1; i <= 16; i++) cout << sharks[i].first << ',' << sharks[i].second << '\n';


    // for (int mv = 1; mv <= 3; mv++) {
    int mv = 1;
    int num = 20;
    
    int nx = X + dx[DIR] * mv;
    int ny = Y + dy[DIR] * mv;
    
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
        cout << "oob\n";
        return;
    }
    if (brd[nx][ny].first == 0) {
        cout << "zero\n";
        return;
    }
    
    int backup = brd[nx][ny].first;
    int backup2 = brd[X][Y].second;
    score += backup;
    brd[nx][ny].first = 20;
    brd[X][Y] = {0, 0};
    swap(sharks[num], sharks[backup]);
    sharks[backup] = {-1, -1};
    
    ans = max(ans, score);
    
    bt();
    
    score -= backup;
    brd[nx][ny].first = backup;
    brd[X][Y] = {20, backup2};
    sharks[backup] = {X, Y};
    swap(sharks[20], sharks[backup]);
    // }

    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) brd[i][j] = backupbrd[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> brd[i][j].first >> brd[i][j].second;
            sharks[brd[i][j].first] = {i, j};
        }
    }

    score += brd[0][0].first;
    swap(sharks[20], sharks[brd[0][0].first]);
    sharks[brd[0][0].first] = {-1, -1};
    brd[0][0].first = 20; // 20은 상어를 의미

    ans = max(ans, score);

    bt();

    // ans = max(ans, score);
    // restore();

    cout << ans;
}