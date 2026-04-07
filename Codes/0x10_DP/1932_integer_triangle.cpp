#include <bits/stdc++.h>
using namespace std;

int N;
int T[502][502], D[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> T[i][j];
        }
    }

    D[1][1] = T[1][1];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            D[i][j] = max(D[i-1][j-1], D[i-1][j]) + T[i][j];
        }
    }

    cout << *max_element(D[N], D[N]+N+1);
}

// D[i][j] = 삼각형의 i번째(맨위층 기준) 층의 j번째(맨왼쪽 기준) 칸의 값을 마지막으로 더했을 때의 최댓값.