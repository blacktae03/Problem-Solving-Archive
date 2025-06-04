#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, K, L, tx, ty, ans, way; // way는 0 : 동, 1 : 남, 2 : 서, 3 : 북
char tcom;
char com[10002];
int brd[105][105];  
pair<int, int> head = {1,1}, tail = {1,1};
bool esc;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    
    brd[head.X][head.Y] = 1;

    for (int i = 0; i < K; i++) {
        cin >> tx >> ty;
        brd[tx][ty] = -1;
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        cin >> tx >> tcom;
        com[tx] = tcom;
    }

    while(!esc) {
        ans++;

        switch(way % 4) {
            case 0 :
                head.Y++;
                if (head.Y > N ||brd[head.X][head.Y] > 0) {esc = 1; break;}
                if (!brd[head.X][head.Y]) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = tail.X + dx[dir];
                        int ny = tail.Y + dy[dir];
    
                        if (brd[nx][ny] == brd[tail.X][tail.Y] + 1) {
                            brd[tail.X][tail.Y] = 0;
                            tail = {nx, ny};
                            break;
                        }
                    }
                }
                
                brd[head.X][head.Y] = ans + 1;

                break;

            case 1 :
                head.X++;
                if (head.X > N || brd[head.X][head.Y] > 0) {esc = 1; break;}
                if (!brd[head.X][head.Y]) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = tail.X + dx[dir];
                        int ny = tail.Y + dy[dir];
    
                        if (brd[nx][ny] == brd[tail.X][tail.Y] + 1) {
                            brd[tail.X][tail.Y] = 0;
                            tail = {nx, ny};
                            break;
                        }
                    }
                }
                
                brd[head.X][head.Y] = ans + 1;

                break;

            case 2 :
                head.Y--;
                if (head.Y < 1 || brd[head.X][head.Y] > 0) {esc = 1; break;}    
                if (!brd[head.X][head.Y]) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = tail.X + dx[dir];
                        int ny = tail.Y + dy[dir];
    
                        if (brd[nx][ny] == brd[tail.X][tail.Y] + 1) {
                            brd[tail.X][tail.Y] = 0;
                            tail = {nx, ny};
                            break;
                        }
                    }
                }
                
                brd[head.X][head.Y] = ans + 1;

                break;

            case 3 :
                head.X--;
                if (head.X < 1 || brd[head.X][head.Y] > 0) {esc = 1; break;}
                if (!brd[head.X][head.Y]) {
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = tail.X + dx[dir];
                        int ny = tail.Y + dy[dir];
    
                        if (brd[nx][ny] == brd[tail.X][tail.Y] + 1) { // brd[nx][ny] > 0 이면 된다는 보장이 있나?
                            brd[tail.X][tail.Y] = 0;
                            tail = {nx, ny};
                            break;
                        }
                    }
                }
                
                brd[head.X][head.Y] = ans + 1;

                break;
        }

        // if (esc) break;

        if (com[ans] == 'D') way++;
        else if (com[ans] == 'L') way += 3;
    }

    cout << ans;
}