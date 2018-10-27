#include <iostream>
#include <MyString/MyString.h>

int main() 
{
	//using namespace customized_string;
	using customized_string::MyString;
	{
		
		// test case 1  +operator£¬ move constructor
		std::cout << "========test case1========== " << std::endl;
		MyString string1 = "string1";
		MyString string2 = "string2";
		MyString string_joint(string1 + string2);

		std::cout << "string_joint = " << string_joint.c_str() << std::endl;
		std::cout << "string1 = " << string1.c_str() << std::endl;

		MyString stringtemp = "stringtemp";
		MyString stringNew = std::move(stringtemp);
		std::cout << "stringNew = " << stringNew.c_str() << std::endl;

		//test case 2
		std::cout << "========test case2========== " << std::endl;
		MyString string3 = "string3";
		char ca = string3[2];
		std::cout << "char ca = " << ca << std::endl;

		//test case 3 copy constructor
		std::cout << "========test case3========== " << std::endl;
		MyString string4 = "string4";
		MyString string5 = string4;
		std::cout << "string5 = " << string5 << std::endl;
		
		//test case 4  assign operator
		std::cout << "========test case4========== " << std::endl;
		MyString string6 = "string6";
		MyString string7 = "string7";
		string7 = string6;
		std::cout << "string7 = " << string7 << std::endl;

		MyString string7_1 = "";
		string7_1 = std::move(string6);
		std::cout << "string7_1 = " << string7_1 << std::endl;
		
		MyString string7_2 = "";
		string7_2 = MyString("jinke");
		std::cout << "string7_2 = " << string7_2 << std::endl;
		
		//test case 5 implict datetype transfer
		std::cout << "========test case5========== " << std::endl;
		MyString string8 = "string8";
		string8 = std::move("jinke");
		std::cout << "string8 = " << string8 << std::endl;
		
		//test case 6 > < ==
		MyString string9 = "string9";
		MyString string10 = "string10";
		if (string9 < string10)
			std::cout << "string9 < string10"<<std::endl;
		else if (string9 == string10)
			std::cout << "string9 = string10"<<std::endl;
		else
			std::cout << "string9 > string10"<<std::endl;
		

		//std::cout << "========finish========== " << std::endl;
	}

	std::system("pause");
	return 0;
}
