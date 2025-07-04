#include <bits/stdc++.h>
using namespace std;

bool G[7][4], B[4][7];
int N;
int t, x, y;
int score, cnt;

// void show() {
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) cout << "x ";
//         for (int j = 0; j < 6; j++) cout << B[i][j] << ' ';
//         cout << '\n';
//     }

//     for (int i = 0; i < 6; i++) {
//         for (int j = 0; j < 4; j++) cout << G[i][j] << ' ';
//         cout << '\n';
//     }
// }

void count() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (B[i][j]) cnt++;
            if (G[j][i]) cnt++;
        }
    }
}

void delRow(int r, bool bomb) {
    for (int i = 0; i < 4; i++) {
        bool tmpCol[8] = {0,};
        int cnt1 = 0;

        for (int j = 0; j < r; j++) {
            tmpCol[j] = G[j][i];
            if (G[j][i]) cnt1++;
        }

        if (!bomb) {
            for (int j = 0; j <= r; j++) {
                G[j][i] = j ? tmpCol[j-1] : 0;
            }
        }

        else {
            int tmp = 0;

            for (int j = r+1; j <= 6; j++) {
                if (!G[j][i]) continue;
                tmp = j;
                break;
            }
            
            for (int k = tmp-1; k >= 0; k--) {
                if (cnt1 > 0) {
                    G[k][i] = 1;
                    cnt1--;
                }
                else G[k][i] = 0;
            }
        }
    }
}

void delCol(int r, bool bomb) {
    for (int i = 0; i < 4; i++) {
        bool tmpRow[8] = {0,};
        int cnt1 = 0;
        
        for (int j = 0; j < r; j++) {
            tmpRow[j] = B[i][j];
            if (B[i][j]) cnt1++;
        }
        
        if (!bomb) {
            for (int j = 0; j <= r; j++) {
                B[i][j] = j ? tmpRow[j-1] : 0;
            }
        }
        
        else {
            int tmp = 0;
            
            for (int j = r+1; j <= 6; j++) {
                if (!B[i][j]) continue;
                tmp = j;
                break;
            }
            
            for (int k = tmp-1; k >= 0; k--) {
                if (cnt1 > 0) {
                    B[i][k] = 1;
                    cnt1--;
                }
                else B[i][k] = 0;
            }
            
        }
    }
}

void Bmove() {
    int arv = 0;

    if (t == 1) {
        for (int i = 2; i <= 6; i++) {
            if (!B[x][i]) continue;
            arv = i-1;
            break;
        }

        B[x][arv] = 1;
    }

    else if (t == 2) {
        for (int i = 2; i <= 6; i++) {
            if (!B[x][i]) continue;
            arv = i-2;
            break;
        }

        B[x][arv] = 1;
        B[x][arv+1] = 1;
    }

    else if (t == 3) {
        for (int i = 2; i <= 6; i++) {
            if (!B[x][i] && !B[x+1][i]) continue;
            arv = i-1;
            break;
        }

        B[x][arv] = 1;
        B[x+1][arv] = 1;
    }

    for (int i = 5; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (i == 1) {
                if (!B[j][i]) continue;
                delCol(5, 0);
                j = 4;
            }

            else {
                if (!B[j][i]) break;
                if (j < 3) continue;
                delCol(i, 1);
                score++;
                i = 6;
            }
        }
    }
    
}

void Gmove() {
    int arv = 0;
    
    if (t == 1) {
        for (int i = 2; i <= 6; i++) {
            if (!G[i][y]) continue;
            arv = i-1;
            break;
        }
        
        G[arv][y] = 1;
    }
    
    else if (t == 2) {
        for (int i = 2; i <= 6; i++) {
            if (!G[i][y] && !G[i][y+1]) continue;
            arv = i-1;
            break;
        }
        
        G[arv][y] = 1;
        G[arv][y+1] = 1;
    }
    
    else if (t == 3) {
        for (int i = 2; i <= 6; i++) {
            if (!G[i][y]) continue;
            arv = i-2;
            break;
        }
        
        G[arv][y] = 1;
        G[arv+1][y] = 1;
    }

    for (int i = 5; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (i == 1) {
                if (!G[i][j]) continue;
                delRow(5, 0);
                j = 4;
            }
    
            else {
                if (!G[i][j]) break;
                if (j < 3) continue;
                delRow(i, 1);
                score++;
                i = 6;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < 4; i++) {
        G[6][i] = 1;
        B[i][6] = 1;
    }

    while(N--) {
        cin >> t >> x >> y;

        Gmove();
        Bmove();
    }

    count();
    // show();

    cout << score << '\n' << cnt;
}