#include <gtest/gtest.h>
#include "triangle.hpp"
#include "square.hpp"
#include "octagon.hpp"

TEST(Group_1, basic_test_set) {
    Triangle<double> t(2);
    Square<double> s(2);
    Octagon<double> o(2);

    EXPECT_FALSE(t == s);
    EXPECT_FALSE(s == o);
    EXPECT_FALSE(t == o);

    EXPECT_TRUE(t == t);

    EXPECT_TRUE(s.center() == std::make_pair(1.0, 1.0));
    EXPECT_EQ(o.center(), std::make_pair(1.0 + 2 * std::cos(M_PI / 4.0), 1.0 + 2 * std::cos(M_PI / 4.0)));
    EXPECT_EQ(t.center(), std::make_pair(1.0, std::sin(M_PI / 3) * 2 / 3));
}

TEST(Group_2, basic_test_set) {
    Triangle<float> t = {std::make_pair(0.0, 0.0), std::make_pair(1.0, 0.0), std::make_pair(1.0, 1.0)};
    
    EXPECT_TRUE(static_cast<double>(t) == 0.5);
    EXPECT_EQ(t.center().first, 2.0 / 3.0);
}

TEST(Group_3, basic_test_set) {
    Square<float> s(5);

    EXPECT_EQ(static_cast<double>(s), 25);
    EXPECT_EQ(s.center(), std::make_pair(2.5, 2.5));
}

TEST(Group_4, basic_test_set) {
    Octagon<float> o(4);

    EXPECT_EQ(static_cast<double>(o), (4 + 8 * std::cos(M_PI / 4)) * (4 + 8 * std::cos(M_PI / 4)) - 2 * (4 * std::cos(M_PI / 4) * 4 * std::cos(M_PI / 4)));
    EXPECT_EQ(o.center(), std::make_pair(2.0 + 4 * std::cos(M_PI / 4.0), 2.0 + 4 * std::cos(M_PI / 4.0)));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}