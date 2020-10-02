#include <iostream>
#include<chrono>
#include<thread>

#include "FloodFill.h"


using namespace std;

int main()
{
	chrono::milliseconds timespan_SHORT(2500);
	chrono::milliseconds timespan_LONG(5000);

	cout << "This program uses a queue to simulate an art program Flood Fill tool." << 
	endl << endl;
	this_thread::sleep_for(timespan_SHORT);

	cout << "FIRST TEST" << endl;
	FloodFill image(12);
	image.generateImage(12);
	image.displayImage();
	this_thread::sleep_for(timespan_LONG);

	image.fill(2, 2, 'X');
	cout << endl << endl;
	this_thread::sleep_for(timespan_SHORT);
	
	image.displayImage();
	this_thread::sleep_for(timespan_LONG);

	cout << endl << endl <<  "SECOND TEST" << endl;
	image.generateImage(24);
	image.displayImage();
	this_thread::sleep_for(timespan_LONG);

	image.fill(12, 12, 'Q');
	cout << endl << endl;
	this_thread::sleep_for(timespan_SHORT);
	
	image.displayImage();
	this_thread::sleep_for(timespan_LONG);

	cout << "Press Any Key to Exit";
	cin.ignore();
	return 0;
}