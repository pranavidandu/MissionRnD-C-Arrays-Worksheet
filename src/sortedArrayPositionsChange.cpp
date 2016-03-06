/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (len < 0 || Arr == NULL)//checks if the array is empty or the input is invalid
		return NULL;
	int temp;
	int index;
	//finds the first element whose position is exchanged
	for (int i = 0; i < len; i++){
		if (Arr[i] < Arr[i + 1]){
			continue;
		}
		else{
			temp = Arr[i];
			index = i;
			break;
		}
	}
	// finds the second element and swaps with first element
	for (int i = len - 1; i > index; i--){
		if (Arr[i] > Arr[i - 1])
			continue;
		else{
			Arr[index] = Arr[i];
			Arr[i] = temp;
			break;
		}
	}
}