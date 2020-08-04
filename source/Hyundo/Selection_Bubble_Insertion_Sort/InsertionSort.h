#pragma once
#include "common.h"

vector<int> InsertionSort(vector<int> array)
{
	array.insert(array.begin(), -1);
	int i, j, Value;
	for (i = 2; i < array.size(); i++)
	{
		Value = array.at(i);
		j = i;
		while (array.at(j - 1) > Value)
		{
			array.at(j) = array.at(j - 1);
			j--;
		}
		array.at(j) = Value;
	}
	array.erase(array.begin());
	return array;
}