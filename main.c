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
	//Erstelle date struct und lese Tastatureingabe mit input_date ein
	struct date CurrentDate;
	CurrentDate = input_date();

	//Gebe Date aus
	printf("Date: %i.%i.%i\n", CurrentDate.day, CurrentDate.month, CurrentDate.year);

	// gebe Wochentag aus
	printf("Weekday is: %i\n", calc_weekday(CurrentDate));

	// Gebe Tag des Jahres aus
    printf("Is day of year no.: %i\n", day_of_the_year(CurrentDate));

    return 0;
}
