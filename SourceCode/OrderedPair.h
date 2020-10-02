/**
@author Darrick Hilburn

Written for CS 250

OrderedPair.h
*/

#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

class OrderedPair
{
private:
	int x, y;	// Coordinate position of an OrderedPair object
public:
	OrderedPair();
	OrderedPair(int x, int y);
	/**
	setPair uses the x and y values to assign itself

	@param x: X-value to set for this OrderedPair's x-value
	@param y: Y-value to set for this OrderedPair's y-value
	*/
	void setPair(int x, int y);
	/**
	getX returns this OrderedPair's X-value

	@return: Returns this OrderedPair's X-value
	*/
	int getX() const;
	/**
	getY returns this OrderedPair's Y-value

	@return: Returns this OrderedPair's Y-value
	*/
	int getY() const;
	/**
	isEqual compares this OrderedPair with another OrderedPair to see
	if their values are equal.

	@return: Returns True if this and another OrderedPair have the same 
			 x and y values; Returns false otherwise.
	*/
	bool isEqual(const OrderedPair& other) const;
	/**
	displayPair is primarily for debugging purposes.
	displayPair displays to output the current x and y values
	of this OrderedPair.
	*/
	void displayPair();
};

#endif
