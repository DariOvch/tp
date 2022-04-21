#pragma once
#include "List.h"
class Stack : public List
{
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	void add(int) override;
	void del() override;
	void show() override;
};
