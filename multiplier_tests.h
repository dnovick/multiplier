#pragma once


#include <gtest/gtest.h>

#include <array>
#include <vector>

#include "multiplier.h"


using namespace Multiplier;

using IntVector = std::vector<int>;

constexpr size_t TEST_DATA_ARRAY_SIZE = 50;




class MultiplierTests : public ::testing::Test {
    private:
    
    public:

};


TEST_F(MultiplierTests, MultiplierTest1) //NOLINT
{
    std::string str {"test"};

    constexpr size_t COUNT = 5;

    auto res = multiplyElement(str, COUNT);

    ASSERT_EQ(std::string {"testtesttesttesttest"}, res);


}


TEST_F(MultiplierTests, MultiplierTest2) //NOLINT
{
    constexpr size_t ELEM_COUNT = 5;

    constexpr size_t COUNT = 4;


    IntVector ivec(ELEM_COUNT, 0x00);

    ASSERT_EQ(ivec.size(), ELEM_COUNT);

    auto vecProd = multiplyElement(ivec, COUNT);

    

    //auto vecLen = vecProd.size();

    ASSERT_EQ(vecProd.size(), ELEM_COUNT * COUNT);


}

TEST_F(MultiplierTests, MultiplierTest3) //NOLINT
{
    
    constexpr size_t ELEM_COUNT = 5;

    constexpr size_t COUNT = 4;


    IntVector ivec(ELEM_COUNT, 0x00);

    ASSERT_EQ(ivec.size(), ELEM_COUNT);

    auto vecProd = ivec * COUNT;

    

    //auto vecLen = vecProd.size();

    ASSERT_EQ(vecProd.size(), ELEM_COUNT * COUNT);

}