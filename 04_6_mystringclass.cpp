#include <iostream>
#include <cstring>

/* ?��만의 ?��?���? ?��?��?�� 만들�? */
//문자(char)로�???�� 문자?�� ?��?��, 문자 ?��?��?��(char *)로�???�� 문자?�� ?��?��
//문자?�� 길이 구하?�� ?��?��
//문자?�� ?��?�� ?���? 문자?�� 붙이�?
//문자?��?�� 같�??�? 비교
//문자?��?�� ?���? 비교 (?��?�� ?��)

class MyString {
    private:
    int string_len; //문자?��?�� 길이 �??��
    char* string_text; //문자?��?�� ?��?��?�� ?��?��?��?�� 배열?�� �?리키?�� char* ?��?��?��
    int memory_capacity; //?��?�� ?��?��?���? ?��?�� 메모리에 ?��?��?�� 문자 공간?�� ?��

    public:
    //?��?��?��
    MyString(char c); //?���? 문자로�???�� ?��?��?�� ?��?��
    MyString(const char* str); //문자?��?�� �?리키?�� ?��?��?��로�???�� ?��?��?�� ?��?��
    MyString(const MyString& str); //?���? MyString ?��?��?��로�???�� ?��?��?�� ?��?��
    //?��멸자
    ~MyString();
    //문자?�� 길이 ?���? ?��?��
    int StringLen() const;
    //문자?�� ?��?�� ?��?�� ?��?��
    void Print() const;
    void Println() const;
    //문자?�� ?��?�� �?�? ?��?��
    MyString& Assign(const MyString& str);
    MyString& Assign(const char* str);
    //?��?��?�� 메모�? 공간 ?��?��
    int CheckCapacity() const;
    //?��?��?�� ?��기의 메모�? 공간 미리 ?��?��
    void Reserve(int size);
    //문자?�� ?��?��
    MyString& Insert(int loc, const MyString& str);
    MyString& Insert(int loc, const char* str);
    MyString& Insert(int loc, char c);
};

//멤버 ?��?�� ?��?�� 구간
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
    if (str.string_len > memory_capacity) { //?��로운 문자?��?�� ?��?��?�� 공간보다 ?�� 길면 메모�? 공간 ?���? ?��?�� ?��?��
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
    //범위�? 벗어?���? 처리?���? ?��?��
    if (loc < 0 || loc > string_len) {
        return *this;
    }
    
}


//?��?���?
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