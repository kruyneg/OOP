#include <gtest/gtest.h>
#include "twelve.h"

TEST(Group_01, basic_test_set)
{
    Twelve num1, num2;

    ASSERT_TRUE(num1.to_string() == "0" && num2.to_string() == "0");

    num1 = "A";
    EXPECT_TRUE(num1.to_decimal() == 10);

    num2 = num2 + num1;
    EXPECT_TRUE(num2.to_string() == "A");

    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 > num2);
    EXPECT_FALSE(num1 < num2);
}

TEST(Group_02, basic_test_set)
{
    Twelve num1(3, '1'), num2(4, '0');

    ASSERT_EQ(num1.size(), 3);
    ASSERT_TRUE(num1.to_decimal() == 157 && num2.to_decimal() == 0);

    num2 = "123";
    EXPECT_TRUE(num1 < num2);
    EXPECT_TRUE(num1 != num2);

    EXPECT_THROW(num1 - num2, std::underflow_error);
    EXPECT_TRUE(num2 - num1 == Twelve("12"));
}

TEST(Group_03, basic_test_set)
{
    Twelve num1 {'2', '0', 'A'};
    Twelve num2 {'B', 'A'};
    
    ASSERT_TRUE(num1.to_string() == "20A" && num2.to_string() == "BA");

    num1 = num1 - num2; //298-142=156
    EXPECT_TRUE(num1.to_string() == "110");
    EXPECT_TRUE(num1 >= num2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}