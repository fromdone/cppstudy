#include <iostream>
#include <limits>

typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal* animal) { // ?��로운 ?��물을 ?��?��?��?�� ?��?��
    std::cout << "Animal's name: ";
    std::cin >> animal->name;

    std::cout << "Animal's age: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play_animal(Animal* animal) { // ?��물이 ???�? ?��?�� ?��?��: ?��?��치�?? �?경됨. ?��?���? 받는 것�?? �? ?��물의 구조체의 주소 ?��?��?��
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
    Animal* list[10]; // Animal* ????��?�� ?��?�� 10개�?? ?��?���??�� 리스?���? ?��?��
    int animal_num = 0;

    for (;;) {
        std::cout << "1. Add animal" << std::endl;
        std::cout << "2. Play with animal" << std::endl;
        std::cout << "3. Check animal's status" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;

            case 1: //?���? 추�???���?
                list[animal_num] = new Animal; //Animal ????�� 구조체만?��?�� 메모리�?? ?��?�� ?��?��?��?�� 주소�? list[animal_num]?�� ?��?��
                create_animal(list[animal_num]); //?��?�� 주소�? �?리키?�� 구조체에 ????�� ?��?��?�� 채우?�� ?��?�� ?���?
                animal_num++; //?��료되�? 리스?�� ?��치�?? ?��?�� ?���?
                break;

            case 2: //?��물과 ???�?
                std::cout << "Which animal do you want to play with?: ";
                std::cin >> play_with;

                if (play_with < animal_num) {
                    play_animal(list[play_with]);
                } else {
                    std::cout << "Animal not found." << std::endl;
                }

                break;

            case 3: //?��?�� 보기
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