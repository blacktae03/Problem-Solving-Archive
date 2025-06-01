#include <bits/stdc++.h>
using namespace std;

int N, mx;
int brd[22][22], brd2[22][22];
deque<int> DQ;

void up() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!brd2[j][i]) continue;

            if (DQ.empty() || DQ.back() != brd2[j][i]) {
                DQ.push_back(brd2[j][i]);
            }

            else {
                DQ.pop_back();
                DQ.push_back(brd2[j][i] * 2);
            }
            brd2[j][i] = 0;
        }

        for (int j = 0; j < N; j++) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front();
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}

void down() {
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (!brd2[j][i]) continue;
            if (DQ.empty() || DQ.back() != brd2[j][i]) {
                DQ.push_back(brd2[j][i]);
            }
            else {
                DQ.pop_back();
                DQ.push_back(brd2[j][i] * 2);
            }
            brd2[j][i] = 0;
        }

        for (int j = N-1; j >= 0; j--) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front();
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}

void left() {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (!brd2[j][i]) continue;
            if (DQ.empty() || DQ.back() != brd2[j][i]) {
                DQ.push_back(brd2[j][i]);
            }
            else {
                DQ.pop_back();
                DQ.push_back(brd2[j][i] * 2);
            }
            brd2[j][i] = 0;
        }

        for (int i = 0; i < N; i++) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front();
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}

void right() {
    for (int j = 0; j < N; j++) {
        for (int i = N-1; i >= 0; i--) {
            if (!brd2[j][i]) continue;
            if (DQ.empty() || DQ.back() != brd2[j][i]) {
                DQ.push_back(brd2[j][i]);
            }
            else {
                DQ.pop_back();
                DQ.push_back(brd2[j][i] * 2);
            }
            brd2[j][i] = 0;
        }

        for (int i = N-1; i >= 0; i--) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front();
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
            mx = max(mx, brd[i][j]);       
        }
    }

    for (int i = 0; i < 4*4*4*4*4; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                brd2[j][k] = brd[j][k];
            }
        }

        int tmp = i;
        for (int j = 0; j < 5; j++) {
            int way = tmp % 4;
            tmp /= 4;

            switch(way) {
                case 0 : // up
                    up();
                    break;

                case 1 : // down
                    down();
                    break;

                case 2 : // left
                    left();
                    break;

                case 3 : // right
                    right();
                    break;
            }
        }

        
    }

    cout << mx;
}