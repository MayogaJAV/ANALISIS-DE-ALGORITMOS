#include <iostream>
#include <algorithm>
using namespace std;

struct Tarea {
	int inicio, fin;
};

bool compararTareas(Tarea a, Tarea b) {
	return (a.fin < b.fin);
}

int planificarTareas(Tarea arr[], int n) {
	sort(arr, arr+n, compararTareas);
	
	int i = 0;
	cout << "(" << arr[i].inicio << ", " << arr[i].fin << ") ";
	
	int cuenta = 1;
	for (int j = 1; j < n; j++) {
		if (arr[j].inicio >= arr[i].fin) {
			cout << "(" << arr[j].inicio << ", " << arr[j].fin << ") ";
			i = j;
			cuenta++;
		}
	}
	cout<<endl;
	return cuenta;
}

int main() {
	Tarea arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Numero maximo de tareas: " << planificarTareas(arr, n);
	return 0;
}
