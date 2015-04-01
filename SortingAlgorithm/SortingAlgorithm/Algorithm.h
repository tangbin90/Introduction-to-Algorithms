#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#define ARRAY_SIZE 50000

using namespace std;

class SortingAlgorithm
{
public:
	void InsertSorting(void);
	SortingAlgorithm() :start(), finish(){}

	unsigned int Array[ARRAY_SIZE];
	
	double runningtime(){
		_runningtime = double(finish - start) / CLOCKS_PER_SEC;
		return _runningtime;
	}

private:
	void InitializeArray(void);
	void DisplayArray(void);
	double _runningtime;
	clock_t start, finish;
};