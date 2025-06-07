#include <bits/stdc++.h>
using namespace std;

int N, ans;
int play[50][9];
int player[8] = {1,2,3,4,5,6,7,8};
bool base[3];

int run(int grade) {
    int tmpscore = 0;
    bool newbase[3];
    newbase[0] = base[0];
    newbase[1] = base[1];
    newbase[2] = base[2];

    fill(base, base+3, 0);

    for (int i = 0; i < 3; i++) {
        int nx = i + grade;

        if (nx < 3) base[nx] = newbase[i];
        else if (newbase[i]) tmpscore++;
    }

    if (grade == 4) tmpscore++;
    else base[grade-1] = 1;

    return tmpscore;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> play[i][j];
        }
    }

    do {
        int score = 0, turn = 0;

        for (int i = 0; i < N; i++) { // n이닝까지
            int out = 0;
            base[0] = 0;
            base[1] = 0;
            base[2] = 0;
    
            while(out < 3) { // 3out 될 때까지
                int grade;

                if (turn % 9 == 3) grade = play[i][0];
                else if (turn % 9 < 3) grade = play[i][player[turn % 9]];
                else grade = play[i][player[turn % 9 - 1]];

                // 1, 2, 3, 0, 4, 5, 6, 7, 8
                // 1, 2, 3, 0, 4, 5, 6, 8, 7

                switch(grade) {
                    case 0 :
                        out++;
                        break;

                    default :
                        score += run(grade);
                }
                
                turn++;

                // cout << score << ' ' << base[0] << base[1] << base[2];
            }
        }

        ans = max(ans, score);

    } while(next_permutation(player, player+8));

    // int score = 0, turn = 0;

    // for (int i = 0; i < N; i++) { // n이닝까지
    //     int out = 0;

    //     while(out < 3) { // 3out 될 때까지
    //         int grade;

    //         if (turn % 9 == 3) grade = play[i][0];
    //         else if (turn % 9 < 3) grade = play[i][player[turn % 9]];
    //         else grade = play[i][player[turn % 9 - 1]];

    //         // 1, 2, 3, 0, 4, 5, 6, 7, 8
    //         // 1, 2, 3, 0, 4, 5, 6, 8, 7

    //         switch(grade) {
    //             case 0 :
    //                 out++;
    //                 break;

    //             default :
    //                 score += run(grade);
    //         }
            
    //         turn++;

    //         cout << score << ' ' << out << ' ' << base[0] << base[1] << base[2] << '\n';
    //     }
    // }

    cout << ans;
}