#include <iostream>

/* new and delete */

// int main() {
//     int *p = new int; //int ?¬ê¸? ê³µê°„?„ ?• ?‹¹?•˜ê³? ê·? ì£¼ì†Œë¥? p?— ?• ?‹¹ (ê°’ì?? ?—†?Œ!)
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

    int *list = new int[arr_size]; //list?¼?Š” int ?¬?¸?„°?— int ë°°ì—´?˜ ì£¼ì†Œë¥? ?• ?‹¹

    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }

    for (int i = 0; i < arr_size; i++) {
        std::cout << (i+1) << "th elements is: " << list[i] << std::endl;
    }

    delete[] list;

    return 0;
}