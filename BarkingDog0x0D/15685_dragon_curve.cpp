// 자고 일어나서 제출하기... 하얗게 불태웠다...
#include <bits/stdc++.h>
using namespace std;

bool tmp[101][101], tmp2[101][101], tmp3[101][101];
bool brd[4][11][100][100];
bool ans[101][101];
int N, realans;

void rotate() {
    bool rot[101][101];

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            rot[i][j] = tmp2[i][j];
        }
    }

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            tmp2[i][j] = rot[100-j][i];
        }
    }
}

void connect() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            tmp[i][j] = tmp[i][j] || tmp3[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 일단 10세대까지 방향 = 0 시작점 50, 50이라고 가정하고 만들기.

    int sx = 50, sy = 50;
    int ex = 50, ey = 51;
    
    for (int i = 0; i < 11; i++) {
        if (!i) {
            tmp[sx][sy] = 1;
            tmp[ex][ey] = 1;
        }
        
        else { // 돌릴 때 끝 점을 50, 50으로 만들어서(평행이동) tmp2에 저장하기. tmp2에다가 rotate 함수 쓰기.
            int mvx = 50 - ex, mvy = 50 - ey;
            // cout << ex << ' ' << ey << '\n';
            // cout << mvx << ' ' << mvy << '\n';
            
            for (int i = 0; i < 101; i++) { // tmp의 끝점을 50, 50이 되도록 평행이동한 걸 tmp2에 저장
                for (int j = 0; j < 101; j++) {
                    int nx = i+mvx;
                    int ny = j+mvy;
                    
                    if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
                    
                    tmp2[nx][ny] = tmp[i][j];
                }
            }
            // cout << "after move\n";
            // for (int i = 45; i < 56; i++) {
            //     for (int j = 45; j < 56; j++) {
            //         cout << tmp2[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            rotate(); // tmp2를 끝 점 기준으로 돌린다.
            // cout << "after rotate\n";
            // for (int i = 45; i < 56; i++) {
            //     for (int j = 45; j < 56; j++) {
            //         cout << tmp2[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            
            for (int i = 0; i < 101; i++) { // tmp2의 시작점이 50, 50이 되도록 평행이동한 걸 tmp3에 저장
                for (int j = 0; j < 101; j++) {
                    int nx = i-mvx;
                    int ny = j-mvy;
                    
                    if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
                    
                    tmp3[nx][ny] = tmp2[i][j];
                }
            }
            
            // cout << "after move\n";
            // for (int i = 45; i < 56; i++) {
            //     for (int j = 45; j < 56; j++) {
            //         cout << tmp3[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            connect();
            // cout << "after connect\n";
            // for (int i = 45; i < 56; i++) {
            //     for (int j = 45; j < 56; j++) {
            //         cout << tmp[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            
            // sx += mvx;
            // sy += mvy;
            ex = sx+mvx;
            ey = sy+mvy; // 50, 49 (끝점이 50,50이 되었을 때 시작점의 위치) 51, 49
            // cout << ex << ' ' << ey << '\n';
            int tmpex = ex; // 아 이거 때문에 생2지랄 떨었네
            ex = ey;
            ey = 100-tmpex; // 49, 50 (시계방향으로 돌렸을 때 시작점의 위치) 49, 49
            // cout << ex << ' ' << ey << '\n';
            ex -= mvx;
            ey -= mvy; // 49, 51
            // cout << ex << ' ' << ey << '\n';
        }
        
        for (int dir = 4; dir > 0; dir--) {
            for (int j = 0; j < 101; j++) {
                for (int k = 0; k < 101; k++) {
                    brd[dir%4][i][j][k] = tmp[j][k];
                }
            }

            bool rot[101][101]; // rotate

            for (int i = 0; i < 101; i++) {
                for (int j = 0; j < 101; j++) {
                    rot[i][j] = tmp[i][j];
                }
            }

            for (int i = 0; i < 101; i++) {
                for (int j = 0; j < 101; j++) {
                    tmp[i][j] = rot[100-j][i];
                }
            }
        }
        
        for (int i = 0; i < 101; i++){
            fill(tmp2[i], tmp2[i]+101, 0);
            fill(tmp3[i], tmp3[i]+101, 0);
        }
        
        // for (int i = 45; i < 56; i++) {
        //     for (int j = 45; j < 56; j++) {
        //         cout << tmp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        
    }

    cin >> N;
    int x, y, d, g;

    while(N--) {
        cin >> x >> y >> d >> g;

        // x = 4, y = 3 이면
        // [3][4] = [50][50]
        int mvx = y - 50; // -47
        int mvy = x - 50; // -46
        for (int i = 0; i < 101; i++) { // 시작점을 x, y 값에 맞게 평행이동하여 붙여넣기. 
            for (int j = 0; j < 101; j++) {
                // i = j = 50일 때
                int nx = i+mvx; // 3
                int ny = j+mvy; // 4

                if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;

                ans[nx][ny] = ans[nx][ny] || brd[d][g][i][j];
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (!ans[i][j] || !ans[i+1][j] || !ans[i][j+1] || !ans[i+1][j+1]) continue;
            realans++;
        }
    }

    cout << realans;

}