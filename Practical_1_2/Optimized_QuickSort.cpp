#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        int p = partition(arr, low, high);

        if (p - low < high - p)
        {
            quickSort(arr, low, p - 1);
            low = p + 1;
        }
        else
        {
            quickSort(arr, p + 1, high);
            high = p - 1;
        }
    }
}
 
int main()
{
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}