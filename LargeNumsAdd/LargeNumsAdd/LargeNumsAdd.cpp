// LargeNumsAdd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <iostream>

using namespace std;
#define maxnum 100000000
unsigned int partsumresult[1024];
int depth = 0;
int iter = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int sum = 0;
	unsigned int a[10000];
	unsigned int b[10000];
	for (int i = 1; i <= 10000;i++)
	{
		a[i] = i;
		sum += i;
	}
}

unsigned int partsum(unsigned int* p,unsigned int length)
{
	if (depth == 10)
	{
		unsigned tempadd = 0;
		for (int i = 0; i < length; i++)
			tempadd += *(p + i);
		return tempadd;
	}
	else
	{
		int mid = length / 2;
		depth++;
		partsum(p, mid);
		partsum((p + mid), length - mid);
	}


}



