#include "Queue.h"
#include <fstream>
Queue::Queue()
{
	size = 0;
	head = nullptr;
}
Queue::Queue(const Queue& _queue)
{
	this->size = _queue.size;
	Element* tmp = _queue.node;
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
Queue::~Queue()
{
}
void Queue::add(int elem)
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
void Queue::del()
{
	if (node->ptrnext == nullptr)
	{
		delete(node);
		head = nullptr;
	}
	else
	{
		Element* tmp = head->ptrnext;
		delete(head);
		head = tmp;
	}
	size--;
}
void Queue::show()
{
	std::cout << "Queue:" << std::endl;
	std::ofstream fout;
	fout.open("output.txt");
	fout << "Queue:" << std::endl;
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
