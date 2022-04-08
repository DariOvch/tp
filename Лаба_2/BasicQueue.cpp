#include"BasicQueue.h";
BasicQueue::BasicQueue(float x)
{
	end = nullptr;
	counter = 0;
	*this += x;
}
BasicQueue::BasicQueue(const BasicQueue& x)
{
	end = nullptr;
	counter = 0;
	element* ptr = x.end;
	while (ptr != nullptr)
	{
		*this += ptr->value;
		ptr = ptr->prev;
	}
}
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
BasicQueue& operator+= (BasicQueue& ref, float newelements)
{

	if (ref.end == nullptr)
	{
		ref.end = new element;
		ref.end->prev = nullptr;
		ref.end->value = newelements;
	}
	else
	{
		element* ptr = new element;
		ptr->prev = ref.end;
		ptr->value = newelements;
		ref.end = ptr;
	}
	ref.counter++;
	return ref;
}
BasicQueue& BasicQueue:: operator-= (int x)
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

	this->counter--;
	return *this;
}
void BasicQueue::show()
{
	setlocale(LC_ALL, "rus");
	element* ptr = end;
	if (ptr != nullptr)
	{
		std::cout << std::endl << "Конец " << std::endl;
		while (ptr != nullptr)
		{
			std::cout << ptr->value << std::endl;
			ptr = ptr->prev;
		}
		if (ptr == nullptr)
			std::cout << "Начало" << std::endl;
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
BasicQueue& BasicQueue:: operator+ (BasicQueue& Queue_Merge)
{

	element** bufer = new element * [this->counter];
	element* tmp;
	tmp = Queue_Merge.end;
	for (int i = Queue_Merge.counter - 1; i > -1; i--)
	{
		bufer[i] = tmp;
		tmp = tmp->prev;
	}

	element** bufer1 = new element * [this->counter];

	tmp = this->end;
		for (int i = this->counter - 1; i > -1; i--)
		{
			bufer1[i] = tmp;
			tmp = tmp->prev;
		}

	for (int i = 0; i < this->counter; i++)
	{
		bufer1[i]->value += bufer[i]->value;
	}
	end = bufer1[Queue_Merge.counter - 1];
	show();
	delete[] bufer;
	return *this;
}
BasicQueue& BasicQueue:: operator* (BasicQueue& Queue_Merge)
{
	element** bufer = new element * [this->counter];
	element* tmp;
	tmp = Queue_Merge.end;
	for (int i = Queue_Merge.counter - 1; i > -1; i--)
	{
		bufer[i] = tmp;
		tmp = tmp->prev;
	}
	element** bufer1 = new element * [this->counter];
	tmp = this->end;
	for (int i = this->counter - 1; i > -1; i--)
	{
		bufer1[i] = tmp;
		tmp = tmp->prev;
	}
	for (int i = 0; i < this->counter; i++)
	{
		bufer1[i]->value *= bufer[i]->value;
	}
	show();
		return *this;
}
BasicQueue& operator- (BasicQueue& ref, BasicQueue& Queue_Merge)
{
	element** bufer = new element * [Queue_Merge.counter];
	element* tmp;
	tmp = Queue_Merge.end;
	for (int i = Queue_Merge.counter - 1; i > -1; i--)
	{
		bufer[i] = tmp;
		tmp = tmp->prev;
	}
	element** bufer1 = new element * [Queue_Merge.counter];
	tmp = ref.end;
	for (int i = ref.counter - 1; i > -1; i--)
	{
		bufer1[i] = tmp;
		tmp = tmp->prev;
	}
	for (int i = 0; i < ref.counter; i++)
	{
		bufer1[i]->value -= bufer[i]->value;
	}
	ref.end = bufer1[ref.counter - 1];

	return ref;
}
BasicQueue& BasicQueue:: operator/ (int x)
{
	element* ptr = end;


	while (ptr != nullptr)
	{
		ptr->value /= x;
		ptr = ptr->prev;
	}

	show();
		return *this;
}
