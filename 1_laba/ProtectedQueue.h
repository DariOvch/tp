#pragma once
#include "BasicQueue.h"
class ProtectedQueue : protected BasicQueue
{
public:
	ProtectedQueue();
	~ProtectedQueue();
	void add(int newelements);
	void delet();
	void show();
    void copy(ProtectedQueue&);
	void merge(ProtectedQueue&);
	void solution();
};
