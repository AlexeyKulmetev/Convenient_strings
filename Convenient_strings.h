#include <iostream>
#include <cstddef>


class TString {
private:
    char *s = nullptr;
    int len;

public:
    TString(int l = 0) : len{l} {
        s = new char[len];
    }

    TString(const TString& other) : len{other.len} {
        
        s = new char[len];
        
    }
    // Shoud I implement the extending buffer functional ?
    TString(const char* str) {
       
        len = sizeof(str);
        if (s == nullptr) {
            s = new char[len];
            for (int i = 0; i < len; ++i) {
                s[i] = str[i];
            }
            s[len] = '\0';
        }
        else {
            delete[] s;
            s = new char[len];
            for (int i = 0; i < len; ++i) {
                s[i] = str[i];
            }
            s[len] = '\0';
        }
    }
    
    ~TString() {
        delete[] s;
    }

    int size() { 
        return sizeof(s);
    }

    operator char*() const {
        return s;
    }

    friend std::ostream& operator << (std::ostream& out, const TString& str);

    TString& operator = (const TString str);

    TString operator + (const TString& str);

    bool operator == (const TString& str);

    bool operator != (const TString& str);

    bool operator < (const TString& str);

    bool operator <= (const TString& str);

    bool operator > (const TString& str);

    bool operator >= (const TString& str);
};