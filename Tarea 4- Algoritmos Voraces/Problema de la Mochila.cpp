//Problema de la Mochila:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto {
    int peso;
    int valor;
};

bool compararPorRatio(Objeto o1, Objeto o2) {
    double ratio1 = (double)o1.valor / o1.peso;
    double ratio2 = (double)o2.valor / o2.peso;
    return ratio1 > ratio2;
}

int problemaMochila(vector<Objeto> objetos, int capacidad) {
    sort(objetos.begin(), objetos.end(), compararPorRatio);

    int pesoActual = 0;
    int valorTotal = 0;

    for (int i = 0; i < objetos.size(); i++) {
        if (pesoActual + objetos[i].peso <= capacidad) {
            pesoActual += objetos[i].peso;
            valorTotal += objetos[i].valor;
        } else {
            int espacioRestante = capacidad - pesoActual;
            valorTotal += (objetos[i].valor / objetos[i].peso) * espacioRestante;
            break;
        }
    }

    return valorTotal;
}

int main() {
    vector<Objeto> objetos = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}, {4, 18}, {1, 3}};
    int capacidadMochila = 15;

    int valorMaximo = problemaMochila(objetos, capacidadMochila);

    cout << "Valor ma+ximo en la mochila: " << valorMaximo << endl;

    return 0;
}
