#include <bits/stdc++.h>
using namespace std;
#define X first.first
#define Y first.second
// 250610 이거 제출해보고 안되면 v2에다가 입력받을 때부터 벡터에 값 넣는거 고려해보기
// 그래야 3중 반복문까지 안씀. 근데 어차피 물고기가 격자 안에 다 있다는 가정하에 3중 반복문이랑
// 같은 시간복잡도를 가지기는 할텐데 모르겠네..

struct shark {
    int speed, direction, size;
};

int R, C, M, ans;
shark brd[105][105];
int num[105][105];

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
        
        // cout << j << " before fish\n";
        // for (int a = 1; a <= R; a++) {
        //     for (int b = 1; b <= C; b++) {
        //         cout << brd[a][b].size << ' ';
        //     }
        //     cout << '\n';
        // }
        
        
        for (int i = 1; i <= R; i++) { // 상어 잡기
            if(brd[i][j].size > 0 && num[i][j] == j-1) {
                ans += brd[i][j].size;
                brd[i][j] = {0,0,0};
                num[i][j] = 0;
                break;
            }
        }
        
        // cout << j << " after fish\n";
        // for (int a = 1; a <= R; a++) {
        //     for (int b = 1; b <= C; b++) {
        //         cout << brd[a][b].size << ' ';
        //     }
        //     cout << '\n';
        // }
        // 상어 이동
        for (int rtmp = 1; rtmp <= R; rtmp++) {
            for (int ctmp = 1; ctmp <= C; ctmp++) {
                if (brd[rtmp][ctmp].size == 0) continue;
                if (num[rtmp][ctmp] == j) continue;
                
                pair<pair<int, int>, shark> sh = {{rtmp, ctmp}, brd[rtmp][ctmp]};
                brd[rtmp][ctmp] = {0,0,0};
                // rtmp, ctmp는 이동할 상어의 좌표
                // mr, mc는 이동 후 상어의 좌표
                
                int stmp = sh.second.speed; // 밥먹고 와서 brd[sh.X][sh.Y] 다 sh.second로 바꾸기
                int mr = sh.X, mc = sh.Y;
        
                while(stmp--) { 
                    
                    switch(sh.second.direction) { // 벽이면 방향 바꾸기
                        case 1:
                            if (mr == 1) sh.second.direction = 2;
                            break;
        
                        case 2:
                            if (mr == R) sh.second.direction = 1;
                            break;
                        
                        case 3:
                            if (mc == C) sh.second.direction = 4;
                            break;
                        
                        case 4:
                            if (mc == 1) sh.second.direction = 3;
                            break;
                    }
                    
                    switch(sh.second.direction) { // 이동
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
        
                if (brd[mr][mc].size > sh.second.size && j == num[mr][mc]) continue; // 도착한 자리에 더 큰 상어 있으면 죽음
                num[mr][mc] = j;
                brd[mr][mc] = sh.second; // 없거나 내가 더 크면 내 자리

                // brd[rtmp][ctmp] = {0,0,0};
            }
        }
    }

    cout << ans;
}