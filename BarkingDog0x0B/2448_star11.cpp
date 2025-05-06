#include <bits/stdc++.h>
using namespace std;

char brd[3200][6400];

void star(int n, int x1, int y1) {
    if (n == 3) {
        brd[x1][y1] = '*';
        brd[x1+1][y1-1] = '*';
        brd[x1+1][y1+1] = '*';
        brd[x1+2][y1-2] = '*';
        brd[x1+2][y1-1] = '*';
        brd[x1+2][y1] = '*';
        brd[x1+2][y1+1] = '*';
        brd[x1+2][y1+2] = '*';
        return;
    }

    int nxt = n/2;

    star(nxt, x1, y1);
    star(nxt, x1+nxt, y1-nxt);
    star(nxt, x1+nxt, y1+nxt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++)
        fill(brd[i], brd[i]+n*2-1, ' ');
    
    star(n, 0, n-1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n*2-1; j++) {
            cout << brd[i][j];    
        }
        cout << '\n';
    }
}