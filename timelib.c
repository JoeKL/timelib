/**
 * @file timelib.c
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
 * @brief Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. 
 * 
 * @param year 
 * @return int 
 */
int is_leapyear(int year){

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
 * @brief Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 * 
 * @param month 
 * @param year 
 * @return int 
 */
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


/**
 * @brief Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400. 
 * 
 * @param VarDate 
 * @return int 
 */
int exists_date(struct date VarDate){
	
	if (!(VarDate.month >= 1 && VarDate.month <= 12))
		return 0;

	if(!(VarDate.day >= 1 && VarDate.day <= get_days_for_month(VarDate.month, VarDate.year)))
		return 0;

	if(!( (VarDate.day >= 1 && VarDate.month >= 1 && VarDate.year >= 1582) && (VarDate.day <= 31 && VarDate.month <= 12 && VarDate.year <= 2400) ))
		return 0;

	return 1;
}



/**
 * @brief Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 * 
 * @param VarDate 
 * @return int 
 */
int day_of_the_year(struct date VarDate){

	if(exists_date(VarDate) == 0){
		return -1;
	}

	int days_amount = 0;

	if (!(VarDate.day >= 1 && VarDate.day <= get_days_for_month(VarDate.month, VarDate.year)))
		return -1;

	if (!(VarDate.month >= 1 && VarDate.month <= 12))
		return -1;

	int i = 1;
	for (i; i <= VarDate.month - 1; i++) {
		days_amount += get_days_for_month(i, VarDate.year);
	}

	days_amount += VarDate.day;

	return days_amount;
}


/**
 * @brief Diese Funktion gibt den Wochentag des übergebenen Datums zurück. Sollte das Jahr kleiner als 1752 oder größer als 2400 sein, so gibt die Funktion -1 zurück.
 * 
 * @param VarDate 
 * @return int 
 */
int calc_weekday(struct date VarDate){

	if(VarDate.year < 1752 || VarDate.year > 2400)
		return -1;

	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    VarDate.year -= VarDate.month < 3;

	return (VarDate.year + VarDate.year/4 - VarDate.year/100 + VarDate.year/400 + t[VarDate.month-1] + VarDate.day) % 7;
}

/**
 * @brief Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 * 
 * @return struct date 
 */
struct date input_date(){
	struct date VarDate;
	do{
		VarDate.day = 0, VarDate.month = 0, VarDate.year = 0;

		printf("Please input day: ");
		scanf("%i",&VarDate.day);
		fflush(stdin);

		printf("Please input month: ");
		scanf("%i",&VarDate.month);
		fflush(stdin);
		
		printf("Please input year: ");
		scanf("%i",&VarDate.year);
		fflush(stdin);

	} while (exists_date(VarDate) != 1);
	return VarDate;
}