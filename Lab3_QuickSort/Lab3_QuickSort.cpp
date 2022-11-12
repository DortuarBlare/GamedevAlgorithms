#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
#include "QuickSort.h"
#include <windows.h>

double frequency = 0.0;
long long int CounterStart = 0;

void StartCounter() {
    LARGE_INTEGER freq;
    if (!QueryPerformanceFrequency(&freq))
        std::cout << "QueryPerformanceFrequency failed!\n";

    frequency = double(freq.QuadPart / 1000000.0);

    QueryPerformanceCounter(&freq);
    CounterStart = freq.QuadPart;
}

double GetCounter() {
    LARGE_INTEGER freq;
    QueryPerformanceCounter(&freq);
    return double(freq.QuadPart - CounterStart) / frequency;
}

int main() {
    std::default_random_engine randGenerator;
    std::uniform_int_distribution<int> randNumber(1, 100);
    randGenerator.seed(time(NULL));
    double insertSortTime = 0.0;
    double quickSortTime = 0.0;
    std::ofstream os("Data.txt", std::ios::out/* | std::ios::trunc*/);

    for (int SIZE = 5; SIZE <= 100; SIZE++) {
        int* A = new int[SIZE];
        int* B = new int[SIZE];
        insertSortTime = 0.0;
        quickSortTime = 0.0;

        for (int j = 0; j < 100; j++) {
            // For InsertSort
            for (int i = SIZE - 1, j = 1; i >= 0; i--, j++)
                A[i] = j;

            // For QuickSort
            for (int i = 0; i < SIZE; i++)
                B[i] = randNumber(randGenerator);

            StartCounter();
            InsertionSort(A, A + SIZE - 1, [](int a, int b) { return a < b; });
            insertSortTime += GetCounter();

            StartCounter();
            QuickSort(B, B + SIZE - 1, [](int a, int b) { return a < b; });
            quickSortTime += GetCounter();
        }

        insertSortTime /= 10000;
        quickSortTime /= 10000;

        if (os.is_open())
            os << SIZE << ';' << insertSortTime << ';' << quickSortTime << std::endl;

        delete[] A;
        delete[] B;
    }
}