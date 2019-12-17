#define _CRT_SECURE_NO_WARNINGS

#include "DateTime.h"
#include <ctime>

DateTime::DateTime(unsigned day, unsigned month, unsigned year) {
	date = {};
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	mktime(&date);
}

DateTime::DateTime() {
	time_t timeTmp;
	time(&timeTmp);
	date = *(localtime(&timeTmp));
	date.tm_sec = 0;
	date.tm_min = 0;
	date.tm_hour = 0;
}

DateTime::DateTime(const DateTime& dateOrig) {
	date = dateOrig.date;
}

std::string DateTime::createDateString(tm dateStruct) {
	return std::to_string(dateStruct.tm_mday) + " " + months[dateStruct.tm_mon] + " " + std::to_string(dateStruct.tm_year + 1900) + ", " + weekdays[dateStruct.tm_wday];
}

std::string DateTime::getToday() {
	return createDateString(date);
}

std::string DateTime::getYesterday() {
	return getPast(1);
}

std::string DateTime::getTomorrow() {
	return getFuture(1);
}

std::string DateTime::getFuture(unsigned int N) {
	time_t timeTmp = mktime(&date);
	timeTmp += (long long)secsInDay * N;
	tm datePast = *(localtime(&timeTmp));
	return createDateString(datePast);
}

std::string DateTime::getPast(unsigned int N) {
	time_t timeTmp = mktime(&date);
	timeTmp -= (long long)secsInDay * N;
	tm datePast = *(localtime(&timeTmp));
	return createDateString(datePast);
}

int DateTime::getDifference(DateTime& other) {
	time_t dayFirst = mktime(&date), daySecond = mktime(&other.date);
	return (int)(dayFirst - daySecond) / secsInDay;
}
