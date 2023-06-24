#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Punto {
	int x, y;
	Punto(int x = 0, int y = 0): x(x), y(y) {}
};

double distancia(Punto a, Punto b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

vector<int> heuristicaVertices(vector<Punto> puntos) {
	int n = puntos.size();
	vector<int> recorrido;
	vector<bool> visitado(n);
	recorrido.push_back(0);
	visitado[0] = true;
	for (int i = 1; i < n; i++) {
		double minDist = 1e18;
		int minVertice = -1;
		for (int j = 0; j < n; j++) {
			if (!visitado[j]) {
				double dist = distancia(puntos[recorrido.back()], puntos[j]);
				if (dist < minDist) {
					minDist = dist;
					minVertice = j;
				}
			}
		}
		recorrido.push_back(minVertice);
		visitado[minVertice] = true;
	}
	return recorrido;
}

int main() {
	cout << "Ingrese el número de puntos y las coordenadas de cada punto:" << endl;
	int n;
	cin >> n;
	vector<Punto> puntos(n);
	cout << "Ingrese las coordenadas de cada punto:" << endl;
	for (int i = 0; i < n; i++)
		cin >> puntos[i].x >> puntos[i].y;
	vector<int> recorrido = heuristicaVertices(puntos);
	cout << "Recorrido:" << endl;
	for (int i = 0; i < n; i++)
		cout << recorrido[i] << ' ';
	cout << endl;
	return 0;
}

