#include <bits/stdc++.h>
using namespace std;
#define PX loc[who].first
#define PY loc[who].second

int ans, dice[10];
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

    for (int T = 0; T < 1<<(2*10); T++) {
        pair<int, int> loc[4] = {{0,0}, {0,0}, {0,0}, {0,0}};
        int score = 0;
        bool fault = 0;
        for (int i = 0; i < 4; i++) fill(on[i], on[i]+104, 0);

        int brute = T;
        
        for (int i = 0; i < 10; i++) {
            int who = brute % 4;
            brute /= 4;
            if (i && loc[0].second == 100 && loc[1].second == 100 && loc[2].second == 100 && loc[3].second == 100) break;

            if(PY == 100) { //if((PX || PY) && !brd[PX][PY]) {
                fault = 1;
                break;
            }
            
            on[PX][PY] = 0;
            
            PY += dice[i];
            if (PX == 0 && PY % 5 == 0 && PY < 20) {
                PX += PY / 5;
                PY = 0;
            }

            else if (brd[PX][PY] == 40) PX = 0, PY = 20; // 이거 else if 가 아니라 if 하면 왜 안되지??
            // 왜 안되냐면 이미 43번 줄에서 10, 20, 30에 따라 처리를 했는데 48번 줄이 if면 51-53에 조건이 맞는 게 나올 때까지 조건문을 돌게 되는데
            // 그러면 30인 경우에는 52번줄에서 걸리게 됨. 우리가 바라는 구현이 아님.
            else if (brd[PX][PY] == 25) PX = 1, PY = 4;
            else if (brd[PX][PY] == 30 && PX) PX = 1, PY = 5;
            else if (brd[PX][PY] == 35) PX = 1, PY = 6;
            
            if (on[PX][PY]) {
                fault = 1;
                break;
            }
            
            if (brd[PX][PY]) on[PX][PY] = who+1;
            else PY = 100;
            score += brd[PX][PY];
        }
        // if (score == 218) cout << T << '\n';
        
        if (fault) continue;
        ans = max(ans, score);
    }

    cout << ans;
}