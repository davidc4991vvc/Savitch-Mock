/*
chapter2, page 137, programming projects 6

A mobile phone operator charges $0.5 per minute for the first 10 minutes for an international call.
Any minutes over that cost $1 per minute. From the subscriber's gross cost, 5% is withheld for VAT, 10% is witheld for cross-network charge, 2% is witheld for contribution to the regulating authority,
and 3% is witheld for the company's scholarship program.
Write a program which takes the number of minutes for an overseas call as input and output the operator's gross income.
The program should also output the amount witheld for each category and the nett income generated from the call.

Sample Output:
Enter minutes for call: 32
Gross Income: 27
witheld VAT: 1.35
witheldNetwork: 2.7
witheldScholarship: 0.81
witheld regulator: 0.54


*/
#include <iostream>

int calculate (int minutes);

int main(){

	std::cout<<"Enter minutes for call: \n";
	int minutes;

	std::cin>>minutes;

	calculate(minutes);

}

int calculate (int minutes){

	const float firstTen {0.5}, afterTen {1}, VAT {0.05}, networkCharge {0.1}, scholarship {0.03}, regulator {0.02};
	float grossIncome, withheldVAT, witheldNetwork, witheldScholarship, witheldRegulator;

	if (minutes>10){
		grossIncome = 10*firstTen+minutes-10*afterTen;
		withheldVAT=grossIncome*VAT;
		witheldNetwork=grossIncome*networkCharge;
		witheldScholarship=grossIncome*scholarship;
		witheldRegulator=grossIncome*regulator;
	}

	else{
		grossIncome = minutes*firstTen;
		withheldVAT=grossIncome*VAT;
		witheldNetwork=grossIncome*networkCharge;
		witheldScholarship=grossIncome*scholarship;
		witheldRegulator=grossIncome*regulator;

	}

	std::cout<<"Gross Income: "<<grossIncome<<std::endl;
	std::cout<<"witheld VAT: "<<withheldVAT<<std::endl;
	std::cout<<"witheldNetwork: "<<witheldNetwork<<std::endl;
	std::cout<<"witheldScholarship: "<<witheldScholarship<<std::endl;
	std::cout<<"witheld regulator: "<<witheldRegulator<<std::endl;

}