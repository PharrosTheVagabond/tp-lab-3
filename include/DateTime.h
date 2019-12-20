#ifndef DATETIME_H
#define DATETIME_H

#include <string>

class DateTime {
private:
	tm date;
	const int secsInDay = 60 * 60 * 24;
	static const std::string weekdays[7];
	static const std::string months[12];
	std::string createDateString(tm dateStruct);
public:
	DateTime(unsigned day, unsigned month, unsigned year);
	DateTime();
	DateTime(const DateTime& dateOrig);
	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(unsigned int N);
	std::string getPast(unsigned int N);
	int getDifference(DateTime& other);
};

#endif // !DATETIME_H
