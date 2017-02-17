/*
chapter2, page 137, programming projects 8

You have just purchased a stereo system that cost $1,000 on the following credit plan: 
no down payment, an interest rate of 18% per year (and hence 1.5% per month), and monthly payments of $50. 
The monthly payment of $50 is used to pay the interest and whatever is left is used to pay part of the remaining debt. 
Hence, the first month you pay 1.5% of $1,000 in interest. That is $15 in interest. 
So, the remaining $35 is deducted from your debt, which leaves you with a debt of $965.00. 
The next month you pay interest of 1.5% of $965.00, which is $14.48. 
Hence, you can deduct $35.52 (which is $50 – $14.48) from the amount you owe. 
Write a program that will tell you how many months it will take you to pay off the loan, as well as the total amount of interest paid over the life of the loan. 
Use a loop to calculate the amount of interest and the size of the debt after each month. 
(Your final program need not output the monthly amount of interest paid and remaining debt, but you may want to write a preliminary version of the program
that does output these values.) Use a variable to count the number of loop iterations and hence the number of months until the debt is zero. You may
want to use other variables as well. The last payment may be less than $50. Do not forget the interest on the last payment. 
If you owe $50, then your monthly payment of $50 will not pay off your debt, although it will come close. One month’s interest on $50 is only 75 cents.

Sample Output:
Enter the principal amount: 
1000
Enter your monthly payments: 
50
Enter your monthly interest rate: 
1.5

Month: 0
Interest: 0
Principal: 1000
Month: 1
Interest: 15
Principal: 965
Month: 2
Interest: 14.475
Principal: 929.475
Month: 3
Interest: 13.9421
Principal: 893.417


*/
#include <iostream>

int calculate (float principal, float monthlyInterest, int monthlyPayments);

int main(){

	std::cout<<"Enter the principal amount: "<<std::endl;

	float principal, monthlyInterest; 
	int monthlyPayments;

	std::cin>>principal;

	std::cout<<"Enter your monthly payments: "<<std::endl;

	std::cin>>monthlyPayments;

	std::cout<<"Enter your monthly interest rate: "<<std::endl;

	std::cin>>monthlyInterest;

	calculate (principal, monthlyInterest, monthlyPayments);


}

int calculate (float principal, float monthlyInterest, int monthlyPayments){

	int paymentMonths {0};

	float totalInterest {0}, interest{0};

	while (principal>0){

		std::cout<<"Month: "<<paymentMonths<<std::endl;
		std::cout<<"Interest: "<<interest<<std::endl;
		std::cout<<"Principal: "<<principal<<std::endl;
		interest=principal*(monthlyInterest/100);
		++paymentMonths;

		totalInterest+=interest;
		principal-=(static_cast<float>(monthlyPayments)-interest);
		

	}

	std::cout<<"\nMonths to pay off principal: "<<paymentMonths<<std::endl;
	std::cout<<"Total Interest paid: "<<totalInterest<<std::endl;

	return 0;

}