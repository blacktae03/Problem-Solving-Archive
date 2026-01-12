// 간단하게 만들려 했는데 그냥 귀찮아졌음.. 이건 일단 오답.
// 이유: 함수를 활용한 정답 코드는 미리 인접한 사다리에는 사다리를 놓지 못하게 작업을 해놓은 상태. 그 상태에서는 모든 사다리가 가능한 사다리이기 때문에
// 그냥 함수를 짜면 되지만 나는 그렇지 않기 때문에 예를 들어 첫 사다리가 인접한 사다리거나 이미 놓아진 사다리라면 다음 사다리를 설치하면서 cnt가 2가 되어버림/
// 그냥 나처럼 짤래 ㅅㄱ 안해 이거
// 시간초과 떄문에 돌아버리겠네 ㅎㅎ
#include <bits/stdc++.h>
using namespace std;

int N, M, H, ans = -1;
bool ladder[32][11];
int cnt;

bool check(int lad) {
    bool retry = 0;
    if (lad > -1) {
        
    
        int ttly = lad % (N-1) + 1;
        int ttlx = lad / (N-1) + 1;
        
        if (ladder[ttlx][ttly] || ladder[ttlx][ttly - 1] || ladder[ttlx][ttly + 1]) return 0;
        // if (retry) continue;
        ladder[ttlx][ttly] = 1;
    }

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
    
    if (retry) return 0;
    cout << cnt;
    return 1;
}

void rewind(int lad) {
    int ttly = lad % (N-1) + 1;
    int ttlx = lad / (N-1) + 1;

    ladder[ttlx][ttly] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int lx, ly; cin >> lx >> ly;
        ladder[lx][ly] = 1;
    }

    bool noneedtomove = check(-1);

    if (noneedtomove) return 0;

    int num = H*(N-1);

    for (int lad1 = 0; lad1 < num; lad1++) {
        cnt = 1;
        if(check(lad1)) return 0;
        
        for (int lad2 = lad1+1; lad2 < num; lad2++) { // 사다리 두 개일 때
            cnt = 2;
            if(check(lad2)) return 0;

            for (int lad3 = lad2+1; lad3 < num; lad3++) { // 사다리 두 개일 때
                cnt = 3;
                if(check(lad3)) return 0;
                rewind(lad3);
            }

            rewind(lad2);
        }
        rewind(lad1);
    }

    cout << -1;
}

// 270 P 3 = 19464840