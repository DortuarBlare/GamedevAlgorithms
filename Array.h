#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
class Array final {
private:
	T* items;
	int size;
	int capacity;
	const int defaultCapacity = 8;
	const int resizeCoef = 2;

	template<bool Const, bool Reverse>
	class Iterator {
	private:
		Array& array;
		T* ptr;

	public:
		Iterator(Array& array) : array(array) {
			if (Reverse)
				ptr = array.items + array.size - 1;
			else
				ptr = array.items;
		}

		const T& get() const {
			return *ptr;
		}

		void set(const T& value) {
			if (!Const) {
				*ptr = value;
			}
		}

		void next() {
			if (!hasNext())
				throw "Iterator out of range";

			if (Reverse)
				ptr--;
			else
				ptr++;
		}

		bool hasNext() const {
			if (Reverse)
				return ptr >= array.items;
			else
				return ptr < array.items + array.size;
		}
	};

public:
	Array();
	Array(int capacity);
	Array(const Array& other); // Copy
	Array(Array&& other); // Move
	~Array();

	int insert(const T& value);
	int insert(int index, const T& value);
	void remove(int index);
	int getSize() const;
	int getCapacity() const;

	Iterator<false, false> iterator();
	Iterator<true, false> iterator() const;
	Iterator<false, true> reverseIterator();
	Iterator<true, true> reverseIterator() const;

	Array& operator=(Array& other); // Copy
	Array& operator=(Array&& other); // Move
	const T& operator[](int index) const;
	T& operator[](int index);

private:
	void resize();
	void deepCopy(Array& other);
	T* allocate(size_t capacity);
	T* allocateWithInit(int size, size_t capacity);
};

template<typename T>
inline Array<T>::Array() {
	this->items = nullptr;
	this->size = 0;
	this->capacity = defaultCapacity;
}

template<typename T>
inline Array<T>::Array(int capacity) {
	this->size = 0;

	if (capacity == 0)
		this->capacity = defaultCapacity;
	else
		this->capacity = capacity;

	items = allocate(capacity);
}

// Copy
template<typename T>
inline Array<T>::Array(const Array& other) {
	deepCopy(const_cast<Array&>(other));
}

// Move
template<typename T>
inline Array<T>::Array(Array&& other) {
	size = other.size;
	capacity = other.capacity;
	items = other.items;

	other.size = 0;
	other.capacity = 0;
	other.items = nullptr;
}

template<typename T>
inline Array<T>::~Array() {
	for (int i = 0; i < size; i++)
		items[i].~T();

	std::free(items);
}


template<typename T>
inline int Array<T>::insert(const T& value) {
	if (size == capacity)
		resize();
	else if (!items)
		items = allocate(capacity);

	new(items + size) T(value);
	size++;

	return size - 1;
}

template<typename T>
inline int Array<T>::insert(int index, const T& value) {
	if (size == capacity)
		resize();
	if (!items)
		items = allocate(capacity);

	new(items + size) T{};
	std::move(items + index, items + size, items + index + 1);

	//new(items + index) T(value);
	items[index] = value;
	size++;

	return index;
}

template<typename T>
inline void Array<T>::remove(int index) {
	if (size == 0)
		throw "Array is empty";

	std::move(items + index + 1, items + size, items + index);
	size--;
}

template<typename T>
inline int Array<T>::getSize() const {
	return size;
}

template<typename T>
inline int Array<T>::getCapacity() const {
	return capacity;
}


template<typename T>
inline Array<T>::Iterator<false, false> Array<T>::iterator() {
	return Iterator<false, false>(*this);
}

template<typename T>
inline Array<T>::Iterator<true, false> Array<T>::iterator() const {
	return Iterator<true, false>(*this);
}

template<typename T>
inline Array<T>::Iterator<false, true> Array<T>::reverseIterator() {
	return Iterator<false, true>(*this);
}

template<typename T>
inline Array<T>::Iterator<true, true> Array<T>::reverseIterator() const {
	return Iterator<true, true>(*this);
}


// Copy
template<typename T>
inline Array<T>& Array<T>::operator=(Array& other) {
	if (this != &other) {
		//std::free(items)
		this->~Array();
		deepCopy(other);
	}
	return *this;
}

// Move
template<typename T>
inline Array<T>& Array<T>::operator=(Array&& other) {
	if (this != &other) {
		//std::free(items);
		this->~Array();

		size = other.size;
		capacity = other.capacity;
		items = other.items;

		other.size = 0;
		other.capacity = 0;
		other.items = nullptr;
	}
	return *this;
}

template<typename T>
inline const T& Array<T>::operator[](int index) const {
	return items[index];
}

template<typename T>
inline T& Array<T>::operator[](int index) {
	return items[index];
}


template<typename T>
inline void Array<T>::resize() {
	capacity *= resizeCoef;
	T* temp = allocateWithInit(size, capacity);
	std::move(items, items + size, temp);
	std::free(items);
	items = temp;
}

template<typename T>
inline void Array<T>::deepCopy(Array& other) {
	size = other.size;
	capacity = other.capacity;
	items = allocateWithInit(size, capacity);
	std::copy(other.items, other.items + size, items);
}

template<typename T>
inline T* Array<T>::allocate(size_t capacity) {
	return static_cast<T*>(std::malloc(capacity * sizeof(T)));
}

template<typename T>
inline T* Array<T>::allocateWithInit(int size, size_t capacity) {
	T* temp = static_cast<T*>(std::malloc(capacity * sizeof(T)));

	for (int i = 0; i < size; i++)
		new(temp + i) T{};

	return temp;
}