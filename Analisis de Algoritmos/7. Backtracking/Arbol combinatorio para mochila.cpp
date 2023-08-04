#include <iostream>
#include <vector>

using namespace std;

struct Objeto {
	int peso;
	int valor;
};

int mochilaCombinatoria(vector<Objeto>& objetos, int capacidad, int pesoActual, int valorActual, int indice) {
	if (indice >= objetos.size() || pesoActual >= capacidad) {
		return valorActual;
	}
	
	int valorMaximo = valorActual;
	
	for (int i = indice; i < objetos.size(); i++) {
		if (pesoActual + objetos[i].peso <= capacidad) {
			int nuevoValor = mochilaCombinatoria(objetos, capacidad, pesoActual + objetos[i].peso,
												 valorActual + objetos[i].valor, i + 1);
			valorMaximo = max(valorMaximo, nuevoValor);
		}
	}
	
	return valorMaximo;
}

int main() {
	// Ejemplo de uso
	vector<Objeto> objetos = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
	int capacidad = 5;
	
	int valorMaximo = mochilaCombinatoria(objetos, capacidad, 0, 0, 0);
	
	cout << "Valor máximo de la mochila: " << valorMaximo << endl;
	
	return 0;
}
