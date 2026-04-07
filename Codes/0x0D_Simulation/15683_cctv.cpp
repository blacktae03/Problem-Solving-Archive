#include <bits/stdc++.h>
using namespace std;

int r, c, cnt;
int brd[8][8];
int tmp[8][8];
int cctv[8], kind[8];
pair<int, int> loc[8];
int ans = 100;

bool oob(int & x, int & y) {
    return x < 0 || x >= r || y < 0 || y >= c || tmp[x][y] == 6;
}

void back(int i, int & x, int & y) {
    x = loc[i].first;
    y = loc[i].second;
}

void right(int i, int & x, int & y) {
    while (true) {
        if (oob(x, y)) break;
        tmp[x][y] = 7;
        y++;
    }
    back(i, x, y); 
}

void left(int i, int & x, int & y) {
    while (true) {
        if (oob(x, y)) break;
        tmp[x][y] = 7;
        y--;
    }
    back(i, x, y); 
}

void up(int i, int & x, int & y) {
    while (true) {
        if (oob(x, y)) break;
        tmp[x][y] = 7;
        x--;
    }
    back(i, x, y); 
}

void down(int i, int & x, int & y) {
    while (true) {
        if (oob(x, y)) break;
        tmp[x][y] = 7;
        x++;
    }
    back(i, x, y); 
}

void comb(int k) {
    if (k == cnt) {
        int zero_cnt = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                tmp[i][j] = brd[i][j];
            }
        }

        for (int i = 0; i < cnt; i++) {
            int x = loc[i].first;
            int y = loc[i].second;

            switch(kind[i]) {
                case 0:
                    if (cctv[i] == 1) {
                        right(i, x, y);
                    }
                    else if (cctv[i] == 2) {
                        right(i, x, y);
                        left(i, x, y);
                    }
                    else if (cctv[i] == 3) {
                        up(i, x, y);
                        right(i, x, y);
                    }
                    else if (cctv[i] == 4) {
                        up(i, x, y); 
                        right(i, x, y); 
                        left(i, x, y); 
                    }
                    else if (cctv[i] == 5) {
                        up(i, x, y); 
                        down(i, x, y); 
                        left(i, x, y); 
                        right(i, x, y);
                    }
                    break;
                
                case 1:
                    if (cctv[i] == 1) {
                        down(i, x, y); 
                    }
                    else if (cctv[i] == 2) {
                        down(i, x, y); 
                        up(i, x, y); 
                    }
                    else if (cctv[i] == 3) {
                        right(i, x, y); 
                        down(i, x, y); 
                    }
                    else if (cctv[i] == 4) {
                        up(i, x, y); 
                        down(i, x, y); 
                        right(i, x, y); 
                    }
                    break;
                
                case 2:
                    if (cctv[i] == 1) {
                        left(i, x, y); 
                    }
                    else if (cctv[i] == 3) {
                        left(i, x, y); 
                        down(i, x, y); 
                    }
                    else if (cctv[i] == 4) {
                        down(i, x, y); 
                        left(i, x, y); 
                        right(i, x, y); 
                    }
                    break;
                
                case 3:
                    if (cctv[i] == 1) {
                        up(i, x, y); 
                    }
                    else if (cctv[i] == 3) {
                        up(i, x, y); 
                        left(i, x, y); 
                    }
                    else if (cctv[i] == 4) {
                        left(i, x, y); 
                        down(i, x, y); 
                        up(i, x, y); 
                    }
                break;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (tmp[i][j] == 0) zero_cnt++;
            }
        }

        ans = min(ans, zero_cnt);

        return;
    }

    switch(cctv[k]) {
        case 5:
            kind[k] = 0; 
            comb(k+1);
            
            break;
        case 2:
            for (int i = 0; i < 2; i++) { kind[k] = i; comb(k+1); }
            break;
        case 1:
        case 3:
        case 4:
            for (int i = 0; i < 4; i++) { kind[k] = i; comb(k+1); }
            break;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
            if (brd[i][j] != 0 && brd[i][j] != 6) {
                cctv[cnt] = brd[i][j];
                kind[cnt] = 0; // Initialize kind to 0
                loc[cnt].first = i;
                loc[cnt].second = j;
                cnt++;
            }
        }
    }

    comb(0);

    cout << ans;
}