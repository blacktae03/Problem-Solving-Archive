#include <bits/stdc++.h>
using namespace std;
// 자 여기서 터지는 게 많으면 같이 터트리는 것만 구현하면 돼.
// 아 도저히 못하겠다 6시간은 쓴 듯 ㅅㅂ 내일 다시..
// 정답코드

int G[7][4], B[4][7];

int N;
int t[10004], x[10004], y[10004];
int bt[10004], bx[10004], by[10004];
int gt[10004], gx[10004], gy[10004];
int score, cnt, turn;

void show() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) cout << "x ";
        for (int j = 0; j < 6; j++) cout << B[i][j] << ' ';
        cout << '\n';
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) cout << G[i][j] << ' ';
        cout << '\n';
    }
}

void count() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (B[i][j]) cnt++;
            if (G[j][i]) cnt++;
        }
    }
}

void delCol(int c) {
    for (int i = 0; i < 4; i++) {
        int cur = B[i][c];

        switch(bt[cur]) {
            case 1 :
            case 3 :
                bt[cur] = 0;
                bx[cur] = 0;
                by[cur] = 0;
                break;
            
            case 2 :
                bt[cur] = 1;
                bx[cur] = i;
                if (by[cur] == c) by[cur] = c+1;
                else by[cur] = c-1;
                break;
        }
        
        B[i][c] = 0;
    }
}

void delRow(int r) {
    for (int i = 0; i < 4; i++) {
        int cur = G[r][i];

        switch(gt[cur]) {
            case 1 :
            case 2 :
                gt[cur] = 0;
                gx[cur] = 0;
                gy[cur] = 0;
                break;
            
            case 3 :
                gt[cur] = 1;
                gy[cur] = i;
                if (gx[cur] == r) gx[cur] = r+1;
                else gx[cur] = r-1;
                break;
        }
        
        G[r][i] = 0;
    }
}

void Bmove(int t, int x, int y, int cur) {
    int arv = 0;
    int curY = by[cur];

    if (t == 1) {
        B[bx[cur]][by[cur]] = 0;
        for (int i = curY+1; i <= 6; i++) {
            if (!B[x][i]) continue;
            arv = i-1;
            break;
        }

        B[x][arv] = cur;
    }

    else if (t == 2) {
        B[bx[cur]][by[cur]] = 0;
        B[bx[cur]][by[cur]+1] = 0;
        for (int i = curY+2; i <= 6; i++) {
            if (!B[x][i]) continue;
            arv = i-2;
            break;
        }

        B[x][arv] = cur;
        B[x][arv+1] = cur;
    }

    else if (t == 3) {
        B[bx[cur]][by[cur]] = 0;
        B[bx[cur]+1][by[cur]] = 0;
        for (int i = curY+1; i <= 6; i++) {
            if (!B[x][i] && !B[x+1][i]) continue;
            arv = i-1;
            break;
        }

        B[x][arv] = cur;
        B[x+1][arv] = cur;
    }

    bt[cur] = t;
    bx[cur] = x;
    by[cur] = arv;
}


void Gmove(int t, int x, int y, int cur) {
    int arv = 0;
    int curX = gx[cur];

    if (t == 1) {
        G[gx[cur]][gy[cur]] = 0;
        for (int i = curX+1; i <= 6; i++) {
            if (!G[i][y]) continue;
            arv = i-1;
            break;
        }

        G[arv][y] = cur;
    }

    else if (t == 3) {
        G[gx[cur]][gy[cur]] = 0;
        G[gx[cur]+1][gy[cur]] = 0;
        for (int i = curX+2; i <= 6; i++) {
            if (!G[i][y]) continue;
            arv = i-2;
            break;
        }

        G[arv][y] = cur;
        G[arv+1][y] = cur;
    }

    else if (t == 2) {
        G[gx[cur]][gy[cur]] = 0;
        G[gx[cur]][gy[cur]+1] = 0;
        for (int i = curX+1; i <= 6; i++) {
            if (!G[i][y] && !G[i][y+1]) continue;
            arv = i-1;
            break;
        }

        G[arv][y] = cur;
        G[arv][y+1] = cur;
    }

    gt[cur] = t;
    gx[cur] = arv;
    gy[cur] = y;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < 4; i++) {
        G[6][i] = -1;
        B[i][6] = -1;
    }

    for (turn = 1; turn <= N; turn++) {
        cin >> t[turn] >> x[turn] >> y[turn];
        Gmove(t[turn], x[turn], y[turn], turn);
        Bmove(t[turn], x[turn], y[turn], turn);

        while (true) {
            bool haveToMove = 0;
            int tscore = 0, tspot = 0;

            for (int i = 2; i < 6; i++) { // B 삭제할 거 있는지 확인.
                if (B[0][i] && B[1][i] && B[2][i] && B[3][i]) {
                    delCol(i);
                    tscore++;
                    tspot = i;
                    haveToMove = 1;
                }
            }
            
            if (tscore) {
                for (int i = tspot-tscore; i >= 0; i--) {
                    for (int j = 3; j >= 0; j--) {
                        int cur = B[j][i];
    
                        B[j][i+tscore] = cur;
                        x[cur] = j;
                        y[cur] = i+tscore;
                    }
                }
            }
            
            
            else {
                for (int i = 5; i >= 0; i--) {
                    for (int j = 0; j < 4; j++) {
                        if (!B[j][i]) continue;
                        int cur = B[j][i];
                        B[j][i] = 0;
                        Bmove(bt[cur], bx[cur], by[cur], cur);
                    }
                }
            }
            
            score += tscore;
            
            int tcnt = 0;
            
            for (int i = 0; i < 2; i++) {
                if (B[0][i] || B[1][i] || B[2][i] || B[3][i]) {
                    tcnt++;
                    delCol(5+1-tcnt);
                    haveToMove = 1;
                }
            }
            
            for (int i = 5; i >= 0; i--) {
                for (int j = 0; j < 4; j++) {
                    if (!B[j][i]) continue;
                    int cur = B[j][i];
                    B[j][i] = 0;
                    Bmove(bt[cur], bx[cur], by[cur], cur);
                }
            }
            
            if (!haveToMove) break;
        }
        
        // cout << "B Complete " << turn << '\n';
        
        while (true) {
            bool haveToMove = 0;
            int tscore = 0, tspot = 0;
            
            for (int i = 2; i < 6; i++) { // G 삭제할 거 있는지 확인.
                if (G[i][0] && G[i][1] && G[i][2] && G[i][3]) {
                    delRow(i);
                    tscore++;
                    tspot = i;
                    haveToMove = 1;
                }
            }
            
            if (tscore) {
                for (int i = tspot-tscore; i >= 0; i--) {
                    for (int j = 3; j >= 0; j--) {
                        int cur = G[i][j];
    
                        G[i+tscore][j] = cur;
                        x[cur] = i+tscore;
                        y[cur] = j;
                    }
                }
            }

            else {
                for (int i = 5; i >= 0; i--) {
                    for (int j = 0; j < 4; j++) {
                        if (!G[i][j]) continue;
                        int cur = G[i][j];
                        G[i][j] = 0;
                        Gmove(gt[cur], gx[cur], gy[cur], cur);
                    }
                }
            }

            score += tscore;

            int tcnt = 0;
            
            for (int i = 0; i < 2; i++) {
                if (G[i][0] || G[i][1] || G[i][2] || G[i][3]) {
                    tcnt++;
                    delRow(5+1-tcnt);
                    haveToMove = 1;
                }
            }
            
            for (int i = 5; i >= 0; i--) {
                for (int j = 0; j < 4; j++) {
                    if (!G[i][j]) continue;
                    int cur = G[i][j];
                    G[i][j] = 0;
                    Gmove(gt[cur], gx[cur], gy[cur], cur);
                }
            }
            
            if (!haveToMove) break;
        }

        // cout << "G Complete " << turn << '\n';
    }

    count();
    show();

    cout << score << '\n' << cnt;
}
// 9
// 1 1 1
// 2 3 0
// 3 2 2
// 3 2 3
// 3 1 3
// 2 0 0
// 3 2 0
// 3 1 2
// 2 1 0