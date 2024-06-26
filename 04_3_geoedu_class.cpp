#include <iostream>
#include <cstdlib>
#include <cmath>

/* μ€ν??© κΈ°ν? ???Έ?¨?΄ */
//?΄??€? ? κ°?: Point(? ? κ΄?? ? λ³΄λ?? ?΄?), Geometry(? ? κ°?μ§?κ³? ?°?°)

class Point {
    private:
    int x;
    int y;

    public:
    Point(int _x, int _y) { //?¨?¬λ―Έν° ?¬?¨ ??±?
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
    Point* point_array[100]; // Point ?΄??€? ?Έ?€?΄?€λ₯? κ°?λ¦¬ν€? μ£Όμλ₯? 100κ°? ?΄? λ°°μ΄
    int num_of_points;

    public:
    //Geometry ?΄??€? ??±?
    Geometry() {
        num_of_points = 0;
    }

    //Geometry ?Έ?€?΄?€? ? ? μΆκ???? ?¨?
    void AddPoint(const Point &point) { // ?Έ?€?΄?€λ₯? const μ°Έμ‘°λ‘? ?Έ?λ‘? κ°?? Έ?΄
        point_array[num_of_points] = new Point(point.GetX(), point.GetY());
        num_of_points++;
    }

    //λͺ¨λ  ? ?€ κ°μ κ±°λ¦¬λ₯? μΆλ ₯?? ?¨?
    void PrintDistances() {
        int dx, dy;
        double dist;

        if (num_of_points < 2) {
            std::cout << "? ?΄ ??λ°μ ??΅??€." << std::endl;
            return;
        }

        for (int i = 0; i < num_of_points-1; i++) {
            for (int j = i+1; j < num_of_points; j++) {
                dx = abs((point_array[i]->GetX())-(point_array[j]->GetX()));
                dy = abs((point_array[i]->GetY())-(point_array[j]->GetY()));
                dist = std::sqrt(std::pow(dx, 2)+std::pow(dy, 2));
                std::cout << (i+1) << "λ²μ§Έ ? κ³? " << (j+1) << "λ²μ§Έ ?  ?¬?΄? κ±°λ¦¬? " << dist << "???€." << std::endl;
            }
        }
        return;
    }

    //λͺ¨λ  ? ?€? ?? μ§μ ?€ ?¬?΄? κ΅μ ? ?λ₯? μΆλ ₯?? ?¨?
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
        std::cout << "κ΅μ°¨? ? ?? " << num_of_cross << "κ°? ???€.";
        return;
    }

    //?? ₯??΄ ?? λͺ¨λ  ? ? μΆλ ₯?? ?¨?
    void PrintPoints() {
        for (int i = 0; i < num_of_points; i++) {
            std::cout << i+1 << "λ²μ§Έ κ³΅κ°?? (" << point_array[i]->GetX() << "," << point_array[i]->GetY() << ")κ°? ??΅??€." << std::endl;
        }
    }

};

int main() {
    int input;
    int entered_point_num = 0;
    Geometry gm;

    std::cout << "---κΈ°ν? κ³μ°κΈ?---" << std::endl;

    while (true) {
        int x, y;

        std::cout << "?΄?€ κΈ°λ₯? ?¬?©??κ² μ΄??" << std::endl;
        std::cout << "1 - ?  μΆκ???κΈ?" << std::endl;
        std::cout << "2 - ?? ₯? ? ?€ ?¬?΄? κ±°λ¦¬ κ΅¬νκΈ?" << std::endl;
        std::cout << "3 - ?? ₯? ? ?€? λͺ¨λ ?΄?? ?? κ΅μ  ? κ΅¬νκΈ?" << std::endl;
        std::cout << "0 - ?? ₯??΄ ?? ? ?€? λͺ©λ‘ ??Έ?κΈ?" << std::endl;

        std::cin >> input;

        switch(input) {
            case 1: { 
                std::cout << "? ? X μ’νλ₯? ?? ₯?΄μ£ΌμΈ?: ";
                std::cin >> x;
                std::cout << "? ? Y μ’νλ₯? ?? ₯?΄μ£ΌμΈ?: ";
                std::cin >> y;
                Point point(x, y);
                gm.AddPoint(point);
                std::cout << "?? ₯??  (" << x << ", " << y << ")κ°? " << entered_point_num+1 << "λ²μ§Έ κ³΅κ°? ????₯???΅??€." << std::endl;
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