#include <iostream>
#include <string>
#include <sstream>

#include "sort.h"
#include "array_populator.h"

using namespace std;

int main() {
    string input = "";
    int size;

    while (true) {
        cout << "Enter a valid array size: ";
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> size)
            break;
        cout << "Invalid number, please try again" << endl;
    }

    int array[size];

    array_populator::populate(array, size);

    sort * my_sort = new sort();
    my_sort->size = size;

    int array_copy[size];
    double duration;

    copy(array,array + size - 1,array_copy);

    std::clock_t start = clock();
    my_sort->bubbleSort(array_copy);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "Bubble Sort: " << duration << "s";
    my_sort->write(array_copy, "bubble.txt");




    return 0;
}
