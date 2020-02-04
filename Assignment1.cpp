// Author: Ben Nichols
// This program takes two floating-point numbers (a and b) through the keyboard and shows the results 
// of the four main arithmetic operations (a + b, a - b, a * b, a / b) on the screen

#include <iostream>
using namespace std;

int main() {

	// Prompt user for numbers A and B and recieve input from keyboard

	float a;
	float b;

	cout << "Input number A: ";
	cin >> a;

	cout << "Input number B: ";
	cin >> b;

	cout << endl; // Line break

	// Output calculations to the screen

	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;

	cout << endl; // Line break

	// Notify user the program has ended; press any button to exit

	system("pause");
	return 0;

}