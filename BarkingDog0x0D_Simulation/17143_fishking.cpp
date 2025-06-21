#include <bits/stdc++.h>
using namespace std;

struct shark {
    int speed, direction, size;
};

int R, C, M, ans;
shark brd[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int tr, tc;
        cin >> tr >> tc;
        cin >> brd[tr][tc].speed >> brd[tr][tc].direction >> brd[tr][tc].size;
    }

    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) { // 상어 잡기
            if(brd[i][j].size > 0) {
                ans += brd[i][j].size;
                brd[i][j] = {0,0,0};
                break;
            }
        }

        // 상어 이동
        for (int rtmp = 1; rtmp <= R; rtmp++) {
            for (int ctmp = 1; ctmp <= C; ctmp++) {
                int stmp = brd[rtmp][ctmp].speed;
                int mr = rtmp, mc = ctmp;
    
                while(stmp--) { 
                    switch(brd[rtmp][ctmp].direction) { // 벽이면 방향 바꾸기
                        case 1:
                            if (mr == 1) brd[rtmp][ctmp].direction = 2;
                            break;
    
                        case 2:
                            if (mr == R) brd[rtmp][ctmp].direction = 1;
                            break;
                        
                        case 3:
                            if (mc == C) brd[rtmp][ctmp].direction = 4;
                            break;
                        
                        case 4:
                            if (mc == 1) brd[rtmp][ctmp].direction = 3;
                            break;
                    }
                    
                    switch(brd[rtmp][ctmp].direction) { // 이동
                        case 1:
                            mr--;
                            break;
    
                        case 2:
                            mr++;
                            break;
                        
                        case 3:
                            mc++;
                            break;
                        
                        case 4:
                            mc--;
                            break;
                    }
    
                }

                if (brd[mr][mc].size > brd[rtmp][ctmp].size) {}
    
                brd[mr][mc] = brd[rtmp][ctmp];
                brd[rtmp][ctmp] = {0,0,0};
            }
        }
    }
}