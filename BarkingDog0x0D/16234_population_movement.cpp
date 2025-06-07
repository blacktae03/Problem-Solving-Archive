#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int brd[51][51];
int num[51][51];
bool vis1[51][51], vis2[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
        }
    }

    int cnt = 1;
    num[0][0] = cnt;

    while(true) {
        for (int i = 0; i < N; i++) { // 국경 열기 (열려서 한 묶음이 된 칸은 num을 같게 만들거임
            for (int j = 0; j < N; j++) {
                if (!num[i][j]) num[i][j] = ++cnt;

                for (int dir = 0; dir < 2; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (abs(brd[i][j] - brd[nx][ny]) < L || abs(brd[i][j] - brd[nx][ny]) > R) continue;
                    
                }
            }
        }
    }
}