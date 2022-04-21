#pragma once
class Element
{
public:
	Element(int data = 0, Element* ptrnext = nullptr);
	Element* ptrnext;
	int value;
	//Element* head;
};
