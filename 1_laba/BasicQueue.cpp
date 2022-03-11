#include"BasicQueue.h";
BasicQueue::BasicQueue()
{
	end = nullptr;
	counter = 0;
}
BasicQueue::~BasicQueue()
{
	element* ptr = end;
	while ((ptr = end) != nullptr)
	{
		end = end->prev;
		delete ptr;
	}
	end = nullptr;
}
void BasicQueue::add(int newelements)
{
	if (end == nullptr)
	{
		end = new element;
		end->prev = nullptr;
		end->value = newelements;
		
	}
	else
	{
		element* ptr = new element;
		ptr->prev = end;
		ptr->value = newelements;
		end = ptr;
	}
	counter++;
}
void BasicQueue::delet()
{
	setlocale(LC_ALL, "rus");
	element* ptr = end;
	if (ptr != nullptr)
		while (ptr->prev != nullptr && ptr->prev->prev != nullptr)
			ptr = ptr->prev;
	if (ptr != nullptr && ptr->prev != nullptr)
	{
		std::cout << std::endl << "Изъято: " << ptr->prev->value << std::endl;
		ptr->prev = nullptr;
		delete ptr->prev;
	}
	else if (ptr != nullptr && ptr->prev == nullptr)
	{
		std::cout << std::endl << "Изъято: " << ptr->value << std::endl;
		end = nullptr;
		delete end;
	}
	else
		std::cout << std::endl << "В очереди нет данных" << std::endl;
}
void BasicQueue::show()
{
	setlocale(LC_ALL, "rus");
	element* ptr = end;
	if (ptr != nullptr)
	{
		std::cout << std::endl << "Начало " << std::endl;
		while (ptr != nullptr)
		{
			std::cout << ptr->value << std::endl;
			ptr = ptr->prev;
		}
		if (ptr == nullptr)
			
			std::cout << "Конец" << std::endl;
	}
	else
		std::cout << std::endl << "В очереди нет данных" << std::endl;
}
void BasicQueue::copy(BasicQueue& Queue_Copy)
{
	setlocale(LC_ALL, "rus");
	element* tmp;
	element* copy = new element;
	element* copyend = copy;
	while (Queue_Copy.end != nullptr && Queue_Copy.end->prev != nullptr)
	{
		tmp = Queue_Copy.end;
		Queue_Copy.end = Queue_Copy.end->prev;
		tmp = nullptr;
		delete tmp;
		if (Queue_Copy.end->prev == nullptr)
		{
			delete Queue_Copy.end->prev;
			Queue_Copy.end = nullptr;
			delete Queue_Copy.end;
		}
	}
	element* ptr = end;
	if (ptr != nullptr)
	{
		while (ptr->prev != nullptr)
		{
			copy->value = ptr->value;
			ptr = ptr->prev;
			copy->prev = new element;
			copy = copy->prev;
			if (ptr->prev == nullptr)
			{
				copy->prev = nullptr;
				copy->value = ptr->value;
			}
		}
		Queue_Copy.end = copyend;
		Queue_Copy.counter = this->counter;
	}
	else
		std::cout << std::endl << "Нет данных для копирования";
}

void BasicQueue::merge(BasicQueue & Queue_Merge)
{
	element* tmp = end;
	element* ptr;
	element* Queue_Merge_Ptr;
	if (Queue_Merge.end == nullptr)
		copy(Queue_Merge);
	if (end != nullptr && Queue_Merge.end != nullptr)
	{
		end = new element;
		ptr = end;
		Queue_Merge_Ptr = Queue_Merge.end;
		while (Queue_Merge_Ptr != nullptr)
		{
			ptr->value = Queue_Merge_Ptr->value;
			if (Queue_Merge_Ptr->prev == nullptr)
			{
				ptr->prev = tmp;
				break;
			}
			ptr->prev = new element;
			ptr = ptr->prev;
			Queue_Merge_Ptr = Queue_Merge_Ptr->prev;
		}
	}
	else
		std::cout << std::endl << "Слияние невозможно";
	show();
}
element* BasicQueue::getend()
{
	return this->end;
}
