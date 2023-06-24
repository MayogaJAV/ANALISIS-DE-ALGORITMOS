//Programacion Modular
#include <iostream>
#include <cstdlib> // Necesario para la función realloc
void Resize(int*& rpVect, int& rnMax)
{
	const int delta = 10; // Utilizado para aumentar el tamaño del vector
	rpVect = static_cast<int*>(std::realloc(rpVect, sizeof(int) * (rnMax + delta)));
	rnMax += delta; // El valor máximo debe aumentar en delta
}
void Insert(int*& rpVect, int& rnCount, int& rnMax, int elem)
{
	if (rnCount == rnMax) // Verificar desbordamiento
		Resize(rpVect, rnMax); // Redimensionar el vector antes de insertar elem
	
	rpVect[rnCount++] = elem; // Insertar el elemento al final de la secuencia
}



struct Vector
{
	int* m_pVect; // Puntero al buffer
	int m_nCount; // Controla cuántos elementos se utilizan realmente
	int m_nMax; // Controla cuántos están asignados como máximo
	int m_nDelta; // Para controlar el crecimiento
};

void Insert(Vector* pThis, int elem)
{
	if (pThis->m_nCount == pThis->m_nMax) // Verificar desbordamiento
		Resize(pThis->m_pVect, pThis->m_nMax); // Redimensionar el vector antes de insertar elem
	
	pThis->m_pVect[pThis->m_nCount++] = elem; // Insertar el elemento al final de la secuencia
}

void Resize(Vector* pThis)
{
	const int delta = 10; // Utilizado para aumentar el tamaño del vector
	pThis->m_pVect = static_cast<int*>(std::realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + delta)));
	pThis->m_nMax += delta; // El valor máximo debe aumentar en delta
}

int main()
{
	// Ejemplo de uso de las funciones y estructura
	
	// Uso del vector de tamaño fijo
	int* gVect = nullptr; // Inicializar el puntero
	int gnCountFixed = 0;
	int gnMaxFixed = 0;
	
	Insert(gVect, gnCountFixed, gnMaxFixed, 1);
	Insert(gVect, gnCountFixed, gnMaxFixed, 2);
	Insert(gVect, gnCountFixed, gnMaxFixed, 3);
	
	std::cout << "Elementos en gVect: ";
	for (int i = 0; i < gnCountFixed; i++)
	{
		std::cout << gVect[i] << " ";
	}
	std::cout << std::endl;
	
	// Uso de la estructura Vector (vector dinámico)
	Vector dynamicVector;
	dynamicVector.m_pVect = nullptr; // Inicializar el puntero
	dynamicVector.m_nCount = 0;
	dynamicVector.m_nMax = 0;
	dynamicVector.m_nDelta = 10;
	
	Insert(&dynamicVector, 4);
	Insert(&dynamicVector, 5);
	Insert(&dynamicVector, 6);
	
	std::cout << "Elementos en dynamicVector.m_pVect: ";
	for (int i = 0; i < dynamicVector.m_nCount; i++)
	{
		std::cout << dynamicVector.m_pVect[i] << " ";
	}
	std::cout << std::endl;
	
	// Liberar memoria del vector de tamaño fijo
	std::free(gVect);
	
	// Liberar memoria del vector dinámico
	std::free(dynamicVector.m_pVect);
	
	return 0;
}

