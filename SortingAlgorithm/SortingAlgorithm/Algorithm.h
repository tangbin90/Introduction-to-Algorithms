#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

class SortingAlgorithm
{
public:
	void InsertSorting(void);
	SortingAlgorithm() :start(), finish(){}

	unsigned int Array[100000];
	clock_t start, finish;
	double runningtime;
private:
	void InitializeArray(void);
	void DisplayArray(void);
};