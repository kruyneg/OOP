#include <gtest/gtest.h>
#include "solution.h"

TEST(test_01, basic_test_set)
{
    ASSERT_EQ(solution("sdfgh"), 0);
}

TEST(test_02, basic_test_set)
{
    ASSERT_EQ(solution("abcd"), 1);
}

TEST(test_03, basic_test_set)
{
    ASSERT_EQ(solution("aeiuyo"), 6);
}

TEST(test_04, basic_test_set)
{
    ASSERT_EQ(solution(""), 0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_EQ(solution("i like to travel."), 6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}