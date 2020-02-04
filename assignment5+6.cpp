#include <iostream>
using namespace std;

int locate(const int l[], int n, int k);
int locateSort(const int l[], int n);
int recursionFunction(const int l[], int n, int k);
int matrixFunction();

const int ARRAY_SIZE = 5;
const int MATRIX_SIZE = 6;

int main() {

	int array[ARRAY_SIZE] = {5, 3, 6, 7, 2};
	int searchFor = 6;

	cout << "- - - Locate function - - -" << endl << endl;

	int found = locate(array, ARRAY_SIZE, searchFor);
	cout << found << " numbers less than or equal to " << searchFor << endl << endl;

	cout << "- - - Sorting function - - -" << endl << endl;
	locateSort(array, ARRAY_SIZE);


	cout << endl << endl << "- - - Recursion Function - - -" << endl << endl;

	int a = recursionFunction(array, 0, searchFor);
	if (a == -1) {
		cout << "No integers with value " << searchFor << " were found";
	}
	else {
		cout << "An integer with value " << searchFor << " was found";
	}

	cout << endl << endl << "- - - Matrix Function - - -" << endl << endl;

	matrixFunction();

	cout << endl;
	system("PAUSE");
	return 0;
}

int locate(const int l[], int n, int k) {

	int inc = 0;

	for (int i = 0; i < n; i++) {
		if (l[i] <= k) {
			inc++;
		}
	}

	return inc;

}

int locateSort(const int l[], int n) {

	int found = 0;
	int sort = 0;
	int sortedArray[ARRAY_SIZE];

	for (int i = 0; i < n; i++) {
		sortedArray[i] = 0;
	}

	for (int a = 0; a < n; a++) {
		sort = l[a];
		found = locate(l, n, sort);
		sortedArray[found-1] = sort;
		for (int i = 0; i < n; i++) {
			cout << sortedArray[i] << " ";
		}
		cout << endl;
	}

	cout << endl << "Sorting completed";

	return found;
}

int recursionFunction(const int l[], int n, int k) {

	if (n == ARRAY_SIZE) {
		return -1;
	}
	else if (l[n] == k) {
		return n;
	}
	else {
		return recursionFunction(l, n + 1, k); 
	}
}

int matrixFunction() {
	int matrix[MATRIX_SIZE][MATRIX_SIZE];

	for (int a = 0; a < MATRIX_SIZE; a++) {
		for (int b = 0; b < MATRIX_SIZE; b++) {
			matrix[a][b] = b;
		}
	}

	bool rep;
	rep = true;
	int col, row;

	while (rep == true) {
		cout << "Enter column number (0 - " << MATRIX_SIZE - 1 << "): ";
		cin >> col;
		cout << "Enter row number (0 - " << MATRIX_SIZE - 1 << "): ";
		cin >> row;

		if (col >= MATRIX_SIZE || row >= MATRIX_SIZE) {
			cout << endl << "Invalid column or row entered, terminating function.";
			break;
		}
		else {
			cout << "Column " << col << ", Row " << row << ": " << matrix[col][row] << endl << endl;
		}
	}

	return 0;
}