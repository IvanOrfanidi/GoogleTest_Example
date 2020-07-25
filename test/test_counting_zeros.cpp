#include <gtest/gtest.h>
#include <list>
#include <stddef.h>
#include <stdio.h>
#include <vector>

#include <inc/counting_zeros.h>

template <class T>
class FXCountingZeros : public ::testing::TestWithParam<T> {
};

TYPED_TEST_CASE_P(FXCountingZeros);
TYPED_TEST_P(FXCountingZeros, CountingZeros)
{
    // arrange
    TypeParam TestItem;

    // act
    const size_t res = counting_zeros(TestItem.data);

    // assert
    EXPECT_EQ(res, TestItem.zeros);
}

REGISTER_TYPED_TEST_CASE_P(FXCountingZeros, CountingZeros);

template <class T>
struct vectorI8TestItem {
    const std::vector<T> data = { -1, 0, -2, 0, -3 };

    const size_t zeros = 2;
};

template <class T>
struct vectorU8TestItem {
    const std::vector<T> data = { 1, 0, 1, 0, 3, 0, 4 };

    const size_t zeros = 3;
};

template <class T>
struct listI8TestItem {
    const std::list<T> data = { -1, 0, -2, 0, -3 };

    const size_t zeros = 2;
};

template <class T>
struct listU8TestItem {
    const std::list<T> data = { 1, 0, 1, 0, 3, 0, 4 };

    const size_t zeros = 3;
};

typedef ::testing::Types<
    // Vectors
    vectorI8TestItem<int8_t>,
    vectorU8TestItem<uint8_t>,
    // Lists
    listI8TestItem<int8_t>,
    listU8TestItem<uint8_t>>
    CountingZerosTypesT;

INSTANTIATE_TYPED_TEST_CASE_P(CountingZeros, FXCountingZeros, CountingZerosTypesT);