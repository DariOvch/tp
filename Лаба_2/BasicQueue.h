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
	BasicQueue(float x);
	BasicQueue(const BasicQueue& x);
		~BasicQueue();
	friend BasicQueue& operator += (BasicQueue& ref, float newelements);//Добавление
	BasicQueue& operator -= (int x);//Удаление
	BasicQueue& operator + (BasicQueue& Queue_Merge);//Сложение
	friend BasicQueue& operator- (BasicQueue& ref, BasicQueue& Queue_Merge);//Вычетание
	BasicQueue& operator* (BasicQueue& Queue_Merge);//Умножение
	BasicQueue& operator/ (int x);//Деление
	void show();
	void copy(BasicQueue& Queue_Copy);
};
