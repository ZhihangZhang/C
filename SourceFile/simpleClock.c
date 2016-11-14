#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ---------declare structure --------
struct date
{
	int month;
	int day;
	int year;
};

struct time
{
	int hour;
	int minutes;
	int seconds;
};

struct dateAndTime
{
	struct time stime;
	struct date sdate;
};

struct days
{
	char nameOfDay[3];
};



// -------------declare functions--------------
struct time timeUpdate(struct time ct);
struct date dateUpdate(struct date d);
struct dateAndTime clockKeeper(struct dateAndTime DAT);
int numberOfDays (struct date d);
int isLeapYear(int year);
int getN (struct date d);
int fYear(int year, int month);
int gMonth(int month);
void dayOfDate(struct date d);




// ------------main function---------------------
int main (void){
	struct dateAndTime event =
	{
		{23, 59, 59},
		{11, 12, 2016}
	};


	// event.sdate = dateUpdate (event.sdate);
	// event.stime = timeUpdate (event.stime);
	event = clockKeeper(event);

	printf("%d/%d/%.2d  ", event.sdate.month, event.sdate.day, event.sdate.year % 100);
	printf("%.2d:%.2d:%.2d  ", event.stime.hour, event.stime.minutes, event.stime.seconds);

	dayOfDate(event.sdate);

	system("PAUSE");
	return 0;
}


// --------------update date-----------
/* function to update date
 * takes; struct date d - date to be update
 * returns: struct date t - updated date
 */
struct date dateUpdate(struct date d){

	struct date t;

	if( d.day != numberOfDays(d) ){
		t.day   = d.day + 1;
		t.month = d.month;
		t.year  = d.year;

	}else if(d.month == 12){     // end of year
		t.day   = 1;
		t.month = 1;
		t.year  = d.year + 1;

	}else{                       // end of month
		t.day   = 1;
		t.month = d.month + 1;
		t.year  = d.year;
	}

	return t;
}

/* function to determine days of the specified month
 * takes: atruct date d - the date
 * returns: int days - the number of days in that month
 */
int numberOfDays (struct date d){  // a copy of structure (unlike arrays)

	const int LeapYearDaysFeb = 29;
	const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if( d.month == 2 && isLeapYear(d.year) ){
		return LeapYearDaysFeb;
	}else{
		return daysPerMonth[d.month - 1];   // NOTICE! days of the month = array[month - 1]
	}
}

/* function to determine whether the specified year is a leap year
 * takes: int year - the year to be checked
 * returns: int 1 or 0 - flag of leap year
 */
int isLeapYear(int year){

	if( (year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ){
		return 1;
	}else{
		return 0;
	}
}



// -------------update time--------------
/* function to update time
 * takes: struct time ct- time to update
 * returns: struct time ct- updated time
 */
struct time timeUpdate(struct time ct){

	const int SECONDS = 60;
	const int HOURS = 24;
	const int MINUTES = 60;

	ct.seconds++;

	if(ct.seconds == SECONDS){
		ct.seconds = 0;
		ct.minutes++;

		if(ct.minutes == MINUTES){
			ct.minutes = 0;
			ct.hour++;

			if(ct.hour == HOURS){
				ct.hour = 0;
			}
		}
	}

	return ct;
}




// ----------------update day name------------
int getN (struct date d){
	int N;

	N = 1461 * fYear(d.year, d.month) / 4 + 153 * gMonth(d.month) / 5 + d.day;

	// improvement for formula: 29 days in Feb for leap year
	if(d.year > 1900 || (d.year == 1900 && d.month >= 3) ){
		return N;
	}else if(d.year > 1800 || (d.year == 1800 && d.month >= 3) ){
		return N+1;
	}else if(d.year > 1700 || (d.year == 1700 && d.month >= 3) ){
		return N+2;
	}else{
		return N; // unknown correction?
	}

}

int fYear(int year, int month){
	year = month <= 2 ? (year - 1) : year;
	return year;
}

int gMonth(int month){
	month = month <= 2 ? (month + 13) : (month + 1);
	return month;
}


void dayOfDate(struct date d){
	const struct days name[7] =
	{
		{ {'S', 'u', 'n'} }, { {'M', 'o', 'n'} },
		{ {'T', 'u', 'e'} }, { {'W', 'e', 'd'} },
		{ {'T', 'h', 'u'} }, { {'F', 'r', 'i'} },
		{ {'S', 'a', 't'} }
	};

	int dayNum;

	dayNum = (getN(d) - 621049) % 7;

	printf("%c%c%c\n\n", name[dayNum].nameOfDay[0], name[dayNum].nameOfDay[1], name[dayNum].nameOfDay[2]);


}




// --------------update clock--------------
/* function to update time and date (if time passes midnight)
 * takes: struct dateAndTime DAT- date and time to update
 * returns: struct dateAndTime DAT- updated day and time
 */
struct dateAndTime clockKeeper(struct dateAndTime DAT){
	// struct dateAndTime updatedDAT;
	// struct time Temp;

	DAT.stime = timeUpdate(DAT.stime);

	if(DAT.stime.hour == 0 && DAT.stime.minutes == 0 && DAT.stime.seconds == 0){
		DAT.sdate = dateUpdate(DAT.sdate);
	}

	return DAT;
}

