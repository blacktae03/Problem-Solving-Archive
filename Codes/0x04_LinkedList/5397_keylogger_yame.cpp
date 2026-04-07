#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

char dat[MAX];
int pre[MAX], nxt[MAX];
int unused = 1;
int cur;

int insert(int addr, char c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
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

    int M;
    string put = "";
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> put;
        
        fill(pre, pre+MAX, -1);
        fill(nxt, nxt+MAX, -1);
        fill(dat, dat+MAX, -1);
        unused = 1;
        cur = 0;

        for (auto c : put) {
            if (c == '<') {
                if (pre[cur] != -1) cur = pre[cur];
            }

            else if (c == '>') {
                if (nxt[cur] != -1) cur = nxt[cur];
            }

            else if (c == '-') {
                if (pre[cur] != -1) cur = erase(cur);
            }

            else cur = insert(cur, c);
        }

        traverse();
    }
}