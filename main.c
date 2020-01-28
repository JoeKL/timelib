/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int is_leapyear(int year) {
	// Pr�ft ob Jahr durch 4 teilbar und nicht durch 100 teilbar oder Jahr durch 400 teilbar ist
	// Wenn ja, dann Schaltjahr
	if(year < 1582) {
		return -1;
	}

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	} else {
		return 0;
	}

}

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
	int days_amount = 0;

	if (!(day >= 1 && day <= get_days_for_month(month, year)))
		return -1;

	if (!(month >= 1 && month <= 12))
		return -1;

	int i = 1;
	for (i; i <= month - 1; i++) {
		days_amount += get_days_for_month(i, year);
	}

	days_amount += day;

	return days_amount;
}

/**
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
**/
int get_days_for_month(int month, int year){
	
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (is_leapyear(year) == -1 || month < 1 || month > 12) {
		return -1;
	}
	
	if (is_leapyear(year) == 1) {
		days[1] = 29;
	}

	return days[month - 1];
}


int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2019));
    return 0;
}
