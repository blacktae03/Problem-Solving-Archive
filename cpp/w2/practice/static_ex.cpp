int print( int val ) {
    static int sum = 0 ; // static 지역 변수 sum
    sum += val ;
    return sum ;
}

int main() {
    cout << print(1) << endl ; // 1=(0+1)
    cout << print(2) << endl ; // 3=(1+2)
    cout << print(3) << endl ; // 6=(3+3)
}
    