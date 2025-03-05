#pragma once

#include <vector>

class QuickSort {
public:
    static void sort(std::vector<int>& arr);
    static void bubbleSort(std::vector<int>& arr); // Для сравнения
private:
    static void quickSortHelper(std::vector<int>& arr, int low, int high);
    static int partition(std::vector<int>& arr, int low, int high);
};
