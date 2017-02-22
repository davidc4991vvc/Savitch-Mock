/*
chapter3, page 204, programming projects 2

A triangle can be of three types: all sides are equal, only two sides are equal, all three sides are unequal.
Write a program which allows the user to enter the three sides of the triangle. Use three double variables to store the triangle sides.
The program should print the three angles if the triangle is equilateral.
If the triangle is isosceles, it should prompt the user to input the odd angle and the program should print the remaining angles.
If all the sides are unequal, the program should do nothing.

*/

#include <iostream>

int printAngles(double side1, double side2, double side3);

int main(){
	std::cout<<"Enter the length of side one: \n";
	double side1, side2, side3;

	std::cin>>side1;

	std::cout<<"Enter the length of side two: \n";

	std::cin>>side2;

	std::cout<<"Enter the length of side three: \n";

	std::cin>>side3;

	printAngles(side1,side2,side3);
}

int printAngles(double side1, double side2, double side3){

	if(side1==side2 && side2==side3){
		std::cout<<"Angle 1: 60, Angle 2: 60, Angle 3: 60\n";
		

	}

	else if (side1==side2 || side1==side3) {
		std::cout<<"The triangle is isosceles.\n";
		std::cout<<"Enter the odd angle: \n";

		double oddAngle, otherAngle;

		std::cin>>oddAngle;
		otherAngle=(180-oddAngle)/2;

		std::cout<<"The other two angles are: "<<otherAngle<<std::endl;
		

	}
	else {
		std::cout<<"None of the sides are equal\n";

	}
	return 0;
	
}

