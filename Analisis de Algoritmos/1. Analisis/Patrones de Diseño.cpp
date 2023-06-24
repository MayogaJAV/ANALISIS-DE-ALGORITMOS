//Patrones de Dise�o
#include <iostream>
#include <cstdlib> // Necesario para la funci�n realloc

template <typename Type>
class CVector
{
public:
	Type* m_pVect; // Puntero al buffer
	int m_nCount; // Controla cu�ntos elementos se utilizan realmente
	int m_nMax; // Controla cu�ntos est�n asignados como m�ximo
	int m_nDelta; // Para controlar el crecimiento
	
	void Init(int delta) // Inicializar las variables privadas
	{
		m_pVect = nullptr;
		m_nCount = 0;
		m_nMax = 0;
		m_nDelta = delta;
	}
	
	void Resize() // Redimensionar el vector en caso de desbordamiento
	{
		m_pVect = static_cast<Type*>(std::realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta)));
		m_nMax += m_nDelta; // El valor m�ximo debe aumentar en delta
	}
	
public:
		CVector(int delta = 10) // Constructor
		{
			Init(delta);
		}
		
		void Insert(Type elem) // Insertar un nuevo elemento
		{
			if (m_nCount == m_nMax) // Verificar desbordamiento
				Resize(); // Redimensionar el vector antes de insertar elem
			
			m_pVect[m_nCount++] = elem; // Insertar el elemento al final de la secuencia
		}
		
		// Otros m�todos van aqu�
		
		~CVector() // Destructor
		{
			std::free(m_pVect); // Liberar memoria asignada al vector
		}
};

int main()
{
	// Ejemplo de uso de la clase CVector
	
	CVector<int> intVector; // Crear un vector de enteros
	
	intVector.Insert(1);
	intVector.Insert(2);
	intVector.Insert(3);
	
	std::cout << "Elementos en intVector: ";
	for (int i = 0; i < intVector.m_nCount; i++)
	{
		std::cout << intVector.m_pVect[i] << " ";
	}
	std::cout << std::endl;
	
	CVector<double> doubleVector(5); // Crear un vector de n�meros de punto flotante con delta = 5
	
	doubleVector.Insert(1.5);
	doubleVector.Insert(2.7);
	doubleVector.Insert(3.9);
	
	std::cout << "Elementos en doubleVector: ";
	for (int i = 0; i < doubleVector.m_nCount; i++)
	{
		std::cout << doubleVector.m_pVect[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
