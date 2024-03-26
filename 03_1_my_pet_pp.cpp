#include <iostream>
#include <limits>

typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal* animal) { // 새로운 동물을 입력하는 함수
    std::cout << "Animal's name: ";
    std::cin >> animal->name;

    std::cout << "Animal's age: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play_animal(Animal* animal) { // 동물이 놀게 하는 함수: 능력치가 변경됨. 인자로 받는 것은 그 동물의 구조체의 주소 포인터
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
    Animal* list[10]; // Animal* 타입의 요소 10개가 들어가는 리스트를 선언
    int animal_num = 0;

    for (;;) {
        std::cout << "1. Add animal" << std::endl;
        std::cout << "2. Play with animal" << std::endl;
        std::cout << "3. Check animal's status" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;

            case 1: //동물 추가하기
                list[animal_num] = new Animal; //Animal 타입 구조체만큼의 메모리를 힙에 할당하여 주소를 list[animal_num]에 할당
                create_animal(list[animal_num]); //해당 주소가 가리키는 구조체에 대해 내용을 채우는 함수 호출
                animal_num++; //완료되면 리스트 위치를 하나 위로
                break;

            case 2: //동물과 놀기
                std::cout << "Which animal do you want to play with?: ";
                std::cin >> play_with;

                if (play_with < animal_num) {
                    play_animal(list[play_with]);
                } else {
                    std::cout << "Animal not found." << std::endl;
                }

                break;

            case 3: //상태 보기
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