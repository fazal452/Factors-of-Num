#include <iostream>
#include <iomanip>
using namespace std;

int sum_of_digits(int number);
int product_of_digits(int number);


int main() {

	//Initiliaze start variables
	int first_digit = 0;
	int second_digit = 1000;

	//Asking Users for Input
	cout << "enter value between 1 and 999: ";
	cin >> first_digit;
	while (first_digit < 1 || first_digit > 999) {
		cout << "The value must be greater than 0 and less than 1000: ";
		cin >> first_digit;
	}

	cout << "enter a second value between 1 and 999: ";
	cin >> second_digit;
	while (second_digit < 1 || second_digit > 1000) {
		cout << "The value must be greater than 0 and less than 1000: ";
		cin >> second_digit;
	}

	//Swap start and end points if needed
	if (first_digit > second_digit) {

		int temp = first_digit;
		first_digit = second_digit;
		second_digit = temp;
		
	}
	cout << endl;


	//Cycle Through all numbers in range(startpoint,endpoint)
	for (int num = first_digit; num <= second_digit; num++) {

		cout << setw(3) << num;

		int counter = 0;

		//Cycle through all possible factors of "num"
		for (int possible_factor = 1; possible_factor <= num; possible_factor++) {

			if (num % possible_factor == 0)
			{
				//Increment counter for every factor found
				//Print out said factor
				counter++;
				cout << setw(5) << possible_factor;
			}
		}

		//Print total number of factors found
		cout << setw(4) << "(" << counter << ")";


		//Check through logic of Factors
		if (counter % 2 == 1) {
			cout << setw(5) << " **Perfect Square** ";
		}

		if (counter == 2){
			cout << setw(5) << " **Prime Number** ";
		}

		cout << endl;
	}

	// Print sum of first digits
	cout << endl << first_digit << ": sum of digits = " << sum_of_digits(first_digit);

	// Check if number is an INTERESTING number
	if (product_of_digits(first_digit) + sum_of_digits(first_digit) == first_digit) {
		cout << "  -- Interesting Number --  ";
	}

	// Print sum of second digits
	cout << endl << second_digit << ": sum of digits = " << sum_of_digits(second_digit);

	// Check if number is an INTERESTING number
	if (product_of_digits(second_digit) + sum_of_digits(second_digit) == second_digit) {
		cout << "  -- Interesting Number --  ";
	}

	return(0);
}


int sum_of_digits(int number)
{
	//Use math to find all digits (only 3 digits to find due to restrictions)
	int last_digit = number % 10;
	int second_last_digit = (number / 10) % 10;
	int first_digit = (number / 100) % 10;

	//Calculate sum of digits and return them
	int sum = last_digit + second_last_digit + first_digit;
	return (sum);
}

int product_of_digits(int number) {

	//Use math to find all digits (only 3 digits to find due to restrictions)
	int last_digit = number % 10;
	int second_last_digit = (number / 10) % 10;
	int first_digit = (number / 100) % 10;

	//Neccassary step in order to find product of numbers
	//Empty spaces return 0 as digit, and to avoid mult by 0, we add 1
	if (last_digit == 0) {
		last_digit += 1;
	}
	if (second_last_digit == 0) {
		second_last_digit += 1;
	}
	if (first_digit == 0) {
		first_digit += 1;
	}

	//Find and return product of digits
	int product = last_digit * second_last_digit * first_digit;
	return(product);
	
}
