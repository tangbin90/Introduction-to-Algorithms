// 4-1FindMaxSubarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

#define MAX_INT ((unsigned)(-1)>>1)
#define MIN_INT (~MAX_INT)
struct array
{
	int low;
	int high;
	int value;
};
struct array FindMaximunSubarray(int low, int high);
struct array FindMaximunSubarrayLinear();
int Array[12] = { -12, -7, -2, -4, -3,-5,13,10,1923,-100,12,-3};
int _tmain(int argc, _TCHAR* argv[])
{	
	struct array arrayresult, arrayresultlinear;
	arrayresult = FindMaximunSubarray(0, 11);
	arrayresultlinear = FindMaximunSubarrayLinear();
	return 0;
}
struct array FindCrossingSubarray(int low, int mid, int high)
{
	int left_sum = MIN_INT;
	int sum = 0;
	int max_left = 0;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + Array[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = MIN_INT;
	sum = 0;
	int max_right = 0;
	for (int j = mid + 1; j <= high; j++)
	{
		sum = sum + Array[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}

	struct array array1;
	array1.low = max_left;
	array1.high = max_right;
	array1.value = right_sum + left_sum;
	return array1;
}
struct array FindMaximunSubarray(int low, int high)
{
	struct array arrays;
	if (high == low)
	{
		arrays.high = high;
		arrays.low = low;
		arrays.value = Array[low];
		return arrays;
	}else
	{
		int mid = (low + high) / 2;
		struct array result = FindMaximunSubarray(low, mid);
		struct array result1 = FindMaximunSubarray(mid+1, high);
		struct array result2 = FindCrossingSubarray(low, mid, high);
		if (result.value <= result1.value)
		{
			if (result1.value <= result2.value)
			{
				return result2;
			}
			else
			{
				return result1;
			}
		}
		else
		{
			if (result.value > result2.value)
				return result;
			else
				return result2;
		}
	 }
}

struct array FindMaximunSubarrayLinear()
{
	int length = sizeof(Array) / sizeof(int);
	int sum=0;
	array result;
	result.high = 0;
	result.low = 0;
	result.value = Array[0];
	for (int i = 0; i < length; i++)
	{
		int sum = 0;
		if (Array[i] <= 0)
			continue;
		for (int j = i; j >= 0; j--)
		{
			sum += Array[j];
			if (sum > result.value)
			{
				result.value = sum;
				result.high = i;
				result.low = j;
			}
		}
	}
	return result;
}
