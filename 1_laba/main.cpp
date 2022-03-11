#include <iostream>
#include "BasicQueue.h"
#include "PrivateQueue.h"
#include "ProtectedQueue.h"
#include "PublicQueue.h"
#define SIZE 10

int main()
{
	PrivateQueue Queue;
	PrivateQueue Queue_Copy;
	PrivateQueue warehouse[SIZE];

	int pick = 0;
	char* element = new char[10];
	int tmp = 0;
	int choise = 0;
	int counter = 0;
	do
	{
		setlocale(LC_ALL, "rus");
		system("cls");
		std::cout << "Выберите действие:\n1. Добавить элемент.\n2. Извлечь элемент.\n3. Вывести очередь на экран.";
		std::cout << "\n4. Задание.\n5. Копирование очереди.\n6. Слияние очередей.\n7. Выход.\nВаш выбор: ";
		std::cin >> pick;
		std::cin.ignore(1, '\n');
		switch (pick)
		{
		case 1:
			std::cout << "Введите значение: ";
			std::cin >> element;
			std::cin.ignore(1, '\n');
			Queue.add(atoi(element));
			break;
		case 2:
			Queue.delet();
			getchar();
			break;
		case 3:
			Queue.show();
			getchar();
			break;
		case 4:
			Queue.solution();
			getchar();
			break;
		case 5:

			Queue.copy(Queue_Copy);

			if (counter == SIZE) {
				PrivateQueue* warehouse = new PrivateQueue[SIZE + 1];
				
			}
			warehouse[counter] = Queue_Copy;
			counter++;
			std::cout << std::endl << "Готово!";
			getchar();
			break;

		case 6:

			while (tmp != counter)
			{
				std::cout << "-------------------" << tmp << "-------------------" << std::endl;
				warehouse[tmp].show();
				std::cout << "-------------------" << tmp << "" << std::endl << std::endl;
				tmp++;
			}

			std::cout << "Выберите очередь для слияния" << std::endl;
			std::cin >> choise;

			tmp = 0;
			Queue.merge(warehouse[choise]);

			getchar();
			break;


		}
	} while (pick != 7);
	return 0;
}
