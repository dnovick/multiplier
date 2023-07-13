#pragma once


#include <gtest/gtest.h>

#include <array>
#include <ios>
#include <vector>
#include <iterator>

#include "multiplier.h"


using namespace Multiplier;

using IntVector = std::vector<int>;
using CharArray = std::array<char, 10U>;
using CharVector = std::vector<char>;

constexpr size_t TEST_DATA_ARRAY_SIZE = 50;




class MultiplierTests : public ::testing::Test {
    private:
    
    public:
        template<typename InColl, typename OutColl = InColl>
        inline auto productIsValid(const InColl& coll  , size_t count, const OutColl& prod) {
            bool res = true;

            auto inSize = coll.size();

            for (auto i = 0; i < count; i++) {
                for (auto j = 0; j < inSize; j++) {                    
                    res &= (coll[j] == prod[(i * inSize) + j]);
                }
            }

            return res;
        }

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


    ASSERT_EQ(vecProd.size(), ELEM_COUNT * COUNT);

    ASSERT_TRUE(productIsValid(ivec, COUNT, vecProd));

}

TEST_F(MultiplierTests, MultiplierTest3) //NOLINT
{
    
    constexpr size_t ELEM_COUNT = 7;

    constexpr size_t COUNT = 5;


    IntVector ivec(ELEM_COUNT, 0x00);

    ASSERT_EQ(ivec.size(), ELEM_COUNT);

    auto vecProd = ivec * COUNT;


    ASSERT_EQ(vecProd.size(), ELEM_COUNT * COUNT);


    ASSERT_TRUE(productIsValid(ivec, COUNT, vecProd));

}

TEST_F(MultiplierTests, MultiplierTest4) //NOLINT
{
    
    constexpr size_t ELEM_COUNT = 10;

    constexpr size_t COUNT = 5;


    CharArray carr {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    ASSERT_EQ(carr.size(), ELEM_COUNT);

    auto prod = multiplyElement<CharArray, CharVector>(carr, COUNT);

    ASSERT_EQ(prod.size(), ELEM_COUNT * COUNT);
    
    ASSERT_TRUE(productIsValid(carr, COUNT, prod));

}

//TODO: Modify the multiplier to enable operator*() with differing input and output collection types.
// TEST_F(MultiplierTests, MultiplierTest5) //NOLINT
// {
    
//     constexpr size_t ELEM_COUNT = 10;

//     constexpr size_t COUNT = 5;


//     CharArray carr {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

//     ASSERT_EQ(carr.size(), ELEM_COUNT);

//     CharVector prod = carr * COUNT;
//     //auto prod = multiplyElement<CharArray, CharVector>(carr, COUNT);

//     ASSERT_EQ(prod.size(), ELEM_COUNT * COUNT);
    
//     ASSERT_TRUE(productIsValid(carr, COUNT, prod));

// }