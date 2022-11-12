#pragma once

const int kSizeForInsertionSort = 40; // Экспериментально найденное значение

template<typename T, typename Compare>
void InsertionSort(T* first, T* last, Compare compare) {
    for (T* i = first; i <= last; i++) {
        T* j = i - 1;
        T value = *i;

        while (j >= first && compare(value, *j)) {
            *(j + 1) = std::move(*j);
            j--;
        }

        *(j + 1) = value;
    }
}

template<typename T, typename Compare>
T FindPivot(T& a, T& b, T& c, Compare compare) {
    if ((compare(a, b) && compare(c, a)) || (compare(a, c) && compare(b, a)))
        return a; // c < a < b или b < a < c
    else if ((compare(b, a) && compare(c, b)) || (compare(b, c) && compare(a, b)))
        return b; // c < b < a или a < b < c
    else
        return c;
}

template<typename T, typename Compare>
void QuickSort(T* first, T* last, Compare compare) {
    while (first < last) {
        T pivot = FindPivot(*first, *(first + (last - first) / 2), *last, compare);
        T* left = first;
        T* right = last;

        while (left <= right) {
            while (compare(*left, pivot))
                left++;

            while (compare(pivot, *right))
                right--;

            if (left <= right) {
                std::swap(*left, *right);
                left++;
                right--;
            }
        }

        if (last - right > right - first) {
            QuickSort(first, right, compare);
            first = right + 1;
        }
        else {
            QuickSort(right + 1, last, compare);
            last = right;
        }
    }
}

template<typename T, typename Compare>
void QuickSortWithInsert(T* first, T* last, Compare compare) {
    while (first < last) {
        if (last - first < kSizeForInsertionSort) {
            InsertionSort(first, last, compare);
            return;
        }

        T pivot = FindPivot(*first, *(first + (last - first) / 2), *last, compare);
        T* left = first;
        T* right = last;

        while (left <= right) {
            while (compare(*left, pivot))
                left++;

            while (compare(pivot, *right))
                right--;

            if (left <= right) {
                std::swap(*left, *right);
                left++;
                right--;
            }
        }

        if (last - right > right - first) {
            QuickSort(first, right, compare);
            first = right + 1;
        }
        else {
            QuickSort(right + 1, last, compare);
            last = right;
        }
    }
}