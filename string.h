#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

#include "memtrace.h"

class String {
    char *pData;         /// pointer az adatra
    size_t len;    /// hossz 0 nelkul
public:

    size_t size() const { return len; }

    /// Default konstruktor:
    String() :pData(0), len(0) {}

    /// Destruktor (disposeString)
    ~String() { delete[] pData; }

    void dispose(String& e) { delete[] pData; len = 0; }

    /// C-stringet ad vissza
    const char* c_str() const { if (pData) return pData; else return "";}

    /// Konstruktor:(createStrFromChar)
    String(char ch){
        len = 1;
        pData = new char[len+1];
        pData[0] = ch;
        pData[1] = '\0';
}


    /// Konstruktor:  (createStringFromCharStr)
    String(const char *p){
        len = strlen(p);
        pData = new char[len+1];
        strcpy(pData, p);
}

    ///cpy ctr
    String(const String& s1){
        len = s1.len;
        if ((pData = s1.pData) == NULL) return;
        pData = new char[len+1];
        strcpy(pData, s1.pData);
    }


    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }

  /// Operatorok:
    String& operator=(const String& rhs_s) {
        if (this != &rhs_s) {
            delete[] pData;
            len = rhs_s.len;
            if ((pData = rhs_s.pData) == NULL) return *this;
            pData = new char[len+1];
            strcpy(pData, rhs_s.pData);
        }
        return *this;
}

    String& operator+=(const String& rhs_s) {
        *this = *this + rhs_s;
        return *this;
    }

    /// 2 Stringet concatString)

    String operator+(const String& rhs_s) const {
        String temp;
        temp.len = len + rhs_s.len;
        delete []temp.pData;
            if (temp.len == 0) {
                temp.pData = NULL;
                return temp;
            }
        temp.pData = new char[temp.len+1];
            if (pData == NULL)
                temp.pData[0] = '\0';
            else
                strcpy(temp.pData, pData);
            if (rhs_s.pData != NULL)
                strcat(temp.pData, rhs_s.pData);

        return temp;

}

    /// Sztrinhez karaktert (concatString)
    String operator+(char rhs_c) const { return *this + String(rhs_c);}

    /// A string egy megadott indexu elem ref-val ter vissza
    char& operator[](unsigned int idx){
        if (idx >= len) throw "String: indexelesi hiba";
        return pData[idx];
}

    /// A string egy megadott indexu...

    const char& operator[](unsigned int idx) const{
        if (idx >= len) throw "String: indexelesi hiba";
        return pData[idx];
    }

    bool operator==(const String& rhs) const {
        if (len != rhs.len) {
            return false;
        }
        return std::strcmp(pData, rhs.pData) == 0;
    }

    void erase() { *this = ""; }
};

using std::cin;
using std::ios_base;

/// Globalis fgvek
/// kii­r az ostream-re (printString)
std::ostream& operator<<(std::ostream& os, const String& s0){
    os << s0.c_str();
    return os;
}

/// Beolvas az istreamrol egy szot egy string-be.
std::istream& operator>>(std::istream& is, String& s0){
    unsigned char ch;
    s0 = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(ios_base::skipws);
    while (is >> ch) {
	    is.unsetf(ios_base::skipws);
        if (isspace(ch)) {
            is.putback(ch);
            break;
        } else {
            s0 = s0 + ch;
        }
    }
	is.setf(fl);
    return is;
}

/// String operator+(char ch, const String& str);
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif
