//Recurrencia Homogenea
#include <iostream>
int RecurrenciaHomogenea(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 2;
	}
	else
	{
		return 3 * RecurrenciaHomogenea(n - 1) - 2 * RecurrenciaHomogenea(n - 2);
	}
}

int main()
{
	int n = 5;
	int resultado = RecurrenciaHomogenea(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
