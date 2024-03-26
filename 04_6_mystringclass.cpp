#include <iostream>
#include <cstring>

/* ?‚˜ë§Œì˜ ?Š¤?Š¸ë§? ?´?˜?Š¤ ë§Œë“¤ê¸? */
//ë¬¸ì(char)ë¡œë???„° ë¬¸ì?—´ ?ƒ?„±, ë¬¸ì ?¬?¸?„°(char *)ë¡œë???„° ë¬¸ì?—´ ?ƒ?„±
//ë¬¸ì?—´ ê¸¸ì´ êµ¬í•˜?Š” ?•¨?ˆ˜
//ë¬¸ì?—´ ?’¤?— ?‹¤ë¥? ë¬¸ì?—´ ë¶™ì´ê¸?
//ë¬¸ì?—´?´ ê°™ì??ì§? ë¹„êµ
//ë¬¸ì?—´?˜ ?¬ê¸? ë¹„êµ (?‚¬? „ ?ˆœ)

class MyString {
    private:
    int string_len; //ë¬¸ì?—´?˜ ê¸¸ì´ ë³??ˆ˜
    char* string_text; //ë¬¸ì?—´?˜ ?‚´?š©?´ ?“¤?–´?ˆ?Š” ë°°ì—´?„ ê°?ë¦¬í‚¤?Š” char* ?¬?¸?„°
    int memory_capacity; //?•´?‹¹ ?´?˜?Š¤ë¥? ?œ„?•´ ë©”ëª¨ë¦¬ì— ?• ?‹¹?œ ë¬¸ì ê³µê°„?˜ ?ˆ˜

    public:
    //?ƒ?„±?
    MyString(char c); //?¼ë°? ë¬¸ìë¡œë???„° ?´?˜?Š¤ ?ƒ?„±
    MyString(const char* str); //ë¬¸ì?—´?„ ê°?ë¦¬í‚¤?Š” ?¬?¸?„°ë¡œë???„° ?´?˜?Š¤ ?ƒ?„±
    MyString(const MyString& str); //?‹¤ë¥? MyString ?´?˜?Š¤ë¡œë???„° ?´?˜?Š¤ ?ƒ?„±
    //?†Œë©¸ì
    ~MyString();
    //ë¬¸ì?—´ ê¸¸ì´ ?½ê¸? ?•¨?ˆ˜
    int StringLen() const;
    //ë¬¸ì?—´ ?‚´?š© ?™•?¸ ?•¨?ˆ˜
    void Print() const;
    void Println() const;
    //ë¬¸ì?—´ ?‚´?š© ë³?ê²? ?•¨?ˆ˜
    MyString& Assign(const MyString& str);
    MyString& Assign(const char* str);
    //?• ?‹¹?œ ë©”ëª¨ë¦? ê³µê°„ ?™•?¸
    int CheckCapacity() const;
    //?›?•˜?Š” ?¬ê¸°ì˜ ë©”ëª¨ë¦? ê³µê°„ ë¯¸ë¦¬ ?• ?‹¹
    void Reserve(int size);
    //ë¬¸ì?—´ ?‚½?…
    MyString& Insert(int loc, const MyString& str);
    MyString& Insert(int loc, const char* str);
    MyString& Insert(int loc, char c);
};

//ë©¤ë²„ ?•¨?ˆ˜ ? •?˜ êµ¬ê°„
MyString::MyString(char c) {
    string_len = 1;
    memory_capacity = 1;
    string_text = new char[1];
    string_text[0] = c;
}

MyString::MyString(const char* str) {
    string_len = strlen(str);
    memory_capacity = string_len;
    string_text = new char[string_len];
    for (int i = 0; i < string_len; i++) {
        string_text[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    string_len = str.string_len;
    memory_capacity = string_len;
    string_text = new char[string_len];
    for (int i = 0; i < string_len; i++) {
        string_text[i] = str.string_text[i];
    }
}

MyString::~MyString() {
    delete[] string_text;
}

int MyString::StringLen() const {
    return string_len;
}

void MyString::Print() const {
    for (int i = 0; i < string_len; i++) {
        std::cout << string_text[i];
    }
}

void MyString::Println() const {
    for (int i = 0; i < string_len; i++) {
        std::cout << string_text[i];
    }
    std::cout << std::endl;
}

MyString& MyString::Assign(const MyString& str) {
    if (str.string_len > memory_capacity) { //?ƒˆë¡œìš´ ë¬¸ì?—´?´ ?• ?‹¹?œ ê³µê°„ë³´ë‹¤ ?” ê¸¸ë©´ ë©”ëª¨ë¦? ê³µê°„ ?ƒˆë¡? ?• ?‹¹ ?•„?š”
        delete[] string_text;
        string_text = new char[str.string_len];
    }
    for (int i = 0; i < str.string_len; i++) {
        string_text[i] = str.string_text[i];
    }
    string_len = str.string_len;

    return *this;
}

MyString& MyString::Assign(const char* str) {
    if (strlen(str) > memory_capacity) {
        delete[] string_text;
        string_text = new char[strlen(str)];
    }

    return *this;
}

int MyString::CheckCapacity() const {
    return memory_capacity;
}

void MyString::Reserve(int size) {
    if (size > memory_capacity) {
        char* prev_text = string_text;
        string_text = new char[size];

        for (int i = 0; i < string_len; i++) {
            string_text[i] = prev_text[i];
        }

        delete[] prev_text;
        memory_capacity = size;
    }
}

MyString& MyString::Insert(int loc, const MyString& str) {
    //ë²”ìœ„ë¥? ë²—ì–´?‚˜ë©? ì²˜ë¦¬?•˜ì§? ?•Š?Œ
    if (loc < 0 || loc > string_len) {
        return *this;
    }
    
}


//?‹¤?–‰ë¶?
int main() {
    MyString line1("Hello, world!");
    std::cout << line1.CheckCapacity() << std::endl;
    std::cout << line1.StringLen() << std::endl;
    line1.Println();

    line1.Reserve(30);
    std::cout << line1.CheckCapacity() << std::endl;
    std::cout << line1.StringLen() << std::endl;
    line1.Println();

    return 0;
}