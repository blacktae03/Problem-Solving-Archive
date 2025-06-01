#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int r, c, sticker;
int rtmp, ctmp, cnt;
bool sticked;
bool brd[43][43], tmp[43][43], tmp90[43][43], tmp180[43][43], tmp270[43][43];

bool sticking(int angle, int j, int k) {
    switch(angle) {
        case 0 :
            for (int dx = 0; dx < rtmp; dx++)
                for (int dy = 0; dy < ctmp; dy++)
                    if (tmp[dx][dy] && brd[j+dx][k+dy]) return false;
        
            for (int dx = 0; dx < rtmp; dx++) {
                for (int dy = 0; dy < ctmp; dy++) {
                    if (brd[j+dx][k+dy]) continue;
                    brd[j+dx][k+dy] = tmp[dx][dy];
                }
            }
            
            return true;

        case 90 :
            for (int dx = 0; dx < ctmp; dx++)
                for (int dy = 0; dy < rtmp; dy++)
                    if (tmp90[dx][dy] && brd[j+dx][k+dy]) return false;
        
            for (int dx = 0; dx < ctmp; dx++) {
                for (int dy = 0; dy < rtmp; dy++) {
                    if (brd[j+dx][k+dy]) continue;
                    brd[j+dx][k+dy] = tmp90[dx][dy];
                }
            }
            
            return true;

        case 180 :
            for (int dx = 0; dx < rtmp; dx++)
                for (int dy = 0; dy < ctmp; dy++)
                    if (tmp180[dx][dy] && brd[j+dx][k+dy]) return false;
        
            for (int dx = 0; dx < rtmp; dx++) {
                for (int dy = 0; dy < ctmp; dy++) {
                    if (brd[j+dx][k+dy]) continue;
                    brd[j+dx][k+dy] = tmp180[dx][dy];
                }
            }
            
            return true;

        case 270 :
            for (int dx = 0; dx < ctmp; dx++)
                for (int dy = 0; dy < rtmp; dy++)
                    if (tmp270[dx][dy] && brd[j+dx][k+dy]) return false;
        
            for (int dx = 0; dx < ctmp; dx++) {
                for (int dy = 0; dy < rtmp; dy++) {
                    if (brd[j+dx][k+dy]) continue;
                    brd[j+dx][k+dy] = tmp270[dx][dy];
                }
            }

            return true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> sticker;

    for (int i = 0; i < sticker; i++) { // 스티커 개수 만큼 스티커 만들고 붙일 수 있는지 확인하기.
        sticked = false;

        cin >> rtmp >> ctmp;

        for (int j = 0; j < rtmp; j++) {
            for (int k = 0; k < ctmp; k++) {
                cin >> tmp[j][k];
            }
        } // 스티커 모눈 종이 만들기

        if (!sticked) { // 0도 회전
            for (int j = 0; j <= r - rtmp; j++) {
                for (int k = 0; k <= c - ctmp; k++) {
                    if (sticked) break;
                    sticked = sticking(0, j, k);
                }
            }
        }
        
        if (!sticked) { // 90도 회전
            for (int j = 0; j < ctmp; j++)
                for (int k = 0; k < rtmp; k++)
                    tmp90[j][k] = tmp[rtmp-(1+k)][j];

            for (int j = 0; j <= r - ctmp; j++) {
                for (int k = 0; k <= c - rtmp; k++) {
                    if (sticked) break;
                    sticked = sticking(90, j, k);
                }
            }
        }


        
        if (!sticked) { // 180도 회전
            for (int j = 0; j < rtmp; j++)
                for (int k = 0; k < ctmp; k++)
                    tmp180[j][k] = tmp[rtmp-(1+j)][ctmp-(1+k)];

            for (int j = 0; j <= r - rtmp; j++) {
                for (int k = 0; k <= c - ctmp; k++) {
                    if (sticked) break;
                    sticked = sticking(180, j, k);
                }
            }
        }

        
        if (!sticked) { // 270도 회전
            for (int j = 0; j < ctmp; j++)
                for (int k = 0; k < rtmp; k++)
                    tmp270[j][k] = tmp[k][ctmp-(1+j)];

            for (int j = 0; j <= r - ctmp; j++) {
                for (int k = 0; k <= c - rtmp; k++) {
                    if (sticked) break;
                    sticked = sticking(270, j, k);
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cnt += brd[i][j];

    cout << cnt;
}