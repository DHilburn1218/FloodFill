/**
@author Darrick Hilburn

Written for CS 250

PairNode.h
*/

#ifndef PAIRNODE_H
#define PAIRNODE_H

#include"OrderedPair.h"
class PairNode
{
private:
	OrderedPair data;	//OrderedPair data in this node.
	PairNode* next;		//Next PairNode this node points to.
public:
	PairNode();
	PairNode(const OrderedPair& data);
	PairNode(const OrderedPair& data, PairNode* next);
	/**
	setData assigns the OrderedPair data contained by this node.

	@param data: data to assign to this node's OrderedPair data.
	*/
	void setData(const OrderedPair& data);
	/**
	setNext assigns the node that next points to.

	@param next: PairNode that this next pointer will point to.
	*/
	void setNext(PairNode* next);
	/**
	getData gets the data contained in this node.

	@return: Returns the OrderedPair data contained in this node.
	*/
	OrderedPair getData() const;
	/**
	getNext returns the next node that this current node is pointing
	to.

	@return: Node next is pointing to.
	*/
	PairNode* getNext() const;
};

#endif
