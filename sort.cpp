#include "sort.h"

void sort::bubbleSort(int array[]) {



    int i, j;
    int n = size;

    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (array[j] > array[j+1])
            swap(array[j], array[j+1]);



}

void sort::selectionSort(int *array, string filename) {
    // One by one move boundary of unsorted subarray
    int i, j, mindex;
    int n = size;

    for (i = 0; i < n-1; i++)
    {
        mindex = i;
        for (j = i+1; j < n; j++)
            if (array[j] < array[mindex])
                mindex = j;

        swap(array[mindex], array[i]);

        write(array,filename);
    }
}

void sort::insertionSort(int *array, string filename) {
    int i, key, j;
    int n = size;

    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    write(array,filename);
}

void sort::shellSort(int *array, string filename) {
    int n = size;
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = array[i];

            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
                array[j] = array[j - gap];

            array[j] = temp;
        }
    }

    write(array,filename);
}

void sort::mergeSort(int *array, string filename) {
    int l = 0;
    int r = size - 1;

    mergeSortRecursive(array, l, r);

    write(array,filename);
}

void sort::quickSort(int *array, string filename) {
    int l = 0;
    int r = size - 1;

    quickSortRecursive(array, l, r);

    write(array,filename);
}

void sort::radixSort(int *array, string filename) {
    int n = size;

    int m = getMax(array, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(array, n, exp);

    write(array,filename);
}

void sort::swap(int &j, int &r) {
    int temp = j;
    j = r;
    r = temp;
}

void sort::write(int array[], string filename) {

    if(size <= 1000){
        ofstream myfile (filename);
        if(myfile.is_open())
        {
            for (int i = 0; i <  size; ++i) {
                myfile << array[i] << " ";
            }
            myfile.close();
        }
        else{
            cout << "Unable to open file";
        }
    }
}

void sort::merge(int *array, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void sort::mergeSortRecursive(int *array, int l, int r) {
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSortRecursive(array, l, m);
        mergeSortRecursive(array, m+1, r);

        merge(array, l, m, r);
    }
}

int sort::partition(int *array, int low, int high) {
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void sort::quickSortRecursive(int *array, int low, int high) {
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(array, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSortRecursive(array, low, pi - 1);
        quickSortRecursive(array, pi + 1, high);
    }
}

int sort::getMax(int *array, int n) {
    int mx = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > mx)
            mx = array[i];
    return mx;
}

void sort::countSort(int *array, int n, int exp) {
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (array[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (array[i]/exp)%10 ] - 1] = array[i];
        count[ (array[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

