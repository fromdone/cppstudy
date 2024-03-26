#include <iostream>

/* new and delete */

// int main() {
//     int *p = new int; //int 크기 공간을 할당하고 그 주소를 p에 할당 (값은 없음!)
//     *p = 10;

//     std::cout << *p << std::endl;

//     delete p;

//     return 0;
// }

/* assign array using new */
int main() {
    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;

    int *list = new int[arr_size]; //list라는 int 포인터에 int 배열의 주소를 할당

    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }

    for (int i = 0; i < arr_size; i++) {
        std::cout << (i+1) << "th elements is: " << list[i] << std::endl;
    }

    delete[] list;

    return 0;
}