//Vectores y variables de tamaño fijo
#include <iostream>
#include <cstdlib> 

int gVect[100]; 
int gnCountFixed;

void InsertFixed(int elem)
{
	if (gnCountFixed < 100) 
		gVect[gnCountFixed++] = elem; 
}

int *gpVect = nullptr; 
int gnCountDynamic = 0; 
int gnMax = 0;
void Resize()
{
	const int delta = 10; 
	gpVect = static_cast<int*>(std::realloc(gpVect, sizeof(int) * (gnMax + delta)));
	gnMax += delta; 
}
void InsertDynamic(int elem)
{
	if (gnCountDynamic == gnMax)
		Resize();
	
	gpVect[gnCountDynamic++] = elem; 



int main()
{
	InsertFixed(1);
	InsertFixed(2);
	InsertFixed(3);
	
	std::cout << "Elementos en gVect: ";
	for (int i = 0; i < gnCountFixed; i++)
	{
		std::cout << gVect[i] << " ";
	}
	std::cout << std::endl;

	InsertDynamic(4);
	InsertDynamic(5);
	InsertDynamic(6);
	
	std::cout << "Elementos en gpVect: ";
	for (int i = 0; i < gnCountDynamic; i++)
	{
		std::cout << gpVect[i] << " ";
	}
	std::cout << std::endl;
	
	std::free(gpVect);
	
	return 0;
}
