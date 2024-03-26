#include <iostream>
#include <cstring>

/* 나만의 스트링 클래스 만들기 */
//문자(char)로부터 문자열 생성, 문자 포인터(char *)로부터 문자열 생성
//문자열 길이 구하는 함수
//문자열 뒤에 다른 문자열 붙이기
//문자열이 같은지 비교
//문자열의 크기 비교 (사전 순)

class MyString {
    private:
    int string_len; //문자열의 길이 변수
    char* string_text; //문자열의 내용이 들어있는 배열을 가리키는 char* 포인터
    int memory_capacity; //해당 클래스를 위해 메모리에 할당된 문자 공간의 수

    public:
    //생성자
    MyString(char c); //일반 문자로부터 클래스 생성
    MyString(const char* str); //문자열을 가리키는 포인터로부터 클래스 생성
    MyString(const MyString& str); //다른 MyString 클래스로부터 클래스 생성
    //소멸자
    ~MyString();
    //문자열 길이 읽기 함수
    int StringLen() const;
    //문자열 내용 확인 함수
    void Print() const;
    void Println() const;
    //문자열 내용 변경 함수
    MyString& Assign(const MyString& str);
    MyString& Assign(const char* str);
    //할당된 메모리 공간 확인
    int CheckCapacity() const;
    //원하는 크기의 메모리 공간 미리 할당
    void Reserve(int size);
    //문자열 삽입
    MyString& Insert(int loc, const MyString& str);
    MyString& Insert(int loc, const char* str);
    MyString& Insert(int loc, char c);
};

//멤버 함수 정의 구간
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
    if (str.string_len > memory_capacity) { //새로운 문자열이 할당된 공간보다 더 길면 메모리 공간 새로 할당 필요
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
    //범위를 벗어나면 처리하지 않음
    if (loc < 0 || loc > string_len) {
        return *this;
    }
    
}


//실행부
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