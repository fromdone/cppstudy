#include <iostream>
#include <cstdlib>
#include <cmath>

/* ì¤‘í•™?ƒ?š© ê¸°í•˜?•™ ?†Œ?”„?Š¸?›¨?–´ */
//?´?˜?Š¤?Š” ?‘ ê°?: Point(? ?— ê´??•œ ? •ë³´ë?? ?‹´?Œ), Geometry(? ?„ ê°?ì§?ê³? ?—°?‚°)

class Point {
    private:
    int x;
    int y;

    public:
    Point(int _x, int _y) { //?Œ¨?Ÿ¬ë¯¸í„° ?¬?•¨ ?ƒ?„±?
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
    Point* point_array[100]; // Point ?´?˜?Š¤?˜ ?¸?Š¤?„´?Š¤ë¥? ê°?ë¦¬í‚¤?Š” ì£¼ì†Œë¥? 100ê°? ?‹´?Š” ë°°ì—´
    int num_of_points;

    public:
    //Geometry ?´?˜?Š¤?˜ ?ƒ?„±?
    Geometry() {
        num_of_points = 0;
    }

    //Geometry ?¸?Š¤?„´?Š¤?— ? ?„ ì¶”ê???•˜?Š” ?•¨?ˆ˜
    void AddPoint(const Point &point) { // ?¸?Š¤?„´?Š¤ë¥? const ì°¸ì¡°ë¡? ?¸?ë¡? ê°?? ¸?˜´
        point_array[num_of_points] = new Point(point.GetX(), point.GetY());
        num_of_points++;
    }

    //ëª¨ë“  ? ?“¤ ê°„ì˜ ê±°ë¦¬ë¥? ì¶œë ¥?•˜?Š” ?•¨?ˆ˜
    void PrintDistances() {
        int dx, dy;
        double dist;

        if (num_of_points < 2) {
            std::cout << "? ?´ ?•˜?‚˜ë°–ì— ?—†?Šµ?‹ˆ?‹¤." << std::endl;
            return;
        }

        for (int i = 0; i < num_of_points-1; i++) {
            for (int j = i+1; j < num_of_points; j++) {
                dx = abs((point_array[i]->GetX())-(point_array[j]->GetX()));
                dy = abs((point_array[i]->GetY())-(point_array[j]->GetY()));
                dist = std::sqrt(std::pow(dx, 2)+std::pow(dy, 2));
                std::cout << (i+1) << "ë²ˆì§¸ ? ê³? " << (j+1) << "ë²ˆì§¸ ?  ?‚¬?´?˜ ê±°ë¦¬?Š” " << dist << "?…?‹ˆ?‹¤." << std::endl;
            }
        }
        return;
    }

    //ëª¨ë“  ? ?“¤?„ ?‡?Š” ì§ì„ ?“¤ ?‚¬?´?˜ êµì ?˜ ?ˆ˜ë¥? ì¶œë ¥?•˜?Š” ?•¨?ˆ˜
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
        std::cout << "êµì°¨? ?˜ ?ˆ˜?Š” " << num_of_cross << "ê°? ?…?‹ˆ?‹¤.";
        return;
    }

    //?…? ¥?˜?–´ ?ˆ?Š” ëª¨ë“  ? ?„ ì¶œë ¥?•˜?Š” ?•¨?ˆ˜
    void PrintPoints() {
        for (int i = 0; i < num_of_points; i++) {
            std::cout << i+1 << "ë²ˆì§¸ ê³µê°„?—?Š” (" << point_array[i]->GetX() << "," << point_array[i]->GetY() << ")ê°? ?ˆ?Šµ?‹ˆ?‹¤." << std::endl;
        }
    }

};

int main() {
    int input;
    int entered_point_num = 0;
    Geometry gm;

    std::cout << "---ê¸°í•˜?•™ ê³„ì‚°ê¸?---" << std::endl;

    while (true) {
        int x, y;

        std::cout << "?–´?–¤ ê¸°ëŠ¥?„ ?‚¬?š©?•˜?‹œê² ì–´?š”?" << std::endl;
        std::cout << "1 - ?  ì¶”ê???•˜ê¸?" << std::endl;
        std::cout << "2 - ?…? ¥?œ ? ?“¤ ?‚¬?´?˜ ê±°ë¦¬ êµ¬í•˜ê¸?" << std::endl;
        std::cout << "3 - ?…? ¥?œ ? ?“¤?„ ëª¨ë‘ ?´?—ˆ?„ ?•Œ?˜ êµì  ?ˆ˜ êµ¬í•˜ê¸?" << std::endl;
        std::cout << "0 - ?…? ¥?˜?–´ ?ˆ?Š” ? ?“¤?˜ ëª©ë¡ ?™•?¸?•˜ê¸?" << std::endl;

        std::cin >> input;

        switch(input) {
            case 1: { 
                std::cout << "? ?˜ X ì¢Œí‘œë¥? ?…? ¥?•´ì£¼ì„¸?š”: ";
                std::cin >> x;
                std::cout << "? ?˜ Y ì¢Œí‘œë¥? ?…? ¥?•´ì£¼ì„¸?š”: ";
                std::cin >> y;
                Point point(x, y);
                gm.AddPoint(point);
                std::cout << "?…? ¥?•˜?‹  (" << x << ", " << y << ")ê°? " << entered_point_num+1 << "ë²ˆì§¸ ê³µê°„?— ????¥?˜?—ˆ?Šµ?‹ˆ?‹¤." << std::endl;
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