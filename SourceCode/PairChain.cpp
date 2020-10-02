/**
@author Darrick Hilburn

Written for CS 250

PairChain.cpp
*/

#include"PairChain.h"

PairChain::PairChain() : headPtr(nullptr), itemCount(0)
{}

PairChain::~PairChain()
{
	clear();
}

PairNode* PairChain::getPointerTo(const OrderedPair& target)
{
	bool found = false;
	PairNode* curPtr = headPtr;
	while (!found && curPtr != nullptr)
	{
		if (target.isEqual(curPtr->getData()))
			found = true;
		else
			curPtr = curPtr->getNext();
	}
	return curPtr;
}

bool PairChain::isEmpty()
{
	return itemCount == 0;
}

PairNode* PairChain::getHead()
{
	return headPtr;
}

bool PairChain::removeHead()
{
	bool removed = false;
	if (headPtr != nullptr)
	{
		PairNode* rmvPtr = headPtr;
		headPtr = headPtr->getNext();
		rmvPtr->setNext(nullptr);
		delete rmvPtr;
		itemCount--;
		removed = true;
	}
	return removed;
}

bool PairChain::add(const OrderedPair& newEntry)
{
	PairNode* newNode = new PairNode(newEntry);
	newNode->setNext(headPtr);
	headPtr = newNode;
	itemCount++;
	return true;
}

bool PairChain::contains(const OrderedPair& entry)
{
	return getPointerTo(entry) != nullptr;
}

void PairChain::clear()
{
	while (headPtr != nullptr)
	{
		removeHead();
	}
	itemCount = 0;
}

vector<OrderedPair> PairChain::toVector() const
{
	vector<OrderedPair> pVector;
	PairNode* curPtr = headPtr;
	for (int i = 0; i < itemCount; i++)
	{
		pVector.push_back(curPtr->getData());
		curPtr = curPtr->getNext();
	}
	return pVector;
}