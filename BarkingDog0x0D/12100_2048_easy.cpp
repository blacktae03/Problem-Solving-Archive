#include <bits/stdc++.h>
using namespace std;

int N, mx;
int brd[22][22], brd2[22][22];
deque<pair<int, bool>> DQ;

void up() {
    for (int i = 0; i < N; i++) { // 첫번째 열부터 아래 코드 실행
        for (int j = 0; j < N; j++) { // 각 열마다 모든 행 위에서 아래로 스캔
            if (!brd2[j][i]) continue; // 0이면 아무것도 안함

            if (DQ.empty() || DQ.back().first != brd2[j][i] || DQ.back().second) { // 첫번째 0이 아닌 숫자이거나 젤 최근에 나온 0이 아닌 숫자와 다른 0이 아닌 숫자면
                DQ.push_back({brd2[j][i], 0}); // 그 숫자 덱에 넣기
            }

            else { // 덱이 비어있지 않고, 제일 최근에 나온 0이 아닌 숫자와 같은 숫자면
                DQ.pop_back(); // 그 숫자 덱에서 빼고
                DQ.push_back({brd2[j][i] * 2, 1}); // 두 배 한 숫자 덱 뒤에 넣기.
            } // 이렇게 하면 2 2 4 8 일 때 16되네 이게 문제였어 4 4 8 되는게 정상.
            brd2[j][i] = 0;
        }

        for (int j = 0; j < N; j++) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front().first;
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}

void down() {
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--) {
            if (!brd2[j][i]) continue;
            if (DQ.empty() || DQ.back().first != brd2[j][i] || DQ.back().second) {
                DQ.push_back({brd2[j][i], 0});
            }
            else {
                DQ.pop_back();
                DQ.push_back({brd2[j][i] * 2, 1});
            }
            brd2[j][i] = 0;
        }

        for (int j = N-1; j >= 0; j--) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front().first;
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}

void left() {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (!brd2[j][i]) continue;
            if (DQ.empty() || DQ.back().first != brd2[j][i] || DQ.back().second) {
                DQ.push_back({brd2[j][i], 0});
            }
            else {
                DQ.pop_back();
                DQ.push_back({brd2[j][i] * 2, 1});
            }
            brd2[j][i] = 0;
        }

        for (int i = 0; i < N; i++) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front().first;
            mx = max(brd2[j][i], mx);
            DQ.pop_front();
        }
    }
}

void right() {
    for (int j = 0; j < N; j++) {
        for (int i = N-1; i >= 0; i--) {
            if (!brd2[j][i]) continue;
            if (DQ.empty() || DQ.back().first != brd2[j][i] || DQ.back().second) {
                DQ.push_back({brd2[j][i], 0});
            }
            else {
                DQ.pop_back();
                DQ.push_back({brd2[j][i] * 2, 1});
            }
            brd2[j][i] = 0;
        }

        for (int i = N-1; i >= 0; i--) {
            if (DQ.empty()) break;
            brd2[j][i] = DQ.front().first;
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