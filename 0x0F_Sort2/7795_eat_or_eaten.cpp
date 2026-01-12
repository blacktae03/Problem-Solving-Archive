#include <bits/stdc++.h>
using namespace std;

int N, M;
pair<int, char> arr[40001];

bool cmp (const pair<int, char> & a, const pair<int, char> & b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testcase; cin >> testcase;

    while (testcase--) {
        int cnt = 0, acnt = 0;

        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            arr[i] = {tmp, 'A'};
        }

        for (int i = N; i < N+M; i++) {
            int tmp; cin >> tmp;
            arr[i] = {tmp, 'B'};
        }
        
        sort(arr, arr+N+M, cmp);

        for (int i = 0; i < N+M; i++) { // 정렬도 O(NlgN)인데 여기서 O(N^2) 쳐하니까 안되지
            if (arr[i].second == 'B') continue;
            cnt += N+M-1-i; // 자기보다 뒤에있는 것들 다 먹을 수 있다고 가정하고 카운트 증가.
            cnt -= acnt++;
            // 이거 개크랙이네 ㄹㅇ 원리를 좀 메모하자면 윗줄에서 뒤에 A가 있든 B가 있든 다 먹어서 카운트 했기 때문에
            // 뒤에 있는 A만큼 카운트에서 빼줘야 함.
            // A가 나올 때마다 빼주는데 자기보다 뒤에있는 것만 카운트에 포함시키기 때문에 처음 a는 셀 필요 없음.
            // A가 2번째 나오면 A 1번 빼고 A가 3번째 나오면 3번째 A는 두 번이나 개수에 포함 되었기 때문에 1이 아닌 2를 빼줘야함.
            // n+1번째 A가 등장하면 n만큼 A가 카운트에 추가되었다는 뜻이므로 n만큼 뺴주는 것.
        }

        cout << cnt << '\n';
    }
}