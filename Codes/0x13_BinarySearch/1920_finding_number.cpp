#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto start = clock();

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        bool ans = 0;
        int idx = N/2;

        while(true) {
            if (A[idx] == num) {
                ans = 1;
                break;
            }
            
            else {
                int tmp = idx;
                idx = A[idx] < num ? (idx + N) / 2 : idx / 2;
                if (tmp == idx) break;
            }
        }

        cout << ans << '\n';
    }

    auto finish = clock();

    cout << finish-start;
}
// 안되는 이유
// input :
// 9
// 0 1 2 3 4 5 6 7 8
// 1
// 3
// 이면 무한루프 이유는 간단함. 그냥 ㅂㅅ처럼 짰음;;