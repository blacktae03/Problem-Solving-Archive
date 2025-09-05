#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;

        if (maxHeap.size() > minHeap.size()) minHeap.push(tmp);
        else maxHeap.push(tmp);

        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        cout << maxHeap.top() << '\n';
    }
    
}

// 최대힙과 최소힙 두개를 활용
// 1 : 1 | x
// 5 : 1 | 5
// 2 : 2 1 | 5
// 10 : 2 1 | 5 10
// -99 : 2 1 -99 | 5 10
// 7 : 2 1 -99 | 5 7 10
// 5 : 5 2 1 -99 | 5 7 10

// 그냥 답 베꼈음 웬만하면 이렇게 안했는데 도저히 안되네..
// 문제점을 찾아보면 그냥 내가 너무 애매하게 때려맞추려고 했음
// 반반 가르는 바이브까지는 감으로 찾았는데 그 반이 어떻게 갈라져야하는지를 구체화 했어야했음
// maxHeap에 작은 거 반, minHeap에 큰 거 반을 가르는 걸 시각화하니까 그림이 너무 이쁨
// 1,2,3이 maxHeap에, 4,5,6이 minHeap에 들어가있는 걸 상상해봐 얼마나 이쁜가.... 그럴려면 무작위한 숫자들이 들어올 때 어떤 처리를 해줘야할 지 구체적으로 생각했어야했음
// 각 pq에 반을 가르는 기준이 뭔지가 명확해야했다는 뜻. 내일은 더 잘 풀어보자.