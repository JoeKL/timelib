/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/**
 * Führt die Funktionen aus.
 **/

int main()
{
	int day, month, year;

	input_date(&day, &month, &year);

	printf("Date: %i.%i.%i\n", day, month, year);

    printf("Is day of year no.: %i\n", day_of_the_year(day, month, year));
    return 0;
}
