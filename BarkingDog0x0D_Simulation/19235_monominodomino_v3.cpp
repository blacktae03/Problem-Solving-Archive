#include <bits/stdc++.h>
using namespace std;

bool R[4][4], G[7][4], B[4][7];
int N;
int t, x, y;
int score, cnt;

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

void pushGreen() {
    for (int i = 0; i < 4; i++) {
        int cnt1 = 0;

        for (int j = 0; j <= 5; j++) {
            if (!G[j][i]) continue;
            cnt1++;
        }

        for (int j = 5; j >= 0; j--) {
            if (cnt1) {
                G[j][i] = 1;
                cnt1--;
            }
            else G[j][i] = 0;
        }
    }
}

void pushBlue() {
    for (int i = 0; i < 4; i++) {
        int cnt1 = 0;

        for (int j = 0; j <= 5; j++) {
            if (!B[i][j]) continue;
            cnt1++;
        }

        for (int j = 5; j >= 0; j--) {
            if (cnt1) {
                B[i][j] = 1;
                cnt1--;
            }
            else B[i][j] = 0;
        }
    }
}

void delRow(int r) {
    for (int i = 0; i < 4; i++) {
        bool tmpCol[8] = {0,};
        // int cnt1 = 0;

        for (int j = 0; j < r; j++) {
            tmpCol[j] = G[j][i];
        }

        // for (int j = 0; j <= 5; j++) {
        //     if (j == r || !G[j][i]) continue;
        //     cnt1++;
        // }

        // if (!bomb) {
        for (int j = 0; j <= r; j++) {
            G[j][i] = j ? tmpCol[j-1] : 0;
        }
        // }

        // else {
        //     for (int j = 5; j >= 0; j--) {
        //         if (cnt1) {
        //             G[j][i] = 1;
        //             cnt1--;
        //         }
        //         else G[j][i] = 0;
        //     }
        // }
    }
}

void delCol(int r) {
    for (int i = 0; i < 4; i++) {
        bool tmpRow[8] = {0,};
        // int cnt1 = 0;
        
        for (int j = 0; j < r; j++) {
            tmpRow[j] = B[i][j];
        }

        // for (int j = 0; j <= 5; j++) {
        //     if (j == r || !B[i][j]) continue;
        //     cnt1++;
        // }
        
        // if (!bomb) {
        for (int j = 0; j <= r; j++) {
            B[i][j] = j ? tmpRow[j-1] : 0;
        }
        // }
        
        // else {
        //     for (int j = 5; j >= 0; j--) {
        //         if (cnt1) {
        //             B[i][j] = 1;
        //             cnt1--;
        //         }
        //         else B[i][j] = 0;
        //     }
            
        // }
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

    while(true) {
        bool pop = 0;

        for (int i = 5; i > 0; i--) {
            if (i == 1) {
                if (!B[0][i] && !B[1][i] && !B[2][i] && !B[3][i]) continue;
                delCol(5);
                i = 2;
            }
    
            else {
                if (!B[0][i] || !B[1][i] || !B[2][i] || !B[3][i]) continue;
                delCol(i);
                score++;
                i = 6;
                pop = 1;
            }
        }

        if(pop) pushBlue();
        else break;
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

    
    while(true) {
        bool pop = 0;

        for (int i = 5; i > 0; i--) {
            if (i == 1) {
                if (!G[i][0] && !G[i][1] && !G[i][2] && !G[i][3]) continue;
                delRow(5);
                i = 2;
            }
    
            else {
                if (!G[i][0] || !G[i][1] || !G[i][2] || !G[i][3]) continue;
                delRow(i);
                pop = 1;
                score++;
                i = 6;
            }
        }

        if(pop) pushGreen();
        else break;
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
    show();

    cout << score << '\n' << cnt;
}