#include <bits/stdc++.h>
using namespace std;

// 8    
// 1 2 3 4 5 6 7 8
// 2 3 4 5 6 7 8 9
// 3 4 5 6 7 8 9 1
// 4 5 6 7 8 9 1 2
// 5 6 7 8 9 1 2 3
// 6 7 8 9 1 2 3 4
// 7 8 9 1 2 3 4 5
// 8 9 1 2 3 4 5 6

int N;
int brd[22][22], num[22][22], sum[6];
int ans = 99999999;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> brd[i][j];
        }
    }

    int d1 = 6, d2 = 1, x = 1, y = 7;

    int nx = x, ny = y;
    
    for (int i = 0; i < d1; i++) {
        num[nx][ny] = 5;
        nx++;
        ny--;
    }
    
    for (int i = 0; i < d2; i++) {
        num[nx][ny] = 5;
        nx++;
        ny++;
    }

    int endrow = nx, endcol = ny;

    for (int i = 0; i < d1; i++) {
        num[nx][ny] = 5;
        nx--;
        ny++;
    }

    for (int i = 0; i < d2; i++) {
        num[nx][ny] = 5;
        nx--;
        ny--;
    }

    bool inborder = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (num[i][j] != 5) {
                cout << brd[i][j] << ' ';

                if (inborder) {sum[5] += brd[i][j]; cout << 5 << '\n';}
                else if (i < x+d1 && j <= y) {sum[1] += brd[i][j]; cout << 1 << '\n';}
                else if (i <= x+d2 && j > y) {sum[2] += brd[i][j]; cout << 2 << '\n';}
                else if (i >= x+d1 && j < endcol) {sum[3] += brd[i][j]; cout << 3 << '\n';}
                else if (i > x+d2 && j >= endcol) {sum[4] += brd[i][j]; cout << 4 << '\n';}
            }

            else {
                cout << brd[i][j];
                sum[5] += brd[i][j];
                cout << " border!";
                if (i > x && i < endrow) {inborder = !inborder; cout << " border toggled : " << inborder;}
                cout << '\n';
            }
        }
        cout << '\n';
        fill(num[i], num[i]+21, 0);
    }

    ans = min(*max_element(sum+1, sum+6) - *min_element(sum+1, sum+6), ans);
    // fill (sum, sum+6, 0);

    cout << ans;
}