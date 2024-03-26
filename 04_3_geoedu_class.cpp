#include <iostream>
#include <cstdlib>
#include <cmath>

/* 중학생용 기하학 소프트웨어 */
//클래스는 두 개: Point(점에 관한 정보를 담음), Geometry(점을 가지고 연산)

class Point {
    private:
    int x;
    int y;

    public:
    Point(int _x, int _y) { //패러미터 포함 생성자
        x = _x;
        y = _y;
    }
    int GetX() const {
        return x;
    }
    int GetY() const {
        return y;
    }
};

class Geometry {
    private:
    Point* point_array[100]; // Point 클래스의 인스턴스를 가리키는 주소를 100개 담는 배열
    int num_of_points;

    public:
    //Geometry 클래스의 생성자
    Geometry() {
        num_of_points = 0;
    }

    //Geometry 인스턴스에 점을 추가하는 함수
    void AddPoint(const Point &point) { // 인스턴스를 const 참조로 인자로 가져옴
        point_array[num_of_points] = new Point(point.GetX(), point.GetY());
        num_of_points++;
    }

    //모든 점들 간의 거리를 출력하는 함수
    void PrintDistances() {
        int dx, dy;
        double dist;

        if (num_of_points < 2) {
            std::cout << "점이 하나밖에 없습니다." << std::endl;
            return;
        }

        for (int i = 0; i < num_of_points-1; i++) {
            for (int j = i+1; j < num_of_points; j++) {
                dx = abs((point_array[i]->GetX())-(point_array[j]->GetX()));
                dy = abs((point_array[i]->GetY())-(point_array[j]->GetY()));
                dist = std::sqrt(std::pow(dx, 2)+std::pow(dy, 2));
                std::cout << (i+1) << "번째 점과 " << (j+1) << "번째 점 사이의 거리는 " << dist << "입니다." << std::endl;
            }
        }
        return;
    }

    //모든 점들을 잇는 직선들 사이의 교점의 수를 출력하는 함수
    void PrintMeetNums() {
        double slope1;
        double slope2;
        int num_of_cross = 0;
        for (int i = 0; i < num_of_points-1; i++) {
            for (int j = i + 1; j < num_of_points; j++) {
                slope1 = ((point_array[j]->GetY())-(point_array[i]->GetY()))/(point_array[j]->GetX())-(point_array[i]->GetX());
                for (int k = i; k < num_of_points-1; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    for (int l = k + 1; l < num_of_points; l++) {
                        if (l == i || l == j) {
                            continue;
                        }
                        slope2 = ((point_array[l]->GetY())-(point_array[k]->GetY()))/(point_array[l]->GetX())-(point_array[k]->GetX());
                        if (slope1 != slope2) {
                            num_of_cross += 1;
                        }
                    }
                }
            }
        }
        num_of_cross += num_of_points;
        std::cout << "교차점의 수는 " << num_of_cross << "개 입니다.";
        return;
    }

    //입력되어 있는 모든 점을 출력하는 함수
    void PrintPoints() {
        for (int i = 0; i < num_of_points; i++) {
            std::cout << i+1 << "번째 공간에는 (" << point_array[i]->GetX() << "," << point_array[i]->GetY() << ")가 있습니다." << std::endl;
        }
    }

};

int main() {
    int input;
    int entered_point_num = 0;
    Geometry gm;

    std::cout << "---기하학 계산기---" << std::endl;

    while (true) {
        int x, y;

        std::cout << "어떤 기능을 사용하시겠어요?" << std::endl;
        std::cout << "1 - 점 추가하기" << std::endl;
        std::cout << "2 - 입력된 점들 사이의 거리 구하기" << std::endl;
        std::cout << "3 - 입력된 점들을 모두 이었을 때의 교점 수 구하기" << std::endl;
        std::cout << "0 - 입력되어 있는 점들의 목록 확인하기" << std::endl;

        std::cin >> input;

        switch(input) {
            case 1: { 
                std::cout << "점의 X 좌표를 입력해주세요: ";
                std::cin >> x;
                std::cout << "점의 Y 좌표를 입력해주세요: ";
                std::cin >> y;
                Point point(x, y);
                gm.AddPoint(point);
                std::cout << "입력하신 (" << x << ", " << y << ")가 " << entered_point_num+1 << "번째 공간에 저장되었습니다." << std::endl;
                entered_point_num += 1;
                break;
            }                
            case 2:
                gm.PrintDistances();
                break;
            case 3:
                gm.PrintMeetNums();
                break;
            case 0:
                gm.PrintPoints();
                break;
        }
    }

    return 0;
}