#include <iostream>
#include <cstdlib>
#include "BasicQueue.h"
#include "Time.h"
#define SIZE 10
int main()
{
	BasicQueue Queue;
	BasicQueue Queue_Copy;
	BasicQueue warehouse[SIZE];
	Time clock;

	char pick = 0;
	char* element = new char[10];
	int tmp = 0;
	int choise = 0;
	int counter = 0;


		do
		{
			setlocale(LC_ALL, "rus");
			system("cls");
			std::cout << "Выберите действие:\n1. Добавить элемент.\n2. Извлечь элемент.\n3. Вывести очередь на экран.";
				std::cout << "\n4. Задание.\n5. Копирование очереди.\n6. Сложение 2 очередей.\n7. Вычетания очередей.";
				std::cout << "\n8. Умноженеи 2 очередей.\n9. Деление очереди на число.\n0. Выход.\nВаш выбор : ";
				std::cin >> pick;
			std::cin.ignore(1, '\n');
			switch (pick)
			{
				// Добавление
			case '1':
				std::cout << "Введите значение: ";
				std::cin >> element;
				std::cin.ignore(1, '\n');
				Queue += (atof(element));
				break;

				// Извлечение 
			case '2':
				Queue -= 1;
				getchar();
				break;
				//Вывод очереди на экран 
			case '3':
				Queue.show();
				getchar();
				break;
				//Задание 1 
			case '4':
				std::cout << "Выберите действие:\n1. Префиксная форма.\n2. Постфиксная форма."
					<< std::endl;
				std::cin >> choise;
				if (choise == 1)
				{
					std::cout << "Выберите действие:\n1. Часы.\n2. Минуты.\n3. Секунды." <<
						std::endl;
					std::cin >> choise;
					if (choise == 1)//Выбор часов 
					{
						
							std::cout << "Выберите действие:\n1. Увеличить.\n2. Уменьшить." << std::endl;
						std::cin >> choise;
						if (choise == 1)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							for (int i = 0; i < 3600; i++) { ++clock; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						if (choise == 2)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							for (int i = 0; i < 3600; i++) { --clock; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
					}
					if (choise == 2)//Выбор минут
					{
						std::cout << "Выберите действие:\n1. Увеличить.\n2. Уменьшить." << std::endl;;
						std::cin >> choise;
						if (choise == 1)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							for (int i = 0; i < 60; i++) { ++clock; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						if (choise == 2)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							for (int i = 0; i < 60; i++) { --clock; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
							
						}
					}
					if (choise == 3)//Выбор секунд
					{
						std::cout << "Выберите действие:\n1. Увеличить.\n2. Уменьшить." << std::endl;;
						std::cin >> choise;
						if (choise == 1)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							++clock;
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						if (choise == 2)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							--clock;
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
					}
				}
				// Второй вариант работы
				if (choise == 2)
				{
					std::cout << "Выберите действие:\n1. Часы.\n2. Минуты.\n3. Секунды." <<
						std::endl;
					std::cin >> choise;
					if (choise == 1)//Выбор часов 
					{
						std::cout << "Выберите действие:\n1. Увеличить.\n2. Уменьшить." << std::endl;
						std::cin >> choise;
							if (choise == 1)
							{
								std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
									std::endl;
								std::cout << "Введите значение" << " ";
								std::cin >> choise;
								for (int i = 0; i < 3600 * choise; i++) { clock++; }
								std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
									std::endl;
								system("pause");
							}
						if (choise == 2)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							std::cout << "Введите значение" << " ";
							std::cin >> choise;
							for (int i = 0; i < 3600 * choise; i++) { clock--; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						if (choise == 0)
						{
							break;
						}
					}
					if (choise == 2)//Выбор минут
					{
						std::cout << "Выберите действие:\n1. Увеличить.\n2. Уменьшить." << std::endl;
						std::cin >> choise;
						if (choise == 1)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							std::cout << "Введите значение" << " ";
							std::cin >> choise;
							for (int i = 0; i < 60 * choise; i++) { clock++; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						
							if (choise == 2)
							{
								std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
									std::endl;
								std::cout << "Введите значение" << " ";
								std::cin >> choise;
								for (int i = 0; i < 60 * choise; i++) { clock--; }
								std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
									std::endl;
								system("pause");
							}
						if (choise == 0)
						{
							break;
						}
					}
					if (choise == 3)//Выбор секунд
					{
						std::cout << "Выберите действие:\n1. Увеличить.\n2. Уменьшить." << std::endl;
						std::cin >> choise;
						if (choise == 1)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							std::cout << "Введите значение" << " ";
							std::cin >> choise;
							for (int i = 0; i < choise; i++) { clock++; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						if (choise == 2)
						{
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							std::cout << "Введите значение" << " ";
							std::cin >> choise;
							for (int i = 0; i < choise; i++) { clock--; }
							std::cout << clock.seconds << " " << clock.minutes << " " << clock.hours <<
								std::endl;
							system("pause");
						}
						if (choise == 0)
						{
							break;
						}
						
					}
				}


				// Создание копии очереди 
			case '5':
				Queue.copy(Queue_Copy);
				if (counter == SIZE)
				{
					BasicQueue* warehouse = new BasicQueue[SIZE + 1];
				}
				warehouse[counter] = Queue_Copy;
				counter++;
				std::cout << std::endl << "Готово!";
				getchar();
				break;
				// Cложение 2 очередей 
			case '6':
				while (tmp != counter)
				{
					std::cout << "##############" << tmp << "###############" << std::endl;
					warehouse[tmp].show();
					std::cout << "##############" << tmp << "###############" << std::endl <<
						std::endl;
					tmp++;
				}
				std::cout << "Выберите очередь для сложения" << std::endl;
				std::cin >> choise;
				if (choise < 0 || choise > counter)
				{
					std::cout << "Некоректное значение" << std::endl;
					system("pause");
				}
				else {
					Queue + warehouse[choise];
					tmp = 0;
					system("pause");
					break;
				}

				// Вычетаниее 2 очередей 
			case '7':
				while (tmp != counter)
				{
					std::cout << "##############" << tmp << "###############" << std::endl;
					
						warehouse[tmp].show();
					std::cout << "##############" << tmp << "###############" << std::endl <<
						std::endl;
					tmp++;
				}
				std::cout << "Выберите очередь для вычетания" << std::endl;
				std::cin >> choise;
				if (choise < 0 || choise > counter)
				{
					std::cout << "Некоректное значение" << std::endl;
					system("pause");
				}
				else {
					tmp = 0;
					Queue - warehouse[choise];
					system("pause");
					break;
				}

				break;

				// Поэлементное умножения очередей друг на друга
			case '8':
				while (tmp != counter)
				{
					std::cout << "##############" << tmp << "###############" << std::endl;
					warehouse[tmp].show();
					std::cout << "##############" << tmp << "###############" << std::endl <<
						std::endl;
					tmp++;
				}
				std::cout << "Выберите очередь для вычетания" << std::endl;
				std::cin >> choise;
				if (choise < 0 || choise > counter)
				{
					std::cout << "Некоректное значение" << std::endl;
					system("pause");
				}
				else {
					tmp = 0;
					Queue* warehouse[choise];
					system("pause");
					break;
				}

					break;

				//деления очереди на число
			case '9':

				std::cout << "Ввведите число для деления " << std::endl;
				std::cin >> choise;
				if (choise == 0)
				{
					std::cout << "Некоректное значение" << std::endl;
					system("pause");
				}
				else {
					Queue / choise;
					system("pause");
					break;
				}

				break;
			}

		} while (pick != '0');

		return 0;
}
