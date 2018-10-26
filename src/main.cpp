#include <iostream>
#include <MyString/MyString.h>

int main() 
{
	using namespace customized_string;
	// test case 1
	MyString string1 = "string1";
	std::cout << string1 << std::endl;

	MyString string2  = "string2";
	std::cout << string2.c_str() << std::endl;

	MyString string_joint (string1 + string2);
	std::cout << "string_joint = " << string_joint.c_str() << std::endl;
	std::cout << "string1 = " << string1.c_str() << std::endl;

	//test case 2
	MyString string3 = "string3";
	char ca = string3[2];
	std::cout << "char ca = " << ca << std::endl;

	std::system("pause");
	return 0;
}
