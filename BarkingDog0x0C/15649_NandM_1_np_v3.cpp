#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int brd[n];


    for (int i = 0; i < n; i++)
        brd[i] = i+1;


    do { // 나머지 n-m개가 같은 걸로 처리 되어야 하는데...
        for (int i = 0; i < m; i++)
            cout << brd[i] << ' ';

        cout << '\n';
        reverse(brd+m, brd+n);
        // 와 오름차순으로 무조건 다 도니까 오름차순에서 젤 끝 순열로 바꿔버리면
        // 앞에 두 수가 고정돼있을 때 가장 큰 경우의 수가 되어버리니까
        // 다음 순열로 넘어가는구나.
    } while (next_permutation(brd, brd+n));
}