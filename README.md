# timelib - Dokumentation
von Niko Tepe

## Functions

int **is\_leapyear** (int year)

- _Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist._ _Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben._

int **get\_days\_for\_month** (int month, int year)

- _Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt._

int **exists\_date** (struct **date** VarDate)

- _Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400._

int **day\_of\_the\_year** (struct **date** VarDate)

- _Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1._

int **calc\_weekday** (struct **date** VarDate)

- _Diese Funktion gibt den Wochentag des übergebenen Datums zurück. Sollte das Jahr kleiner als 1752 oder größer als 2400 sein, so gibt die Funktion -1 zurück._

struct **date** **input\_date** ()

- _Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde._

_ _ _ _

## Function Documentation

#### int calc\_weekday (struct date _VarDate_)

Diese Funktion gibt den Wochentag des übergebenen Datums zurück. Sollte das Jahr kleiner als 1752 oder größer als 2400 sein, so gibt die Funktion -1 zurück.

- ##### Parameters
    -  _VarDate_

- ##### Returns

    - int

#### int day\_of\_the\_year (struct date _VarDate_)
Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.

- ##### Parameters
   - _VarDate_

- ##### Returns
    - int

#### int exists\_date (struct date _VarDate_)
Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400.

- ##### Parameters
    - _VarDate_

- ##### Returns
    - int

#### int get\_days\_for\_month (int _month_, int _year_)
Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.

- ##### Parameters
    - _month_
    - _year_

- ##### Returns
    - int

#### struct date input\_date ()
Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.

- ##### Returns
    - struct date


#### int is\_leapyear (int  _year_)
Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.

<details>
<summary>Programmablaufplan</summary>
![is_leapyear](/PAP/is_leapyear.png)

</details>

- ##### Parameters
    - _year_

- ##### Returns
    - int
