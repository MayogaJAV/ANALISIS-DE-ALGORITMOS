//Programacion Modular
#include <iostream>
#include <cstdlib> 
void Resize(int*& rpVect, int& rnMax)
{
	const int delta = 10;
	rpVect = static_cast<int*>(std::realloc(rpVect, sizeof(int) * (rnMax + delta)));
	rnMax += delta; 
}
void Insert(int*& rpVect, int& rnCount, int& rnMax, int elem)
{
	if (rnCount == rnMax) 
		Resize(rpVect, rnMax); 
	
	rpVect[rnCount++] = elem; 
}



struct Vector
{
	int* m_pVect; 
	int m_nCount; 
	int m_nMax; 
	int m_nDelta; 
};

void Insert(Vector* pThis, int elem)
{
	if (pThis->m_nCount == pThis->m_nMax) 
		Resize(pThis->m_pVect, pThis->m_nMax); 
	
	pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector* pThis)
{
	const int delta = 10; 
	pThis->m_pVect = static_cast<int*>(std::realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + delta)));
	pThis->m_nMax += delta; 

int main()
{

	int* gVect = nullptr; 
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
	
	Vector dynamicVector;
	dynamicVector.m_pVect = nullptr; 
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

