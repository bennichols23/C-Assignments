#include <iostream>
using namespace std;

/* Horizontal, Vertical, left/right diaganol, right triangle, left triangle, triangle*/

void lineH(int length) {
	for (int i = 0; i < length; i++) {
		cout << "*";
	}
	cout << endl << endl;
}

void lineV(int length) {
	for (int i = 0; i < length; i++) {
		cout << "*" << endl;
	}
	cout << endl << endl;
}

void lineLD(int length) {
	int spaceL = 0;
	for (int i = 0; i < length; i++) {
		for (int x = 0; x < spaceL; x++) {
			cout << " ";
		}
		cout << "*" << endl;
		spaceL++;
	}
	cout << endl << endl;
}

void lineRD(int length) {
	int spaceL = length-1;
	int s = spaceL;
	for (int i = 0; i < length; i++) {
		for (int x = spaceL; x > 0; x--) {
			cout << " ";
		}
		cout << "*" << endl;
		s--;
		spaceL = s;
	}
	cout << endl << endl;
}

void triangleR(int length) {
	int spaceL = 0;
	for (int i = 0; i < length; i++) {
		for (int x = 0; x < spaceL; x++) {
			cout << "*";
		}
		cout << "*" << endl;
		spaceL++;
	}
	cout << endl << endl;
}

void triangleL(int length) {
	int spaceL = length - 1;
	int s = spaceL;
	int a = 1;
	for (int i = 0; i < length; i++) {
		for (int x = spaceL; x > 0; x--) {
			cout << " ";
		}
		for (int y = 0; y < a; y++) {
			cout << "*";
		}
		cout << endl;
		a++;
		s--;
		spaceL = s;
	}
	cout << endl << endl;
}

void triangle(int length) {

}

int main() {

	int input;

	cout << "Input number of asterics for a horizontal line: ";
	cin >> input;

	lineH(input);

	cout << "Input number of asterics for a vertical line: ";
	cin >> input;

	lineV(input);

	cout << "Input number of asterics for a left-diagonal line: ";
	cin >> input;

	lineLD(input);

	cout << "Input number of asterics for a right-diagonal line: ";
	cin >> input;

	lineRD(input);

	cout << "Input number of asterics for a right-triangle line: ";
	cin >> input;

	triangleR(input);

	cout << "Input number of asterics for a left-triangle line: ";
	cin >> input;

	triangleL(input);
	
	bool valid = false;
	while (valid == false) {
		cout << "Input number of asterics for a triangle: ";
		cin >> input;
		if (input % 2 != 0) {
			valid = true;
		}
		else {
			cout << "Error! Input MUST be an odd number!" << endl << endl;
		}
	}

	triangle(input);

	system("PAUSE");
	return 0;
}