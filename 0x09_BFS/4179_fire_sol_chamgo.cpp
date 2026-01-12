// 뇌에 과부하 와서 어떻게 하는지 슥 해답 보고 스스로 짜는 코드임. 내 힘으로 해결하지는 못한 문제라는 뜻.
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    string maze[r];
    int Fdist[r][c];
    int Jdist[r][c];
    queue<pair<int, int>> FQ;
    queue<pair<int, int>> JQ;
    int Jcnt = 0;

    for (int i = 0; i < r; i++) {
        cin >> maze[i];
        fill(Fdist[i], Fdist[i]+c, -1);
        fill(Jdist[i], Jdist[i]+c, -1);

        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'F') {
                FQ.push({i, j});
                Fdist[i][j] = 0;
            }

            else if (maze[i][j] == 'J') {
                JQ.push({i, j});
                Jdist[i][j] = 0;
            }

            // else if (maze[i][j] == '.') {
            //     Fdist[i][j] = 0;
            //     Jdist[i][j] = 0;
            // }
            // 이렇게 하면 불 시작점이랑 길이랑 구분을 못한다는 단점이 있음.
            // + J 시작점이랑 길이랑 구분 불가.
            // 구분 불가능이 아니라 나중에 처음 불에도 그냥 불지펴버릴 가능성이 생김.
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while(!FQ.empty()) {
        pair<int, int> cur = FQ.front(); FQ.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (Fdist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            
            Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
            
            FQ.push({nx, ny});
        }
    }

    while(!JQ.empty()) {
        pair<int, int> cur = JQ.front(); JQ.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << Jdist[cur.X][cur.Y] + 1;
                return 0;
            }

            if (Jdist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            if (Fdist[nx][ny] != -1 && Jdist[cur.X][cur.Y] + 1 >= Fdist[nx][ny]) continue; 
            // 여기서 존나 헤맸음. 아니 시22321발 뒤 조건이 만족하면 불에 J가 가는 거라서 안되는건 맞는데
            // Fdist가 -1 (애초에 불이 번지지 않음)이면 그냥 가도 되는 곳인데 뒤 조건에 만족하기 때문에 불이 안번진 곳을 못가는 불상사가 발생.

            Jdist[nx][ny] = Jdist[cur.X][cur.Y] + 1;
            JQ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}