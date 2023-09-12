#include <iostream>

using namespace std;

//Selection sort
void selectionSort(int arr[]){
    int arrLength = sizeof(arr);
    for (int i = 0; i < arrLength; i++){
        int min = arr[i];
        for (int j = i; j < arrLength; j++){
            if (arr[j] < min) min = arr[j];
        }
        int viTri = i;
        for (int j = i; j < arrLength; j++){
            if (arr[j] == min) viTri = j;
        }
        int doiCho = arr[i];
        arr[i] = arr[viTri];
        arr[viTri] = doiCho;
    }
}

//Insertion sort
void insertionSort(int arr[]){
    int arrLength = sizeof(arr);
    for (int i = 0; i < arrLength; i++){
        int batDauLui = i;
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[i]){
                batDauLui = j;  
                break;
            } 
        }
        int phanTuChen = arr[i];
        for (int j = i; j >= (batDauLui + 1); j--){
            arr[j] = arr[j - 1];
        }
        arr[batDauLui] = phanTuChen;
    }
}

//Bubble sort
void bubbleSort(int arr[]){
    int arrLength = sizeof(arr);
    for (int i = 0; i < arrLength - 2; i++){
        for (int j = 0; j < arrLength - 2; j++){
            if (arr[j] > arr[j + 1]){
                int doiCho = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = doiCho;
            } 
        }
    }
}

//Merge sort
void merge(int a[], int start, int end, int mid)
{
    int subArrayOne = mid - start + 1;
    int subArrayTwo = end - mid;

    int* leftArray = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++) leftArray[i] = a[start+i];
    for (int i = 0; i < subArrayTwo; i++) rightArray[i] = a[i+mid+1];

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfArray = start;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (rightArray[indexOfSubArrayTwo] <= leftArray[indexOfSubArrayOne])
        {
            a[indexOfArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        else if (leftArray[indexOfSubArrayOne] < rightArray[indexOfSubArrayTwo])
        {
            a[indexOfArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        indexOfArray++;
    }
    if (indexOfSubArrayOne < subArrayOne)
    {
        while (indexOfSubArrayOne < subArrayOne)
        {
            a[indexOfArray] = leftArray[indexOfSubArrayOne];
            indexOfArray++;
            indexOfSubArrayOne++;
        }
    }
    else if (indexOfSubArrayTwo < subArrayTwo)
    {
        while (indexOfSubArrayTwo < subArrayTwo)
        {
            a[indexOfArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfArray++;
        }
    }
    delete[] rightArray;
    delete[] leftArray;
}
void mergeSort(int a[], int start, int end)
{
    if (start >= end) return;
    int mid = start + (end - start) /2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    merge(a, start, end, mid);
}

//Quick sort
int partition(int arr[], int left, int right, int pivot){
    int i = left, j = left;
    while (j < right){
        while (arr[i] < pivot) i++;
        j = i;
        while (arr[j] > pivot) j++;
        int doiCho = arr[i];
        arr[i] = arr[j];
        arr[j] = doiCho;
    }
    return i;
}
void quickSort(int arr[], int left, int right){
    int pivot = arr[right];
    if (left < right){
        int vachNgan = partition(arr, left, right, pivot);
        quickSort(arr, left, vachNgan - 1);
        quickSort(arr, vachNgan + 1, right);
    }
}