//Vectores y variables de tamaño fijo
#include <iostream>
#include <cstdlib> // Necesario para la función realloc

int gVect[100]; // Buffer para almacenar los elementos
int gnCountFixed; // Contador para conocer el número de elementos utilizados en el vector de tamaño fijo

void InsertFixed(int elem)
{
	if (gnCountFixed < 100) // Solo se puede insertar si hay espacio
		gVect[gnCountFixed++] = elem; // Insertar el elemento al final
}

int *gpVect = nullptr; // Buffer dinámico para almacenar los elementos
int gnCountDynamic = 0; // Contador para conocer el número de elementos utilizados en el vector dinámico
int gnMax = 0;
void Resize()
{
	const int delta = 10; // Utilizado para aumentar el tamaño del vector
	gpVect = static_cast<int*>(std::realloc(gpVect, sizeof(int) * (gnMax + delta)));
	gnMax += delta; // El valor máximo debe aumentar en delta
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
	
	// Uso del vector de tamaño fijo
	InsertFixed(1);
	InsertFixed(2);
	InsertFixed(3);
	
	std::cout << "Elementos en gVect: ";
	for (int i = 0; i < gnCountFixed; i++)
	{
		std::cout << gVect[i] << " ";
	}
	std::cout << std::endl;
	
	// Uso del vector dinámico
	InsertDynamic(4);
	InsertDynamic(5);
	InsertDynamic(6);
	
	std::cout << "Elementos en gpVect: ";
	for (int i = 0; i < gnCountDynamic; i++)
	{
		std::cout << gpVect[i] << " ";
	}
	std::cout << std::endl;
	
	// Liberar memoria del vector dinámico
	std::free(gpVect);
	
	return 0;
}
