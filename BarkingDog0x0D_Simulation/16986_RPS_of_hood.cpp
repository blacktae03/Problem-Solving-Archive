// 분명 ㅈㄴ 어려웠는데 개짧게 짜서 기분 개좋음.
#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[11][11];
int order[4][21];
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 20; j++) {
            cin >> order[i][j];
        }
    }

    for (int i = 1; i <= N; i++) order[0][i] = i;

    do {
        int p1 = 0, p2 = 1;
        int torder[3] = {0,0,0};
        int win[3] = {0,0,0};

        while(true) {
            torder[p1]++;
            torder[p2]++;

            if (order[p1][torder[p1]] == 0 || order[p2][torder[p2]] == 0) break;
            
            if (p1 > p2) swap(p1, p2);
            // 바꾸는 이유 : 바로 아래에 있는 조건문과 else로 간단하게 구현할려면 무조건 p1이 앞 순서인 사람이어야 함.
            // 무조건 앞 순서여야 1이어도 지는 게 확정적으로 가능.

            if (A[order[p1][torder[p1]]][order[p2][torder[p2]]] == 2) {
                if (++win[p1] == K) break;
                do {
                    p2 = (p2+1) % 3;  
                } while(p1 == p2);
            }

            else {
                if (++win[p2] == K) break;
                do {
                    p1 = (p1+1) % 3;
                } while(p1 == p2);
            }
        }

        if (win[0] == K) ans = 1;

        // if (ans) {
        //     for (int i = )
        // }

    } while(next_permutation(order[0]+1, order[0]+N+1));

    cout << ans;
}
// 아 볼펜 없으니까 너무 힘들다... 내일부턴 챙겨다녀야지..
// 5 2
// 1 0 0 0 2
// 2 1 0 0 2
// 2 2 1 2 0
// 2 2 0 1 0
// 0 0 2 2 1
// 3 5 1 5 2 2 4 5 4 4 1 5 4 3 2 4 3 4 3 4
// 3 1 3 4 1 1 1 1 3 1 2 1 1 1 3 3 4 1 1 3
// 경기 순서는 지우 경희 민호 순.
// 1.
// 지우가 처음에 5를 내서 경희의 3을 이긴다. 지우 1승 / 5 소진
// 지우가 5를 못 내서 4를 내서 민호의 3에게 진다. 민호 1승 / 4 소진
// 경희와 민호가 5와 1로 싸운다. 민호 2승 끝.
// 2.
// 지우가 처음에 4를 내서 경희의 3에게 진다. 경희 1승 / 4 소진
// 경희와 민호가 5와 3으로 싸운다. 경희 2승;;