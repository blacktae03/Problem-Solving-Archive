#include <bits/stdc++.h>
using namespace std;

string ans = "";
int n;

void paper(int next, char * brd) {
    if (next == 1) {ans+=*brd; return;}
    
    char tmp = *brd;
    int nxt = next/2;
    for (int i = 0; i < next; i++) {
        for (int j = 0; j < next; j++) {
            if (tmp == *(brd+i*n+j)) continue;
            ans += '(';
            paper(nxt, brd);
            paper(nxt, brd+nxt);
            paper(nxt, brd+n*nxt);
            paper(nxt, brd+n*nxt+nxt);
            ans += ')';
            return;
        }
    }

    ans += tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    char brd[n*n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> brd[n*i+j];
        }
    }

    paper(n, brd);

    cout << ans;
}