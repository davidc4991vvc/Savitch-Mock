/*
chapter5, page 329, programming projects 1

Write a program which converts temperature between Fahrenheit and Celcius. If the temperature which is entered is Celcius, 
the program should convert to Fahrenheit and vice versa. The input should be a double, and a c or f for temp scale.
The program should allow the user to repeat the calculation as many times as they wish.

C=5/9*(F-32)

Sample output
Convert temperature between Fahrenheit and Celcius

Enter temperature value to convert: 
34
Enter temperature scale, c for Celcius, f for Fahrenheit
c
temperature = 34c
Converting to Fahrenheit
34 in Celcius is 93.2 in Fahrenheit

*/

#include <iostream>

void getInput (double& input, char& selection);

void convert (double temp, char select);

int main (){
	std::cout<<"\nConvert temperature between Fahrenheit and Celcius\n";

	double temp;
	char select;

	getInput(temp, select);

	std::cout<<"temperature = "<<temp<<select<<std::endl;

	convert (temp, select);

}


void getInput (double& input, char& selection){
	std::cout<<"\nEnter temperature value to convert: \n";
	std::cin>>input;

	std::cout<<"Enter temperature scale, c for Celcius, f for Fahrenheit\n";

	std::cin>>selection;
}

void convert (double temp, char select){
	double coefficient = 5.0/9.0, result;

	if (select=='f'||select=='F'){
		std::cout<<"Converting to Celcius"<<std::endl;

		result=coefficient*(temp-32);

		std::cout<<temp<<" in Fahrenheit is "<<result<<" in Celcius\n";
	}

	else if(select=='c'||select=='C'){
		std::cout<<"Converting to Fahrenheit"<<std::endl;

		result=((1/coefficient)*temp)+32;

		std::cout<<temp<<" in Celcius is "<<result<<" in Fahrenheit\n";
	}

	else{
		std::cout<<"Sorry, but I don't recognize that input\n";
	}
}