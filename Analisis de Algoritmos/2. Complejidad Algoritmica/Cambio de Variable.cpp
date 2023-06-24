//Cambio de Variable
#include <iostream>
int RecurrenciaCambioVariable(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		int m = n - 1;
		return RecurrenciaCambioVariable(m) + 2;
	}
}

int main()
{
	int n = 5;
	int resultado = RecurrenciaCambioVariable(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
