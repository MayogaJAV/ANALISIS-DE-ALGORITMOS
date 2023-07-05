//Problema del cambio de monedas:
#include <iostream>
#include <vector>
using namespace std;

vector<int> cambioMonedas(const vector<int>& monedas, unsigned int cantidad) {
    vector<int> cambio;
    int i = monedas.size() - 1;

    while (cantidad > 0 && i >= 0) {
        if (monedas[i] <= cantidad) {
            cambio.push_back(monedas[i]);
            cantidad -= monedas[i];
        } else {
            i--;
        }
    }

    return cambio;
}

int main() {
    vector<int> monedas = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    unsigned int cantidad = 123;

    vector<int> cambio = cambioMonedas(monedas, cantidad);

    cout << "Cambio de monedas: ";
    for (auto it = cambio.begin(); it != cambio.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
