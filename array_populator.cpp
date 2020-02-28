#include "array_populator.h"

namespace array_populator{
    void populate(int *array, int size) {
        for (int i = 0; i < size; ++i) {
            *(array+i) = rand() % 32767 + 0;
        }
    }
}