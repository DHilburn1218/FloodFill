/**
@author Darrick Hilburn

Written for CS 250

FloodFill.cpp
*/
#include"FloodFill.h"
#include<iostream>
#include<queue>
#include<stdlib.h>
#include<time.h>

using namespace std;

/** STRUCTORS **/
FloodFill::FloodFill(int size) : imgSize(size)
{}

FloodFill::~FloodFill()
{
	clear();
}


/** ADDED HELPER METHODS **/
void FloodFill::clear()
{
	for (int i = 0; i < imgSize; i++)
		delete[] imgPtr[i];
	delete[] imgPtr;
	imgPtr = nullptr;
	imgSize = 0;
}

void FloodFill::makeImage()
{
	imgPtr = new char*[imgSize];
	for (int i = 0; i < imgSize; i++)
		imgPtr[i] = new char[imgSize];
	buildImage();
}

void FloodFill::buildImage()
{
	srand((unsigned int)time(nullptr));
	char buildChars[] = {'c', 'm', 'y', 'k' };

	for (int i = 0; i < imgSize; i++)
		for (int j = 0; j < imgSize; j++)
		{
			int charIndex = rand() % 4;
			imgPtr[i][j] = buildChars[charIndex];
		}
}

bool FloodFill::onImage(int x, int y)
{
	return(x >= 0 && x < imgSize && y >= 0 && y < imgSize);
}

PairChain* FloodFill::getSurrounding(OrderedPair center)
{
	PairChain* surrounding = new PairChain();

	for(int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			surrounding->add((OrderedPair(center.getX() + i,
										  center.getY() + j)));
	return surrounding;
}

/** REQUIRED PUBLIC METHODS **/

void FloodFill::generateImage(int size)
{
	if (imgPtr != nullptr)
		clear();
	if (size < 1)
		size = 1;
	imgSize = size;
	makeImage();
}

void FloodFill::fill(int x, int y, char fillChar)
{
	queue<OrderedPair> pairQueue;
	PairChain processed;
	char oldChar = imgPtr[x][y];
	OrderedPair initPos(x, y);
	
	cout << "Beginning at ";
	initPos.displayPair();
	cout << "I will flood fill and replace " << oldChar 
		 << " with " << fillChar << endl;

	pairQueue.push(initPos);	// Make initPos first queue entry.
	while (!pairQueue.empty())	// Loop based on the Processing Queue.
	{
		// Get and pop the first entry in the queue
		OrderedPair curPair = pairQueue.front();
		pairQueue.pop();
		// Process curPair
		imgPtr[curPair.getX()][curPair.getY()] = fillChar;
		processed.add(curPair);		
		// Get Pixels surrounding curPair
		PairChain* surrounding = getSurrounding(curPair);
		// Try to add surrounding pixels back into queue
		PairNode* curPtr = surrounding->getHead();
		while (curPtr != nullptr)
		{
			/**
			Explanation of if block:

			IF the current position is on the image AND
			The current position has not been processed AND
			The current position on image has the character to replace
			*/
			if (onImage(curPtr->getData().getX(), curPtr->getData().getY()) &&			
				!processed.contains(curPtr->getData()) &&								
				imgPtr[curPtr->getData().getX()][curPtr->getData().getY()] 
																== oldChar)
			{
				// Add current position to the queue
				pairQueue.push(curPtr->getData());
			}
			curPtr = curPtr->getNext();
		}
	}
}

void FloodFill::displayImage()
{
	cout << "  ";
	for (int i = 0; i < imgSize; i++)
	{
		cout << (i % 10) << " ";
	}
	cout << endl;
	for (int i = 0; i < imgSize; i++)
	{
		for (int j = -1; j < imgSize; j++)
		{
			if (j == -1)
				cout << (i % 10) << " ";
			else
				cout << imgPtr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

