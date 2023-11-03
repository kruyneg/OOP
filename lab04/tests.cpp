#include <gtest/gtest.h>
#include "triangle.hpp"
#include "square.hpp"
#include "octagon.hpp"

TEST(Group_1, basic_test_set) {
    Triangle<double> t(2);
    Square<double> s(2);
    Octagon<double> o(2);

    EXPECT_FALSE(t.operator==(s));
    EXPECT_FALSE(s.operator==(o));
    EXPECT_FALSE(t.operator==(o));

    EXPECT_TRUE(t.operator==(t));

    EXPECT_TRUE(s.center() == std::make_pair(1.0, 1.0));
    EXPECT_EQ(o.center(), std::make_pair(1.0 + 2 * std::cos(M_PI / 4.0), 1.0 + 2 * std::cos(M_PI / 4.0)));
    EXPECT_EQ(t.center(), std::make_pair(1.0, std::sin(M_PI / 3) * 2 / 3));
}

TEST(Group_2, basic_test_set) {
    Triangle<double> t = {{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}};
    
    EXPECT_TRUE(static_cast<double>(t) == 0.5);
    EXPECT_EQ(t.center().first, 2.0 / 3.0);
}

TEST(Group_3, basic_test_set) {
    Square<float> s(5);

    EXPECT_EQ(static_cast<double>(s), 25);
    EXPECT_EQ(s.center(), std::make_pair((float)2.5, (float)2.5));
}

TEST(Group_4, basic_test_set) {
    Octagon<float> o(4);

    EXPECT_EQ(static_cast<double>(o), (4 + 8 * (float)std::cos(M_PI / 4)) * (4 + 8 * (float)std::cos(M_PI / 4)) - 2 * (4 * (float)std::cos(M_PI / 4) * 4 * (float)std::cos(M_PI / 4)));
    EXPECT_EQ(o.center(), (std::make_pair<float,float>(2.0 + 4 * std::cos(M_PI / 4.0), 2.0 + 4 * std::cos(M_PI / 4.0))));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}