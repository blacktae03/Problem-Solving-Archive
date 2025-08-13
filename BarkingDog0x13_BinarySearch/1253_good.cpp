#include <bits/stdc++.h>
using namespace std;

int N, Z;
int ans;
int A[2020];
// int sum[2000020];
vector<int> sum[2020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            sum[i].push_back(A[i]+A[j]);
        }

        sort(sum[i].begin(), sum[i].end());
    }

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                cnt -= upper_bound(sum[j].begin(), sum[j].end(), A[i]) - lower_bound(sum[j].begin(), sum[j].end(), A[i]);
            }
            else {
                cnt += upper_bound(sum[j].begin(), sum[j].end(), A[i]) - lower_bound(sum[j].begin(), sum[j].end(), A[i]);
            }
        }
        if (cnt) ans++;
    } 

    cout << ans;
}
// 겹치는 건 빼는 방식으로. 합을 벡터에 넣을 때, i가 포함된 모든 합은 sum[i]에 추가함. i = 0, j = 0에서 반복문이 시작하기 때문에, 모든 합은 2번씩 발견될 수 밖에 없음.
// 예를 들어, 1 2 3 4가 초기 입력값이라고 했을 때, 1 3 = 4, 3 1 = 4가 모두 합에 포함된다는 뜻임. 1 3 은 sum[1]에 3 1은 sum[3]에 저장되기 때문
// 근데 31번 줄처럼 해 버리면, 내가 포함된 거는 cnt에 더해지지 않음. 나중에 한 번 더 등장해도 앞에서 뺏기 때문에 아무것도 더하지 않는 것이나 마찬가지.
// 그리고 내가 포함되지 않은 합들은 두번씩 더해져서 2의 배수로 cnt에 추가될 것임. 2의 배수인 것은 사실 중요하지 않고, 0으로 상쇄되지 않는다는 것이 중요한 것.
// 따라서 cnt가 양수면 i가 포함되지 않은 합이 무조건 1개 이상 있다는 뜻이므로 ans++