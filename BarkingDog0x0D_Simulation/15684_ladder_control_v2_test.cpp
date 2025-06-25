#include <bits/stdc++.h>
using namespace std;

int N, M, H, ans = -1;
bool ladder[32][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int lx, ly; cin >> lx >> ly;
        ladder[lx][ly] = 1;
    }

    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= N-1; j++) {
    //         cout << ladder[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int num = H*(N-1)+1; // 4
    int tlx[3] = {0,}, tly[3] = {0,};

    for (int T = 0; T < num*num*num; T++) { // 조건항이 <=인 이유 : 나머지가 0일 때는 사다리를 설치 안하는 걸로 할거임.
        // int T = 2;
        if (ans != -1) break;


        for (int i = 0; i < 3; i++) {
            ladder[tlx[i]][tly[i]] = 0;
            tlx[i] = 0;
            tly[i] = 0;
        }
        
        int brute = T;
        int cnt = 0;
        bool retry = 0;

        for (int put = 0; put < 3; put++) {
            int ltmp = brute % num;
            // cout << "ltmp = " << ltmp << '\n';
            if (ltmp) {
                cnt++;

                int ttlx = (ltmp-1) / (N-1) + 1;
                int ttly = (ltmp-1) % (N-1) + 1;
                // cout << "ttlx = " << ttlx << ", ttly = " << ttly << '\n';
                
                if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) {
                    retry = 1;
                    break;
                }

                tlx[put] = ttlx;
                tly[put] = ttly;
                ladder[tlx[put]][tly[put]] = 1;
            }
            brute /= num;
        } // 사다리 설치
        
        // if (retry) cout << "retry1\n";//continue;
        if (retry) continue;

        for (int i = 1; i <= N; i++) {
            int loc = i;

            for (int j = 1; j <= H; j++) {
                if (ladder[j][loc]) loc++;
                else if (ladder[j][loc-1]) loc--;
            }

            if (loc != i) {
                retry = 1;
                break;
            }
        }

        // if (retry) cout << "retry2\n"; //continue;
        if (retry) continue;

        // for (int put = 0; put < 3; put++) {
        //     if (tlx[put] && tly[put]) ladder[tlx[put]][tly[put]] = 0;
        // }
        // for (int i = 1; i <= H; i++) {
        //     for (int j = 1; j <= N-1; j++) {
        //         cout << ladder[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        ans = cnt;
    }

    cout << ans;
}

// 270 P 3 = 19464840