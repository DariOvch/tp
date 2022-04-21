#include "Stack.h"
#include <fstream>
Stack::Stack()
{
	size = 0;
	head = nullptr;
}
Stack::Stack(const Stack& _stack)
{
	this->size = _stack.size;
	Element* tmp = _stack.node;
	node = new Element(tmp->value);
	this->head = node;
	Element* tmp2 = head;
	while (tmp->ptrnext != nullptr)
	{
		tmp = tmp->ptrnext;
		tmp2->ptrnext = new Element(tmp->value);
		tmp2 = tmp2->ptrnext;
	}
}

Stack::~Stack()
{
}
void Stack::add(int elem)
{
	if (head == nullptr)
	{
		node = new Element(elem);
		head = node;
	}
	else
	{
		Element* tmp = head;
		while (tmp->ptrnext != nullptr)
		{
			tmp = tmp->ptrnext;
		}
		tmp->ptrnext = new Element(elem);
	}
	size++;
}
void Stack::del()
{
	if (node->ptrnext == nullptr)
	{
		delete(node);
		head = nullptr;
	}
	else
	{
		Element* tmp = head;
		while (tmp->ptrnext->ptrnext != nullptr)
			tmp = tmp->ptrnext;
		delete(tmp->ptrnext);
		tmp->ptrnext = nullptr;
	}
	size--;
}
void Stack::show()
{
	std::cout << "Stack:" << std::endl;
	std::ofstream fout;
	fout.open("output.txt");
	fout << "Stack:" << std::endl;
	Element* tmp = head;
	while (tmp->ptrnext != nullptr)
	{
		std::cout << tmp->value << std::endl;
		fout << tmp->value << std::endl;
		tmp = tmp->ptrnext;
	}
	std::cout << tmp->value << std::endl;
	fout << tmp->value << std::endl;
	
		fout.close();
}
