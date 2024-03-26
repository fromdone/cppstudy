#include <iostream>
#include <cstring>

class String {
    private:
    char *str;
    int len;

    public:
    //c�? n�? 반복?��?�� ?��?��?��
    String(char c, int n);
    //?��?��?�� 문자?��?�� ?��?�� ?��?��?��
    String(const char *string);
    //복사 ?��?��?��
    String(const String& string);
    // //?��멸자
    ~String();

    //?��?��
    void PrintString();
    void AddString(const String &s); //기존 문자?�� ?��?�� s�? 추�??
    void CopyString(const String &s); //기존 문자?��?�� s�? �?�?
    int StrLen(); //문자?��?�� 길이�? 출력
    
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
    //str??? ?��?��?��?���?�? 그�??�? 복사?���? 문제?�� ?���?�? ?��?�� 깊�?? 복사 ?��?��
    str = new char[strlen(string.str)+1];
    strcpy(str, string.str);
    len = string.len;
    
    // char *pt1 = string.str;
    // char *pt2 = str;
    
    // std::cout << "?�� ?��?��링의 주소?�� " << static_cast<void*>(pt1) << std::endl;
    // std::cout << "복사?�� ?��?��링의 주소?�� " << reinterpret_cast<void*>(pt2) << std::endl;
}
String::~String() {
    if (str) {
        delete[] str;
    }
}

void String::PrintString() {
    std::cout << "?��?��?��?�� ?��?�� 문장??? " << str << "?��?��?��." << std::endl;
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
