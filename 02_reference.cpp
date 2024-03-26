#include <iostream>

/* ±âÁ¸ c Æ÷ÀÎÅÍ »ç¿ë */
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

/* cppÀÇ ·¹ÆÛ·±½º »ç¿ë */
// int main() {
//     int num = 3;
//     int& num2 = num;

//     num2 = 5;
//     std::cout << "num: " << num << std::endl;
//     std::cout << "num2: " << num2 << std::endl;

//     return 0;
// }


/*pass-by-reference*/
// int change_val(int& p) { //pë¥? ë°›ì?? ?Œ¨?Ÿ¬ë¯¸í„°?— ????•œ ? ˆ?¼?Ÿ°?Š¤ë¡? ì·¨ê¸‰
//     p = 3; //?Œ¨?Ÿ¬ë¯¸í„°ë¡? ?“¤?–´?˜¨ num?˜ ? ˆ?¼?Ÿ°?Š¤ê°? pê°? ?˜ê³?, pë¥? 3?œ¼ë¡? ë³?ê²½í•˜ë©? num?˜ ê°’ë„ ë³?ê²?
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
int& function(int& a) { //int& a = b ê°? ?˜?–´?„œ aê°? ?™¸ë¶? ë³??ˆ˜ b?— ????•œ ? ˆ?¼?Ÿ°?Š¤
    a = 5;
    return a; //a?Š” ?™¸ë¶? ë³??ˆ˜ b?— ????•œ ? ˆ?¼?Ÿ°?Š¤?´ë¯?ë¡? ?•¨?ˆ˜ ì¢…ë£Œ ?›„?—?„ ?ƒì¡?
}

int main () {
    int b = 2;
    int c = function(b);
    std::cout << c << std::endl;

    return 0;
}