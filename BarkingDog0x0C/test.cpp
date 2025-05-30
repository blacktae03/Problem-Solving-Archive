#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int brd[50][50], grow[10];
int r, c, green, red, grcnt;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> r >> c >> green >> red;

    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cin >> brd[i][j];
    //         if (brd[i][j] == 2) grcnt++;
    //     }
    // }

    fill(grow, grow+3, 1);
    fill(grow+3, grow+6, 2);
    cout << grow[0] << grow[2] << grow[3];
}