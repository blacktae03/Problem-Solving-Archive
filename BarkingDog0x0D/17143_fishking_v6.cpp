// 딱 알았다 v2에서 이동하는 부분만 줄이면 될 거 같음.

#include <bits/stdc++.h>
using namespace std;
#define X first.first
#define Y first.second

struct shark {
    int speed, direction, size;
};

int R, C, M, ans;
shark brd[105][105];
vector<pair<pair<int, int>, shark>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int tr, tc;
        cin >> tr >> tc;
        cin >> brd[tr][tc].speed >> brd[tr][tc].direction >> brd[tr][tc].size;
        // 처음부터 벡터에 이 값을 넣는게 답일 수도.
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
            if(brd[i][j].size > 0) {
                ans += brd[i][j].size;
                brd[i][j] = {0,0,0};
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
                if (brd[rtmp][ctmp].size > 0)
                    V.push_back({{rtmp, ctmp}, brd[rtmp][ctmp]});
                
                brd[rtmp][ctmp] = {0,0,0};
            }
        }

        for (auto & sh : V) {

            int stmp = sh.second.speed; // 밥먹고 와서 brd[sh.X][sh.Y] 다 sh.second로 바꾸기
            int mr = sh.X, mc = sh.Y;

            while(stmp > 0) {
                switch(sh.second.direction) {
                    case 1:
                        mr -= stmp;
                        stmp = 1-mr;
    
                        if (mr < 1) {
                            mr = 1;
                            sh.second.direction = 2;
                        }
                        break; // case 마다 break 안넣어서 쳐 틀려서 나중에 풀려고 보류 한 게 ㅈㄴ 어이가없네

                    case 2:
                        mr += stmp;
                        stmp = mr-R;
    
                        if (mr > R) {
                            mr = R;
                            sh.second.direction = 1;
                        }
                        break;

                    case 3:
                        mc += stmp;
                        stmp = mc-C;
    
                        if (mc > C) {
                            mc = C;
                            sh.second.direction = 4;
                        }
                        break;

                    case 4:
                        mc -= stmp;
                        stmp = 1-mc;
    
                        if (mc < 1) {
                            mc = 1;
                            sh.second.direction = 3;
                        }
                }
            }
            
            // while(stmp--) { 
                
            //     switch(sh.second.direction) { // 벽이면 방향 바꾸기
            //         case 1:
            //             if (mr == 1) sh.second.direction = 2;
            //             break;
    
            //         case 2:
            //             if (mr == R) sh.second.direction = 1;
            //             break;
                    
            //         case 3:
            //             if (mc == C) sh.second.direction = 4;
            //             break;
                    
            //         case 4:
            //             if (mc == 1) sh.second.direction = 3;
            //             break;
            //     }
                
            //     switch(sh.second.direction) { // 이동
            //         case 1:
            //             mr--;
            //             break;
    
            //         case 2:
            //             mr++;
            //             break;
                    
            //         case 3:
            //             mc++;
            //             break;
                    
            //         case 4:
            //             mc--;
            //             break;
            //     }
    
            //}
    
            if (brd[mr][mc].size > sh.second.size) continue; // 도착한 자리에 더 큰 상어 있으면 죽음
    
            brd[mr][mc] = sh.second; // 없거나 내가 더 크면 내 자리
        }

        V.clear();
    }

    cout << ans;
}