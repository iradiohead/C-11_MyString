#pragma once

#include <cstring>
#include <cstddef>
#include <ostream>
#include <iterator>
#include <iostream>

namespace customized_string {

class MyString {

public:
    static const int MAX_LENGTH = 65535;

	MyString() = delete;
    MyString(const char* str);
    MyString(const MyString& str);
    MyString(MyString&& str) noexcept;
	
    ~MyString();

    const char* alloc_str(size_t size);
    void reset();
    const char* copy_str(const char * str);
    const char* c_str() const noexcept;
    friend void swap(MyString& str1, MyString& str2) noexcept;

    /******************operators******************/
    MyString& operator = (MyString str);
    MyString& operator += (const MyString& str);
    MyString& operator += (const char* str);
    char& operator [](size_t index);
    const char& operator [] (size_t index) const;

    /******************utilities******************/
    inline size_t length() const { return _str_len;  }
    inline size_t size() const { return _str_len; }
    inline bool empty() const { return !(_str_len); };
    const char& front() const;
    const char& back() const;

private:
    char * _str = nullptr;
    size_t _str_len = 0;
	int _test = 9;
};

/******************non-member functions******************/

//Comparison operators
inline bool operator==(const customized_string::MyString& lhs, const customized_string::MyString& rhs) {
    if(strncmp(lhs.c_str(), rhs.c_str(), customized_string::MyString::MAX_LENGTH) == 0) return true;
    return false;
}

inline bool operator!=(const customized_string::MyString& lhs, const customized_string::MyString& rhs) {
    return !operator==(lhs, rhs);
}

inline bool operator< (const customized_string::MyString& lhs, const customized_string::MyString& rhs) {
    if(strncmp(lhs.c_str(), rhs.c_str(), customized_string::MyString::MAX_LENGTH) < 0) return true;
    return false;
}

inline bool operator> (const customized_string::MyString& lhs, const customized_string::MyString& rhs) {
    return operator<(rhs, lhs);
}

inline bool operator<=(const customized_string::MyString& lhs, const customized_string::MyString& rhs) {
    return !operator>(lhs, rhs);
}

inline bool operator>=(const customized_string::MyString& lhs, const customized_string::MyString& rhs) {
    return !operator<(lhs, rhs);
}

inline MyString operator+(MyString lhs, const MyString& rhs) {
    // here lhs is not left reference parameter, so need call copy constructor!
    // also it does not modify the lhs value, means string1 still string1
    std::cout<< "kjin - operate+" <<std::endl;
    lhs += rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream& os, const MyString str);

}
