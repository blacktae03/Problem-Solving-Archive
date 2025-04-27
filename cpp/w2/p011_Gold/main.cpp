#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int baseGold = 1000;
    int addGold;
    float averGold;
    bool itemAva;

    cin >> addGold;
    averGold = static_cast<float>(addGold + baseGold) / 2;
    itemAva = averGold >= 2000;

    //cout.precision(2);
    
    cout << "Total Gold: " << addGold + baseGold << endl;
    cout << fixed << setprecision(2) << "Average Gold: " << averGold << endl;
    if (itemAva) {
        cout << "Item purchase available" << endl;
    }

    else {
        cout << "More gold needed" << endl;
    }

    return 0;
    
}
/*setprecision은 특정 출력 시점에만 소수점 이하 자리수를 설정할 수 있어서 다음 출력에 영향을 미치지 않는다.
특정 구간에서만 정밀도를 변경하고 다시 원상태로 돌아가야 할 경우 유용하다.
setprecision은 <iomanip> 헤더에 정의된 다른 조작자와 함께 사용될 때 코드가 더 읽기 쉽고 직관적이기 때문에, 가독성과 유지보수성을 높여준다.
setprecision은 fixed 또는 scientific과 함께 사용되어 출력을 더 일관되게 제어할 수 있다. 이는 출력 형식을 쉽게 변경할 수 있게 해준다.
cout.precision()은 멤버 함수로, 출력 스트림의 정밀도를 영구적으로 설정하거나 변경할 때 사용한다.
반면 setprecision은 일시적으로 특정 출력에서만 정밀도를 변경하는 데 더 적합하며, 다른 조작자와 결합하여 코드의 가독성과 일관성을 높이는 데 도움이 된다.*/