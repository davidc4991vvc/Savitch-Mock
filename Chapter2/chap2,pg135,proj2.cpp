/*
chapter2, page 136, programming projects 2

Workers have won a 7.6% pay increase retroactive for 6 months. Write a program which takes an employee's previous annual salary as input and outputs the amount of retroactive pay due.
Also output the new annual salary, and the new monthly salary.
Your program should allow the calculation to be repeated as many times as the user wishes.

Sample Output:
previous Salary: 100 1000
payout: 3800
annualSalary: 107600
monthlySalary: 8966.67

*/
#include <iostream>

int calculatePay(int salary);

int main(){
	char repeat='y';

	while (repeat=='y'){
		std::cout<<"Enter annual salary in Rands: \n";
		int salary;

		std::cin>>salary;

		calculatePay(salary);

		std::cout<<"Enter y to repeat, anything else to exit: \n";
		std::cin>>repeat;

	}
	std::cout<<"Exiting..\n";

}

int calculatePay(int salary){
	const float percentIncrease {0.076};
	float annualSalary, monthlySalary, payOut;
	const int months {6};

	payOut=(static_cast<float>(months)/12)*salary*percentIncrease;

	annualSalary=payOut*(12/(months))+salary;//double payOut added to get yearly salary

	monthlySalary=annualSalary/12;

	std::cout<<"Payout: R "<<payOut<<std::endl;

	std::cout<<"annualSalary: R"<<annualSalary<<std::endl;

	std::cout<<"monthlySalary: R"<<monthlySalary<<std::endl;
	return 0;
}
