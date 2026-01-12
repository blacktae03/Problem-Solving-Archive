#include <bits/stdc++.h>
using namespace std;

const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

int insert(int addr, int num){
    //if(nxt[addr] == -1) pre[0] = unused;
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    nxt[addr] = unused;
    return unused++;
}

int erase(int addr){
    int tmp = pre[addr];
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    return tmp;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur];
    cur = nxt[cur];
  }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    char com;
    int M;
    string s;
    cin >> s;
    cin >> M;

    for (auto c : s) insert(unused-1, c);
    int csr = unused-1;

    for (int i = 0; i < M; i++) {
        cin >> com;

        if (com == 'L' && pre[csr] != -1) csr = pre[csr];

        if (com == 'D' && nxt[csr] != -1) csr = nxt[csr];

        if (com == 'B' && pre[csr] != -1) csr = erase(csr);

        if (com == 'P') {
            cin >> com;
            csr = insert(csr, com);
        }
    }
    
    traverse();
}