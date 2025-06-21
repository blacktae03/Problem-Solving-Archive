// 처음부터 벡터에 물고기 넣기. (v4 수정사항)
// 근데 이렇게 되면 잡아 먹은 물고기 반영하기가 빡셈. 어차피 remove_if 돌릴거면 시간복잡도 안좋아질듯
// 그냥 v4로 해보자.

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
queue<pair<pair<int, int>, shark>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int tr, tc;
        cin >> tr >> tc;
        cin >> brd[tr][tc].speed >> brd[tr][tc].direction >> brd[tr][tc].size;
        V.push_back({{tr, tc}, brd[tr][tc]});
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

        // 상어 이동 생략 가능
        // for (int rtmp = 1; rtmp <= R; rtmp++) {
            //     for (int ctmp = 1; ctmp <= C; ctmp++) {
                //         if (brd[rtmp][ctmp].size > 0)
                //             V.push_back({{rtmp, ctmp}, brd[rtmp][ctmp]});
                
                //         brd[rtmp][ctmp] = {0,0,0};
                //     }
                // }

        while(!Q.empty()) { // 그래서 이렇게 해야하는데 이러면 의미가 있나 싶음 사실 그냥 v4나 v5나 비슷할 듯
            V.push_back(Q.front());
            Q.pop();
        }

        for (auto & sh : V) {

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
    
            if (brd[mr][mc].size > sh.second.size) continue; // 도착한 자리에 더 큰 상어 있으면 죽음
            
            brd[mr][mc] = sh.second; // 없거나 내가 더 크면 내 자리
            // V.push_back({{mr, mc}, sh.second}); 벡터 range-based for문에서 중간에 푸쉬백하면 값을 원하는대로 참조하지 못함.
            // fishking_test.cpp 참고
            Q.push({{mr, mc}, sh.second});
        }

        V.clear();
    }

    cout << ans;
}