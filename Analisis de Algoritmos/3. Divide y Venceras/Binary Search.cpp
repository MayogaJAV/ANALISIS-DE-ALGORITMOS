//Binary Search
#include<iostream>
using namespace std;
int busquedaBinaria(int arr[], int l, int r, int x) {
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		if (arr[m] == x)
			return m;
		
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main() {
	int arr[] = {2, 3, 4, 10, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int resultado = busquedaBinaria(arr, 0, n - 1, x);
	(resultado == -1) ? cout << "El elemento no se encuentra en el arreglo" : cout << "El elemento se encuentra en el índice " << resultado;
	return 0;
}
