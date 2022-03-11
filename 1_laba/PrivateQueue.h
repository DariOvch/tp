#pragma once
#include "BasicQueue.h"
class PrivateQueue : private BasicQueue
{

public:
	PrivateQueue();
	~PrivateQueue();
	void add(int newelements);
	void delet();
	void show();
	void copy(PrivateQueue&);
	void merge(PrivateQueue&);
	void solution();
};
