//Potencia Numero
#include <iostream>
double power(double x, int n) {
	if (n == 0)
		return 1;
	
	if (n % 2 == 0) {
		double y = power(x, n / 2);
		return y * y;
	} else {
		double y = power(x, (n - 1) / 2);
		return x * y * y;
	}
}

int main() {
	double x;
	int n;
	
	std::cout << "Ingrese la base: ";
	std::cin >> x;
	
	std::cout << "Ingrese el exponente: ";
	std::cin >> n;
	
	double result = power(x, n);
	
	std::cout << "El resultado de " << x << " elevado a la " << n << " es: " << result << std::endl;
	
	return 0;
}

