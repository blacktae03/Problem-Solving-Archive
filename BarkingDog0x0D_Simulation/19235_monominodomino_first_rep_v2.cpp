#include <bits/stdc++.h>
using namespace std;
// 자 여기서 터지는 게 많으면 같이 터트리는 것만 구현하면 돼.
// 아 도저히 못하겠다 6시간은 쓴 듯 ㅅㅂ 내일 다시..

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

    while(true) {
        vector<int> V;
    
        for (int i = 5; i >= 2; i--) {
            for (int j = 0; j < 4; j++) {
                if (!B[j][i]) break;
                if (j < 3) continue;
                V.push_back(i);
            }
        }

        if (V.empty()) break;
        
        score += V.size();

        for (int i : V) {
            for (int j = 0; j < 4; j++) {
                B[j][i] = 0;
            }
        }

        int tmp = 0;
    
        for (int i = 0; i < 4; i++) {
            int cnt1 = 0;
    
            for (int j = 0; j < V[V.size()-1]; j++) {
                if (!B[i][j]) continue;
                cnt1++;
            }
    
            for (int j = V[0]+1; j <= 6; j++) {
                if (!B[i][j]) continue;
                tmp = j;
                break;
            }
            
            for (int k = tmp-1; k >= 0; k--) {
                if (cnt1) {
                    B[i][k] = 1;
                    cnt1--;
                }
                else B[i][k] = 0;
            }
        }
    }
    
    for (int i = 1; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (!B[j][i]) continue;
            delCol(5, 0);
            i = 2; // 수정
            j = 4;
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

    while(true) {
        vector<int> V;
    
        for (int i = 5; i >= 2; i--) {
            for (int j = 0; j < 4; j++) {
                if (!G[i][j]) break;
                if (j < 3) continue;
                V.push_back(i);
            }
        }

        if (V.empty()) break;
        
        score += V.size();

        for (int i : V) {
            for (int j = 0; j < 4; j++) {
                G[i][j] = 0;
            }
        }

        int tmp = 0;
    
        for (int i = 0; i < 4; i++) {
            int cnt1 = 0;
    
            for (int j = 0; j < V[V.size()-1]; j++) {
                if (!G[j][i]) continue;
                cnt1++;
            }
    
            for (int j = V[0]+1; j <= 6; j++) {
                if (!G[j][i]) continue;
                tmp = j;
                break;
            }
            
            for (int k = tmp-1; k >= 0; k--) {
                if (cnt1) {
                    G[k][i] = 1;
                    cnt1--;
                }
                else G[k][i] = 0;
            }
        }
    }
    
    for (int i = 1; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (!G[i][j]) continue;
            delRow(5, 0);
            i = 2; // 수정
            j = 4;
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