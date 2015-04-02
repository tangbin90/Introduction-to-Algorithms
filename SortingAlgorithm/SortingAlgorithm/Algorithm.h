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
	//page 22 2.3-5
	int SortedSearch(unsigned int key);
	//page 22 2.3-6 improve insertsorting 
	void AdvancedInsertSorting(void);
	int RecursiveSearch(unsigned int key, int start, int end);

	unsigned int Array[ARRAY_SIZE];

private:
	
	void Merge(int start, int mid, int end);

};