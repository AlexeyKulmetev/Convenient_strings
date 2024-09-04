#include <iostream>
#include <cstddef>
#include <cstring>

class TString {
private:
    char *S = nullptr;
    int Len;

public:
    TString() : Len{0}, S{nullptr} {}

    TString(int len) {
        Len = len;
        if (len > 0) {
            S = new char[len + 1];
            *S = '\0';
            if (nullptr == S) {
                Len = 0;
            }
        }
        else {
            S = nullptr;
            Len = 0;
        }
    }

    TString(const TString& other) : Len{other.Len} {
        if (S != nullptr) {
            delete[] S;
        }
        S = new char[other.Len + 1];
        if (nullptr == S) {
            Len = 0;
        }
        for (int i = 0; i < Len; ++i) {
            S[i] = other.S[i];
        }
        S[Len] = '\0';
    }

    // // Shoud I implement the extending buffer functional ?

    // it is assumed that the string has a terminating zero
    TString(const char* str) {
        if (S != nullptr) {
            delete[] S;
        }
        Len = 0;
        for (; str[Len] != '\0'; ++Len);
        S = new char[Len + 1];
        if (nullptr == S){
            Len = 0;
        }
        else {
            for (int i = 0; i < Len; ++i) {
                S[i] = str[i];
            }
            S[Len] = '\0';            
        }
    }

    TString(TString&& other) {
        if (S != nullptr) {
            delete[] S;
        }
        Len = other.Len;
        S = new char[Len + 1];
        if (nullptr == S) {
            Len = 0;
        }
        for (int i = 0; i < Len; ++i) {
            S[i] = other.S[i];
        }
        S[Len] = '\0';
        delete[] other.S;
    }
    
    ~TString() {
        if (S != nullptr) {
            delete[] S;
            S = nullptr;
        }
    }

    operator char*() const { // allow to usint TString object where char* is expected
        return S;
    }

    TString& operator = (TString&& other) {
        if (this != &other) {
            delete[] S;
            S = new char[Len + 1];
            for (int i = 0; i < Len; ++i) {
                S[i] = other.S[i];
            }
            S[other.Len] = '\0';
            delete[] other.S;
        }
        return *this;
    }

    friend std::ostream& operator << (std::ostream& out, const TString& str) {
        if (str.S != nullptr) {
            return out << str.S;
        }
        else {
            return out;
        }
    }

    TString& operator = (const TString& str) {
        if (this != &str) {
            delete[] S;
            Len = str.Len;
            S = new char[Len + 1];
            if (S == nullptr) {
                Len = 0;
                return *this;
            }
            for (int i = 0; i < Len; ++i) {
                S[i] = str.S[i];
            }
            S[Len] = '\0';
        }
        return *this;
    }

    TString operator + (const TString& str) {
        if (str.Len <= 0) {
            return *this;
        }
        char* tmpS = new char[Len + str.Len + 1];
        if (nullptr == tmpS) {
            return *this;
        }
        for (int i = 0; i < Len; ++i) {
            tmpS[i] = S[i];
        }
        for (int i = 0; i < str.Len; ++i) {
            tmpS[Len + i] = str.S[i];
        }
        tmpS[Len + str.Len + 1] = '\0';
        TString result(tmpS);
        delete tmpS;
        return result;
    }

    // bool operator == (const TString& str);

    // bool operator != (const TString& str);

    // bool operator < (const TString& str);

    // bool operator <= (const TString& str);

    // bool operator > (const TString& str);

    // bool operator >= (const TString& str);
};
