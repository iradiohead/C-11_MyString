#include <gtest/gtest.h>
#include <MyString/MyString.h>
#include <string>

std::string string_input = "Hello";

TEST(CREATESTRING, SETANDGET) {

    customized_string::tstring input("Hello");
    ASSERT_STREQ(string_input.c_str(), input.c_str());
}

//TEST(CREATESTRING, POINTER_OPERATOR_TEST) {
//
//    tlib::tstring input("Hello");
//    ASSERT_STREQ(string_input.c_str(), input);
//}

TEST(CREATESTRING, MOVE_TEST) {

    customized_string::tstring input1("Hello");
    customized_string::tstring input2 = std::move(input1);
    ASSERT_STREQ(string_input.c_str(), input2.c_str());
}

TEST(CREATESTRING, ASSIGN_LIKE_ARRAY_TEST) {
    customized_string::tstring input1("Hello");
    input1[0] = 'W';
    ASSERT_STREQ("Wello", input1.c_str());
}