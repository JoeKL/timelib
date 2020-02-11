#ifndef TIMELIB_H
#define TIMELIB_H

/**
 * Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 * ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. 
 **/
int is_leapyear(int year);

/**
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 **/
int get_days_for_month(int month, int year);

/**
 * Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
 * wie alle Daten nach dem 31.12.2400. 
 **/
int exists_date(int day, int month, int year);

/**
 * Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 * Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 **/
int day_of_the_year(int day, int month, int year);

/**
 * Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
 *	ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 **/
void input_date(int* day, int* month, int* year);

#endif