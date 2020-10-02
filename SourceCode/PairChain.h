/**
@author Darrick Hilburn

Written for CS 250

PairChain.h
*/

#ifndef PAIRCHAIN_H
#define PAIRCHAIN_H

#include"PairNode.h"
#include<vector>
using std::vector;

class PairChain
{
private:
	PairNode* headPtr;
	int itemCount;
	PairNode* getPointerTo(const OrderedPair& target);
public:
	PairChain();
	virtual ~PairChain();
	/**
	isEmpty checks if this PairChain is empty

	@return: True if itemCount is 0; false otherwise
	*/
	bool isEmpty();
	/**
	getHead returns the PairNode headPtr is pointing to.

	@return: Returns headPtr.
	*/
	PairNode* getHead();
	/**
	removeHead removes the current headPtr and reassigns it to the 
	next node in the list.
	*/
	bool removeHead();
	/**
	add adds a new PairNode to the front of the PairChain containing newEntry.

	@param newEntry: OrderedPair data field for a new PairNode.
	*/
	bool add(const OrderedPair& newEntry);
	/**
	clear removes all nodes in the PairChain and sets itemCount to 0.
	*/
	void clear();
	/**
	contains checks the PairChain to see if a node exists in the chain.

	@param entry: OrderedPair data that a node must contain in the chain.
	@return: Returns true if a PairNode's data is equal to entry; 
			 returns false otherwise.
	*/
	bool contains(const OrderedPair& entry);
	/**
	toVector passes the contents of this chain to a vector for output processing.

	@return: Returns a vector of OrderedPairs containing the items in this chain.
	*/
	vector<OrderedPair> toVector() const;
};


#endif