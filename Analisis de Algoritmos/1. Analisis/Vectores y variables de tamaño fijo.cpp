//Vectores y variables de tama�o fijo
#include <iostream>
#include <cstdlib> // Necesario para la funci�n realloc

int gVect[100]; // Buffer para almacenar los elementos
int gnCountFixed; // Contador para conocer el n�mero de elementos utilizados en el vector de tama�o fijo

void InsertFixed(int elem)
{
	if (gnCountFixed < 100) // Solo se puede insertar si hay espacio
		gVect[gnCountFixed++] = elem; // Insertar el elemento al final
}

int *gpVect = nullptr; // Buffer din�mico para almacenar los elementos
int gnCountDynamic = 0; // Contador para conocer el n�mero de elementos utilizados en el vector din�mico
int gnMax = 0;
void Resize()
{
	const int delta = 10; // Utilizado para aumentar el tama�o del vector
	gpVect = static_cast<int*>(std::realloc(gpVect, sizeof(int) * (gnMax + delta)));
	gnMax += delta; // El valor m�ximo debe aumentar en delta
}
void InsertDynamic(int elem)
{
	if (gnCountDynamic == gnMax) // No hay espacio en este momento para elem
		Resize(); // Redimensionar el vector antes de insertar elem
	
	gpVect[gnCountDynamic++] = elem; // Insertar el elemento al final de la secuencia
}



int main()
{
	// Ejemplo de uso de las funciones Insert
	
	// Uso del vector de tama�o fijo
	InsertFixed(1);
	InsertFixed(2);
	InsertFixed(3);
	
	std::cout << "Elementos en gVect: ";
	for (int i = 0; i < gnCountFixed; i++)
	{
		std::cout << gVect[i] << " ";
	}
	std::cout << std::endl;
	
	// Uso del vector din�mico
	InsertDynamic(4);
	InsertDynamic(5);
	InsertDynamic(6);
	
	std::cout << "Elementos en gpVect: ";
	for (int i = 0; i < gnCountDynamic; i++)
	{
		std::cout << gpVect[i] << " ";
	}
	std::cout << std::endl;
	
	// Liberar memoria del vector din�mico
	std::free(gpVect);
	
	return 0;
}
