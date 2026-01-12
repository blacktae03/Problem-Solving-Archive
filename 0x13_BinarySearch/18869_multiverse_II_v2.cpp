#include <bits/stdc++.h>
using namespace std;

int M, N, ans;
pair<int, int> A[104][10004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            A[i][j] = {tmp, j};
        }

        sort(A[i], A[i]+N, [](pair<int, int> a, pair<int, int> b) {
            return a.first <= b.first;
        });
        
        for (int j = 1; j < N; j++) {
            if (A[i][j].first == A[i][j-1].first) A[i][j].second = A[i][j-1].second;
        }
    }

    for (int i = 0; i < M-1; i++) {
        for (int j = i+1; j < M; j++) {
            int k;
            for (k = 0; k < N; k++) {
                if (lower_bound(A[j], A[j]+N, A[i][k]))
                if (A[i][k].second != A[j][k].second) break;
            }
            if (k == N) ans++;
        }
    }

    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << '{' << A[i][j].first << ", " << A[i][j].second << "}, ";
    //     }
    //     cout << '\n';
    // }

    cout << ans;
}
// 가장 간단한 풀이 : pair로 저장 한다. {cin, idx}; O(M*NlgN)
// 정렬 후, idx의 순서가 같은 지 판단한다. O(M^2*N);
// 반례 발견 :
// 2 4
// 2 0 1 2
// 99 44 77 100
// 이것도 균등한 우주쌍으로 처리하게 됨.
// 같은 크기 끼리는 순서가 바뀌게 해야할 듯.
// 근데 이렇게 하면
// 2 4
// 2 0 1 2
// 100 44 77 99 했을 때 또 같은 쌍;;;;;;;;;;
// 같은 거 끼리는 second가 같게 만들어 주면서 해결 (24-26) 정렬하고 하는 거라 O(N) 밖에 안 걸림.
// 근데 내 풀이는 이분탐색이 없어.