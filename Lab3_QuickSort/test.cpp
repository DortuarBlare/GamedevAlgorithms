#include "pch.h"
#include <random>
#include "../Lab3_QuickSort/QuickSort.h"

std::default_random_engine randGenerator;

TEST(IntQuickSortTest, 5ElementsSort) {
    const int size = 5;
    int A[size] = { 666, 333, 111, 555, 8 };

    QuickSort(A, A + size - 1, [](int a, int b) { return a < b; });

    for (int i = 0; i < 4; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(IntQuickSortTest, 100ElementsSort) {
    const int size = 100;
    int A[size]{};
    std::uniform_int_distribution<int> randNumber(1, 100);

    for (int i = 0; i < size; i++)
        A[i] = randNumber(randGenerator);

    QuickSort(A, A + size - 1, [](int a, int b) { return a < b; });

    for (int i = 0; i < size - 1; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(IntQuickSortWithInsertTest, 5ElementsSort) {
    const int size = 5;
    int A[size] = { 666, 333, 111, 555, 8 };

    QuickSortWithInsert(A, A + size - 1, [](int a, int b) { return a < b; });

    for (int i = 0; i < 4; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(IntQuickSortWithInsertTest, 35ElementsSort) {
    const int size = 35;
    int A[size]{};
    std::uniform_int_distribution<int> randNumber(1, 100);

    for (int i = 0; i < size; i++)
        A[i] = randNumber(randGenerator);

    QuickSortWithInsert(A, A + size - 1, [](int a, int b) { return a < b; });

    for (int i = 0; i < size - 1; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(StringQuickSortTest, 5ElementsSort) {
    std::string A[5] = { "666", "333", "111", "555", "8" };

    QuickSort(A, A + 5 - 1, [](std::string a, std::string b) { return a < b; });

    for (int i = 0; i < 4; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(StringQuickSortTest, 100ElementsSort) {
    const int size = 100;
    std::string A[size]{};
    std::uniform_int_distribution<int> randNumber(1, 100);

    for (int i = 0; i < size; i++)
        A[i] = std::to_string(randNumber(randGenerator));

    QuickSort(A, A + size - 1, [](std::string a, std::string b) { return a < b; });

    for (int i = 0; i < size - 1; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(StringQuickSortWithInsertTest, 5ElementsSort) {
    std::string A[5] = { "666", "333", "111", "555", "8" };

    QuickSortWithInsert(A, A + 5 - 1, [](std::string a, std::string b) { return a < b; });

    for (int i = 0; i < 4; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

TEST(StringQuickSortWithInsertTest, 35ElementsSort) {
    const int size = 35;
    std::string A[size]{};
    std::uniform_int_distribution<int> randNumber(1, 100);

    for (int i = 0; i < size; i++)
        A[i] = std::to_string(randNumber(randGenerator));

    QuickSortWithInsert(A, A + size - 1, [](std::string a, std::string b) { return a < b; });

    for (int i = 0; i < size - 1; ++i)
        ASSERT_LE(A[i], A[i + 1]);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
    randGenerator.seed(time(NULL));
	return RUN_ALL_TESTS();
}