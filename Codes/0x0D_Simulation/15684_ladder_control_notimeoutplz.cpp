// 시간초과 떄문에 돌아버리겠네 ㅎㅎ
// ㅋ 정답
#include <bits/stdc++.h>
using namespace std;

int N, M, H, ans = -1;
bool ladder[32][11];
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int lx, ly; cin >> lx >> ly;
        ladder[lx][ly] = 1;
    }

    bool needtomove = 0;

    for (int i = 1; i <= N; i++) {
        int loc = i;

        for (int j = 1; j <= H; j++) {
            if (ladder[j][loc]) loc++;
            else if (ladder[j][loc-1]) loc--;
        }

        if (loc != i) {
            needtomove = 1;
            break;
        }
    }

    if (!needtomove) {
        cout << 0;
        return 0;
    }

    int num = H*(N-1);
    int tlx[3] = {0,}, tly[3] = {0,};
    
    // for (int T = 0; T < num*num*num; T++) { // 조건항이 <=인 이유 : 나머지가 0일 때는 사다리를 설치 안하는 걸로 할거임.
    cnt++;
    for (int lad1 = 0; lad1 < num; lad1++) { // 사다리 하나일 때
        bool retry = 0;

        int ttlx = lad1 / (N-1) + 1;
        int ttly = lad1 % (N-1) + 1;
        
        if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) continue;
        // if (retry) continue;
        ladder[ttlx][ttly] = 1;
    
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
        ladder[ttlx][ttly] = 0;
    
        if (retry) continue;
    
        cout << cnt;
        return 0;
    } 

    cnt++;
    for (int lad1 = 0; lad1 < num; lad1++) { // 사다리 두 개일 때
        int ttly = lad1 % (N-1) + 1;
        int ttlx = lad1 / (N-1) + 1;
        
        if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) continue;
        // if (retry) continue;
        ladder[ttlx][ttly] = 1;

        for (int lad2 = lad1+1; lad2 < num; lad2++) {
            bool retry = 0;
    
            int ttly = lad2 % (N-1) + 1;
            int ttlx = lad2 / (N-1) + 1;
            
            if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) continue;
            // if (retry) continue;
            ladder[ttlx][ttly] = 1;
        
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

            ladder[ttlx][ttly] = 0;
            
            if (retry) continue;
            
            cout << cnt;
            return 0;
        }
        ladder[ttlx][ttly] = 0;
    }
    // }
    cnt++;

    for (int lad1 = 0; lad1 < num; lad1++) {
        int ttly = lad1 % (N-1) + 1;
        int ttlx = lad1 / (N-1) + 1;
        
        if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) continue;
        // if (retry) continue;
        ladder[ttlx][ttly] = 1;

        for (int lad2 = lad1+1; lad2 < num; lad2++) { // 사다리 두 개일 때
            int ttly = lad2 % (N-1) + 1;
            int ttlx = lad2 / (N-1) + 1;
            
            if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) continue;
            // if (retry) continue;
            ladder[ttlx][ttly] = 1;
        
            for (int lad3 = lad2+1; lad3 < num; lad3++) {
                bool retry = 0;
        
                int ttly = lad3 % (N-1) + 1;
                int ttlx = lad3 / (N-1) + 1;
                
                if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) continue;
                // if (retry) continue;
                ladder[ttlx][ttly] = 1;
            
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
        
                ladder[ttlx][ttly] = 0;
                
                if (retry) continue;
                
                cout << cnt;
                return 0;
            }
            ladder[ttlx][ttly] = 0;
        }
        ladder[ttlx][ttly] = 0;
    }

    cout << -1;
}

// 270 P 3 = 19464840