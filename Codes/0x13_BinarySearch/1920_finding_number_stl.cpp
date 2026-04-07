#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        cout << binary_search(A, A+N, num) << '\n';
    }
}
// STL을 활용한 방법.
// binary_search 함수를 사용할 때는 오름차순으로 정렬된 배열에서만 사용할 것.