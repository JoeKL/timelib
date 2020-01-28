/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *
 *
 **/
bool isLeapYear(int year) {
	// Pr�ft ob Jahr durch 4 teilbar und nicht durch 100 teilbar oder Jahr durch 400 teilbar ist
	// Wenn ja, dann Schaltjahr
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}

}

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
	int days_amount = 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


	if (isLeapYear(year)) {
		days[1] = 29;
	}

	if (!(day >= 1 && day <= days[month - 1]))
		return -1;

	if (!(month >= 1 && month <= 12))
		return -1;

	int i = 0;
	for (i; i <= month - 2; i++) {
		days_amount += days[i];
	}

	days_amount += day;

	return days_amount;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
