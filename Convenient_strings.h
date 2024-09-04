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
        if (str) {
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

    TString& operator = (const TString& other) {
        if (this != &other) {
            delete[] S;
            Len = other.Len;
            S = new char[Len + 1];
            if (S == nullptr) {
                Len = 0;
                return *this;
            }
            for (int i = 0; i < Len; ++i) {
                S[i] = other.S[i];
            }
            S[Len] = '\0';
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

    TString operator + (const TString& other) const {
        if (other.Len <= 0) {
            return *this;
        }
        char* tmpS = new char[Len + other.Len + 1];
        if (nullptr == tmpS) {
            return *this;
        }
        for (int i = 0; i < Len; ++i) {
            tmpS[i] = S[i];
        }
        for (int i = 0; i < other.Len; ++i) {
            tmpS[Len + i] = other.S[i];
        }
        tmpS[Len + other.Len + 1] = '\0';
        TString result(tmpS);
        delete[] tmpS;
        return result;
    }

    bool operator == (const TString& other) const {
        int i = 0;
        while (other.S[i] != '\0' && S[i] != '\0' && i <= other.Len && i <= Len) {
            if (S[i] != other.S[i]) {
                return false;
            }
            ++i;
        }
        if (i == Len && i == other.Len) {
            return true;
        } 
        else {
            return false;
        }
    }

    bool operator != (const TString& other) const {
        int i = 0;
        while (other.S[i] != '\0' && S[i] != '\0' && i <= other.Len && i <= Len) {
            if (S[i] != other.S[i]) {
                return true;
            }
            ++i;
        }
        if (i == Len && i == other.Len) {
            return false;
        }
        else {
            return true;
        }
    }

    bool operator < (const TString& other) const {
        for (int i = 0; S[i] != '\0', other.S[i] != '\0', i <= other.Len, i <= Len; ++i) {
            if (S[i] < other.S[i]) {
                return true;
            }
            if (S[i] > other.S[i]) {
                return false;
            }
        }
        if (Len < other.Len) {
            return true;
        }
        return false;
    }

    bool operator <= (const TString& other) const {
        for (int i = 0; S[i] != '\0', other.S[i] != '\0', i <= other.Len, i <= Len; ++i) {
            if (S[i] < other.S[i]) {
                return true;
            }
            if (S[i] > other.S[i]) {
                return false;
            }
        }
        if (Len > other.Len) {
            return false;
        }
        return true;
    }

    bool operator > (const TString& other) const {
        for (int i = 0; S[i] != '\0', other.S[i] != '\0', i <= Len, i <= other.Len; ++i) {
            if (S[i] > other.S[i]) {
                return true;
            }
            if (S[i] < other.S[i]) {
                return false;
            }
        }
        if (Len > other.Len) {
            return true;
        }
        return false;
    }

    bool operator >= (const TString& other) const {
        for (int i = 0; S[i] != '\0', other.S[i] != '\0', i <= other.Len, i <= Len; ++i) {
            if (S[i] > other.S[i]) {
                return true;
            }
            if (S[i] < other.S[i]) {
                return false;
            }
            if (Len < other.Len) {
                return false;
            }
            return true;
        }
    }
};
