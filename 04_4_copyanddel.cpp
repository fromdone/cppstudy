#include <iostream>
#include <cstring>

class String {
    private:
    char *str;
    int len;

    public:
    //c를 n번 반복하는 생성자
    String(char c, int n);
    //입력한 문자열을 담는 생성자
    String(const char *string);
    //복사 생성자
    String(const String& string);
    // //소멸자
    ~String();

    //함수
    void PrintString();
    void AddString(const String &s); //기존 문자열 뒤에 s를 추가
    void CopyString(const String &s); //기존 문자열을 s로 변경
    int StrLen(); //문자열의 길이를 출력
    
};

String::String(char c, int n) {
    len = n;
    str = new char[len+1];
    for (int i = 0; i < len; i++) {
        str[i] = c;
    }
    str[len] = '\0';
}
String::String(const char *string) {
    len = strlen(string);
    str = new char[len+1];
    strcpy(str, string);
}
String::String(const String &string) {
    //str은 포인터이므로 그대로 복사하면 문제의 소지가 있어 깊은 복사 필요
    str = new char[strlen(string.str)+1];
    strcpy(str, string.str);
    len = string.len;
    
    // char *pt1 = string.str;
    // char *pt2 = str;
    
    // std::cout << "원 스트링의 주소는 " << static_cast<void*>(pt1) << std::endl;
    // std::cout << "복사된 스트링의 주소는 " << reinterpret_cast<void*>(pt2) << std::endl;
}
String::~String() {
    if (str) {
        delete[] str;
    }
}

void String::PrintString() {
    std::cout << "입력되어 있는 문장은 " << str << "입니다." << std::endl;
    return;
}
void String::AddString(const String &s) {
    len = strlen(str)+strlen(s.str);
    char* combined = new char[len+1];
    for (int i = 0; i < strlen(str); i++) {
        combined[i] = str[i];
    }
    for (int j = strlen(str); j < len; j++) {
        combined[j] = s.str[j-strlen(str)];
    }
    delete[] str;
    str = combined;
}
void String::CopyString(const String &s) {
    len = strlen(s.str);
    str = new char[len+1];
    strcpy(str, s.str);
}

int String::StrLen() {
    std::cout << len << std::endl;
    return len;
}

int main() {
    String sentence1('a', 10);
    String sentence2("hello");

    sentence1.PrintString();
    sentence2.PrintString();

    String sentence3('b', 10);
    sentence1.AddString(sentence3);

    sentence1.PrintString();

    sentence2.CopyString(sentence3);
    sentence2.PrintString();

    sentence1.StrLen();
    sentence2.StrLen();
    sentence3.StrLen();

    return 0;
}
