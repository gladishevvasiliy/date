

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
	cout << "nextDay = ";
	nextDay(1016, 3, 2);
	cout << endl;

	cout << "nextDay = ";
	nextDay(2016, 12, 31);
	cout << endl;

	////////////////////////////////////////////COUNT DAYS ////////////////////////////
	cout << "countDays = " << countDays(1901, 1, 7) << endl;

	//////////////////////////////////defineDate////////////////////////
	cout << "date: ";
	int nowYear, nowDay, nowMonth;
	defineDate(2, &nowYear, &nowMonth, &nowDay);
	printDate(nowYear, nowMonth, nowDay);
//	cout << nowYear << "." << nowMonth << "." << nowDay << endl;
	///////////////////////////////////FUTURE DATE /////////////////////////////////////////
	cout << "future date: ";
	int futureYear, futureMonth, futureDay;
	futureDate(3, 2016, 3, 2, &futureYear, &futureMonth, &futureDay);
//	cout <<  << "." << futureMonth << "." << futureDay << endl;
	printDate(futureYear, futureMonth, futureMonth);
	///////////////////////////////////PAST DATE/////////////////////////////////////////

	cout << "past date: ";
	int pastYear, pastMonth, pastDay;
	pastDate(3, 2016, 3, 2, &pastYear, &pastMonth, &pastDay);
	printDate(pastYear, pastMonth, pastDay);

	/////////////////////////////////countDaysBetweenTwoDates////////////////////////////

	cout << "DaysBetweenTwoDates:" << countDaysBetweenTwoDates(2016, 1, 1, 2015, 1, 1) << endl;	

	/////////////////////////////////compareDate////////////////////////////////////////

	cout << "days > days 2? " << compareDate(2015, 12, 31, 2016, 2, 3);

	system("pause");
	return 0;
}
bool isLeapYear(int  year) {
	return  (year % 400 == 0 || year % 100 != 0 && year % 4 == 0);
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
		cout << year << " " << month << " " << day << endl;
	}
	else
		cout << "error" << endl;
}

long countDays(int  year, int month, int day) {
	int days = 0;
	for (int y = 1901; y < year; y++)
		days = days + daysInYear(y);
	for (int m = 1; m < month; m++)
		days = days + daysInMonth(year, m);
	days += day;
	return days;
}

void defineDate(long days, int* year, int* month, int* day) {
	int y = 1901;
	while (days > daysInYear(y)) {
		days = days - daysInYear(y);
		y = y + 1;
	}
	int m = 1;
	while (days > daysInMonth(y, m)) {
		days = days - daysInMonth(y, m);
		m = m + 1;
	}
	int d = days;

	*year = y;
	*month = m;
	*day = d;
}

void futureDate(int count, int  year, int month, int day, int* futureYear, int* futureMonth, int* futureDay) {
	int days = countDays(year, month, day);
	days += count;
	int y, m, d;
	defineDate(days, &y, &m, &d);

	*futureYear = y;
	*futureMonth = m;
	*futureDay = d;
}

void pastDate(int count, int  year, int month, int day, int* pastYear, int* pastMonth, int* pastDay) {
	int days = countDays(year, month, day);
	days -= count;
	int y, m, d;
	defineDate(days, &y, &m, &d);

	*pastYear = y;
	*pastMonth = m;
	*pastDay = d;
}

long countDaysBetweenTwoDates(int  year, int month, int day, int  year2, int month2, int day2) {
	int days = countDays(year, month, day);
	int days2 = countDays(year2, month2, day2);
	return(days - days2);
}

bool compareDate(int  year, int month, int day, int  year2, int month2, int day2) {
	int days = countDays(year, month, day);
	int days2 = countDays(year2, month2, day2);
	if (days > days2) return true;
	else return false;
}

void printDate(int  year, int month, int day){
	cout << year << "." << month << "." << day << endl;
}