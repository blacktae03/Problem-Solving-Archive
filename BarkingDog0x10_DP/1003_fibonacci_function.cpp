#include <bits/stdc++.h>
using namespace std;

int T, N;
pair<int, int> D[42];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[0] = {1, 0};
    D[1] = {0, 1};

    for (int i = 2; i <= 40; i++) {
        D[i].first = D[i-1].first + D[i-2].first;
        D[i].second = D[i-1].second + D[i-2].second;
    }

    cin >> T;
    
    while(T--) {
        cin >> N;
        cout << D[N].first << ' ' << D[N].second << '\n';
    }
}

// D[i] = fibonacci(i)를 호출 했을 때 0(first) 또는 1(second)이 출력되는 횟수
// D[0] = 1,0, D[1] = 0,1;
// D[n] = D[n-1] + D[n-2] 니까 그냥 이렇게 하면 되겠네