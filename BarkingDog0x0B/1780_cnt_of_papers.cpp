#include <bits/stdc++.h>
using namespace std;

int cnt[3];
int n;

void paper(int next, int * brd) {
    if (next == 1) {cnt[(*brd)+1]++; return;}
    
    int tmp = *brd;
    int nxt = next/3;
    for (int i = 0; i < next; i++) {
        for (int j = 0; j < next; j++) {
            if (tmp == *(brd+i*n+j)) continue;
            paper(nxt, brd);
            paper(nxt, brd+nxt);
            paper(nxt, brd+nxt*2);
            paper(nxt, brd+n*nxt);
            paper(nxt, brd+n*nxt+nxt);
            paper(nxt, brd+n*nxt+nxt*2);
            paper(nxt, brd+n*nxt*2);
            paper(nxt, brd+n*nxt*2+nxt);
            paper(nxt, brd+n*nxt*2+nxt*2);
            return;
        }
    }

    cnt[tmp+1]++;
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
    cout << cnt[2] << '\n';
}