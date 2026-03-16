#include <iostream>
using namespace std;

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int idx = left; idx <= right; idx++)
        arr[idx] = temp[idx];
}

void optimizedMergeSort(int arr[], int temp[], int left, int right)
{
    if (right - left <= 10)
    {
        insertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    optimizedMergeSort(arr, temp, left, mid);
    optimizedMergeSort(arr, temp, mid + 1, right);

    if (arr[mid] <= arr[mid + 1])
        return;

    merge(arr, temp, left, mid, right);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;   
}

int main()
{
    int arr[] = {6, 3, 7, 5, 2, 4, 9, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n]; 

    cout << "Before Sorting:"<<endl;
    printArray(arr, n);

    optimizedMergeSort(arr, temp, 0, n - 1);

    cout << "After Sorting:"<<endl;
    printArray(arr, n);

    return 0;
}