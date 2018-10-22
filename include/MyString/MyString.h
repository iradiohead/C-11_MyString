#ifndef CUSTOMIZED_TSTRING_H
#define CUSTOMIZED_TSTRING_H
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

    /**
        * Copies the null-terminated character sequence pointed by str
        * @param input null terminated str
        * @return string with copied data
        */
    const char* copy_str(const char * str);

    /**
        * returns a null-terminated character sequence (c-string) type
        * @return c-string
        */
    const char* c_str() const noexcept;

    /**
        * Function to swap two tstring objects
        * @param str1 tstring1
        * @param str2 tstring2
        */
    friend void swap(MyString& str1, MyString& str2) noexcept;

    /******************operators******************/

    /**
        * Copy and assignment
        * @param str tstring to be copied
        * @return reference to the assigned tstring
        */
    MyString& operator = (MyString str);

    /**
        * Concatenates provided tstring
        * @param str tstring to be concatenated
        * @return concatenated tstring
        */
    MyString& operator += (const MyString& str);

    /**
        * Concatenates provided cstring
        * @param str cstring to be concatenated
        * @return concanated tstring
        */
    MyString& operator += (const char* str);

    char& operator [](size_t index);

    /**
        * returns the value at the index
        * @return value at the index
        */
    const char& operator [] (size_t index) const;

    /******************utilities******************/

    /**
        * returns the length of the string
        * @return number of characters in the string
        */
    inline size_t length() const { return _str_len;  }

    /**
        * returns the size (=length) of the string
        * @return number of characters in the string
        */
    inline size_t size() const { return _str_len; }

    /**
        * empty string or not
        * @return true if string length is zero else false
        */
    inline bool empty() const { return !(_str_len); };

    /**
        * returns the first character of the tstring
        * @return the character at the 0 index
        */
    const char& front() const;

    /**
        * returns the character at the back of the tstring
        * @return last character of the tstring
        */
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

#endif //TLIB_TSTRING_TSTRING_H