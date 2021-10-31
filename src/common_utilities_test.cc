#include <gtest/gtest.h>
#include "common_utilities.h"
#include "vec_manipulation.h"
#include <vector>

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
/*
TEST(common_utility_tests, ReverseVecTest)
{
    std::vector<int> int_vec{5,10,15,20,25,30};
    std::vector<int> expected_int_vec{30,25,20,15,10,5};
    std::vector<char> char_vec{'a','b','c','d','e','f'};
    std::vector<char> expected_char_vec{'f','e','d','c','b','a'};

    ASSERT_EQ(int_vec.size(),expected_int_vec.size()) << "Vectors are unequal length";
    ASSERT_EQ(char_vec.size(),expected_char_vec.size()) << "Vectors are unequal length";
    ASSERT_EQ(int_vec.size(),char_vec.size()) << "Vectors are unequal length";

    int_vec = common_utility::ReverseVec(int_vec);
    char_vec = common_utility::ReverseVec(char_vec);
    for(int i = 0; i < int_vec.size(); i++) {
        EXPECT_EQ(int_vec[i], expected_int_vec[i]);
        EXPECT_EQ(char_vec[i],expected_char_vec[i]);
    }
}

TEST(common_utility_tests, ReverseVectorTest)
{
    std::vector<int> int_vec{5,10,15,20,25,30};
    std::vector<int> expected_int_vec{30,25,20,15,10,5};
    std::vector<char> char_vec{'a','b','c','d','e','f'};
    std::vector<char> expected_char_vec{'f','e','d','c','b','a'};

    ASSERT_EQ(int_vec.size(),expected_int_vec.size()) << "Vectors are unequal length";
    ASSERT_EQ(char_vec.size(),expected_char_vec.size()) << "Vectors are unequal length";
    ASSERT_EQ(int_vec.size(),char_vec.size()) << "Vectors are unequal length";

    common_utility::ReverseVector(int_vec);
    common_utility::ReverseVector(char_vec);
    for(int i = 0; i < int_vec.size(); i++) {
        EXPECT_EQ(int_vec[i], expected_int_vec[i]);
        EXPECT_EQ(char_vec[i],expected_char_vec[i]);
    }

}
*/
TEST(common_utility_tests, MaxvTest)
{
    std::vector<int> int_vec{5,10,15,20,25,30};
    std::vector<double> double_vec{5.1,10.1,15.1,20.1,25.1,30.1};
    EXPECT_EQ(common_utility::Maxv(int_vec),30);
    EXPECT_DOUBLE_EQ(common_utility::Maxv(double_vec),30.1);

}

TEST(common_utility_tests, MinvTest)
{
    std::vector<int> int_vec{5,10,15,20,25,30};
    std::vector<double> double_vec{5.12,10.1,15.1,20.1,25.1,30.1};
    EXPECT_EQ(common_utility::Minv(int_vec),5);
    EXPECT_DOUBLE_EQ(common_utility::Minv(double_vec),5.12);
}

TEST(common_utility_tests, MeanVecTest)
{
    std::vector<int> int_vec{5,10,15,20,25,30};
    std::vector<double> double_vec{5.1,10.1,15.1,20.1,25.1,30.1};
    EXPECT_DOUBLE_EQ(common_utility::MeanVec(int_vec),17.5);
    EXPECT_DOUBLE_EQ(common_utility::MeanVec(double_vec),17.6);

}

TEST(common_utility_tests, MedianVecTest)
{   
    //even size
    std::vector<int> int_vec1{5,10,15,20,25,30};
    std::vector<double> double_vec1{5.1,10.1,15.1,20.1,25.1,30.1};
    EXPECT_DOUBLE_EQ(common_utility::MedianVec(int_vec1,true),17.5);
    EXPECT_DOUBLE_EQ(common_utility::MedianVec(double_vec1,true),17.6);
    //uneven size
    std::vector<int> int_vec2{5,10,15,20,25};
    std::vector<double> double_vec2{5.1,10.1,15.1,20.1,25.1};
    EXPECT_DOUBLE_EQ(common_utility::MedianVec(int_vec2,true),15);
    EXPECT_DOUBLE_EQ(common_utility::MedianVec(double_vec2,true),15.1);
    //unsorted
    std::vector<int> unsorted_int_vec{10,5,30,20,25,15};
    std::vector<double> unsorted_double_vec{10.1,5.1,30.1,20.1,25.1,15.1};
    EXPECT_DOUBLE_EQ(common_utility::MedianVec(int_vec1,false),17.5);
    EXPECT_DOUBLE_EQ(common_utility::MedianVec(double_vec1,false),17.6);
}

TEST(common_utility_tests, ModeVecTest)
{
    std::vector<int> int_vec{5,10,15,30,20,25,30};
    std::vector<double> double_vec{5.1,10.1,15.1,30.1,20.1,25.1,30.1};
    EXPECT_DOUBLE_EQ(common_utility::ModeVec(int_vec),30);
    EXPECT_DOUBLE_EQ(common_utility::ModeVec(double_vec),30.1);
}