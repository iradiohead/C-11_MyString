#include <gtest/gtest.h>
#include <MyString/MyString.h>
#include <string>

std::string string_input2 = "Hello";

TEST(OPERATOR_STRING, EQUAL_OPERATOR_TEST1) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("Hello");
    ASSERT_TRUE(input1 == input2);
}

TEST(OPERATOR_STRING, NOTEQUAL_OPERATOR_TEST1) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("Hello");
    ASSERT_FALSE(input1 != input2);
}

TEST(OPERATOR_STRING, NOTEQUAL_OPERATOR_TEST2) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("WORLD");
    ASSERT_TRUE(input1 != input2);
}

TEST(OPERATOR_STRING, GREATOR_EQUAL_OPERATOR_TEST1) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("Hello");
    ASSERT_TRUE(input1 >= input2);
}

TEST(OPERATOR_STRING, LESS_EQUAL_OPERATOR_TEST1) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("Hello");
    ASSERT_TRUE(input1 <= input2);
}

TEST(OPERATOR_STRING, GREATOR_OPERATOR_TEST1) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("Hello");
    ASSERT_FALSE(input1 > input2);
}

TEST(OPERATOR_STRING, LESS_OPERATOR_TEST1) {
    customized_string::tstring input1("Hello");
    customized_string::tstring input2("Hello");
    ASSERT_FALSE(input1 < input2);
}

TEST(OPERATOR_STRING, GREATOR_OPERATOR_TEST2) {
    customized_string::tstring input1("Aello");
    customized_string::tstring input2("Hello");
    ASSERT_TRUE(input1 < input2);
    ASSERT_FALSE(input1 > input2);
}

TEST(OPERATOR_STRING, GREATOR_EQUAL_OPERATOR_TEST2) {
    customized_string::tstring input1("Aello");
    customized_string::tstring input2("Hello");
    ASSERT_TRUE(input1 <= input2);
    ASSERT_FALSE(input1 >= input2);
}

TEST(OPERATOR_STRING, ALL_OPERATOR_TEST1) {
    customized_string::tstring input1("hello");
    customized_string::tstring input2("Hello");
    ASSERT_FALSE(input1 <= input2);
    ASSERT_TRUE(input1 >= input2);
    ASSERT_FALSE(input1 < input2);
    ASSERT_TRUE(input1 > input2);
    ASSERT_FALSE(input1 == input2);
    ASSERT_TRUE(input1 != input2);
}

TEST(OPERATOR_STRING, ALL_OPERATOR_TEST2) {
    customized_string::tstring input1("A");
    customized_string::tstring input2("a");
    ASSERT_FALSE(input1 == input2);
    ASSERT_TRUE(input1 != input2);
    ASSERT_TRUE(input1 < input2);
    ASSERT_TRUE(input1 <= input2);
    ASSERT_FALSE(input1 > input2);
    ASSERT_FALSE(input1 >= input2);
}