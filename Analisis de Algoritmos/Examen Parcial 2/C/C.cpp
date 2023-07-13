#include <iostream>
#include <vector>
#include <algorithm>

int maxMonedas(const std::vector<int>& monedas, int cantidad) {
    std::vector<int> dp(cantidad + 1, 0);  // Tabla de programación dinámica

    for (int i = 1; i <= cantidad; i++) {
        for (const int& moneda : monedas) {
            if (moneda <= i) {
                dp[i] = std::max(dp[i], 1 + dp[i - moneda]);
            }
        }
    }

    return dp[cantidad];
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> monedas(n);
        for (int& moneda : monedas) {
            std::cin >> moneda;
        }

        int cantidad;
        std::cin >> cantidad;

        int max_mon = maxMonedas(monedas, cantidad);

        std::cout << max_mon << std::endl;
    }

    return 0;
}
