#include <iostream>

/* 기존 C의 포인터를 이용 */
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

/* cpp의 레퍼런스 이용 */
// int main() {
//     int num = 3;
//     int& num2 = num;

//     num2 = 5;
//     std::cout << "num: " << num << std::endl;
//     std::cout << "num2: " << num2 << std::endl;

//     return 0;
// }

/*레퍼러스의 다른 점*/
//레퍼런스는 선언할 때 누구의 레퍼런스인지 바로 지정해야 함
//한번 지정된 레퍼런스는 다른 것의 레퍼런스로 바뀔 수 없음

/*함수의 인자로 레퍼런스 받기 pass-by-reference*/
// int change_val(int& p) { //p를 받은 패러미터에 대한 레퍼런스로 취급
//     p = 3; //패러미터로 들어온 num의 레퍼런스가 p가 되고, p를 3으로 변경하면 num의 값도 변경
//     return 0;
// }

// int main() {
//     int num = 5;

//     std::cout << num << std::endl;
//     change_val(num);
//     std::cout << num << std::endl;

//     return 0;
// }

/*레퍼런스로 리턴받기 return by reference*/
int& function(int& a) { //int& a = b 가 되어서 a가 외부 변수 b에 대한 레퍼런스
    a = 5;
    return a; //a는 외부 변수 b에 대한 레퍼런스이므로 함수 종료 후에도 생존
}

int main () {
    int b = 2;
    int c = function(b);
    std::cout << c << std::endl;

    return 0;
}