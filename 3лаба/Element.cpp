#include"Element.h"
Element::Element(int data, Element* ptrnext)
{
	this->value = data;
	this->ptrnext = ptrnext;
}
