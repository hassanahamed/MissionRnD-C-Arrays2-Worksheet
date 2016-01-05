/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (only one transaction : { 30, "03-03-2005", "Third" })

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare(int value1, int value2) {
	if (value1 < value2) {
		return 2;
	}
	if (value1 > value2) {
		return 1;
	}
	return 0;
}

int getInt(char *p, int from, int to) {
	int value = 0;
	while (from <= to) {
		value = value * 10 + p[from] - '0';
		from++;
	}
	return value;
}

int compareDates(char *date1, char *date2) {
	int y1, m1, d1, y2, m2, d2, compareValue;
	y1 = getInt(date1, 6, 9);
	y2 = getInt(date2, 6, 9);
	compareValue = compare(y1, y2);
	if (compareValue != 0) return compareValue;
	m1 = getInt(date1, 3, 4);
	m2 = getInt(date2, 3, 4);
	compareValue = compare(m1, m2);
	if (compareValue != 0) return compareValue;
	d1 = getInt(date1, 0, 1);
	d2 = getInt(date2, 0, 1);
	compareValue = compare(d1, d2);
	return compareValue;
}

int binarySearch(struct transaction Arr[], int len, char *date) {
	int left = 0, right = len - 1;
	while (left <= right) {
		int middle = left + (right - left) / 2;
		int compare = compareDates(Arr[middle].date, date);
		if (compare == 0) {
			return middle;
		}
		if (compare == 2) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return -1;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count = 0;
	int index = binarySearch(Arr, len, date);
	if (index != -1) {
		// To handle same dates case.
		for (int i = index + 1; i < len; ++i) {
			if (compareDates(Arr[i].date, date) == 1) {
				count++;
			}
		}
		//return (len - index - 1);
	}
	return count;
}