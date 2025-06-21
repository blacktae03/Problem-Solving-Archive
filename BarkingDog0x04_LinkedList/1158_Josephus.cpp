#include <bits/stdc++.h>
using namespace std;

const int MAX = 5005;

int dat[MAX];
int pre[MAX], nxt[MAX];
int unused = 1;
int cur = 0;

int insert(int addr, int c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    else nxt[unused] = nxt[0]; // 원형 linked list 만들기.
    nxt[addr] = unused;
    return unused++;
}

int erase(int addr) {
    int tmp = pre[addr];
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];

    return tmp;
}

void traverse(void) {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MAX, -1);
    fill(nxt, nxt+MAX, -1);

    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cur = insert(cur, i+1);
    }

    // traverse();

    cur = K;

    cout << '<';
    for (int i = 0; i < N; i++) {
        int tmp = dat[cur];
        cur = erase(cur);
        for (int j = 0; j < K; j++) {
            cur = nxt[cur];
        }
        
        cout << tmp;

        if (i != N-1) cout << ", ";
    }
    cout << '>';
}