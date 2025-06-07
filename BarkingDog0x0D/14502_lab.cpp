#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int r, c, safe = -3, virus = 100;
int brd[10][10], brd2[10][10];
bool comb[70];
vector<pair<int, int>> blank;
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(comb+3, comb+70, 1);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
            if(!brd[i][j]) {
                blank.push_back({i, j});
                safe++;
            }
        }
    }

    int length = blank.size();
    

    do {
        int tmp = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                brd2[i][j] = brd[i][j];
                if (brd2[i][j] == 2) Q.push({i, j});
            }
        }
        
        for (int i = 0; i < length; i++) {
            if (comb[i]) continue;
            brd2[blank[i].X][blank[i].Y] = 1;
        }

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (brd2[nx][ny]) continue;

                brd2[nx][ny] = 2;
                Q.push({nx, ny});
                tmp++;
            }
        }

        virus = min(tmp, virus);
    } while(next_permutation(comb, comb+length));

    cout << safe - virus;
}