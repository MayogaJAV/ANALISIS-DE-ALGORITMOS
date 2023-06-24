//Recurrencia No Homogenea
#include <iostream>
int RecurrenciaNoHomogenea(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return 2 * RecurrenciaNoHomogenea(n - 1) + n;
	}
}

int main()
{
	int n = 5;
	int resultado = RecurrenciaNoHomogenea(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
