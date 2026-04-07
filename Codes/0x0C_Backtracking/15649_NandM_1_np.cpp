#include <bits/stdc++.h>
using namespace std;

int fact(int f) {
    if (f == 1) return 1;
    return f * fact(f-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int brd[n];

    for (int i = 0; i < n; i++)
        brd[i] = i+1;

    int k = 0;
    do {
        if(!(k % fact(n-m))) { // 시간초과.. 그래 이건 아닌거 같은데 흠...
            for (int i = 0; i < m; i++)
                cout << brd[i] << ' ';
            cout << '\n'; 
        }
            
        k++;
    } while (next_permutation(brd, brd+n));
}