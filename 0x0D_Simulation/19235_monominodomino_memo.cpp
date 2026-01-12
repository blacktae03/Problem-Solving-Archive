#include <bits/stdc++.h>
using namespace std;

void Gmove(int t, int x, int y, int cur) {
    int arv = 0;
    int curX = gx[cur];

    if (t == 1) {
        for (int i = curX+1; i <= 6; i++) {
            if (!G[i][y]) continue;
            arv = i-1;
            break;
        }

        G[arv][y] = cur;
    }

    else if (t == 3) {
        for (int i = curX+2; i <= 6; i++) {
            if (!G[i][y]) continue;
            arv = i-2;
            break;
        }

        G[arv][y] = cur;
        G[arv+1][y] = cur;
    }

    else if (t == 2) {
        for (int i = curX+1; i <= 6; i++) {
            if (!G[i][y] && !G[i][y+1]) continue;
            arv = i-1;
            break;
        }

        G[arv][y] = cur;
        G[arv][y+1] = cur;
    }

    gt[cur] = t;
    gx[cur] = x;
    gy[cur] = arv;
}
