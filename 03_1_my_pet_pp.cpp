#include <iostream>
#include <limits>

typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal* animal) { // ?λ‘μ΄ ?λ¬Όμ ?? ₯?? ?¨?
    std::cout << "Animal's name: ";
    std::cin >> animal->name;

    std::cout << "Animal's age: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play_animal(Animal* animal) { // ?λ¬Όμ΄ ???κ²? ?? ?¨?: ?₯? ₯μΉκ?? λ³?κ²½λ¨. ?Έ?λ‘? λ°λ κ²μ?? κ·? ?λ¬Όμ κ΅¬μ‘°μ²΄μ μ£Όμ ?¬?Έ?°
    animal->health -= 10;
    animal->food -= 20;
    animal->clean -= 30;
}

void one_day_later(Animal* animal) {
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}

void show_animal_stat(Animal* animal) {
    std::cout << animal->name << "'s present status" << std::endl;
    std::cout << "Health: " << animal->health << std::endl;
    std::cout << "Food: " << animal->food << std::endl;
    std::cout << "Clean: " << animal->clean << std::endl;
}

int main() {
    Animal* list[10]; // Animal* ????? ?? 10κ°κ?? ?€?΄κ°?? λ¦¬μ€?Έλ₯? ? ?Έ
    int animal_num = 0;

    for (;;) {
        std::cout << "1. Add animal" << std::endl;
        std::cout << "2. Play with animal" << std::endl;
        std::cout << "3. Check animal's status" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;

            case 1: //?λ¬? μΆκ???κΈ?
                list[animal_num] = new Animal; //Animal ???? κ΅¬μ‘°μ²΄λ§?Ό? λ©λͺ¨λ¦¬λ?? ?? ? ?Ή??¬ μ£Όμλ₯? list[animal_num]? ? ?Ή
                create_animal(list[animal_num]); //?΄?Ή μ£Όμκ°? κ°?λ¦¬ν€? κ΅¬μ‘°μ²΄μ ????΄ ?΄?©? μ±μ°? ?¨? ?ΈμΆ?
                animal_num++; //?λ£λλ©? λ¦¬μ€?Έ ?μΉλ?? ?? ?λ‘?
                break;

            case 2: //?λ¬Όκ³Ό ???κΈ?
                std::cout << "Which animal do you want to play with?: ";
                std::cin >> play_with;

                if (play_with < animal_num) {
                    play_animal(list[play_with]);
                } else {
                    std::cout << "Animal not found." << std::endl;
                }

                break;

            case 3: //?? λ³΄κΈ°
                std::cout << "Which animal do you want to check?: ";
                std::cin >> play_with;

                if (play_with < animal_num) {
                    show_animal_stat(list[play_with]);
                } else {
                    std::cout << "Animal not found." <<std::endl;
                }

                break;
        }
        for (int i = 0; i < animal_num; i++) {
            one_day_later(list[i]);
        }
    }
    for (int i = 0; i < animal_num; i++) {
        delete list[i];
    }
}