/*

chapter4, page 277, programming projects 1

Write a program which computes the annual after-tax cost of a new house for the first year of ownership. 
The cost is computed as the annual mortgage cost minus the tax savings. 
The input should be the price of the house and the down payment. 
The annual mortgage cost can be estimated as 3 percent of the initial loan balance credited toward paying off the loan
principal plus 6 percent of the initial loan balance in interest. The initial loan balance is the price minus the down payment. 
Assume a 35 percent marginal tax rate and assume that interest payments are tax deductible. 
So, the tax savings is 35 percent of the interest payment. 
Your program should use function definitions and should allow the user to repeat this calculation as often as they wish.

Sample output
Enter the price of the house: 
20000
Enter the down payment amount: 
5000
Annual cost is 1350 per year
Tax savings are 315 per year
Final cost is 1035 per year
Would you like to repeat?
*/


#include <iostream>

int annualMortgageCost (int price, int downPayment);

int main () {
	char repeat ='y';

	while (repeat=='y'){

		std::cout<<"Enter the price of the house: \n";

		int price, downPayment;

		std::cin>>price;

		std::cout<<"Enter the down payment amount: \n";

		std::cin>>downPayment;

		annualMortgageCost (price, downPayment);

		std::cout<<"Would you like to repeat? (y/n)\n";

		std::cin>>repeat;

	}

}

int annualMortgageCost (int price, int downPayment){
	int initialLoanBalance;

	float annualCost, taxSavings, finalCost;

	initialLoanBalance=price-downPayment;

	annualCost=0.03*static_cast<float>(initialLoanBalance)+0.06*static_cast<float>(initialLoanBalance);

	std::cout<<"Annual cost is "<<annualCost<<" per year\n";
	taxSavings=0.35*0.06*static_cast<float>(initialLoanBalance);

	std::cout<<"Tax savings are "<<taxSavings<<" per year\n";

	finalCost=annualCost-taxSavings;

	std::cout<<"Final cost is "<<finalCost<<" per year\n";

	return 0;
}
