#include <bits/stdc++.h>
using namespace std;

int N, M, T;
vector<int> V[54];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool rmv[54][54];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        V[i].push_back(0);
        for (int j = 1; j <= M; j++) {
            int tmp; cin >> tmp;
            V[i].push_back(tmp);
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << V[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    
    for (int i = 1; i <= T; i++) {
        
        // if (i != 1) {
        //     cout << "after turn " << i-1 << '-' << 2 << '\n';
        //     for (int i = 1; i <= N; i++) {
        //         for (int j = 1; j <= M; j++) {
        //             cout << V[i][j] << ' ';
        //         }
        //         cout << '\n';
        //     }
        // }
        int x, d, k; cin >> x >> d >> k;
        bool close = 0;
        
        for (int disc = x; disc <= N; disc += x) {
            if (d) rotate(V[disc].begin()+1, V[disc].begin()+1+k, V[disc].end()); // 반시계방향
            else rotate(V[disc].begin()+1, V[disc].end()-k, V[disc].end()); // 시계방향
        }
        
        // cout << "after turn " << i << '-' << 1 << '\n';
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= M; j++) {
        //         cout << V[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        
        for (int curX = 1; curX <= N; curX++) {
            for (int curY = 1; curY <= M; curY++) {
                if (!V[curX][curY]) continue;
                bool close2 = 0;
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = curX + dx[dir];
                    int ny = curY + dy[dir];
                    
                    if (nx < 1 || nx > N) continue;
                    if (ny < 1) ny = M;
                    if (ny > M) ny = 1;
                    if (V[nx][ny] != V[curX][curY]) continue;
                    
                    close = 1, close2 = 1;
                    
                    rmv[nx][ny] = 1;
                    // V[nx][ny] = 0;
                }
                
                if (close2) rmv[curX][curY] = 1;
            }
        }

        for (int curX = 1; curX <= N; curX++) {
            for (int curY = 1; curY <= M; curY++) {
                if (rmv[curX][curY]) V[curX][curY] = 0;
                rmv[curX][curY] = 0;
            }
        }
        
        
        if (close) continue;
        
        float mean = 0;
        float cnt = 0;
        
        for (int curX = 1; curX <= N; curX++) {
            for (int curY = 1; curY <= M; curY++) {
                if (V[curX][curY] == 0) continue;
                mean += V[curX][curY];
                cnt++;
            }
        }
        // cout << '*' << cnt << '*' << '\n';
        
        if (!cnt) continue;
        
        mean /= cnt;
        
        for (int curX = 1; curX <= N; curX++) {
            for (int curY = 1; curY <= M; curY++) {
                if (!V[curX][curY]) continue;

                if (V[curX][curY] > mean) V[curX][curY]--;
                else if (V[curX][curY] < mean) V[curX][curY]++;
            }
        }
    }
    
    int sum = 0;
    
    // cout << "result\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sum += V[i][j];
            // cout << V[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << sum;
}