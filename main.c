/**
 * @file main.c
 * @author Niko Tepe
 * @brief 
 * @version 0.1
 * @date 2020-03-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/**
 * @brief Main Funktion
 * 
 * @return int 
 */

int main()
{
	struct date CurrentDate;
	
	// input_date_struct(CurrentDate);
	CurrentDate = input_date();

	printf("Date: %i.%i.%i\n", CurrentDate.day, CurrentDate.month, CurrentDate.year);
	printf("Weekday is: %i\n", calc_weekday(CurrentDate));

    printf("Is day of year no.: %i\n", day_of_the_year(CurrentDate));

    return 0;
}
