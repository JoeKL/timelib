#include <stdio.h>
#include <stdlib.h>

/**
 * Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 * ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. 
 **/
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


/**
 * Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
 * wie alle Daten nach dem 31.12.2400. 
 **/
int exists_date(int day, int month, int year){
	
	if (!(month >= 1 && month <= 12))
		return 0;

	if(!(day >= 1 && day <= get_days_for_month(month, year)))
		return 0;

	if(!( (day >= 1 && month >= 1 && year >= 1582) && (day <= 31 && month <= 12 && year <= 2400) ))
		return 0;

	return 1;
}



/**
 * Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 * Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 **/
int day_of_the_year(int day, int month, int year){

	if(exists_date(day, month, year) == 0){
		return -1;
	}

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
 * Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
 *	ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 **/
void input_date(int* day, int* month, int* year){
	do{
		*day = 0, *month = 0, *year = 0;

		printf("Please input day: ");
		scanf("%i",day);
		fflush(stdin);

		printf("Please input month: ");
		scanf("%i",month);
		fflush(stdin);
		
		printf("Please input year: ");
		scanf("%i",year);
		fflush(stdin);

	} while (exists_date(*day, *month, *year) != 1);
}

