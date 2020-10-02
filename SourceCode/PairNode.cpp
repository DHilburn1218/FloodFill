/**
@author Darrick Hilburn

Written for CS 250

PairNode.cpp
*/

#include"PairNode.h"

PairNode::PairNode() : next(nullptr)
{}

PairNode::PairNode(const OrderedPair& data) : data(data), next(nullptr)
{}

PairNode::PairNode(const OrderedPair& data, PairNode* next) : data(data),
															  next(next)
{}

void PairNode::setData(const OrderedPair& data)
{
	this->data = data;
}

void PairNode::setNext(PairNode* next)
{
	this->next = next;
}

OrderedPair PairNode::getData() const
{
	return data;
}

PairNode* PairNode::getNext()  const
{
	return next;
}

