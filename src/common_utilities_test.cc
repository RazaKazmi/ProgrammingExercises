#include <gtest/gtest.h>
#include "common_utilities.h"

TEST(common_utility_tests, NumberOfDigitsTest)
{
    EXPECT_EQ(common_utility::NumberOfDigits(0),1);
    EXPECT_EQ(common_utility::NumberOfDigits(1),1);
    EXPECT_EQ(common_utility::NumberOfDigits(10),2);
    EXPECT_EQ(common_utility::NumberOfDigits(11),2);
    EXPECT_EQ(common_utility::NumberOfDigits(100),3);
    EXPECT_EQ(common_utility::NumberOfDigits(1000),4);
    EXPECT_EQ(common_utility::NumberOfDigits(10000),5);
    EXPECT_EQ(common_utility::NumberOfDigits(100000),6);
    EXPECT_EQ(common_utility::NumberOfDigits(1000000),7);
    EXPECT_EQ(common_utility::NumberOfDigits(10000000),8);
    EXPECT_EQ(common_utility::NumberOfDigits(100000000),9);
    EXPECT_EQ(common_utility::NumberOfDigits(1000000000),10);
}