#include <iostream>
#include <cstdlib>
#include <cmath>

/* 중학?��?�� 기하?�� ?��?��?��?��?�� */
//?��?��?��?�� ?�� �?: Point(?��?�� �??�� ?��보�?? ?��?��), Geometry(?��?�� �?�?�? ?��?��)

class Point {
    private:
    int x;
    int y;

    public:
    Point(int _x, int _y) { //?��?��미터 ?��?�� ?��?��?��
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
    Point* point_array[100]; // Point ?��?��?��?�� ?��?��?��?���? �?리키?�� 주소�? 100�? ?��?�� 배열
    int num_of_points;

    public:
    //Geometry ?��?��?��?�� ?��?��?��
    Geometry() {
        num_of_points = 0;
    }

    //Geometry ?��?��?��?��?�� ?��?�� 추�???��?�� ?��?��
    void AddPoint(const Point &point) { // ?��?��?��?���? const 참조�? ?��?���? �??��?��
        point_array[num_of_points] = new Point(point.GetX(), point.GetY());
        num_of_points++;
    }

    //모든 ?��?�� 간의 거리�? 출력?��?�� ?��?��
    void PrintDistances() {
        int dx, dy;
        double dist;

        if (num_of_points < 2) {
            std::cout << "?��?�� ?��?��밖에 ?��?��?��?��." << std::endl;
            return;
        }

        for (int i = 0; i < num_of_points-1; i++) {
            for (int j = i+1; j < num_of_points; j++) {
                dx = abs((point_array[i]->GetX())-(point_array[j]->GetX()));
                dy = abs((point_array[i]->GetY())-(point_array[j]->GetY()));
                dist = std::sqrt(std::pow(dx, 2)+std::pow(dy, 2));
                std::cout << (i+1) << "번째 ?���? " << (j+1) << "번째 ?�� ?��?��?�� 거리?�� " << dist << "?��?��?��." << std::endl;
            }
        }
        return;
    }

    //모든 ?��?��?�� ?��?�� 직선?�� ?��?��?�� 교점?�� ?���? 출력?��?�� ?��?��
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
        std::cout << "교차?��?�� ?��?�� " << num_of_cross << "�? ?��?��?��.";
        return;
    }

    //?��?��?��?�� ?��?�� 모든 ?��?�� 출력?��?�� ?��?��
    void PrintPoints() {
        for (int i = 0; i < num_of_points; i++) {
            std::cout << i+1 << "번째 공간?��?�� (" << point_array[i]->GetX() << "," << point_array[i]->GetY() << ")�? ?��?��?��?��." << std::endl;
        }
    }

};

int main() {
    int input;
    int entered_point_num = 0;
    Geometry gm;

    std::cout << "---기하?�� 계산�?---" << std::endl;

    while (true) {
        int x, y;

        std::cout << "?��?�� 기능?�� ?��?��?��?��겠어?��?" << std::endl;
        std::cout << "1 - ?�� 추�???���?" << std::endl;
        std::cout << "2 - ?��?��?�� ?��?�� ?��?��?�� 거리 구하�?" << std::endl;
        std::cout << "3 - ?��?��?�� ?��?��?�� 모두 ?��?��?�� ?��?�� 교점 ?�� 구하�?" << std::endl;
        std::cout << "0 - ?��?��?��?�� ?��?�� ?��?��?�� 목록 ?��?��?���?" << std::endl;

        std::cin >> input;

        switch(input) {
            case 1: { 
                std::cout << "?��?�� X 좌표�? ?��?��?��주세?��: ";
                std::cin >> x;
                std::cout << "?��?�� Y 좌표�? ?��?��?��주세?��: ";
                std::cin >> y;
                Point point(x, y);
                gm.AddPoint(point);
                std::cout << "?��?��?��?�� (" << x << ", " << y << ")�? " << entered_point_num+1 << "번째 공간?�� ????��?��?��?��?��?��." << std::endl;
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