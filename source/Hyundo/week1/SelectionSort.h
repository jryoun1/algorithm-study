#pragma once
#include "common.h"

vector<int> selectionSort(vector<int> array)
{
	int k = 0;
	int tmp = 0;
	int min = 0;
	for (int i = 0; i < array.size(); i++)
	{
		min=array.at(i);
		for (int j = i + 1; j < array.size(); j++)
		{
			if (min >= array.at(j))
			{
				min = array.at(j);
				k = j;
			}
		}

		tmp=array.at(k);
		array.at(k) = array.at(i);
		array.at(i) = tmp;
	}
	return array;
}