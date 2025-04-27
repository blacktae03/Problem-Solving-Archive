#include <limits> // numeric_limits<T>를 이용하기 위함
#include <iostream>
using namespace std ;
int main() {
    cout << numeric_limits<short int>::min() << endl ;
    cout << numeric_limits<short int>::max() << endl << endl ;
    cout << numeric_limits<int>::min() << endl ;
    cout << numeric_limits<int>::max() << endl << endl ;
    cout << numeric_limits<unsigned int>::min() << endl ;
    cout << numeric_limits<unsigned int>::max() << endl << endl ;
    cout << numeric_limits<long>::min() << endl ;
    cout << numeric_limits<long>::max() << endl << endl ;
    cout << numeric_limits<float>::min() << endl ;
    cout << numeric_limits<float>::max() << endl << endl ;
    cout << numeric_limits<double>::min() << endl ;
    cout << numeric_limits<double>::max() << endl << endl ;
    cout << static_cast<int> (numeric_limits<char>::min()) << endl ;
    cout << static_cast<int> (numeric_limits<char>::max()) << endl ;
}