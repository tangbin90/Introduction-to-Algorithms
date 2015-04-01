#include "stdafx.h"
#include "Algorithm.h"

void SortingAlgorithm::InsertSorting(void)
{
	InitializeArray();
	DisplayArray();
	start = clock();
	for (int j = 1; j < sizeof(Array) / sizeof(Array[0]); j++)
	{
		int i = j - 1;
		unsigned int key = Array[j];
		while (i >= 0 && Array[i] > key)
		{
			Array[i + 1] = Array[i];
			i--;
		}
		Array[i + 1] = key;
	}
	finish = clock();
	cout << "InsertSorting using time: " << runningtime() << " seconds"<<endl;
	DisplayArray();
}
void SortingAlgorithm::InitializeArray()
{
	srand((unsigned)time(NULL));
	for (int k = 0; k < sizeof(Array) / sizeof(Array[0]); k++)
	{
		Array[k] = rand();
	}
}

void SortingAlgorithm::DisplayArray()
{
	/*cout << "Array contents ";
	for (int k = 0; k < sizeof(Array) / sizeof(Array[0]); k++)
		cout << Array[k] << " ";
	cout << endl;*/
}


