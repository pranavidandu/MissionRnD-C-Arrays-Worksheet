/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
int binary_search(int *Arr, int len, int num){
	int first = 0;
	int last = len - 1;
	int mid;
	while (first <= last){
		mid = (first + last) / 2;
		if (num > Arr[mid])
			first = mid + 1;
		else
			last = mid - 1;
	}
	if (mid == 0)
		return mid;
	return mid + 1;
}
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{	if (Arr == NULL || len < 0)//check if the array is empty or the input is invalid
		return NULL;
	//Size increased by 1
	Arr = (int*)realloc(Arr, (len + 1) * sizeof(int));
	//function to find position to insert the element
	int index = binary_search(Arr, len, num);
	//loop to shift elements
	for (int i = len; i > index; i--){
		Arr[i] = Arr[i - 1];
	}
	Arr[index] = num;
	return Arr;
}