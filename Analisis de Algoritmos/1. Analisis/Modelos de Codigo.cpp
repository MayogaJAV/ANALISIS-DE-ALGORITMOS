//Modelos de Codigo
#include <iostream>
#include <vector>

class CMyComplexDataStructure
{
	std::vector<float> m_container;
	
public:
	void Insert(float fVal)
	{
		m_container.push_back(fVal);
	}
	
	template <typename objclass>
		void sumone(objclass funobj)
	{
		typename std::vector<float>::iterator iter = m_container.begin();
		for (; iter != m_container.end(); iter++)
			funobj(*iter);
	}
};

template <typename T>
struct NODE
{
	T m_data;              // The data goes here
	struct NODE* m_pNext; // Pointer to the next node
	static long id;         // Node id
	
	NODE() // Constructor
		: m_data(0), m_pNext(nullptr)
	{
	}
};

template <typename T>
long NODE<T>::id = 0;

template <typename T>
class CLinkedList
{
private:
	struct NODE
	{
		T m_data;              // The data goes here
		struct NODE* m_pNext; // Pointer to the next Node
		// Some methods go here
	};
	
	NODE* m_pRoot; // Pointer to the root
	
public:
	CLinkedList() : m_pRoot(nullptr) {}
	
	void Insert(T data)
	{
		NODE* newNode = new NODE();
		newNode->m_data = data;
		newNode->m_pNext = nullptr;
		
		if (m_pRoot == nullptr)
		{
			m_pRoot = newNode;
		}
		else
		{
			NODE* currentNode = m_pRoot;
			while (currentNode->m_pNext != nullptr)
			{
				currentNode = currentNode->m_pNext;
			}
			currentNode->m_pNext = newNode;
		}
	}
};

template <typename T>
class CBinaryTree
{
private:
	struct NODE
	{
		T m_data;                 // The data goes here
		struct NODE* m_pLeft;    // Pointer to the left node
		struct NODE* m_pRight;   // Pointer to the right node
		// Some methods go here
	};
	
	NODE* m_pRoot; // Pointer to the root
	
public:
	CBinaryTree() : m_pRoot(nullptr) {}
	
	void Insert(T data)
	{
		NODE* newNode = new NODE();
		newNode->m_data = data;
		newNode->m_pLeft = nullptr;
		newNode->m_pRight = nullptr;
		
		if (m_pRoot == nullptr)
		{
			m_pRoot = newNode;
		}
		else
		{
			NODE* currentNode = m_pRoot;
			while (true)
			{
				if (data < currentNode->m_data)
				{
					if (currentNode->m_pLeft == nullptr)
					{
						currentNode->m_pLeft = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->m_pLeft;
					}
				}
				else
				{
					if (currentNode->m_pRight == nullptr)
					{
						currentNode->m_pRight = newNode;
						break;
					}
					else
					{
						currentNode = currentNode->m_pRight;
					}
				}
			}
		}
	}
};

int main()
{
	CMyComplexDataStructure complexDataStructure;
	complexDataStructure.Insert(1.5f);
	complexDataStructure.Insert(2.7f);
	complexDataStructure.Insert(3.9f);
	
	class funcobjclass
	{
	public:
		void operator()(float& objinstance)
		{
			objinstance++;
		}
	} funcObj;
	
	complexDataStructure.sumone(funcObj);
	
	CLinkedList<int> linkedList;
	linkedList.Insert(10);
	linkedList.Insert(20);
	linkedList.Insert(30);
	
	CBinaryTree<char> binaryTree;
	binaryTree.Insert('A');
	binaryTree.Insert('B');
	binaryTree.Insert('C');
	
	return 0;
}

