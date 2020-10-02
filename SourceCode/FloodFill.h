/**
@author Darrick Hilburn

Written for CS 250

FlodFill.h
*/

#ifndef FLOODFILL_H
#define FLOODFILL_H

#include"PairChain.h"
#include"OrderedPair.h"

class FloodFill
{
private:
	char** imgPtr;	// 2D pointer representing an image
	int imgSize;	// Size of image; image is always square.
	/**
	makeImage is called by generateImage to build
	a new image for FloodFill to use.
	makeImage allocates heap memory for imgPtr based
	on imgSize.
	*/
	void makeImage();
	/**
	buildImage is called by makeImage to randomly fill
	imgPtr with a selection of characters.
	*/
	void buildImage();
	/**
	clear is used where needed to free the heap memory being
	used by imgPtr.
	*/
	void clear();
	/**
	onImage is called by fill when checking surrounding
	pixels of a pixel. 
	onImage checks that both the X and Y of an OrderedPair
	representing a pixel are on the image.
	That is, X and Y are both greater than 0 and less than
	the imgSize.
	*/
	bool onImage(int x, int y);
	/**
	getSurrounding creates a PairChain of OrderedPairs
	surrounding an OrderedPair.

	@param center: OrderedPair to find surrounding OrderedPairs of.
	@return: Returns a list of OrderedPairs containing center to be
	processed for flood filling.
	*/
	PairChain* getSurrounding(OrderedPair center);
public:
	FloodFill(int size);
	~FloodFill();
	/**
	generateImage allocates memory and a size for imgPtr and imgSize 
	respectively.

	@param size: value for imgSize
	*/
	void generateImage(int size);
	/**
	displayImage displays the contents of imgPtr to the screen.
	*/
	void displayImage();
	/**
	fill simulates a flood fill in imgPtr starting at the
	passed x and y values and changing the character at x,y
	currently in imgPtr to fillChar

	@param x: X-value of starting fill position
	@param y: Y-value of starting fill position
	@param fillChar: character that will be used to replace
					 character in passed x,y in imgPtr and
					 surrounding fill positions.
	*/
	void fill(int x, int y, char fillChar);
};

#endif