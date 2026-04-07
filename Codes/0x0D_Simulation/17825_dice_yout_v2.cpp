#include <bits/stdc++.h>
using namespace std;
#define PX loc[who].first
#define PY loc[who].second

int ans = 0, dice[10];
int brd[4][104] =
{
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0,},
    {10, 13, 16, 19, 25, 30, 35, 40, 0,},
    {20, 22, 24, 25, 30, 35, 40, 0,},
    {30, 28, 27, 26, 25, 30, 35, 40, 0,}
};
int on[4][104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) cin >> dice[i];

    // for (int T = 0; T < 1<<(2*10); T++) {
        // dice = 5 1 2 3 4 5 5 3 2 4
        //int test[10] = {0,0,1,1,1,0,2,3,0,1}; // 10+13+4+10+25+35+10+6+0+0 = 113 TC1
        //int test[10] = {0,0,0,0,0,1,1,1,2,2}; // 10+13+19+35+0+10+30+0+4+12 = 133 TC2
        //int test[10] = {1,1,1,1,1,2,2,2,3,3}; // TC2와 결과 동일 TC3
        int test[10] = {1,1,2,1,0,0,0,1,0,0}; // 10+13+4+25+8+18+28+40+32+40 = 218 // 이유 알았다 8번째랑 10번째에서 40을 두번 더함. 와 그러면 25도 겹치면 안되네 ㅅㅂ 30 35도 마찬가지..
        int T = 0;
        for (int i = 9; i >= 0; i--) {
            T *= 4;
            T += test[i];
        }
        pair<int, int> loc[4] = {{0,0}, {0,0}, {0,0}, {0,0}};
        int score = 0;
        bool fault = 0;
        for (int i = 0; i < 4; i++) fill(on[i], on[i]+104, 0);

        int brute = T;
        
        for (int i = 0; i < 10; i++) {
            int who = brute % 4;
            brute /= 4;
            if (i && loc[0].second == 100 && loc[1].second == 100 && loc[2].second == 100 && loc[3].second == 100) break;

            if(PY == 100) {
                fault = 1;
                break;
            }
            
            on[PX][PY] = 0;
            
            PY += dice[i];
            if (PX == 0 && PY % 5 == 0 && PY < 20) {
                PX += PY / 5;
                PY = 0;
            }
            
            if (on[PX][PY]) {
                fault = 1;
                break;
            }
            
            if (brd[PX][PY]) on[PX][PY] = who+1;
            else PY = 100;
            score += brd[PX][PY];
            cout << brd[PX][PY] << ' ';
        }
        cout << '\n';

        cout << fault << '\n';
        if (fault) return 0;
        
        // if (fault) continue;
        ans = max(ans, score);
    // }

    cout << ans;
}