#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int R, C, ans = 1000000000;
string brd[21];
int dist[11][21][21];
vector<tuple<int, int, int>> V;
int sx, sy;
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {

        cin >> C >> R;
        if (!C && !R) break;
        ans = 1000000000;
        int cnt = 0;
    
        for (int i = 0; i < R; i++) {
            cin >> brd[i];
            for (int j = 0; j < C; j++) {
                if (brd[i][j] == '*') V.push_back({++cnt, i, j});
                if (brd[i][j] == 'o') V.push_back({0, i, j});
            }
        }
    
        sort (V.begin(), V.end());

        // for (auto t : V) cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << '\n';
    
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 21; j++) fill(dist[i][j], dist[i][j]+21, -1);
        }
    
        for (int i = 0; i <= cnt; i++) {
            Q.push({get<1>(V[i]), get<2>(V[i])});
    
            dist[i][Q.front().X][Q.front().Y] = 0;
    
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
    
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
    
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (dist[i][nx][ny] >= 0 || brd[nx][ny] == 'x') continue;
    
                    Q.push({nx, ny});
                    dist[i][nx][ny] = dist[i][cur.X][cur.Y] + 1;
                }
            }
        } // 11 * 400
    
        do {
            int move = 0;
    
            for (int i = 0; i < V.size()-1; i++) {
                int tmp = dist[get<0>(V[i])][get<1>(V[i+1])][get<2>(V[i+1])];
                if (tmp == -1) {move = -1; break;}
                else move += tmp;
            }
    
            ans = min(ans, move);

        } while(next_permutation(V.begin()+1, V.end())); // 10!
    
        cout << ans << '\n';
        V.clear();
    }
}

// 어떤 방식으로 풀까.. pair는 first, second 순으로 대소 비교를 하니까 더러운 곳을 차례로 입력 받으면 사전순 정렬이 되어 있는 상태임.
// 더러운 곳이 10개 이하니까 이 좌표를 next_permutation 돌리는 게 제일 좋아보임.
// 장애물이 없으면 next_permutation의 순서대로 좌표 차이로 하면 되지만 장애물이 있어서 bfs를 여러번 써야하는 방법이긴 함.
// brd의 N의 최댓값이 20이라 근데 상관없을 듯. 해보자
// 400 * 10 * 10! = 145억이네 안됨.. bfs 한번만 쓴다고 가정해도 400 * 10! = 14억
// 아니 심지어 테스트케이스가 여러개네 어떻게 하는거지
// 어 근데 그냥 청소기 + 모든 더러운 곳을 기준으로 bfs 한 상태로 다 brd에 저장해놓은 다음에 값만 더하면 괜찮은데?
// 11 * 400 + 10! 충분히 가능 ㄷㄷ