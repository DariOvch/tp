#pragma once
#include"TreeElements.h"
#include<iostream>
#include<iomanip>
template<class Type>
class BinaryTree
{
private:
	TreeElements* m_root;
	Type m_size;
	void print_tree(TreeElements*, int indent = 0);
	void delete_tree(TreeElements*);
	void postorder(TreeElements*, int indent = 0);
public:
	BinaryTree();
	BinaryTree(int);
	~BinaryTree();
	void print1();
	void print2();
	bool find(int);
	void insert(int);
	void erase(int);
};
