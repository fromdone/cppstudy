#include <iostream>
#include <cstring>

class String {
    private:
    char *str;
    int len;

    public:
    //cλ₯? nλ²? λ°λ³΅?? ??±?
    String(char c, int n);
    //?? ₯? λ¬Έμ?΄? ?΄? ??±?
    String(const char *string);
    //λ³΅μ¬ ??±?
    String(const String& string);
    // //?λ©Έμ
    ~String();

    //?¨?
    void PrintString();
    void AddString(const String &s); //κΈ°μ‘΄ λ¬Έμ?΄ ?€? sλ₯? μΆκ??
    void CopyString(const String &s); //κΈ°μ‘΄ λ¬Έμ?΄? sλ‘? λ³?κ²?
    int StrLen(); //λ¬Έμ?΄? κΈΈμ΄λ₯? μΆλ ₯
    
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
    //str??? ?¬?Έ?°?΄λ―?λ‘? κ·Έλ??λ‘? λ³΅μ¬?λ©? λ¬Έμ ? ?μ§?κ°? ??΄ κΉμ?? λ³΅μ¬ ??
    str = new char[strlen(string.str)+1];
    strcpy(str, string.str);
    len = string.len;
    
    // char *pt1 = string.str;
    // char *pt2 = str;
    
    // std::cout << "? ?€?Έλ§μ μ£Όμ? " << static_cast<void*>(pt1) << std::endl;
    // std::cout << "λ³΅μ¬? ?€?Έλ§μ μ£Όμ? " << reinterpret_cast<void*>(pt2) << std::endl;
}
String::~String() {
    if (str) {
        delete[] str;
    }
}

void String::PrintString() {
    std::cout << "?? ₯??΄ ?? λ¬Έμ₯??? " << str << "???€." << std::endl;
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
