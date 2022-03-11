#include "ProtectedQueue.h"
#include "BasicQueue.h"
ProtectedQueue::ProtectedQueue()
{}
ProtectedQueue::~ProtectedQueue()
{}
void ProtectedQueue::add(int newelements)
{
	BasicQueue::add(newelements);
}
void ProtectedQueue::delet()
{
	BasicQueue::delet();
}
void ProtectedQueue::show()
{
	BasicQueue::show();
}
void ProtectedQueue::copy(ProtectedQueue& Queue_Copy)
{
	BasicQueue::copy(Queue_Copy);
}
void ProtectedQueue::merge(ProtectedQueue& Queue_Mergre)
{
	BasicQueue::merge(Queue_Mergre);
}
void ProtectedQueue::solution()
{
	setlocale(LC_ALL, "rus");
	element* ptr = this->getend();
	element* ptr2 = this->getend();
	int sum1 = 0;
	int counter = 0;
	int quantity = 0;
	int averag = 0;
	int answer = 0;
	while (ptr != nullptr)
		
	{
		sum1 += ptr->value;
		ptr = ptr->prev;
		counter++;
	}
	averag = sum1 / counter;
	while (ptr2 != nullptr)
	{
		if (ptr2->value < averag && ptr2->value > answer)
		{
			answer = ptr2->value;
		}
		ptr2 = ptr2->prev;
	}
	std::cout << "Сумма элементов:" << sum1 << std::endl;
	std::cout << "Колличество элементов:" << counter << std::endl;
	std::cout << "Среднее:" << averag << std::endl;
	std::cout << "Решение:" << answer << std::endl;
}
