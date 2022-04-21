#pragma once
#include"Element.h"
#include<iostream>
class List
{
public:
	Element* node;
	Element* head;
	int size;
	List();
	List(const List& _list);
	virtual void add(int data);
	virtual void del();
	virtual void show();
	virtual ~List();
};
