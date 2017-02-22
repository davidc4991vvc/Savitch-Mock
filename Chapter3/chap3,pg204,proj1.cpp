/*
chapter3, page 204, programming projects 1

Write a program that computes the cost of a long-distance call. The cost of the call is determined according to the following 
rate schedule:
	a. Any call started between 8:00 am and 6:00 pm, Monday through Friday, is billed at a rate of $0.40 per minute.
	b. Any call starting before 8:00 am or after 6:00 pm, Monday through Friday, is charged at a rate of $0.25 per minute.
	c. Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
The input will consist of the day of the week, the time the call started, and the length of the call in minutes. 
The output will be the cost of the call. 
The time is to be input in 24-hour notation, so the time 1:30 pm is input as 13:30
The day of the week will be read as one of the following pairs of character values, which are stored in two variables of type char :
Mo Tu We Th Fr Sa Su

Be sure to allow the user to use either uppercase or lowercase letters or a combination of the two. 
The number of minutes will be input as a value of type int . 
(You can assume that the user rounds the input to a whole number of minutes.) 
Your program should include a loop that lets the user repeat this calculation until the user says she or he is done.

Sample Output

Call cost calculator
Enter the day of the week: 
TH
Enter the hour of the call in 24 hour notation: 
5
Enter the minute of the call in 24 hour notation: 
34
Enter the length of the call in minutes: 
89
Your call occurred on Thursday
Off peak call charges apply
The cost of the call: $22.25

Enter Y if you would like to repeat: 
t
Exiting..

*/

#include <iostream>

int callCost(char character1,char character2, int hour, int callTime);

int weekendCallCost (int callTime);

int peakCallCost (int callTime);

int offPeakCallCost (int callTime);


int main (){

	std::cout<<"\nCall cost calculator\n";

	char repeat = 'y';

	char character1, character2;

	int callTime, hour;

	while (repeat =='y' || repeat =='Y'){
		std::cout<<"Enter the day of the week: \n";

		std::cin>>character1;
		std::cin>>character2;

		std::cout<<"Enter the hour of the day during which the call started; in 24 hour notation: \n";

		std::cin>>hour;

		std::cout<<"Enter the length of the call in minutes: \n";

		std::cin>>callTime;

		callCost(character1, character2, hour, callTime);

		std::cout<<"\nEnter Y if you would like to repeat: \n";

		std::cin>>repeat;
	}

	std::cout<<"Exiting..\n";
}


int callCost(char character1,char character2, int hour, int callTime){

	switch (character1){
		case 's':
		case 'S':
			if (character2 =='a'||character2=='A'){//saturday
				std::cout<<"Your call occurred on Saturday\n";

				weekendCallCost (callTime);
			}

			else{//sunday
				std::cout<<"Your call occurred on Sunday\n";

				weekendCallCost (callTime);
			}
			break;

		case 'm':
		case 'M'://monday
			std::cout<<"Your call occurred on Monday\n";

			if (hour>8&&hour<18){
				peakCallCost (callTime);
			}

			else{
				offPeakCallCost (callTime);
			}
			break;
		case 't':
		case 'T':
			if(character2=='u'||character2=='U'){//Tuesday
				std::cout<<"Your call occurred on Tuesday\n";

				if (hour>8&&hour<18){
					peakCallCost (callTime);
				}

				else{
					offPeakCallCost (callTime);
				}

			}

			else{//Thursday
				std::cout<<"Your call occurred on Thursday\n";

				if (hour>8&&hour<18){

					peakCallCost (callTime);
				}

				else{
					offPeakCallCost (callTime);
				}

			}
			break;
		case 'w':
		case'W'://Wednesday
			std::cout<<"Your call occurred on Wednesday\n";

			if (hour>8&&hour<18){
				peakCallCost (callTime);
			}

			else{
				offPeakCallCost (callTime);
			}
			break;
		case 'f':
		case 'F'://Friday
			std::cout<<"Your call occurred on Friday\n";

			if (hour>8&&hour<18){
				peakCallCost (callTime);
			}

			else{
				offPeakCallCost (callTime);
			}
			break;
		default:
			std::cout<<"Sorry, invalid entry\n";
	}
	return 0;
}

int weekendCallCost (int callTime){
	const float weekends {0.15};

	std::cout<<"Weekend call charges apply\n";

	float callCost=weekends*callTime;

	std::cout<<"The cost of the call: $"<<callCost<<std::endl;

	return 0;
}

int peakCallCost (int callTime){
	const float officeHours {0.4};

	std::cout<<"Peak call charges apply\n";

	float callCost=officeHours*callTime;

	std::cout<<"The cost of the call: $"<<callCost<<std::endl;

	return 0;
}


int offPeakCallCost (int callTime){

	const float afterHours {0.25};

	std::cout<<"Off peak call charges apply\n";

	float callCost=afterHours*callTime;

	std::cout<<"The cost of the call: $"<<callCost<<std::endl;

	return 0;
}