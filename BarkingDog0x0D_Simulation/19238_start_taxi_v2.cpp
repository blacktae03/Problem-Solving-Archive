#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, F;
int brd[24][24], brd2[24][24]; // brd는 출발지 표시, brd2는 도착지 표시
int dist[24][24], dist2[24][24]; // dist는 승객을 데리러 가는 거리 표시, dist2는 승객을 태우고 도착지까지 가는 거리 표시
queue<pair<int, int>> Q, Q2;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
// 같은 거리일 때, 행 번호가 낮은 순, 열 번호가 낮은 순으로 우선순위가 정해지므로 bfs도 그 순서로 돌린다.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> F;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> brd[i][j];
            brd2[i][j] = brd[i][j];
            dist[i][j] = -1;
            dist2[i][j] = -1;
        }
    }
    
    int tx, ty;
    cin >> tx >> ty;
    // brd[tx][ty] = 2; // 2는 택시 위치
    dist[tx][ty] = 0;
    Q.push({tx, ty});
    
    for (int i = 0; i < M; i++) {
        int tx1, ty1, tx2, ty2; // tx1, ty1 은 출발지의 행과 열 번호, tx2, ty2는 도착지의 행과 열 번호.
        cin >> tx1 >> ty1 >> tx2 >> ty2;
        
        brd[tx1][ty1] = i+3; // 3부터 차례로 표시
        brd2[tx2][ty2] = i+3; // brd2의 n번 칸은 n번 손님의 도착지
    } // 문제점 발견 : 다른 손님끼리 도착지가 겹칠 수 있음. (2번 손님과 3번 손님의 도착지가 1,1인 동시에 1번 손님의 출발지가 1,1일 수가 있음)
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (brd2[i][j]) cout << brd2[i][j] << ' ';
            else cout << brd[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < M; i++) {
        int guest = 0;
        int gift = 0;

        cout << "---------------\n";

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();

            if (brd[cur.X][cur.Y] > 2) {
                Q2.push(cur);
                dist2[cur.X][cur.Y] = 0;
                guest = brd[cur.X][cur.Y];
                brd[cur.X][cur.Y] = 0;
                break; // 자동차와 승객의 위치가 같은 경우
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (brd[nx][ny] == 1 || dist[nx][ny] >= 0) continue;

                if (brd[nx][ny] > 2) {
                    Q2.push({nx, ny});
                    dist2[nx][ny] = 0;
                    guest = brd[nx][ny];
                    brd[nx][ny] = 0;
                    F -= dist[cur.X][cur.Y]+1;
                    while(!Q.empty()) Q.pop();
                    break;
                }
                
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        
        cout << F << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (brd2[i][j]) cout << brd2[i][j] << ' ';
                else cout << brd[i][j] << ' ';
            }
            cout << '\n';
        }
        
        for (int i = 1; i <= N; i++) fill(dist[i], dist[i]+24, -1);
        
        if (F < 0 || Q2.empty()) {
            cout << -1;
            return 0;
        }
        
        while(!Q2.empty()) {
            auto cur = Q2.front(); Q2.pop();
            // if (brd[cur.X][cur.Y] > 2) break; // 자동차와 승객의 위치가 같은 경우
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (brd2[nx][ny] == 1 || dist2[nx][ny] >= 0) continue;
                
                if (brd2[nx][ny] == guest) {
                    Q.push({nx, ny});
                    brd2[nx][ny] = 0;
                    dist[nx][ny] = 0;
                    F -= dist2[cur.X][cur.Y]+1;
                    gift = (dist2[cur.X][cur.Y]+1) * 2;
                    while(!Q2.empty()) Q2.pop();
                    break;
                }
                
                Q2.push({nx, ny});
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            }   
        }
        
        for (int i = 1; i <= N; i++) fill(dist2[i], dist2[i]+24, -1);
        
        if (F < 0 || Q.empty()) {
            cout << -1;
            return 0;
        }
        F += gift;

        cout << F << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (brd2[i][j]) cout << brd2[i][j] << ' ';
                else cout << brd[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    cout << F;
}
// 1. 일단 보드에다가 길, 벽, 택시 위치, 승객 출발지 / 도착지 (0, 1, 2, n, -n (n>=3)) 기록하기
// 2. 택시에서 bfs 돌리기, 돌리면서 승객 출발지 나오면 바로 그 위치 Q2에 집어넣고 연료 그만큼 까고 Q 비우기. 연료 음수면 탈락
// 3. 승객 출발지에서(Q2) 도착지까지 bfs 돌리기. 도착지 나오면 바로 그 위치 Q에 집어넣고 연료 그만큼 까고 Q2 비우기. 연료 음수면 탈락 음수 아니면 2배만큼 돌려받기.
// 4. 2~3을 M번 하고 남은 F 출력