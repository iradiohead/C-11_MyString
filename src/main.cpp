#include <iostream>
#include <MyString/MyString.h>


int test(const int &a)
{
	std::cout << "const int &" << std::endl;
	return 0;
}

int test(int&& a)
{
	std::cout << " int &&" << std::endl;
	return 0;
}

int main() 
{
	using namespace customized_string;

	MyString string1 = "string1";
	std::cout << string1 << std::endl;

	MyString string2  = "string2";
	std::cout << string2.c_str() << std::endl;

	MyString string_joint (string1 + string2);
	std::cout << "string_joint = " << string_joint.c_str() << std::endl;
	std::cout << "string1 = " << string1.c_str() << std::endl;


	std::system("pause");
	return 0;
}
