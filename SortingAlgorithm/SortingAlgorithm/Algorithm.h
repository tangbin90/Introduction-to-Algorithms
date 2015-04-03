#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#define ARRAY_SIZE 10000

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
	int RecursiveSearch(unsigned int key, int start, int end);
	//page 22 2.3-6 improve insertsorting 
	void AdvancedInsertSorting(void);
	//page 22 2.3-7 s1+s2=x with time O(nlogn)
	int SumEqualsValue(int sum, int* p);
	

	unsigned int Array[ARRAY_SIZE];

private:
	int SortedSearchWithStartPosition(int start, int end, unsigned int key);
	void Merge(int start, int mid, int end);

};