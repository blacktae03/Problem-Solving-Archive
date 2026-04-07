#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, L, R;
int brd[101][101];
bool vis[101][101];
int dx[4] = {2,0,-2,0};
int dy[4] = {0,2,0,-2};
queue<pair<int,int>> Q;
vector<pair<int, int>> V;

// N+1 * N+1 만큼 만든다음에 각 꼭짓점은 쓰지 않는 칸으로 해야할 듯. 그래야 국경 표시가 야무지게 가능할 거 같다. 아 ㅈㄴ 애매하네
// 이렇게 하면 가운데 끼여있는 나라는 국경이 4개인데 다 표시할 수가 없음.

// 그냥 brd 자체를 (N*2-1) * (N*2-1) 로 해서 N이 3인 경우 (쓰 : 안쓰는 칸, 국 : 국경, 칸 : 나라) 이렇게 해야할 듯.
// 칸 국 칸 국 칸
// 국 쓰 국 쓰 국
// 칸 국 칸 국 칸
// 국 쓰 국 쓰 국
// 칸 국 칸 국 칸


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < 2*N-1; i += 2) {
        for (int j = 0; j < 2*N-1; j += 2) {
            cin >> brd[i][j];
        }
    }

    int ans = 0;
    bool esc = 0;

    while(!esc) {
        esc = 1;

        for (int i = 0; i < 2*N-1; i+=2) { // 국경 열기
            for (int j = 0; j < 2*N-1; j+=2) {
                for (int dir = 0; dir < 2; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx < 0 || nx >= 2*N-1 || ny < 0 || ny >= 2*N-1) continue;
                    if (abs(brd[i][j] - brd[nx][ny]) < L || abs(brd[i][j] - brd[nx][ny]) > R) continue;

                    esc = 0;
                    brd[(i+nx)/2][(j+ny)/2] = 1;
                }
            }
        }
        
        if (esc) break;

        for (int i = 0; i < 2*N-1; i+=2) { // 열린 부분 인구 이동
            for (int j = 0; j < 2*N-1; j+=2) {
                if (vis[i][j]) continue;

                Q.push({i, j});
                V.push_back({i, j});
                vis[i][j] = 1;

                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= 2*N-1 || ny < 0 || ny >= 2*N-1) continue;
                        if (vis[nx][ny]) continue;
                        if (!brd[(cur.X+nx)/2][(cur.Y+ny)/2]) continue;
                    
                        Q.push({nx, ny});
                        V.push_back({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }

                int sum = 0;
            

                for (auto p : V) sum += brd[p.X][p.Y];
                sum /= V.size();
                for (auto p : V) brd[p.X][p.Y] = sum;

                V.clear();
            }
        }

        for (int i = 0; i < 2*N-1; i++) {
            fill(vis[i], vis[i]+101, 0);

            for (int j = i%2 ? 0 : 1; j < 2*N-1; j+=2) {
                brd[i][j] = 0;
            }
        }

        // for (int i = 0; i < 2*N-1; i+=2) {
        //     for (int j = 0; j < 2*N-1; j+=2) {
        //         cout << brd[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        ans++;
    }

    cout << ans;
}