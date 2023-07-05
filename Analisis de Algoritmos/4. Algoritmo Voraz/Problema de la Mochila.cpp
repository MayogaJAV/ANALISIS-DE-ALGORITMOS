//Problema de la Mochila:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto {
    double peso;
    double valor;
};

bool compararPorRatio(const Objeto& o1, const Objeto& o2) {
    double ratio1 = o1.valor / o1.peso;
    double ratio2 = o2.valor / o2.peso;
    return ratio1 > ratio2;
}

double problemaMochila(const vector<Objeto>& objetos, double capacidad) {
    vector<Objeto> objetosOrdenados(objetos);
    sort(objetosOrdenados.begin(), objetosOrdenados.end(), compararPorRatio);

    double pesoActual = 0;
    double valorTotal = 0;

    for (auto it = objetosOrdenados.begin(); it != objetosOrdenados.end(); ++it) {
        if (pesoActual + it->peso <= capacidad) {
            pesoActual += it->peso;
            valorTotal += it->valor;
        } else {
            double espacioRestante = capacidad - pesoActual;
            valorTotal += (it->valor / it->peso) * espacioRestante;
            break;
        }
    }

    return valorTotal;
}

int main() {
    vector<Objeto> objetos = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}, {4, 18}, {1, 3}};
    double capacidadMochila = 15;

    double valorMaximo = problemaMochila(objetos, capacidadMochila);

    cout << "Valor maximo en la mochila: " << valorMaximo << endl;

    return 0;
}
