/*
chapter2, page 135, programming projects 1

Sample Output:
Enter your weight in kilograms: 45.4
You can drink 18365 cans

Enter your weight in kilograms: 37.29
You can drink 15099 cans
*/
#include <iostream>

int calculateAmount(int weight);

int main(){
	char again='y';

	while (again=='y'){
		std::cout<<"Enter your weight in kilograms: \n";
		int cans;
		float weight;

		std::cin>>weight;

		cans = calculateAmount(weight);

		std::cout<<"You can drink "<<cans<<" cans\n";

		std::cout<<"Enter y to calculate again, anything else to exit\n";

		std::cin>>again;
		}
		std::cout<<"Exiting\n";
}

int calculateAmount(int weight){
	const int mouseSweetener {5}, mouseMass {35}, canMass {350}; //grams
	const float sweetenerFraction {0.001};
	int canNumber, humanSweetener;

	humanSweetener=(weight*1000)*(static_cast<float>(mouseSweetener)/mouseMass);//grams of sweetener safe to consume

	canNumber=humanSweetener/((static_cast<float>(sweetenerFraction)*canMass));

	return canNumber;
}