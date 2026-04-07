#include <bits/stdc++.h>
using namespace std;
#define S first
#define W second

int n, mxcnt, cnt;
pair<int, int> arr[8];
bool isbroken[8];
bool isused = 0;

void hit(int k) {
    isused = 0;
    if (k == n) {
        mxcnt = max(mxcnt, cnt);
        return;
    }

    if (isbroken[k]) {
        hit(k+1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i == k || isbroken[i]) continue;
        isused = 1;
        arr[k].S -= arr[i].W;
        arr[i].S -= arr[k].W;
        if (arr[k].S <= 0) { isbroken[k] = 1; cnt++; }
        if (arr[i].S <= 0) { isbroken[i] = 1; cnt++; }
        hit(k+1);
        if (isbroken[k]) { isbroken[k] = 0; cnt--; }
        if (isbroken[i]) { isbroken[i] = 0; cnt--; }
        arr[k].S += arr[i].W;
        arr[i].S += arr[k].W;
    }
    if (!isused) hit(n);
    // 원래 n으로 하려다가 k+1 해도 상관없을 거 같아서
    // k+1 했는데 92%에서 틀렸다길래 다시 n으로 하니까 맞음 ㄷㄷ
    // 근데 이유는 모르겠음.
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int ts, tw;
        cin >> ts >> tw;
        arr[i] = {ts, tw};
    }

    hit(0);
    
    cout << mxcnt;
}