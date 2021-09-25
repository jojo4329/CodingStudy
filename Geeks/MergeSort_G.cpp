#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#define TEST1
using namespace std;

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int const subArrOne = m - l + 1;
        int const subArrTwo = r - m;

        // Create temp arrays
        auto* leftArray = new int[subArrOne];
        auto* rightArray = new int[subArrTwo];

        // Copy data
        for (int i = 0; i < subArrOne; i++) {
            leftArray[i] = arr[l + i];
        }
        for (int j = 0; j < subArrTwo; j++) {
            rightArray[j] = arr[m + 1 + j];
        }

        auto idxSubArrOne = 0;
        auto idxSubArrTwo = 0;
        int idxMergedArr = l;

        while (idxSubArrOne < subArrOne && idxSubArrTwo < subArrTwo) {
            if (leftArray[idxSubArrOne] <= rightArray[idxSubArrTwo]) {
                arr[idxMergedArr] = leftArray[idxSubArrOne];
                idxSubArrOne++;
            }
            else {
                arr[idxMergedArr] = rightArray[idxSubArrTwo];
                idxSubArrTwo++;
            }
            idxMergedArr++;
        }

        while (idxSubArrOne < subArrOne) {
            arr[idxMergedArr] = leftArray[idxSubArrOne];
            idxSubArrOne++;
            idxMergedArr++;
        }

        while (idxSubArrTwo < subArrTwo) {
            arr[idxMergedArr] = rightArray[idxSubArrTwo];
            idxSubArrTwo++;
            idxMergedArr++;
        }
    }
public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l >= r) {
            return;
        }

        auto mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
};

int main(void)
{
#ifdef TEST1
    int n = 5;
    int ar[] = { 4, 1, 3, 9, 7 };
#else
    int n = 10;
    int ar[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
#endif

    Solution sol;
    sol.mergeSort(ar, 0, n - 1);

    printArray(ar, n);

    return 0;
}