#include <iostream>
#include <cstring>

class String {
    private:
    char *str;
    int len;

    public:
    //cë¥? në²? ë°˜ë³µ?•˜?Š” ?ƒ?„±?
    String(char c, int n);
    //?…? ¥?•œ ë¬¸ì?—´?„ ?‹´?Š” ?ƒ?„±?
    String(const char *string);
    //ë³µì‚¬ ?ƒ?„±?
    String(const String& string);
    // //?†Œë©¸ì
    ~String();

    //?•¨?ˆ˜
    void PrintString();
    void AddString(const String &s); //ê¸°ì¡´ ë¬¸ì?—´ ?’¤?— së¥? ì¶”ê??
    void CopyString(const String &s); //ê¸°ì¡´ ë¬¸ì?—´?„ së¡? ë³?ê²?
    int StrLen(); //ë¬¸ì?—´?˜ ê¸¸ì´ë¥? ì¶œë ¥
    
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
    //str??? ?¬?¸?„°?´ë¯?ë¡? ê·¸ë??ë¡? ë³µì‚¬?•˜ë©? ë¬¸ì œ?˜ ?†Œì§?ê°? ?ˆ?–´ ê¹Šì?? ë³µì‚¬ ?•„?š”
    str = new char[strlen(string.str)+1];
    strcpy(str, string.str);
    len = string.len;
    
    // char *pt1 = string.str;
    // char *pt2 = str;
    
    // std::cout << "?› ?Š¤?Š¸ë§ì˜ ì£¼ì†Œ?Š” " << static_cast<void*>(pt1) << std::endl;
    // std::cout << "ë³µì‚¬?œ ?Š¤?Š¸ë§ì˜ ì£¼ì†Œ?Š” " << reinterpret_cast<void*>(pt2) << std::endl;
}
String::~String() {
    if (str) {
        delete[] str;
    }
}

void String::PrintString() {
    std::cout << "?…? ¥?˜?–´ ?ˆ?Š” ë¬¸ì¥??? " << str << "?…?‹ˆ?‹¤." << std::endl;
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
