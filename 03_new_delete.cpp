#include <iostream>

/* new and delete */

// int main() {
//     int *p = new int; //int ?¬κΈ? κ³΅κ°? ? ?Ή?κ³? κ·? μ£Όμλ₯? p? ? ?Ή (κ°μ?? ??!)
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

    int *list = new int[arr_size]; //list?Ό? int ?¬?Έ?°? int λ°°μ΄? μ£Όμλ₯? ? ?Ή

    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }

    for (int i = 0; i < arr_size; i++) {
        std::cout << (i+1) << "th elements is: " << list[i] << std::endl;
    }

    delete[] list;

    return 0;
}