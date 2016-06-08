// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

enum{LEFT = -1, MIDDLE, RIGHT};



int arr[] = 
{
	75,
	95, 64,
	17, 47, 82,
	18, 35, 87, 10,
	20, 04, 82, 47, 65,
	19, 01, 23, 75, 03, 34,
	88, 02, 77, 73, 07, 63, 67,
	99, 65, 04, 28, 06, 16, 70, 92,
	41, 41, 26, 56, 83, 40, 80, 70, 33,
	41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
	53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
	70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
	91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
	63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
	04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23
};

int rowStart(int level)
{
	int count = 0;
	for (int i = 1; i < level; ++i)
		count += i;
	return count;
}

int biggest_way(int level, int pos)
{
	if (level == 1)
		return arr[0];

	int row_start = rowStart(level)-1;
	int sum = arr[row_start + pos];

	if (pos == 1)
	{
		sum += max(biggest_way(level - 1, pos + RIGHT),
			biggest_way(level - 1, pos + MIDDLE));
	}
	else if (pos == level)
	{
		sum += biggest_way(level - 1, pos + LEFT);
	}
	else if (pos == (level - 1))
	{
		sum += max(biggest_way(level - 1, pos + LEFT),
			biggest_way(level - 1, pos + MIDDLE));
	}
	else
	{
		int temp = max(biggest_way(level - 1, pos + LEFT),
			biggest_way(level - 1, pos + MIDDLE));
		sum += max(temp, biggest_way(level - 1, pos + RIGHT));
	}

	return sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int size = sizeof(arr) / sizeof(int);
	int levels = 0;
	for (int i = 1, count = 1; count <= size; ++i)
	{
		for (int j = 1; j <= i; ++j, ++count);
		++levels;
	}
	
	int max = biggest_way(levels, 1);

	for (int i = 2; i <= levels; ++i)
		max = std::max(max, biggest_way(levels, i));
	std::cout << max << std::endl;
	return 0;
}

