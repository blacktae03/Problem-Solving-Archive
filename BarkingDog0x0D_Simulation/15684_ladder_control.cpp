// 아 일단 보류할까.. 이 방법이면 백트래킹도 써야되는데 개복잡하노
// 일단 보류하자 250606 14:55
#include <bits/stdc++.h>
using namespace std;

int N, M, H, ans, cnt;
bool lad[12][33];
vector<int> garo;
stack<int> S;
int need;
bool esc = 1;

void func(int cnt) {
    esc = 0;

    if (cnt == need) {
        for (int i = 1; i <= N; i++) {
            int cur = i;
    
            for (int j = 1; j <= H; j++) {
                if (lad[cur-1][j]) {
                    if (!S.empty() && S.top() == cur-1) S.pop();
                    else S.push(--cur);
                }
    
                if (lad[cur][j]) {
                    if (!S.empty() && S.top() == cur) S.pop();
                    else S.push(cur++);
                }
            }
    
            if (!S.empty()) {
                bool same = 0;

                for (auto g : garo) {
                    if (g == S.top()) same = 1;
                }

                if (!same) {
                    garo.push_back(S.top());
                    need++;
                }

                esc = 1;
            }
            while(!S.empty()) S.pop();
        }


        return;
    }

    for (int j = 1; j <= H; j++) {
        if (lad[j][garo[cnt]]) continue;
        lad[j][garo[cnt]] = 1;
        func(cnt+1);
        if (esc) return;
        lad[j][garo[cnt]] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> H;
    
    while(M--) {
        int tx, ty;
        cin >> tx >> ty;
        
        lad[tx][ty] = 1;
    }

    for (int i = 1; i <= N; i++) {
        int cur = i;

        for (int j = 1; j <= H; j++) {
            if (lad[j][cur-1]) {
                if (!S.empty() && S.top() == cur-1) S.pop();
                else S.push(--cur);
            }

            if (lad[j][cur]) {
                if (!S.empty() && S.top() == cur) S.pop();
                else S.push(cur++);
            }
        }
        
        if (!S.empty()) {
            bool same = 0;
            
            for (auto g : garo) {
                if (g == S.top()) same = 1;
            }
            
            if (!same) {
                garo.push_back(S.top());
                need++;
            }
        }
        while(!S.empty()) S.pop();
    }
    
    
    while(esc || cnt > 3) {
        // if (!garo.empty()) continue;
        func(cnt);
        cnt += need;
    }

    if (cnt > 3) cout << -1;
    else cout << cnt;
}

// 1. 그냥 조합 써야되겠는데? 0 한 개 일 때부터 2개 3개일때 까지만 하면되니까
// {(N-1) * H Combination 1} +
// {(N-1) * H Combination 2} +
// {(N-1) * H Combination 3} = 270 + 270 * 269 / 2 + 270 * 269 * 268 / 6 = 3280725 (최댓값)
// 3280725 * ( 9 * 2 * 30 ) = 1771591500 (17억...)

// 2. 괄호처럼 생각해서 스택으로 해결하면 어떨까?
// 1번째 세로선 입장에서 먼저 생각해보자.
// 1->2 가로선이 있으면 2->1 가로선을 만나면 된다.
// 근데 2->1을 만나기 전까지 또 가로선을 만나도 되는데 그 가로선도 쌍을 이루면 상관없다.
// 가령 2->1을 만나기 전에 2->3을 만나면 2->1을 만나기 전에 3->2를 만나면 된다.
// 근데 3->2를 만나기 전에 또 3->4를 만나면 3->2를 만나기 전에 4->3을 만나면 된다.
// 이 연산의 시간복잡도는? 연산 자체의 시간복잡도는 똑같은듯. 아니다 저 가운데 낀 2 없어져도 될듯 그래도 9억임.
// 그냥 이 아이디어를 통해서 모든 조합을 안 도는 게 방법인 거 같은데..
// 추가로 사다리를 넣기 전에 이렇게 해서 제자리 오는데 성공한 세로줄은 미리 표시를 한다.
// 각 세로선에서 시작했을 때 비워져있던 스택이 다시 비워져야 됨.
// 안비워졌다면, top의 사다리를 보고 무슨 사다리가 필요한지 판단.
// 사다리를 만나서 stack의 push 또는 pop 을 성공할 때마다 세로선의 위치 또한 기록해야함 그래야 실패했을 때 그 세로선 보다 아래에 세로선이 필요하다는 걸 알 수 있음.
//  (이거 하면 근데 경우의 수가 너무 복잡해져서 이거까진 기록 안해보고 일단 해야겠다 그래도 제한시간 안에는 충분히 할듯.
// 모든 사다리의 입장에서 H번 연산해야하니까 10 * 30 = 300
// 사다리가 필요한 세로선 번호가 4개 이상이면 안할거니까 최대 3개라고 가정하고, 그 안에서 다 조합 돌린다고 생각하면 30 * 30 * 30 (최댓값보다 넉넉하게 잡은거임)
// 되는지 다시 확인하기 = 10 * 30
// 10 * 30 + 30 * 30 * 30 * 10 * 30 = 
// 안되면 3개 될 때까지 하기.