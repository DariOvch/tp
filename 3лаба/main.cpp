#include<iostream>
#include<locale>
#include"List.h"
#include"Queue.h"
#include"Stack.h"
#include <fstream>
template <typename T>
void menu2(T& structure)
{
	std::ifstream fin("input.txt");
	char pick = '-';
	while (pick != '4')
	{
		fin >> pick;
		switch (pick)
		{
		case '1':
			int data;
			fin >> data;
			structure.add(data);
			break;
		case '2':
			structure.del();
			break;
		case'3':
			structure.show();
			break;
		}
	}
	fin.close();
	
}
template <typename T>
void menu(T& structure)
{
	std::ifstream fin("input.txt");
	char pick = '-';
	while (pick != '4')
	{
		std::cout << "1) Введите пожалуйста число" << std::endl;
		std::cout << "2) Удалить элемент " << std::endl;
		std::cout << "3) Вывести струкутру на экран " << std::endl;
		std::cin >> pick;
		switch (pick)
		{
		case '1':
			int data;
			std::cin >> data;
			structure.add(data);
			system("pause");
			system("cls");
			break;
		case '2':
			structure.del();
			system("pause");
			system("cls");
			break;
		case'3':
			structure.show();
			system("pause");
			system("cls");
			break;
		}
	}
}
int main(void)
{
	char pick = '0';
	char type = '0';
	int data = 0;
	List List_;
	Queue Queue_;
	Stack Stack_;
	setlocale(LC_ALL, "ru");
	std::cout << "Какую струкуру данных использовать ? " << std::endl;
	std::cout << "Список(L)" << std::endl;
	std::cout << "Очередь(Q)" << std::endl;
	std::cout << "Стек(S)" << std::endl;
	std::cin >> type;
	std::cout << "Откройте меню(С)" << std::endl; 

	char input_type;
	std::cin >> input_type;
	switch (type)
	{
	case 'L':
		if (input_type == 'C')
		{
			menu<List>(List_);
		}
		else {
			menu2<List>(List_);
		}
		break;
	case 'Q':
		if (input_type == 'C')
		{
			menu<Queue>(Queue_);
		}
		else {
			menu2<Queue>(Queue_);
		}
		break;
	case 'S':
		if (input_type == 'C')
		{
			menu<Stack>(Stack_);
		}
		else {
			menu2<Stack>(Stack_);
		}
		break;
	}
	return 0;
}
