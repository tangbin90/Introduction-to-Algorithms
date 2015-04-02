// SortingAlgorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Algorithm.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double runningtime;
	clock_t start, finish;

	SortingAlgorithm SortClass;

	/*insert sorting page14*/
	start = clock();
	SortClass.InsertSorting();
	finish = clock();
	runningtime = double(finish - start)/CLOCKS_PER_SEC;
	cout << "InsertSorting using time: " << runningtime << " seconds" << endl;

	/*merge sorting page14*/
	SortClass.InitializeArray();
	start = clock();
	SortClass.MergeSort(0,ARRAY_SIZE-1);
	finish = clock();
	runningtime = double(finish - start) / CLOCKS_PER_SEC;
	cout << "mergesorting using time: " << runningtime << " seconds" << endl;

	/*binary search page 22 2.3-5*/
	unsigned int key = 123;
	start = clock();
	int position = SortClass.SortedSearch(key);
	finish = clock();
	runningtime = double(finish - start) / CLOCKS_PER_SEC;
	if (position < 0)
		cout << "Cannot find the key word!" << endl;
	else
		cout << "Key word " << key << " in posotion " << position << " of Array"<<endl;
	cout << "Using time: " << runningtime << " seconds."<<endl;

	start = clock();
	position = SortClass.RecursiveSearch(key,0,ARRAY_SIZE-1);
	finish = clock();
	runningtime = double(finish - start) / CLOCKS_PER_SEC;
	if (position < 0)
		cout << "Cannot find the key word!" << endl;
	else
		cout << "Recursive search Key word " << key << " in posotion " << position << " of Array" << endl;
	cout << "Using time: " << runningtime << " seconds." << endl;

	start = clock();
	SortClass.AdvancedInsertSorting();
	finish = clock();
	runningtime = double(finish - start) / CLOCKS_PER_SEC;
	cout << "AdvancedInsertSorting using time: " << runningtime << " seconds" << endl;
	
	getchar();

	return 0;
}

