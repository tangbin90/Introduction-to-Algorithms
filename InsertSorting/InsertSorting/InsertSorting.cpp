// InsertSorting.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int A[10] = { 31, 41, 59, 4, 5, 6, 7, 8, 9, 0 };
	for (int i = 1; i < sizeof(A)/sizeof(int); i++)
	{
		int temp = A[i];
		int j = i-1;
		while (j>=0 && A[j] > temp)
		{
			
			A[j+1] = A[j];
			j--;
		}
		A[j + 1] = temp;
		
	}
	for (int i = 0; i < sizeof(A)/sizeof(int); i++)
		std::cout << A[i]<<" ";
	return 0;
}

