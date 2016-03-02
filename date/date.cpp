

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include "math.h"
#include "conio.h"
#include "iostream"

using namespace std;

const int firstYear = 1901;  // начало времён


bool isLeapYear(int  year);
int daysInYear(int  year);
int daysInMonth(int  year, int month);
bool isCorrectDate(int  year, int month, int day);
void nextDay(int  year, int month, int day);
long countDays(int  year, int month, int day);
void defineDate(long days, int* year, int* month, int* day);
void futureDate(int count, int  year, int month, int day, int* futureYear, int* futureMonth, int* futureDay);
void pastDate(int count, int  year, int month, int day, int* futureYear, int* futureMonth, int* futureDay);
long countDaysBetweenTwoDates(int  year, int month, int day, int  year2, int month2, int day2);
bool compareDate(int  year, int month, int day, int  year2, int month2, int day2);
void swap(int dates[][3], int k, int p);
void sort(int dates[][3], int countDate);
void printDate(int  year, int month, int day);
void printArrayDate(int dates[][3], int countDate);


int main() {
	int year0 = 1000;
	int year1 = 1004;
	
	int month0 = 10;
	int month1 = 9;

	int day0 = 31; 
	int day1 = 32;


	cout << isLeapYear(year0);
	cout << endl;
	cout << isLeapYear(year1);
	cout << endl;

	///////////////////////////DAYS IN YEAR//////////////////////////
	cout << "days in year = " << daysInYear(year0) << endl;
	cout << "days in year = " << daysInYear(year1) << endl;
	
	///////////////////////////DAYS IN MOUNTH//////////////////////////
	//cout << "daysInMonth = " << daysInMonth(year0, 5) << endl;
	cout << "daysInMonth = " << daysInMonth(year0, 11) << endl;
	//cout << "daysInMonth = " << daysInMonth(year1, 2) << endl;
	cout << "daysInMonth = " << daysInMonth(year0, 2) << endl;

	/////////////////////////////////////// IS CORRECT DATE ////////////////////////////
	cout << "isCorrectDate = " << isCorrectDate(2015, 2, 30) << endl;
	cout << "isCorrectDate = " << isCorrectDate(2016, 2, 29) << endl;
	cout << "isCorrectDate = " << isCorrectDate(1015, 2, 10) << endl;

	/////////////////////////////////////// NEXT DAY ////////////////////////////
	nextDay(int  year, int month, int day);

	system("pause");
	return 0;
}
bool isLeapYear(int  year) {
	return  (year % 400 == 0 || year % 100 != 0 &&	year % 4 == 0);
}
int daysInYear(int  year) {
	if (isLeapYear(year)) return 366;
	else return 365;
}
int daysInMonth(int  year, int month) {
	if (month == 0 || month == 8 || month == 9 || month == 11) return 30;
	else 
		if (month == 2) 
			if (isLeapYear(year)) return 29;
			else return 28;
		else return 31;
	
}
bool isCorrectDate(int  year, int month, int day) {
	bool result;
	result = (year >= 1901 && month >= 1 && month <= 12 && day >= 1 && day <= daysInMonth(year, month));
	return result;
}
void nextDay(int  year, int month, int day) {
	if (isCorrectDate(year, month, day)) {
		if (day < daysInMonth(year, month))
			day = day + 1;
		else {
			day = 1;
			month = month + 1;
		}
		if (month == 13) {
			month = 1;
			year = year + 1;
		}
	}
	else return 0;
}
