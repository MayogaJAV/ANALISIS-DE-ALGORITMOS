//Quick Sort
#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	
	// Colocar todos los elementos menores que el pivote al principio y los mayores al final
	for (int *j = &arr[low]; j <= &arr[high - 1]; j++) {
		if (*j <= pivot) {
			i++;
			swap(arr[i], *j);
		}
	}
	
	// Colocar el pivote en su posición correcta
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		// Obtener la posición del pivote
		int pi = partition(arr, low, high);
		
		// Ordenar recursivamente los elementos antes y después del pivote
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	quickSort(arr, 0, n - 1);
	
	cout << "Arreglo ordenado: \n";
	for (int *i = arr; i < arr + n; i++)
		cout << *i << " ";
	cout << endl;
	
	return 0;
}

