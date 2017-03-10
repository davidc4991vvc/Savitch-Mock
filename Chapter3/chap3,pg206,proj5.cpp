/*
chapter3, page 206, programming projects 5

Interest on a loan is paid on a declining balance, and hence a loan with an interest rate of, say, 
14 percent can cost significantly less than 14 percent of the balance. 
Write a program that takes a loan amount and interest rate as input and then outputs the monthly payments and balance of the loan
until the loan is paid off. Assume that the monthly payments are one twentieth of the original loan amount, 
and that any amount in excess of the interest is credited toward decreasing the balance due. 
Thus, on a loan of $20,000, the payments would be $1,000 a month. 
If the interest rate is 10 percent, then each month the interest is one-twelfth of 10 percent of
the remaining balance. The first month, (10 percent of $20,000)/12, or $166.67, would be paid in interest, 
and the remaining $833.33 would decrease the balance to $19,166.67. 
The following month the interest would be (10 percent of $19,166.67)/12, and so forth. 
Also have the program output the total interest paid over the life of the loan.

Finally, determine what simple annualized percentage of the original loan balance was paid in interest. 
For example, if $1,000 was paid in interest on a $10,000 loan and it took 2 years to pay off, 
then the annualized interest is $500, which is 5 percent of the $10,000 loan amount. 
Your program should allow the user to repeat this calculation as often as desired.

Sample Output

Loan calculator
Enter the loan amount:
20000
Enter the yearly interest rate, as a percentage: 
14
Interest: 233.333
principalPayment: 766.667
Loan remaining: 19233.3
Interest: 224.389
principalPayment: 775.611
Loan remaining: 18457.7
............

Interest: 66.2232
principalPayment: 933.777
Loan remaining: 4742.5
Interest: 55.3292
principalPayment: 944.671
Loan remaining: 3797.83
Interest: 44.308
principalPayment: 955.692
Loan remaining: 2842.14
Interest: 33.1583
principalPayment: 966.842
Loan remaining: 1875.29
Interest: 21.8784
principalPayment: 978.122
Loan remaining: 897.173
Interest: 10.467
principalPayment: 989.533
Loan remaining: -92.3605
Total interest paid: 2907.64
Total number of months to repay loan: 23
Annualised interest rate: 7.58515%

Enter Y to repeat or any other key to exit:
c
Exiting....


*/

#include <iostream>

int calculateLoan( double loanAmount,double interestRate);

int main (){
	char repeat='y';
	std::cout<<std::endl;

	std::cout<<"Loan calculator\n";

	while (repeat=='y' || repeat=='Y'){

		std::cout<<"Enter the loan amount:\n";

		double loanAmount, interestRate;

		std::cin>>loanAmount;

		std::cout<<"Enter the yearly interest rate, as a percentage: \n";

		std::cin>>interestRate;

		calculateLoan(loanAmount,interestRate);

		std::cout<<"\nEnter Y to repeat or any other key to exit:\n";

		std::cin>>repeat;

	}

	std::cout<<"Exiting....\n";

}

int calculateLoan( double loanAmount,double interestRate){
	double monthlyPayments, monthlyInterestRate, interest, principalPayment, loanRemaining, totalInterest {0}, numberMonths {0}, annnualisedInterest, annnualisedInterestRate;

	loanRemaining=loanAmount;

	monthlyPayments=loanAmount/20;

	monthlyInterestRate=(interestRate/100)/12;

	while (loanRemaining>0){

		interest=loanRemaining*monthlyInterestRate;
		totalInterest+=interest;

		std::cout<<"Interest: "<<interest<<std::endl;

		principalPayment=monthlyPayments-interest;
		numberMonths++;
		std::cout<<"principalPayment: "<<principalPayment<<std::endl;

		loanRemaining-=principalPayment;

		std::cout<<"Loan remaining: "<<loanRemaining<<std::endl;

	}

	std::cout<<"Total interest paid: "<<totalInterest<<std::endl;

	std::cout<<"Total number of months to repay loan: "<<numberMonths<<std::endl;

	annnualisedInterest=(totalInterest/numberMonths)*12;

	annnualisedInterestRate=(annnualisedInterest/loanAmount)*100;

	std::cout<<"Annualised interest rate: "<<annnualisedInterestRate<<"%"<<std::endl;

	return 0;

}