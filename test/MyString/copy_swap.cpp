#include <gtest/gtest.h>
#include <MyString/MyString.h>
#include <string>

std::string string_ = "Hello";

TEST(COPYSTRING, COPYSTRING_COPY_CONSTRUCTOR_Test) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2(input1);
    ASSERT_STREQ(string_.c_str(), input2.c_str());
    ASSERT_STREQ(input2.c_str(), input1.c_str());
}

TEST(STRING_SWAP, STRING_SWAP_ASSIGNMENT_Test) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2 = input1;
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), input1.c_str());
}

TEST(STRING_SWAP, STRING_SWAP_NON_EMPTY_ASSIGNMENT_Test) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2("World");
    input2 = input1;
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "Hello");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST1) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2("World");
    input2 += input1;
    //Check if the input1 has not been modified
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "WorldHello");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST3) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2("World");
    input2 = input1 + input2;
    //Check if the input1 has not been modified
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "HelloWorld");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST2) {
    customized_string::MyString input1("Jinke");
    customized_string::MyString input2("Hello");
    input2 += input1;
    //Check if the input1 has not been modified
    ASSERT_STREQ("Jinke", input1.c_str());
    ASSERT_STREQ(input2.c_str(), "HelloJinke");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST4) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2("Jinke");
    input2 += input1;
    //Check if the input1 has not been modified
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "JinkeHello");
}

TEST(STRING_SWAP, STRING_SWAP_TEST) {
    customized_string::MyString input1("Hello");
    customized_string::MyString input2("World");
    using std::swap;
    swap(input1, input2);
    ASSERT_STREQ(input1.c_str(), "World");
    ASSERT_STREQ(input2.c_str(), "Hello");
}

TEST(STRING_SWAP, STRING_ACCESS_OPERATOR_TEST) {
    customized_string::MyString input1("Hello");
    for(int i = 0; i < string_.length(); i++)
        ASSERT_EQ(string_[i], input1[i]);
}

