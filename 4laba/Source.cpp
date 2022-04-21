#include<iostream>
#include"BinaryTree.h"
#include<locale>

template<typename Type>
void SearchArray(Type A = 0)
{
	int counter = 0;
	int element = 0;
	int size = 30 + rand() % 71;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 101;
		std::cout << "Array[" << i << "]" << "=" << array[i] << std::endl;
	}
	try
	{
		std::cout << "Введите элемент для поиска" << std::endl;
		std::cin >> element;

		if
			(std::cin.fail())
		{
			throw "error";
		}
	}
	catch (const char* error)
	{
		std::cout << "Не удалось считать переменную" << std::endl;
		system("pause");
		std::cin.ignore(32767, '\n');
		std::cin.clear();
		std::cin >> element;
	}
	for (int i = 0; i < size; i++)
	{
		if (element == array[i])
		{
			std::cout << "Array[" << i << "]" << "=" << array[i] << std::endl;
		}
	}
}

template<typename Type >
BinaryTree<Type>::BinaryTree() : m_size(1) {};

template<typename Type >
inline BinaryTree<Type>::BinaryTree(int key)
{
	m_root = new TreeElements(key);
	m_size = 1;
}

template<typename Type >
inline BinaryTree<Type>::~BinaryTree()
{
	delete_tree(m_root);
}

template<typename Type >
inline void BinaryTree<Type>::delete_tree(TreeElements* curr)
{
	if (curr)
	{
		delete_tree(curr->m_left);
		delete_tree(curr->m_right);
		delete curr;
	}
}

template<typename Type >
inline void BinaryTree<Type>::print1()
{
	TreeElements* tmp_root = m_root;
	print_tree(tmp_root);
	std::cout << std::endl;
}

template<typename Type >
inline void BinaryTree<Type>::print_tree(TreeElements* curr, int indent)//Прямой
{
	if (curr) // Проверка на ненулевой указатель
	{
		std::cout << curr->m_data << " ";
		print_tree(curr->m_left);
		print_tree(curr->m_right);
	}
}

template<typename Type >
inline void BinaryTree<Type>::postorder(TreeElements* curr, int indent)//Концевая
{
	if (curr) // Проверка на ненулевой указатель
	{
		print_tree(curr->m_left);
		print_tree(curr->m_right);
		std::cout << curr->m_data << " ";
	}
}

template<typename Type >
inline void BinaryTree<Type>::print2()
{
	TreeElements* tmp_root = m_root;
	postorder(tmp_root);
	std::cout << std::endl;
}

template<typename Type >
inline bool BinaryTree<Type>::find(int key)
{
	TreeElements* curr = m_root;
	while (curr && curr->m_data != key)
	{
		if (curr->m_data > key)
			curr = curr->m_left;
		else
			curr = curr->m_right;
	}
	return curr != nullptr;
}

template<typename Type >
inline void BinaryTree<Type>::insert(int key)
{
	TreeElements* curr = m_root;
	while (curr && curr->m_data != key)
	{
		if (curr->m_data > key && curr->m_left == nullptr)
		{
			curr->m_left = new TreeElements(key);
			++m_size;
			return;
		}
		if (curr->m_data < key && curr->m_right == nullptr)
		{
			curr->m_right = new TreeElements(key);
			++m_size;
			return;
		}
		if (curr->m_data > key)
			curr = curr->m_left;
		else
			curr = curr->m_right;
	}
}

template<typename Type >
inline void BinaryTree<Type>::erase(int key)
{
	TreeElements* curr = m_root;
	TreeElements* parent = NULL;
	while (curr && curr->m_data != key)
	{
		parent = curr;
		if (curr->m_data > key)
		{
			curr = curr->m_left;
		}
		else
		{
			curr = curr->m_right;
		}
	}
	if (!curr)
		return;
	if (curr->m_left == NULL)
	{
		// Вместо curr подвешивается его правое поддерево
		if (parent && parent->m_left == curr)
			parent->m_left = curr->m_right;
		if (parent && parent->m_right == curr)
			parent->m_right = curr->m_right;
		--m_size;
		delete curr;
		return;
	}
	if (curr->m_right == NULL)
	{
		// Вместо curr подвешивается его левое поддерево
		if (parent && parent->m_left == curr)
			parent->m_left = curr->m_left;
		if (parent && parent->m_right == curr)
			parent->m_right = curr->m_left;
		--m_size;
		delete curr;
		return;
	}
	// У элемента есть два потомка, тогда на место элемента поставим
	// наименьший элемент из его правого поддерева
	TreeElements* replace = curr->m_right;
	while (replace->m_left)
		replace = replace->m_left;
	int replace_value = replace->m_data;
	erase(replace_value);
	curr->m_data = replace_value;
}
int main(void)
{
	char pick = '0';
	int data = 0;
	int root = 0;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите корень" << std::endl;
	std::cin >> root;
	BinaryTree<int> Structure(root);
	system("cls");
	while (pick != '7')
	{
	std::cout << "1)Добавить:" << std::endl;
	std::cout << "2)Удалить:" << std::endl;
	std::cout << "3)Поиск:" << std::endl;
	std::cout << "4)Печать дерева(Прямая):" << std::endl;
	std::cout << "5)Печать дерева(Концевая):" << std::endl;
	std::cout << "6)Задание 1:" << std::endl;
	std::cout << "7)Выход:" << std::endl;
	std::cin >> pick;
	switch (pick)
	{
	case '1':
		std::cout << "Ввведите значение для дoбавление:" << std::endl;
		std::cin >> data;
		Structure.insert(data);
		system("pause");
		system("cls");
		break;
	case '2':
		std::cout << "Ввведите значение которое хотите удалить:" << std::endl;
		std::cin >> data;
		Structure.erase(data);
		system("pause");
		system("cls");
		break;
	case '3':
		std::cout << "Ввведите значение которое хотите найти:" << std::endl;
		std::cin >> data;
		bool status;
		status = Structure.find(data);
		if (status == true)
		{
			std::cout << "Такой элемент существует" << std::endl;
		}
		else 
		{ 
			std::cout << "Такого элемента не существует" << std::endl; 
		}
		system("pause");
		system("cls");
		break;
	case '4':
		system("cls");
		Structure.print1();
		break;
	case '5':
		system("cls");
		Structure.print2();
		break;
	case '6':
		SearchArray(0);
		break;
	case '7':
		std::cout << "BYE" << std::endl;
		break;
	default:
		std::cout << "Вы ввели не коректное значение" << std::endl;
		break;
		}
	}
	return 0;
}
