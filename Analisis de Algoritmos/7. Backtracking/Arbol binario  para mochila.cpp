#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
	int peso;
	int valor;
};

int mochilaBinaria(vector<Objeto>& objetos, int capacidad) {
	int n = objetos.size();
	vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacidad; j++) {
			if (objetos[i - 1].peso <= j) {
				dp[i][j] = max(dp[i - 1][j],
					dp[i - 1][j - objetos[i - 1].peso] + objetos[i - 1].valor);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	return dp[n][capacidad];
}

int main() {
	// Ejemplo de uso
	vector<Objeto> objetos = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
	int capacidad = 5;
	
	int valorMaximo = mochilaBinaria(objetos, capacidad);
	
	cout << "Valor máximo de la mochila: " << valorMaximo << endl;
	
	return 0;
}
