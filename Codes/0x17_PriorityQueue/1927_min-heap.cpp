#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수
int N;

void push(int x){
    heap[++sz] = x;
    int idx = sz;

    while (heap[idx/2] > heap[idx]) {
        if (idx == 1) break;
        swap(heap[idx], heap[idx/2]);
        idx /= 2;
    }
}

int top(){
    // if (!sz) return 0;
    // else 
    return heap[1];
}

void pop(){
    // swap(heap[sz], heap[1]);
    // heap[sz--] = 0;
    if (!sz) return;
    heap[1] = heap[sz];
    heap[sz--] = 0;
    int idx = 1;

    // while (heap[idx] > heap[idx*2] || heap[idx] > heap[idx*2+1]) {
    //     if (idx * 2 > sz) break;
    //     if (heap[idx*2+1] && heap[idx*2+1] < heap[idx*2]) {
    //         swap(heap[idx], heap[idx*2+1]);
    //         idx = idx*2+1;
    //     }
    //     else {
    //         swap(heap[idx], heap[idx*2]);
    //         idx *= 2;
    //     }
    //     // idx *= 2;
    // }
    while (idx * 2 <= sz) {
        if (heap[idx] <= heap[idx*2] && (heap[idx] <= heap[idx*2+1] || !heap[idx*2+1])) break;

        if (heap[idx*2+1] && heap[idx*2+1] < heap[idx*2]) {
            swap(heap[idx], heap[idx*2+1]);
            idx = idx*2+1;
        }
        else {
            swap(heap[idx], heap[idx*2]);
            idx *= 2;
        }
        // idx *= 2;
    }
}

// void test(){
//   push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
//   cout << top() << '\n'; // 2
//   pop(); // {10, 5, 9}
//   pop(); // {10, 9}
//   cout << top() << '\n'; // 9
//   push(5); push(15); // {10, 9, 5, 15}
//   cout << top() << '\n'; // 5
//   pop(); // {10, 9, 15}
//   cout << top() << '\n'; // 9
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N--) {
        int x; cin >> x;

        if (x) push(x);
        else {
            cout << top() << '\n';
            pop();
        }
    }

    // for (int i = 0; i <= sz; i++) cout << heap[i] << ' ';
}