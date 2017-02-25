/*
pg 307, supermarket case study, Savitch and Mock

We have been commissioned by the Quick-Shop supermarket chain to write a program that will determine the retail price of an item; 
given suitable input. 
Their pricing policy is that any item that is expected to sell in one week or less is marked up 5 percent, 
and any item that is expected to stay on the shelf for more than one week is marked up 10 percent over the wholesale price. 
Be sure to notice that the low markup of 5 percent is used for up to 7 days and that at 8 days the markup changes to 10 percent. 
It is important to be precise about exactly when a program should change from one form of calculation to a different one. 

Input
The input will consist of the wholesale price of an item (double) and the expected number of days until the item is sold.

Output
The output will give the retail price of the item.

Sample Output
Enter wholesale price of item:
45.67
Enter the expected number of days until sold: 
12
WholesalePrice: R45.67
daysUntilSale: 12

More than a week before sale
Retail price R50.237

*/

#include <iostream>

void getInput (double& price, int& daysSold);

void computeRetailPrice (double& rPrice, double WholesalePrice, int daysUntilSale);

int main(){
	double WholesalePrice, retailPrice;
	int daysUntilSale;

	getInput (WholesalePrice, daysUntilSale);

	std::cout<<"WholesalePrice: R"<<WholesalePrice<<std::endl;
	std::cout<<"daysUntilSale: "<<daysUntilSale<<std::endl;

	computeRetailPrice (retailPrice, WholesalePrice, daysUntilSale);

	std::cout<<"Retail price R"<<retailPrice<<std::endl;


}

void getInput (double& price, int& daysSold){

	std::cout<<"Enter wholesale price of item:\n";
	std::cin>>price;

	std::cout<<"Enter the expected number of days until sold: \n";
	std::cin>>daysSold;

}

void computeRetailPrice (double& rPrice, double WholesalePrice, int daysUntilSale){
	double markup1 {0.05}, markup2 {0.1};

	if (daysUntilSale<=7){
		rPrice=WholesalePrice*(1+markup1);
		std::cout<<"\nLess than a week before sale\n";
	}

	else{
		rPrice=WholesalePrice*(1+markup2);
		std::cout<<"\nMore than a week before sale\n";

	}

}