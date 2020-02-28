#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <string>
#include <array>
#include "iostream"
#include "fstream"
#include <chrono>

using namespace std;

class sort{
public:
    sort(){
        int size = 0;
    }
    void bubbleSort(int array[]);
    void selectionSort(int array[], string filename);
    void insertionSort(int array[], string filename);
    void shellSort(int array[], string filename);
    void mergeSort(int array[], string filename);
    void quickSort(int array[], string filename);
    void radixSort(int array[], string filename);
    int size;
    void write(int array[], string filename);
private:
    void swap(int &j, int &r);
    void merge(int array[], int l, int m, int r);
    void mergeSortRecursive(int array[], int l, int r);
    int partition(int array[], int low, int high);
    void quickSortRecursive(int array[], int low, int high);
    int getMax(int array[], int n);
    void countSort(int array[], int n, int exp);
};

#endif //SORT_SORT_H
