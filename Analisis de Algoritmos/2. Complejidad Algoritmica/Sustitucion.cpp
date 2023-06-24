//Sustitucion
#include <iostream>
int FuncionRecursiva(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return 2 * FuncionRecursiva(n - 1);
	}
}

int main()
{
	int n = 5;
	int resultado = FuncionRecursiva(n);
	std::cout << "Resultado: " << resultado << std::endl;
	
	return 0;
}
