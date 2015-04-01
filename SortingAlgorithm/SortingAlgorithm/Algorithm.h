#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#define ARRAY_SIZE 100000

using namespace std;

class SortingAlgorithm
{
public:
	void DisplayArray(void);
	void InitializeArray(void);
	//page 14
	void InsertSorting(void);
	//page 17 
	void MergeSort(int start, int end);

	unsigned int Array[ARRAY_SIZE];

private:
	
	void Merge(int start, int mid, int end);

};