#include <iostream>
#include <limits>

typedef struct Animal{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

void create_animal(Animal* animal) { // ?ƒˆë¡œìš´ ?™ë¬¼ì„ ?…? ¥?•˜?Š” ?•¨?ˆ˜
    std::cout << "Animal's name: ";
    std::cin >> animal->name;

    std::cout << "Animal's age: ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play_animal(Animal* animal) { // ?™ë¬¼ì´ ???ê²? ?•˜?Š” ?•¨?ˆ˜: ?Š¥? ¥ì¹˜ê?? ë³?ê²½ë¨. ?¸?ë¡? ë°›ëŠ” ê²ƒì?? ê·? ?™ë¬¼ì˜ êµ¬ì¡°ì²´ì˜ ì£¼ì†Œ ?¬?¸?„°
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
    Animal* list[10]; // Animal* ????…?˜ ?š”?†Œ 10ê°œê?? ?“¤?–´ê°??Š” ë¦¬ìŠ¤?Š¸ë¥? ?„ ?–¸
    int animal_num = 0;

    for (;;) {
        std::cout << "1. Add animal" << std::endl;
        std::cout << "2. Play with animal" << std::endl;
        std::cout << "3. Check animal's status" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;

            case 1: //?™ë¬? ì¶”ê???•˜ê¸?
                list[animal_num] = new Animal; //Animal ????… êµ¬ì¡°ì²´ë§Œ?¼?˜ ë©”ëª¨ë¦¬ë?? ?™?— ?• ?‹¹?•˜?—¬ ì£¼ì†Œë¥? list[animal_num]?— ?• ?‹¹
                create_animal(list[animal_num]); //?•´?‹¹ ì£¼ì†Œê°? ê°?ë¦¬í‚¤?Š” êµ¬ì¡°ì²´ì— ????•´ ?‚´?š©?„ ì±„ìš°?Š” ?•¨?ˆ˜ ?˜¸ì¶?
                animal_num++; //?™„ë£Œë˜ë©? ë¦¬ìŠ¤?Š¸ ?œ„ì¹˜ë?? ?•˜?‚˜ ?œ„ë¡?
                break;

            case 2: //?™ë¬¼ê³¼ ???ê¸?
                std::cout << "Which animal do you want to play with?: ";
                std::cin >> play_with;

                if (play_with < animal_num) {
                    play_animal(list[play_with]);
                } else {
                    std::cout << "Animal not found." << std::endl;
                }

                break;

            case 3: //?ƒ?ƒœ ë³´ê¸°
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