#include <bits/stdc++.h>
using namespace std;

int cnt[2];
int n;

void paper(int next, int * brd) {
    if (next == 1) {cnt[*brd]++; return;}
    
    int tmp = *brd;
    int nxt = next/2;
    for (int i = 0; i < next; i++) {
        for (int j = 0; j < next; j++) {
            if (tmp == *(brd+i*n+j)) continue;
            paper(nxt, brd);
            paper(nxt, brd+nxt);
            paper(nxt, brd+n*nxt);
            paper(nxt, brd+n*nxt+nxt);
            return;
        }
    }

    cnt[tmp]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int brd[n*n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> brd[n*i+j];
        }
    }

    paper(n, brd);

    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';
}