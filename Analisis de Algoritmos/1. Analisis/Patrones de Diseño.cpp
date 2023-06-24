//Patrones de Diseño
#include <iostream>
#include <cstdlib> 

template <typename Type>
class CVector
{
public:
	Type* m_pVect; 
	int m_nCount;
	int m_nMax; 
	int m_nDelta; 
	
	void Init(int delta) 
	{
		m_pVect = nullptr;
		m_nCount = 0;
		m_nMax = 0;
		m_nDelta = delta;
	}
	
	void Resize() 
	{
		m_pVect = static_cast<Type*>(std::realloc(m_pVect, sizeof(Type) * (m_nMax + m_nDelta)));
		m_nMax += m_nDelta; 
	}
	
public:
		CVector(int delta = 10)
		{
			Init(delta);
		}
		
		void Insert(Type elem) 
		{
			if (m_nCount == m_nMax) 
				Resize();
			
			m_pVect[m_nCount++] = elem; 
		}
		
		~CVector() 
		{
			std::free(m_pVect); 
		}
};

int main()
{
	
	
	CVector<int> intVector; 
	
	intVector.Insert(1);
	intVector.Insert(2);
	intVector.Insert(3);
	
	std::cout << "Elementos en intVector: ";
	for (int i = 0; i < intVector.m_nCount; i++)
	{
		std::cout << intVector.m_pVect[i] << " ";
	}
	std::cout << std::endl;
	
	CVector<double> doubleVector(5); 
	
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
