/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
struct student * bubble_sort(struct student *students, int len){
	for (int pass = 0; pass < len - 1; pass++){
		for (int j = 0; j < len - pass - 1; j++){
			if (students[j].score > students[j + 1].score){
				 students[j].score = students[j].score + students[j + 1].score;
				 students[j + 1].score = students[j].score - students[j + 1].score;
				 students[j].score = students[j].score - students[j + 1].score;
			}
		}
	}
	return students;
}
struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL || len < 0 || K <= 0)
		return NULL;
	if (K > len)
		K = len;
	struct student **result = (struct student**)malloc(sizeof(struct student) * K);
	students = bubble_sort(students, len);
	for (int i = len - K, j = 0; i < len; i++, j++)
		result[j] = &students[i];
	return result;
}