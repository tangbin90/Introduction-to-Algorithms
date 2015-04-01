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

	getchar();

	return 0;
}

