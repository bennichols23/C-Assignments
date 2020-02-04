#include <iostream>
using namespace std;

int main() {

	cout << "Input a character: ";

	char input; cin.get(input);

	if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z') {
		cout << input << " is an alphabetical letter.";
	}
	else if (input >= '0' && input <= '9') {
		cout << input << " is a number.";
	}
	else if (input == '+' || input == '-' || input == '*' || input == '/') {
		cout << input << " is an arithematic operation.";
	}
	else {
		cout << input << " ASCII code is " << static_cast<int>(input);
	}

	cout << endl;
	system("PAUSE");
	return 0;
}