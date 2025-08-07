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
        int st = 0, en = N;
        bool ans = 0;
        int mid = (st+en)/2;

        while(st <= en) {
            // if (en-st < 0) break; // 아니 이렇게 처리하면 근데 더 시간이 오래 걸리는 거 아닌가 테스트 해볼게요

            if (A[mid] == num) {
                ans = 1;
                break;
            }
            
            else {
                if (A[mid] < num) st = mid+1;
                else en = mid-1;
                mid = (st+en)/2;
            }
        }
        // cout << st << ' ' << en << '\n';
        cout << ans << '\n';
    }

    auto finish = clock();

    cout << finish-start;
}
// en이 N-1이어야 하는 이유는 뭘까?
// N은 안되나?
// 만약 모든 정수가 음수인데, 0을 찾으려고 한다고 하자.
// 그러면 계속 이분탐색을 진행하다가, st가 N-1이 된다.
// st가 N-1이고, en이 N이므로 mid = N-1이다.
// 이 때, num > A[mid]이므로 st = N, en = N, mid = N인 상황이 발생한다.
// 배열을 충분히 할당하는 것이 습관화 되어 있어서 에러가 발생하지는 않지만, 이미 A의 범위를 벗어나버렸다.
// 심지어 전역변수의 경우 모든 값이 0으로 초기화 되어 있어서 음수 안에서 0을 발견하는 오류가 발생한다.
// input :
// 4
// -4 -3 -2 -1
// 1
// 0
// output : 1 (0이 정답)