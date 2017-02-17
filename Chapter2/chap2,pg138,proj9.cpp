/*
Write a program that reads in ten whole numbers and that outputs the sum of all the numbers greater than zero, the sum of all the numbers less
than zero (which will be a negative number or zero), and the sum of all the numbers, whether positive, negative, or zero. 
The user enters the ten numbers just once each and the user can enter them in any order. Your program should not ask the user to enter the positive numbers and the
negative numbers separately.
*/
#include <iostream>
#include <vector>

int calculate (std::vector<int> input);

int main(){
	std::cout<<"Enter ten numbers: \n";
	std::cout<<"\nEntering a non integer will exit \n";
	std::vector<int> input;

	int i {1};

	std::cout<<"Entry number: "<<i<<std::endl;

	for (int entry; std::cin>>entry;){
		std::cout<<"Entry number: "<<i<<std::endl;
		input.push_back(entry);
		++i;
	}

	//std::cout<<input.size()<<std::endl;

	if (input.size()!=11){
		std::cout<<"You didn't enter 10 numbers!"<<std::endl;
	}

	else{
		calculate (input);
	}
	

}

int calculate (std::vector<int> input){
	int sum {0}, sumPositive {0}, sumNegative {0};

	std::cout<<"You entered: "<<std::endl;

	for (int i =0; i<input.size()-1;++i){
		std::cout<<input[i]<<" ";
	}

	for (int i=0;i<input.size();++i){
		if (input[i]>0){
			sumPositive+=input[i];
		}

		else{
			sumNegative+=input[i];
		}

	}

	sum = sumPositive-sumNegative;

	std::cout<<"\nPositive sum: "<<sumPositive<<std::endl;
	std::cout<<"Negative sum: "<<sumNegative<<std::endl;
	std::cout<<"Sum: "<<sum<<std::endl;

	return 0;
}