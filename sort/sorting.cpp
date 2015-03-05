#include <iostream>

//quicksort: pick a partition, every left is smaller, 
//everything right is greater. Do this recursively
void quicksort(int *data, unsigned left, unsigned right)
{
	if(left > right)
		return;
	unsigned pivotIndex = (left + right)/2;//watch out for overflow, just use middle element
	int pivot = data[pivotIndex];
	int tmp;
	unsigned i = left;
	unsigned j = right;
	while(i < j)
	{
		while(data[i] < pivot)
		{
			i++;
		}
		while(data[j] > pivot)
		{
			j--;
		}
		if(i <= j)
		{
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
		
	}

	quicksort(data, left, j);
	quicksort(data, i, right);
}

void swap(data, unsigned index1, unsigned index2)
{
	int tmp = data[index1];
	data[index1] = data[index2];
	data[index2] = tmp;
}

void quicksort1(int *data, unsigned left, unsigned right)
{
	if(left > right)
		return;
	unsigned pivotIndex (left+ right)/2;
	int pivot = data[pivotIndex];
	swap(data, pivotIndex, right);// get pivot out of the way
	unsigned storeIndex = left;

	for(unsigned i=left; i < right; i++)
	{
		if(data[i] < pivot)
		{
			swap(data, i, storeIndex);
			storeIndex++;
		}
	}
	swap(data, storeIndex, right);
	quicksort1(data, left, storeIndex - 1);
	quicksort1(data, storeIndex + 1, right);
}


void mergesort()

























