#include <iostream>
#include <cstddef>


class TString {
private:
    char *s = nullptr;
    int len;

public:
    TString(int l = 0);
    TString(const TString& other);
    TString(const char* str);
    
    ~TString() {
        delete[] s;
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