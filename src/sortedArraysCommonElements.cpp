/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare2(int value1, int value2) {
	if (value1 < value2) {
		return 2;
	}
	if (value1 > value2) {
		return 1;
	}
	return 0;
}

int getInt2(char *p, int from, int to) {
	int value = 0;
	while (from <= to) {
		value = value * 10 + p[from] - '0';
		from++;
	}
	return value;
}

int compareDates2(char *date1, char *date2) {
	int y1, m1, d1, y2, m2, d2, compareValue;
	y1 = getInt2(date1, 6, 9);
	y2 = getInt2(date2, 6, 9);
	compareValue = compare2(y1, y2);
	if (compareValue != 0) return compareValue;
	m1 = getInt2(date1, 3, 4);
	m2 = getInt2(date2, 3, 4);
	compareValue = compare2(m1, m2);
	if (compareValue != 0) return compareValue;
	d1 = getInt2(date1, 0, 1);
	d2 = getInt2(date2, 0, 1);
	compareValue = compare2(d1, d2);
	return compareValue;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (!A || !B) return NULL;
	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction));
	int i = 0, j = 0, count = 0;
	while (i < ALen && j < BLen) {
		int compareValue = compareDates2(A[i].date, B[j].date);
		if (compareValue == 0) {
			result = (struct transaction *)realloc(result, (count + 1) * sizeof(struct transaction));
			result[count++] = A[i];
			++i;
			++j;
		}
		else if (compareValue == 1) {
			++j;
		}
		else {
			++i;
		}
	}
	return (count == 0) ? NULL : result;
}