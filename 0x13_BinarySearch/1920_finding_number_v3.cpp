#include <bits/stdc++.h>
using namespace std;
// 오답임 v2가 정답 헷갈리지 말기.

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
        int st = 0, en = N-1;
        bool ans = 0;
        int mid = (st+en)/2;

        while(true) {
            
            if (A[mid] == num) {
                ans = 1;
                break;
            }
            else if (en-st == 0) break; // 왜 이렇게 하는게 더 느리지.
            
            else {
                if (A[mid] < num) st = mid+1;
                else en = mid-1;
                mid = (st+en)/2;
            }
        }

        cout << ans << '\n';
    }

    auto finish = clock();

    cout << finish-start;
}
// 이렇게 하면 안되는 이유!!! 찾았다 더 느려서 그런게 아니라 무한루프 발생
// 4
// 1 3 5 7
// 1
// 4
// 이면, 무한루프 돎.
// 난 무조건 같은 곳에서 st와 en이 만날 수 밖에 없다고 생각했는데,
// st와 en이 1차이 나고, mid = st일 때, A[mid]이 num보다 커버리면 en = mid-1이 되어서 같아 지지 않고 역전 되는 현상이 벌어짐.
// 그럼 여기서 계속 똑같이 돎. 우와 찾았다 이제 밥 먹어야지 고추장 계란밥 레츠고~