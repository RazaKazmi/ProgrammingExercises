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

TEST(common_utility_tests, IsDistinctDigitsTest)
{
    EXPECT_TRUE(common_utility::IsDistinctDigits(0));
    EXPECT_TRUE(common_utility::IsDistinctDigits(1));
    EXPECT_TRUE(common_utility::IsDistinctDigits(12));
    EXPECT_TRUE(common_utility::IsDistinctDigits(123));
    EXPECT_TRUE(common_utility::IsDistinctDigits(1234));
    EXPECT_TRUE(common_utility::IsDistinctDigits(15623));
    EXPECT_TRUE(common_utility::IsDistinctDigits(903145));
    EXPECT_TRUE(common_utility::IsDistinctDigits(876543));

    EXPECT_FALSE(common_utility::IsDistinctDigits(11));
    EXPECT_FALSE(common_utility::IsDistinctDigits(121));
    EXPECT_FALSE(common_utility::IsDistinctDigits(3423));
    EXPECT_FALSE(common_utility::IsDistinctDigits(12341));
    EXPECT_FALSE(common_utility::IsDistinctDigits(43223));
    EXPECT_FALSE(common_utility::IsDistinctDigits(4567882));
}