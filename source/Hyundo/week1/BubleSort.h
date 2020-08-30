#pragma once
#include "common.h"

vector<int> BubleSort(vector<int> array)
{
	int i, Sorted;
	Sorted = false;
	while (!Sorted)
	{
		Sorted = true;
		for (i = 1; i < array.size(); i++)
		{
			if (array.at(i - 1) > array.at(i))
			{
				int tmp = array.at(i-1);
				array.at(i-1) = array.at(i);
				array.at(i) = tmp;
				Sorted = false;
			}
		}
	}
	return array;
}