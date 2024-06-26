#include <iostream>

/* 기존 c 포인터 사용 */
// int change_val(int *p);
// int main() {
//     int num = 5;

//     std::cout << num << std::endl;
//     change_val(&num);
//     std::cout << num << std::endl;

//     return 0;
// }

// int change_val(int *p) {
//     *p = 3;
//     return 0;
// }

/* cpp의 레퍼런스 사용 */
// int main() {
//     int num = 3;
//     int& num2 = num;

//     num2 = 5;
//     std::cout << "num: " << num << std::endl;
//     std::cout << "num2: " << num2 << std::endl;

//     return 0;
// }


/*pass-by-reference*/
// int change_val(int& p) { //p瑜? 諛쏆?? ?뙣?윭誘명꽣?뿉 ????븳 ?젅?띁?윴?뒪濡? 痍④툒
//     p = 3; //?뙣?윭誘명꽣濡? ?뱾?뼱?삩 num?쓽 ?젅?띁?윴?뒪媛? p媛? ?릺怨?, p瑜? 3?쑝濡? 蹂?寃쏀븯硫? num?쓽 媛믩룄 蹂?寃?
//     return 0;
// }

// int main() {
//     int num = 5;

//     std::cout << num << std::endl;
//     change_val(num);
//     std::cout << num << std::endl;

//     return 0;
// }

/*return by reference*/
int& function(int& a) { //int& a = b 媛? ?릺?뼱?꽌 a媛? ?쇅遺? 蹂??닔 b?뿉 ????븳 ?젅?띁?윴?뒪
    a = 5;
    return a; //a?뒗 ?쇅遺? 蹂??닔 b?뿉 ????븳 ?젅?띁?윴?뒪?씠誘?濡? ?븿?닔 醫낅즺 ?썑?뿉?룄 ?깮議?
}

int main () {
    int b = 2;
    int c = function(b);
    std::cout << c << std::endl;

    return 0;
}