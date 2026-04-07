#include <bits/stdc++.h>
using namespace std;

int N, M, T;
long long ans; // 주어지는 모든 값(T, A, B)이 0일 때를 생각하면 왜 long long을 써야하는 지 알 수 있다.
int A[1004], B[1004];
vector<int> sumOfA;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    cin >> N;
    int ASum = 0;
    for (int i = 1; i <= N; i++) { // prefix sum
        int tmp; cin >> tmp;
        ASum += tmp;
        A[i] = ASum;
    }

    cin >> M;
    int BSum = 0;
    for (int i = 1; i <= M; i++) {
        int tmp; cin >> tmp;
        BSum += tmp;
        B[i] = BSum;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            sumOfA.push_back(A[i]-A[j]);
        }
    } // O(N^2)

    sort(sumOfA.begin(), sumOfA.end()); // O(NlgN)

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < i; j++) {
            ans += upper_bound(sumOfA.begin(), sumOfA.end(), T - (B[i] - B[j])) - lower_bound(sumOfA.begin(), sumOfA.end(), T - (B[i] - B[j]));
        }
    } // O(M^2lgN^2)

    cout << ans;
}