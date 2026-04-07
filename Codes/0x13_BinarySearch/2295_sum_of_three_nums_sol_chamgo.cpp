#include <bits/stdc++.h>
using namespace std;

int N, sum, ans;
int U[1004];
vector<int> two;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // fill(C+3, C+1004, 1);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> U[i];
    sort(U, U+N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { // O(N^2)
            if (U[i] > INT_MAX - U[j]) continue;
            two.push_back(U[i] + U[j]); // two의 공간복잡도는 O(N^2)
        }
    }
    
    sort(two.begin(), two.end()); // O(NlgN)

    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            if (binary_search(two.begin(), two.end(), U[l] - U[k])) ans = max(ans, U[l]); // O(N^2lg(N^2)) == O(N^2 * 2lgN)
        }
    }

    cout << ans;
}
// 28번 줄 시간복잡도에서 진짜 이분탐색이 대단한 이유를 딱 알았네
// N^2짜리에서 원소를 찾는데 2lgN이라서 결국은 lgN인게 그냥 말이안됨
// 원래 방식대로 찾으면 N에서 N^2 되는 거라 당연히 늘어나는게 맞는 건데 어떻게 같은 시간복잡도로 해결할 수가 있지 이건 그냥 혁명이다 시2발