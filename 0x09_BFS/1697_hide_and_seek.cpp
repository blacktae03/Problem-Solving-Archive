#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S, B;
    queue<int> Q;
    int board[100001];
    int cur;
    fill(board, board+100001, 0);

    cin >> S >> B;
    Q.push(S);

    int dx[3] = {-1, 1, 2};
    
    if (S == B) { // 1
        cout << 0;
        return 0; 
    }

    while (!Q.empty()) {
        cur = Q.front(); Q.pop();

        for (int i = 0; i < 3; i++) {
            int nx;
            if(i == 2) {
                nx = cur*dx[i];
            }
            else {
                nx = cur+dx[i];
            }

            if (nx < 0 || nx >= 100001) continue;
            // 지금 설명이 잘 이해가 가지 않을 수 있습니다.
            // 이해가 가지 않더라도 상관은 없지만 이 문제에서
            // 당연히 수빈이가 0에서 100,000 사이에서만 움직인다고
            // 멋대로 가정을 하고 풀면 안된다는 점은 꼭 짚고 넘어가면 좋겠습니다.
            // 이 문제에서는 운 좋게 논리적으로 생각을 했을 때
            // 수빈이가 0에서 100,000 사이에서만 움직이게 되었지만
            // 다른 문제에서는 멋대로 가정한 것 때문에 말아먹을수도 있습니다.
            if (board[nx] > 0) continue;
            board[nx] = board[cur] + 1;
            if (nx == B) {
                cout << board[nx];
                return 0;
            } // 2
            Q.push(nx);
        }
    }

    //cout << board[B];
    // 1+2 대신 다 끝나고 출력해도 되긴하겠넹 ㅎㅎ;
}

