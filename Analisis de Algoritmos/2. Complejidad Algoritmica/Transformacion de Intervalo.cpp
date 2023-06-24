//Transformacion de Intervalo
#include <iostream>
int RecurrenciaTransformacionIntervalo(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n % 2 == 0)
	{
		return RecurrenciaTransformacionIntervalo(n / 2);
	}
	else
	{
		return RecurrenciaTransformacionIntervalo(n - 1) + 1;
	}
}

int main()
{
	int n = 5;
	int resultado = RecurrenciaTransformacionIntervalo(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
