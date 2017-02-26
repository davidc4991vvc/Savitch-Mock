/*
chapter5, page 331, programming projects 7

Write a program that inputs a date (for example, July 4, 2008) and outputs
the day of the week that corresponds to that date. The following algorithm
is from http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week.
The implementation will require several functions.

bool isLeapYear(int year); This function should return true if year is a leap year and false if it is not.
Here is pseudocode to determine a leap year:
year = (year divisible by 400) or (year divisible by 4 and year not divisible by 100))

int getCenturyValue(int year); This function should take the first two digits of the year (that is, the cen-
tury), divide by 4, and save the remainder. Subtract the remainder from 3 and return this value multiplied by 2. 
For example, the year 2008 becomes: (20/4) = 5 with a remainder of 0. 3 − 0 = 3. Return 3 * 2 = 6.

int getYearValue(int year); This function computes a value based on the years since the beginning of
the century. First, extract the last two digits of the year. For example, 08 is extracted for 2008. Next, factor in leap years. 
Divide the value from the previous step by 4 and discard the remainder. Add the two results together and return this value. 
For example, from 2008 we extract 08. Then (8/4) = 2 with a remainder of 0. Return 2 + 8 = 10.

int getMonthVa0lue(int month, int year); This function should return a value based on the table below and will require invoking the isLeapYear function.
Month ReturnValue
January 0 (6 if year is a leap year)
February 3 (2 if year is a leap year)
March 3 
April 6 
May 1 
June 4 
July 6 
August 2 
September 5 
October 0 
November 3 
December 5

Finally, to compute the day of the week, compute the sum of the date’s day plus the values returned by getMonthValue, getYearValue, and getCenturyValue. 
Divide the sum by 7 and compute the remainder. A remainder of 0 corresponds to Sunday, 1 corresponds to Monday, etc.,	up to 6, which corresponds to Saturday. 
For example, the date July 4, 2008 should be computed as (day of month) + (getMonthValue) + (getYearValue) + (getCenturyValue) 
= 4 + 6 + 10 + 6 = 26. 26/7 = 3 with a remainder of 5. The fifth day of the week corresponds to Friday.
		
Your program should allow the user to enter any date and output the corresponding day of the week in English.
This program should include a void function named getInput that prompts the user for the date and returns the month, day, and year using pass-by-reference parameters. 
You may choose to have the user enter the date’s month as either a number (1–12) or a month name.

Sample output
Calculate day of the week from date
for example: 30/9/1986
Enter the day:
30
Enter 1 to 12 for month, from January to December: 
9
Enter year:
1986
30/9/1986
That was not a leap year
The day of the week for that date is Tuesday
Would you like to repeat the program (y/n)?
t
exiting..

*/

#include <iostream>
#include <cmath>
#include <string>


bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
std::string getDayOfWeek(int day, int month, int year);
void getInput(int& day, int& month, int& year);

int main(){
	char repeat ='t';

	int dayDigits, monthDigits, yearDigits;
	std::string dayResult;

	do {
		getInput(dayDigits, monthDigits, yearDigits);
		std::cout<<"\ndate: "<<dayDigits<<"/"<<monthDigits<<"/"<<yearDigits<<std::endl;

		if (dayDigits<=31&&monthDigits<=12&&yearDigits>0){
			dayResult=getDayOfWeek(dayDigits, monthDigits, yearDigits);

			std::cout<<"\nThe day of the week for that date is "<<dayResult<<std::endl;

			std::cout<<"\nEnter y if you would like to repeat the program, any other key will exit \n";
			std::cin>>repeat;

		}

		else{
			std::cout<<"\nInvalid entry, please try again\n";
		}

	}while(repeat =='y');

	std::cout<<"exiting..\n";
}

bool isLeapYear(int year){
	if(year%400==0){
		std::cout<<"That was a leap year\n";
		return true;
	}
	else if (year%4==0&& year%100!=0){
		std::cout<<"That was a leap year\n";
		return true;
	}

	else{
		std::cout<<"That was not a leap year\n";
		return false;
	}
	
}

int getCenturyValue(int year){
	int twoDigits = year/100;
	double remainder;

	remainder=twoDigits%4;
	int result = 2*(3-remainder);

	//std::cout<<"\ncentury value: "<<result<<std::endl;
	return result;
}

int getYearValue(int year){
	int lastTwoDigits = year%100;

	int leapYearFactor = lastTwoDigits/4+lastTwoDigits;
	//std::cout<<"leapYearFactor "<<leapYearFactor;

	return leapYearFactor;
}

int getMonthValue(int month, int year){
	bool leapYear = isLeapYear(year);

	switch (month){
		case 1://January
			std::cout<<"Jan";
			if(leapYear){

				return 6;
				break;
			}
			else{
				return 0;
				break;
			}
		
		case 2:
			std::cout<<"Feb";
			if(leapYear){
				return 2;
				break;
			}
			else{
				return 3;
				break;
			}
		
		case 3:
			std::cout<<"March";
			return 3;
			break;
		case 4:
			std::cout<<"May";
			return 6;
			break;
		case 5: 
			std::cout<<"June";
			return 1;
			break;
		case 6:
			return 4;
			break;
		case 7:
			return 6;
			break;
		case 8:
			return 2;
			break;
		case 9:
			return 5;
			break;
		case 10:
			return 0;
			break;
		case 11:
			return 3;
			break;
		case 12:
			return 5;
			break;
		default:
			std::cout<<"Invalid entry\n";
			break;
	}

}

std::string getDayOfWeek(int day, int month, int year){
	int sum = day+getMonthValue(month,year)+getYearValue(year)+getCenturyValue(year);
	//std::cout<<"sum "<<sum<<std::endl;

	int remainder = sum%7;//modulo returns an integer representing the remainder

	//std::cout<<"remainder "<<remainder<<std::endl;

	switch (remainder){
		case 1://monday
			return "Monday";
			break;

		case 2:
			return "Tuesday";
			break;
		case 3:
			return "Wednesday";
			break;
		case 4:
			return "Thursday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
		case 0:
			return "Sunday";
			break;
		default:
			std::cout<<"Invalid input\n";
			return "-1";
			break;
	}
}

void getInput(int& day, int& month, int& year){
	std::cout<<"Calculate day of the week from date\n";
	std::cout<<"for example: 30/9/1986\n";

	std::cout<<"Enter the day:\n";
	std::cin>>day;

	std::cout<<"Enter 1 to 12 for month, from January to December: \n";

	std::cin>>month;

	std::cout<<"Enter year:\n";
	std::cin>>year;
}