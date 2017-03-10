/*
chapter1, page 66, programming projects 1

*/
#include <iostream>

int main(){
	std::cout<<"Enter score one: \n";

	int score1, score2, difference;

	std::cin>>score1;

	std::cout<<"Enter score two: \n";

	std::cin>>score2;

	difference = score1-score2;

	std::cout<<"The difference between scores is: "<<difference<<std::endl;

	float average = static_cast<float>((score1+score2))/2;

	std::cout<<"The average is: "<<average<<std::endl;

}