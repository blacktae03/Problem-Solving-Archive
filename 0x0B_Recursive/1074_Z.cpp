#include <bits/stdc++.h>
using namespace std;


// void Z(int n, int x1, int y1, int x2, int y2) {
//     static int cnt = 0;
//     if (n == 0) {
//         if (x1 == r && y1 == c) cout << cnt;
//         cnt++;
//         return;
//     } 
//     Z(n-1, x1, y1, (x1+x2)/2, (y1+y2)/2);
//     Z(n-1, x1, (y1+y2)/2+1, (x1+x2)/2, y2);
//     Z(n-1, (x2+x1)/2+1, y1, x2, (y1+y2)/2);
//     Z(n-1, (x2+x1)/2+1, (y1+y2)/2+1, x2, y2);
// }

void Z (int n, int r, int c) {
    static int cnt = 0;
    if (n == 0) {
        cout << cnt;
        return;
    }
    if (r < 1<<n-1 && c < 1<<n-1) {
        Z(n-1, r, c);
    }
    else if (r < 1<<n-1 && c >= 1<<n-1) {
        cnt += ((1<<n)*(1<<n)/4) * 1;
        Z(n-1, r, c-(1<<n-1));
    }
    else if (r >= 1<<n-1 && c < 1<<n-1) {
        cnt += ((1<<n)*(1<<n)/4) * 2;
        Z(n-1, r-(1<<n-1), c);
    }
    else {
        cnt += ((1<<n)*(1<<n)/4) * 3;
        Z(n-1, r-(1<<n-1), c-(1<<n-1));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    Z(n, r, c);
}

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n >> r >> c;
//     Z(n, 0, 0, (1<<n) - 1, (1<<n) - 1);
// }