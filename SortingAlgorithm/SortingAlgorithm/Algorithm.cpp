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
			memcpy((Array + k), pright + r, (n2 - r)*sizeof(int));//这里是关键！！大小乘以sizeof()int
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

int SortingAlgorithm::SortedSearch(unsigned int key)
{
	int end = sizeof(Array) / sizeof(Array[0])-1;
	int start = 0;
	int mid = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (Array[mid] < key)
		{
			start = mid+1;
		}
		else if (Array[mid] > key)
		{
			end = mid-1;
		}
		else
		{
			return mid;
		}
	}
	if (Array[start] == key)
		return start;
	return -1;

}

int SortingAlgorithm::RecursiveSearch(unsigned int key,int start, int end)
{
	if (start >= end)
		return -1;
	else
	{
		int mid = (start + end) / 2;
		if (Array[mid] > key)
		{
			return RecursiveSearch(key, start, mid-1);
		}
		else if (Array[mid] < key)
		{
			return RecursiveSearch(key, mid+1, end);
		}
		else
			return mid;
	}
}

void SortingAlgorithm::AdvancedInsertSorting()
{
	InitializeArray();
	for (int j = 1; j < sizeof(Array) / sizeof(Array[0]); j++)
	{
		int i = j - 1;
		unsigned int key = Array[j];
		int end = i;
		int start = 0;
		int mid = 0;
		while (start <= end)
		{
		    mid = (start + end) / 2;
			if (Array[mid] < key)
				start = mid+1;
			else if (Array[mid] > key)
				end = mid-1;
			else
			{
				for (int k = j; k > mid; k--)
				{
					Array[k] = Array[k-1];
				}
				break;
			}
		}
		if (Array[mid] >= key)
		{
			for (int k = j; k > start; k--)
			{
				Array[k] = Array[k - 1];
			}
			Array[mid] = key;
		}
		else
		{
			for (int k = j; k > start + 1; k--)
			{
				Array[k] = Array[k - 1];
			}
			Array[mid+1] = key;
		}
		Array[i + 1] = key;
	}
	DisplayArray();
}

int SortingAlgorithm::SumEqualsValue(int sum,int* p)
{
	InitializeArray();
	MergeSort(0, ARRAY_SIZE - 1);
	
	for (int j = 0; j < ARRAY_SIZE; j++)
	{
		int result=SortedSearchWithStartPosition(j + 1, ARRAY_SIZE-1,sum - Array[j]);
		if(result < 0)
			continue;
		else
		{
			*p = j;
			*(p + 1) = result;
			return 0;
		}
			
	}
	return -1;
}

int SortingAlgorithm::SortedSearchWithStartPosition(int start, int end, unsigned int key)
{
	int mid = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (Array[mid] < key)
		{
			start = mid + 1;
		}
		else if (Array[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;

}


