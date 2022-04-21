#pragma once
#include "List.h"
class Queue : public List
{
public:
	Queue();
	Queue(const Queue&);
	~Queue();
	void add(int) override;
	void del() override;
	void show() override;
};
