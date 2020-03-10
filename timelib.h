/**
 * @file timelib.h
 * @author Niko Tepe
 * @brief 
 * @version 0.1
 * @date 2020-03-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TIMELIB_H
#define TIMELIB_H

/**
 * @brief Aufbau int day, int month, int year
 * 
 */
struct date{
    int day;
    int month;
    int year;
};

/**
 * @brief Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. 
 * 
 * @param year 
 * @return int 
 */
int is_leapyear(int year);

/**
 * @brief Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 * 
 * @param month 
 * @param year 
 * @return int 
 */
int get_days_for_month(int month, int year);

/**
 * @brief Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400. 
 * 
 * @param VarDate 
 * @return int 
 */
int exists_date(struct date VarDate);

/**
 * @brief Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 * 
 * @param VarDate 
 * @return int 
 */
int day_of_the_year(struct date VarDate);

/**
 * @brief Diese Funktion gibt den Wochentag des übergebenen Datums zurück. Sollte das Jahr kleiner als 1752 oder größer als 2400 sein, so gibt die Funktion -1 zurück.
 * 
 * @param VarDate 
 * @return int 
 */
int calc_weekday(struct date VarDate);

/**
 * @brief Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 * 
 * @return struct date 
 */
struct date input_date();

#endif