#include <iostream>
#include <cstring>

/* ?λ§μ ?€?Έλ§? ?΄??€ λ§λ€κΈ? */
//λ¬Έμ(char)λ‘λ???° λ¬Έμ?΄ ??±, λ¬Έμ ?¬?Έ?°(char *)λ‘λ???° λ¬Έμ?΄ ??±
//λ¬Έμ?΄ κΈΈμ΄ κ΅¬ν? ?¨?
//λ¬Έμ?΄ ?€? ?€λ₯? λ¬Έμ?΄ λΆμ΄κΈ?
//λ¬Έμ?΄?΄ κ°μ??μ§? λΉκ΅
//λ¬Έμ?΄? ?¬κΈ? λΉκ΅ (?¬?  ?)

class MyString {
    private:
    int string_len; //λ¬Έμ?΄? κΈΈμ΄ λ³??
    char* string_text; //λ¬Έμ?΄? ?΄?©?΄ ?€?΄?? λ°°μ΄? κ°?λ¦¬ν€? char* ?¬?Έ?°
    int memory_capacity; //?΄?Ή ?΄??€λ₯? ??΄ λ©λͺ¨λ¦¬μ ? ?Ή? λ¬Έμ κ³΅κ°? ?

    public:
    //??±?
    MyString(char c); //?Όλ°? λ¬Έμλ‘λ???° ?΄??€ ??±
    MyString(const char* str); //λ¬Έμ?΄? κ°?λ¦¬ν€? ?¬?Έ?°λ‘λ???° ?΄??€ ??±
    MyString(const MyString& str); //?€λ₯? MyString ?΄??€λ‘λ???° ?΄??€ ??±
    //?λ©Έμ
    ~MyString();
    //λ¬Έμ?΄ κΈΈμ΄ ?½κΈ? ?¨?
    int StringLen() const;
    //λ¬Έμ?΄ ?΄?© ??Έ ?¨?
    void Print() const;
    void Println() const;
    //λ¬Έμ?΄ ?΄?© λ³?κ²? ?¨?
    MyString& Assign(const MyString& str);
    MyString& Assign(const char* str);
    //? ?Ή? λ©λͺ¨λ¦? κ³΅κ° ??Έ
    int CheckCapacity() const;
    //??? ?¬κΈ°μ λ©λͺ¨λ¦? κ³΅κ° λ―Έλ¦¬ ? ?Ή
    void Reserve(int size);
    //λ¬Έμ?΄ ?½?
    MyString& Insert(int loc, const MyString& str);
    MyString& Insert(int loc, const char* str);
    MyString& Insert(int loc, char c);
};

//λ©€λ² ?¨? ? ? κ΅¬κ°
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
    if (str.string_len > memory_capacity) { //?λ‘μ΄ λ¬Έμ?΄?΄ ? ?Ή? κ³΅κ°λ³΄λ€ ? κΈΈλ©΄ λ©λͺ¨λ¦? κ³΅κ° ?λ‘? ? ?Ή ??
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
    //λ²μλ₯? λ²μ΄?λ©? μ²λ¦¬?μ§? ??
    if (loc < 0 || loc > string_len) {
        return *this;
    }
    
}


//?€?λΆ?
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