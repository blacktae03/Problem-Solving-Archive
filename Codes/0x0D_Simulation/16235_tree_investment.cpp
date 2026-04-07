#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, K, x, y, z;
int A[13][13], brd[13][13];
vector<int> tree[13][13];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 13; i++) {
        fill(brd[i], brd[i]+13, 5);
    }

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    for (int year = 0; year < K; year++) {
        for (int i = 1; i <= N; i++) { // spring
            for (int j = 1; j <= N; j++) {
                vector<int> tmp;
                int sum = 0; // summer

                for (auto t : tree[i][j]) {
                    if (t > brd[i][j]) {
                        sum += t/2;
                    }

                    else {
                        brd[i][j] -= t;
                        tmp.push_back(t+1);
                    }
                }

                tree[i][j].clear();
                
                for (auto t : tmp) {
                    tree[i][j].push_back(t);
                }

                brd[i][j] += sum;
            }
        }

        for (int i = 1; i <= N; i++) { // autumn
            for (int j = 1; j <= N; j++) {
                for (auto t : tree[i][j]) {
                    if (t % 5) continue;

                    for (int dir = 0; dir < 8; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        
                        tree[nx][ny].push_back(1);
                    }
                
                }
            }
        }

        for (int i = 1; i <= N; i++) { // winter
            for (int j = 1; j <= N; j++) {
                brd[i][j] += A[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                sort(tree[i][j].begin(), tree[i][j].end());
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cnt += tree[i][j].size();
        }
    }

    cout << cnt;
    
}