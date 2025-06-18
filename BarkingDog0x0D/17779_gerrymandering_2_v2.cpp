// 와 이거는 근데 문제를 진짜 제대로 이해해야하네.. 선거구의 경계선이 길다란 모양이 될수록 선거구를 정하는게 조건식만으로 안됨.
// 이거를 깨달으려면 사실 문제를 잘 이해하는 것도 이해하는 건데 출력으로 문제의 오류가 어딘지를 찾는 실력을 키우는게 먼저인 듯.

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
int brd[22][22], num[22][22], sum[6], vis[22][22];
int ans = 99999999;
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> brd[i][j];
        }
    }

    for (int d1 = 1; d1 <= N-1; d1++) {
        for (int d2 = 1; d1+d2 <= N-1; d2++) {
            for (int x = 1; x+d1+d2 <= N; x++) {
                for (int y = 1+d1; y+d2 <= N; y++) {

                    int nx = x, ny = y;
                    
                    for (int i = 0; i < d1; i++) {
                        num[nx][ny] = 5;
                        nx++;
                        ny--;
                    }

                    int leftendrow = nx, leftendcol = ny;
                    
                    for (int i = 0; i < d2; i++) {
                        num[nx][ny] = 5;
                        nx++;
                        ny++;
                    }

                    int endrow = nx, endcol = ny;

                    for (int i = 0; i < d1; i++) {
                        num[nx][ny] = 5;
                        nx--;
                        ny++;
                    }

                    int rightendrow = nx, rightendcol = ny;

                    for (int i = 0; i < d2; i++) {
                        num[nx][ny] = 5;
                        nx--;
                        ny--;
                    }

                    bool inborder = 0;

                    Q.push({1, 1});
                    num[1][1] = 1;

                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 1 || nx >= leftendrow || ny < 1 || ny > y) continue;
                            if (num[nx][ny]) continue;
                            
                            Q.push({nx, ny});
                            num[nx][ny] = num[1][1];
                        }
                    } // 1번째 선거구

                    Q.push({1, N});
                    num[1][N] = 2;

                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < 1 || nx > rightendrow || ny <= y || ny > N) continue;
                            if (num[nx][ny]) continue;
                            
                            Q.push({nx, ny});
                            num[nx][ny] = num[1][N];
                        }
                    } // 2번째 선거구

                    Q.push({N, 1});
                    num[N][1] = 3;

                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx < leftendrow || nx > N || ny < 1 || ny >= endcol) continue;
                            if (num[nx][ny]) continue;
                            
                            Q.push({nx, ny});
                            num[nx][ny] = num[N][1];
                        }
                    } // 3번째 선거구

                    Q.push({N, N});
                    num[N][N] = 4;
                    
                    while(!Q.empty()) {
                        auto cur = Q.front(); Q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];

                            if (nx <= rightendrow || nx > N || ny < endcol || ny > N) continue;
                            if (num[nx][ny]) continue;
                            
                            Q.push({nx, ny});
                            num[nx][ny] = num[N][N];
                        }
                    } // 4번째 선거구


                    for (int i = 1; i <= N; i++) {
                        for (int j = 1; j <= N; j++) {
                            if (num[i][j] != 5) {
                                if (inborder) sum[5] += brd[i][j];
                                else sum[num[i][j]] += brd[i][j];
                            }

                            else {
                                sum[5] += brd[i][j];

                                if (i > x && i < endrow) inborder = !inborder;
                            }
                        }
                        fill(num[i], num[i]+22, 0);
                    }
                    
                    ans = min(*max_element(sum+1, sum+6) - *min_element(sum+1, sum+6), ans);
                    fill (sum, sum+6, 0);
                }
            }
        }
    }

    cout << ans;
}