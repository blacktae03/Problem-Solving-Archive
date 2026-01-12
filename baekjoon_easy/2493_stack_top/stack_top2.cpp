#include <iostream>
using namespace std;

int top = 0, top2 = 0, N, tmp, tmp2;
int arr[500001] = {0,};
int arr2[500001] = {0,};

void push(int * arr, int num);
void pop(int * arr);
void push2(int * arr, int num);
void pop2(int * arr);


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        push(arr, tmp);
    }

    for (int j = 0; j < N; j++) {
        tmp2 = arr[top];
        pop(arr);
        if(arr[top] > tmp2) {
            for (int k = 0; k < )
            push(arr2, -(tmp2-N));
        }
            
    }

    return 0;
}

void push(int * arr, int num) {
    *(arr+(++top)) = num;
}

void pop(int * arr) {
    top--;
}

void push2(int * arr, int num) {
    *(arr+(++top2)) = num;
}

void pop2(int * arr) {
    top2--;
}