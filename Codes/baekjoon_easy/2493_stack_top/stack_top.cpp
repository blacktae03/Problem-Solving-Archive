#include <iostream>
using namespace std;

int top = 0, N, tmp;
int arr[500001] = {0,};

void push(int * arr, int num);
void pop(int * arr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        top = i;
        push(arr, tmp);

        while (top > 0) {
            pop(arr);
            if(arr[top] > tmp) break;
        }
        
        cout << top << " ";
    }

    return 0;
}

void push(int * arr, int num) {
    *(arr+(++top)) = num;
}

void pop(int * arr) {
    top--;
}