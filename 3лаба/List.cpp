#include "List.h"
#include <fstream>
List::List()
{
	size = 0;
	head = nullptr;
}
List::List(const List& _list)
{
	this->size = _list.size;
	Element* tmp = _list.node;
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
List::~List()
{
	Element* tmp = head;
	Element* tmp2;
	if (tmp->ptrnext == nullptr) return;
	while (tmp->ptrnext->ptrnext != nullptr)
	{
		tmp2 = tmp;
		tmp = tmp->ptrnext->ptrnext;
		delete(tmp);
	}
	delete(head);
}

void List::add(int data)
{
	if (head == nullptr)
	{
		node = new Element(data);
		head = node;
	}
	else
	{
		Element* tmp = head;
		while (tmp->ptrnext != nullptr)
		{
			tmp = tmp->ptrnext;
		}
		tmp->ptrnext = new Element(data);
	}
	size++;
}
void List::del()
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
void List::show()
{
	std::ofstream fout;
	fout.open("output.txt");
	std::cout << "Список:" << std::endl;
	fout << "Список:" << std::endl;
	
		Element * tmp = head;
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
