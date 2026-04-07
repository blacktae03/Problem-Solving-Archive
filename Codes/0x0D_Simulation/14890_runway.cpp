// 다시 생각해야겠는데?
#include <bits/stdc++.h>
using namespace std;

int N, L;
int brd[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        int cur = 0, length = 0;
        bool asc = 0;

        for (int j = 0; j < N; j++) {
            int tmp = brd[i][j] - cur;
            cur = brd[i][j];
            if (!j) continue;

            if (tmp) { // 다르면
                if (abs(tmp) > 1) break;
                if (asc)

                if (tmp == 1) { // 다음 칸이 더 크면
                    if (length < L) break;
                    // length -= L;
                }

                if (tmp == -1) { // 다음 칸이 더 작으면
                    asc = 1;
                }

                length = 0;
            }

            else {
                length++;
            }
        }
    }
}

// 일정한 높이가 유지되는 길을 한 묶음으로 봤을 때
// 0. 전 길의 높이보다 차이가 2이상 나면 그냥 탈락.
// 1. 올라가는 경사로만 필요한 경우 : 오른쪽 길이 나보다 1칸 높을 때 -> L칸 이상 필요
// 2. 내려가는 경사로만 필요한 경우 : 왼쪽 길이 나보다 1칸 높을 때 -> L칸 이상 필요
// 3. 양쪽에 둘 다 필요한 경우 : 왼쪽 길이 나보다 1칸 높고, 오른쪽 길이 나보다 1칸 높을 때 -> 2L칸 이상 필요
// 4. 필요없는 경우 : 왼쪽 길이 나보다 낮고, 오른쪽 길도 나보다 낮을 때 -> 0칸 필요
// 오른쪽 길이 나보다 높으면 case++
// 왼쪽 길이 나보다 높으면 case++
// case * L 보다 길의 길이가 작으면 탈락.
// 2*N만큼 반복