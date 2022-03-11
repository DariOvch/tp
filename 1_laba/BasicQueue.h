#pragma once
#include<iostream>
#include<locale>
#include"Element.h"
class BasicQueue
{
	element* end;
	int counter;
public:
	BasicQueue();
	~BasicQueue();
	void add(int newelements);
	void delet();
	void show();
	void copy(BasicQueue& Queue_Copy);
	void merge(BasicQueue& Queue_Merge);
	void setend(element*);
	void solution();
	element* getend();
};
