#include <iostream>
using namespace std;

template<typename T, int size = 50>
class Stack
{
private:
	T* m_pData;
	int m_stackPointer;

public:
	Stack()
		: m_stackPointer(-1)
	{
		if (size <= 0)
			return;

		m_pData = new T[size];
	}

	bool Push(T data)
	{
		if (m_stackPointer >= size - 1)
			return false;

		++m_stackPointer;
		*(m_pData + m_stackPointer) = data;
		
		return true;
	}
	
	bool Pop()
	{
		if (m_stackPointer <= -1)
		{
			cout << "stack underFlow-" << endl;
			return false;
		}

		--m_stackPointer;
		return true;
	}
};


void main()
{
	Stack<short> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(1356);

	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
	cout << stack.Pop() << endl;
}