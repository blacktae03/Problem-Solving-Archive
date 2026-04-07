#include <bits/stdc++.h>
using namespace std;

int N;
int mn = 1000000001;
int mx = -1000000001;
int num[12], opercnt[4], oper[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp = 0;
    for (int i = 0; i < N; i++) cin >> num[i];
    for (int i = 0; i < 4; i++) {
        cin >> opercnt[i];
        fill(oper+tmp, oper+tmp+opercnt[i], i);
        tmp += opercnt[i];
    }

    do {
        int sum = num[0];

        for (int i = 0; i < N-1; i++) {
            switch(oper[i]) {
                case 0 : // 더하기
                    sum += num[i+1];
                    break;
                
                case 1 :
                    sum -= num[i+1];
                    break;

                case 2 :
                    sum *= num[i+1];
                    break;
                
                case 3 :
                    sum /= num[i+1];
                    break;
            }
        }

        mn = min(mn, sum);
        mx = max(mx, sum);
    } while(next_permutation(oper, oper+N-1));

    cout << mx << '\n' << mn;
}