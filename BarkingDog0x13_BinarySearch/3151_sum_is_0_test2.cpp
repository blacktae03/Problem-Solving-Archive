#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

// 사용자 정의 비교 함수 (x 좌표 기준으로 정렬)
bool comparePoints(const Point& a, const Point& b) {
    return a.x < b.x;
}

int main() {
    std::vector<Point> points = {{1, 2}, {3, 4}, {1, 5}, {2, 3}};
    std::sort(points.begin(), points.end(), comparePoints); // x 좌표 기준으로 정렬

    Point target = {1, 0}; // x 좌표가 1인 점 찾기

    // x 좌표가 1보다 큰 최초 위치 찾기
    auto it = std::upper_bound(points.begin(), points.end(), target,
                               [](const Point& a, const Point& b) { return a.x < b.x; });

    if (it != points.end()) {
        std::cout << "x: " << it->x << ", y: " << it->y << std::endl;
    } else {
        std::cout << "찾는 원소가 없습니다." << std::endl;
    }

    return 0;
}
