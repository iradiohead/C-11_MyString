#include <MyString/MyString.h>
#include <utility>


namespace customized_string
{
	//Constructors
	/*MyString::MyString() {
		reset();
	}*/

	MyString::MyString(const char *str) {
		copy_str(str);
	}

	MyString::MyString(MyString && str) noexcept {
		std::cout << "kjin - move constructor" << std::endl;
		reset();
		_str = str._str;
		_str_len = str._str_len;
		str._str = nullptr;
		str._str_len = 0;
		str.reset();
	}

	//Copy constructor
	MyString::MyString(const MyString & str) {
		std::cout << "kjin - copy constructor" << std::endl;
		copy_str(str._str); //can access private member
	}

	MyString::~MyString() {
		reset();
	}

	//Data management
	const char* MyString::copy_str(const char * str) {
		if (str) {
			size_t length = strnlen(str, customized_string::MyString::MAX_LENGTH);
			alloc_str(length);
			strncpy(_str, str, length);
			_str_len = length;
		}
		return _str;
	}

	const char* MyString::alloc_str(size_t size) {
		if (_str)
			reset();
		_str_len = (size > customized_string::MyString::MAX_LENGTH) ? customized_string::MyString::MAX_LENGTH : size;
		_str = new char[_str_len + 1]();
		return _str;
	}

	void MyString::reset() {
		if (_str)
			delete[] _str;
		_str = nullptr;
		_str_len = 0;
	}

	const char * MyString::c_str() const noexcept {
		return _str;
	}

	void swap(MyString & str1, MyString & str2) noexcept {
		//enabling ADL with swap is not useful for our case as cstring and int don't have their own swap methods)
		using std::swap;
		swap(str1._str, str2._str);
		swap(str1._str_len, str2._str_len);
	}

	//Operators
	MyString & MyString::operator=(MyString str) {
		swap(*this, str);
		return *this;
	}

	MyString & MyString::operator+=(const char * rhs) {
		if (rhs) {
			size_t rhs_len = strnlen(rhs, customized_string::MyString::MAX_LENGTH);
			size_t combined_length = _str_len + rhs_len;
			combined_length = combined_length < MAX_LENGTH ? combined_length : MAX_LENGTH;
			std::cout << "kjin - before make first" <<std::endl;
			MyString first(*this);
			std::cout << "kjin - operator+=" <<std::endl;
			alloc_str(combined_length);
			strncpy(_str, first._str, first._str_len);
			strncpy(_str + first._str_len, rhs, rhs_len);
		}
		return *this;
	}

	MyString & MyString::operator+=(const MyString &rhs) {
		operator+=(rhs._str);
		return *this;
	}

	char& MyString::operator[](size_t index) {
		if (index < 0 || index >= (int)_str_len) return _str[_str_len];
		return _str[index];
	}

	const char& MyString::operator[](size_t index) const {
		if (index < 0 || index >= (int)_str_len) return _str[_str_len];
		return _str[index];
	}

	std::ostream& operator<<(std::ostream& os, const MyString str) {
		os << str.c_str();
		return os;
	}

	//Utilities

	const char& MyString::front() const {
		return _str[0];
	}

	const char& MyString::back() const {
		return _str[_str_len - 1];
	}

}
