#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int howManyStud;
    map<string, int> studGrades;
    float averGrade = 0;
    string tmp1;
    int tmp2;

    cout << "# of students: ";
    cin >> howManyStud;

    for (int i = 0; i < howManyStud; i++) {
        cout << "name & score of student " << i+1 << ": ";
        cin >> tmp1 >> tmp2;
        
        studGrades.insert({tmp1, tmp2}); // pair<string, int>(tmp1, tmp2) 넣어도 될듯
        
        averGrade += tmp2;
    }

    // for (auto iter = studGrades.begin(); iter != studGrades.end(); iter++) {
    //     iterFirst = iter->second > iterFirst->second ? iter : iterFirst;
    // } 이렇게 하니까 아래 출력에서 iterFirst->first 참조가 안됨;;;;;; 이걸 위 반복문에 넣어서 더 간단하게도 해보려고 했는데 그때도 똑같이 first 참조 불가.

    auto iterFirst = max_element(studGrades.begin(), studGrades.end(), [](const auto &x, const auto &y) {
        return x.second < y.second;
    });

    averGrade /= howManyStud;
    
    cout << fixed << setprecision(0) << "The average score of the student is " << averGrade << endl;
    cout << "The student with the highest score is " << iterFirst->first << " with a score of " << iterFirst->second << endl;

    return 0;
}