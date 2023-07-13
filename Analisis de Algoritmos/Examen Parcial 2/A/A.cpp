#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int *j = &arr[low]; j <= &arr[high - 1]; j++) {
        if (*j <= pivot) {
            i++;
            swap(arr[i], *j);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> nums;
    int n, dato;
    while (cin >> dato) {
        nums.push_back(dato);
        n = nums.size();

        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        quickSort(arr, 0, n - 1);

        int mediana;
        if (n % 2 == 0) {
            mediana = (arr[n / 2] + arr[n / 2 - 1]) / 2;
        } else {
            mediana = arr[n / 2];
        }

        cout << mediana << endl;
    }

    return 0;
}