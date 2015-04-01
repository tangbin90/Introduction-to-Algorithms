#include "stdafx.h"
#include "Algorithm.h"

void SortingAlgorithm::InsertSorting(void)
{
	InitializeArray();
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
void SortingAlgorithm::MergeSort(int start, int end)
{
	if (start < end)
	{
		int mid = (end + start) / 2;
		MergeSort(start, mid);
		MergeSort(mid+1, end);
		Merge(start, mid, end);
	}
}

void SortingAlgorithm::Merge(int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int *pleft = new int[n1];
	int *pright = new int[n2];
	for (int j = 0; j < n1; j++)
	{
		*(pleft + j) = Array[start + j];
	}
	for (int j = 0; j < n2; j++)
	{
		*(pright + j) = Array[mid + j+1];
	}
	int i = 0;
	int r = 0;
	for (int k = start; k <= end; k++)
	{
		if (i >= n1)
		{
			memcpy((Array + k), pright + r, (n2 - r)*sizeof(int));//�����ǹؼ�������С����sizeof()int
			break;
		}
		if (r >= n2)
		{
			memcpy((Array + k), pleft + i, (n1 - i)*sizeof(int));
			break;
		}
		
		if (*(pleft+i) <= *(pright+r))
		{
			Array[k] = *(pleft+i);	
			i++;
		}
		else
		{
			Array[k] = *(pright+r);
			r++;
		}
	}
	delete pleft;
	delete pright;
}

