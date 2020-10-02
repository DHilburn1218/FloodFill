/**
@author Darrick Hilburn

Written for CS 250

OrderedPair.cpp
*/

#include"OrderedPair.h"
#include<iostream>
using std::cout;
using std::endl;

OrderedPair::OrderedPair() : x(0), y(0)
{}

OrderedPair::OrderedPair(int x, int y) : x(x), y(y)
{}

void OrderedPair::setPair(int x, int y)
{
	this->x = x;
	this->y = y;
}

int OrderedPair::getX() const
{
	return x;
}

int OrderedPair::getY() const
{
	return y;
}

bool OrderedPair::isEqual(const OrderedPair& other) const
{
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

void OrderedPair::displayPair()
{
	cout << "(" << x << ", " << y << ")" << endl;
}