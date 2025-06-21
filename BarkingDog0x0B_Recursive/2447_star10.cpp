#include <bits/stdc++.h>
using namespace std;

char brd[2187][2187];

void star(int n, int x1, int y1, int x2, int y2) {
    if (n == 1) {
        brd[x1][y1] = '*';
        return;
    }

    for (int i = (2*x1+x2)/3+1; i <= (x1+2*x2)/3; i++) 
        for (int j = (2*y1+y2)/3+1; j <= (y1+2*y2)/3; j++)
            brd[i][j] = ' ';

    star(n/3, x1, y1, (2*x1+x2)/3, (2*y1+y2)/3);
    star(n/3, x1, (2*y1+y2)/3+1, (2*x1+x2)/3, (y1+2*y2)/3);
    star(n/3, x1, (y1+2*y2)/3+1, (2*x1+x2)/3, y2);
    star(n/3, (2*x1+x2)/3+1, y1, (x1+2*x2)/3, (2*y1+y2)/3);
    //star (n/3, (2*x1+x2)/3+1, (2*y1+y2)/3+1, (x1+2*x2)/3, (y1+2*y2)/3);
    star(n/3, (2*x1+x2)/3+1, (y1+2*y2)/3+1, (x1+2*x2)/3, y2);
    star(n/3, (x1+2*x2)/3+1, y1, x2, (2*y1+y2)/3);
    star(n/3, (x1+2*x2)/3+1, (2*y1+y2)/3+1, x2, (y1+2*y2)/3);
    star(n/3, (x1+2*x2)/3+1, (y1+2*y2)/3+1, x2, y2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    star(n, 0, 0, n-1, n-1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << brd[i][j];
        }
        cout << '\n';
    }
}