#include "pch.h"
#include "../Lab2_DynamicArray/Array.h"

TEST(IntArrayTest, DefaultConstructor) {
	Array<int> array;

	ASSERT_EQ(array.getSize(), 0);
	ASSERT_EQ(array.getCapacity(), 8);
}

TEST(IntArrayTest, ConstructorWithCapacity) {
	Array<int> array(16);

	ASSERT_EQ(array.getSize(), 0);
	ASSERT_EQ(array.getCapacity(), 16);
}

TEST(IntArrayTest, CopyConstructor) {
	Array<int> array;
	array.insert(10);
	array.insert(20);
	array.insert(30);
	array.insert(40);

	Array<int> copiedArray(array);

	ASSERT_EQ(array.getSize(), copiedArray.getSize());
	ASSERT_EQ(array.getCapacity(), copiedArray.getCapacity());

	for (int i = 0; i < array.getSize(); i++)
		EXPECT_EQ(array[i], copiedArray[i]);
}

TEST(IntArrayTest, MoveConstructor) {
	Array<int> array;
	array.insert(10);
	array.insert(20);
	array.insert(30);
	array.insert(40);

	Array<int> copiedArray(std::move(array));

	ASSERT_EQ(copiedArray.getSize(), 4);
	ASSERT_EQ(copiedArray.getCapacity(), 8);
	EXPECT_EQ(copiedArray[0], 10);
	EXPECT_EQ(copiedArray[1], 20);
	EXPECT_EQ(copiedArray[2], 30);
	EXPECT_EQ(copiedArray[3], 40);
}

TEST(IntArrayTest, Insert) {
	Array<int> array;
	array.insert(10);
	array.insert(20);
	array.insert(30);
	array.insert(40);

	ASSERT_EQ(array.getSize(), 4);
	EXPECT_EQ(array[0], 10);
	EXPECT_EQ(array[1], 20);
	EXPECT_EQ(array[2], 30);
	EXPECT_EQ(array[3], 40);
}

TEST(IntArrayTest, InsertWithResize) {
	Array<int> array;
	for (int i = 1; i <= 10; i++)
		array.insert(i * 10);

	ASSERT_EQ(array.getSize(), 10);
	ASSERT_EQ(array.getCapacity(), 16);

	for (int i = 0, rightAnswer = 10; i < array.getSize(); i++, rightAnswer += 10)
		EXPECT_EQ(array[i], rightAnswer);
}

TEST(IntArrayTest, InsertWithIndex) {
	Array<int> array;
	array.insert(10);
	array.insert(20);
	array.insert(0, 30);

	ASSERT_EQ(array.getSize(), 3);
	EXPECT_EQ(array[0], 30);
	EXPECT_EQ(array[1], 10);
	EXPECT_EQ(array[2], 20);
}

TEST(IntArrayTest, Remove) {
	Array<int> array;
	array.insert(10);
	array.insert(20);
	array.insert(30);
	array.insert(40);
	array.remove(0);
	array.remove(1);
	array.remove(1);

	ASSERT_EQ(array.getSize(), 1);
	EXPECT_EQ(array[0], 20);
}

TEST(IntArrayTest, Iterator) {
	Array<int> array;
	int rightAnswer = 10;

	array.insert(10);
	array.insert(20);
	array.insert(30);
	array.insert(40);

	for (auto it = array.iterator(); it.hasNext(); it.next(), rightAnswer += 10)
		EXPECT_EQ(it.get(), rightAnswer);
}

TEST(IntArrayTest, ReverseIterator) {
	Array<int> array;
	int rightAnswer = 40;

	array.insert(10);
	array.insert(20);
	array.insert(30);
	array.insert(40);

	for (auto it = array.reverseIterator(); it.hasNext(); it.next(), rightAnswer -= 10)
		EXPECT_EQ(it.get(), rightAnswer);
}



TEST(StringArrayTest, DefaultConstructor) {
	Array<std::string> array;

	ASSERT_EQ(array.getSize(), 0);
	ASSERT_EQ(array.getCapacity(), 8);
}

TEST(StringArrayTest, ConstructorWithCapacity) {
	Array<std::string> array(16);

	ASSERT_EQ(array.getSize(), 0);
	ASSERT_EQ(array.getCapacity(), 16);
}

TEST(StringArrayTest, CopyConstructor) {
	Array<std::string> array;
	array.insert("10");
	array.insert("20");
	array.insert("30");
	array.insert("40");

	Array<std::string> copiedArray(array);

	ASSERT_EQ(array.getSize(), copiedArray.getSize());
	ASSERT_EQ(array.getCapacity(), copiedArray.getCapacity());

	for (int i = 0; i < array.getSize(); i++)
		EXPECT_EQ(array[i], copiedArray[i]);
}

TEST(StringArrayTest, MoveConstructor) {
	Array<std::string> array;
	array.insert("10");
	array.insert("20");
	array.insert("30");
	array.insert("40");

	Array<std::string> copiedArray(std::move(array));

	ASSERT_EQ(copiedArray.getSize(), 4);
	ASSERT_EQ(copiedArray.getCapacity(), 8);
	EXPECT_EQ(copiedArray[0], "10");
	EXPECT_EQ(copiedArray[1], "20");
	EXPECT_EQ(copiedArray[2], "30");
	EXPECT_EQ(copiedArray[3], "40");
}

TEST(StringArrayTest, Insert) {
	Array<std::string> array;
	array.insert("10");
	array.insert("20");
	array.insert("30");
	array.insert("40");

	ASSERT_EQ(array.getSize(), 4);
	EXPECT_EQ(array[0], "10");
	EXPECT_EQ(array[1], "20");
	EXPECT_EQ(array[2], "30");
	EXPECT_EQ(array[3], "40");
}

TEST(StringArrayTest, InsertWithIndex) {
	Array<std::string> array;
	array.insert("10");
	array.insert("20");
	array.insert(0, "30");

	ASSERT_EQ(array.getSize(), 3);
	EXPECT_EQ(array[0], "30");
	EXPECT_EQ(array[1], "10");
	EXPECT_EQ(array[2], "20");
}

TEST(StringArrayTest, Remove) {
	Array<std::string> array;
	array.insert("10");
	array.insert("20");
	array.insert("30");
	array.insert("40");
	array.remove(0);
	array.remove(1);
	array.remove(1);

	ASSERT_EQ(array.getSize(), 1);
	EXPECT_EQ(array[0], "20");
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}