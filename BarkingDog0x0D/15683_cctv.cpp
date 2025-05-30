#include <bits/stdc++.h>
using namespace std;

int r, c, cnt;
int brd[8][8];
int cctv[8], kind[8];

void comb(int k) {
    if (k == cnt) {

    }

    switch(cctv[k]) {
        case 5: 
            comb(k+1);
            break;
        case 2:
            for (int i = 0; i < 2; i++) comb(k+1);
            break;
        case 1:
        case 3:
        case 4:
            for (int i = 0; i < 4; i++) comb(k+1);
            break;
    }

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
            if (brd[i][j] != 0 && brd[i][j] != 6) cnt++;

        }
    }

    while()
}