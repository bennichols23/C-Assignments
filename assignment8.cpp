#include <iostream>
#include <cctype>
using namespace std;

int part1();
void part2();
void part3();

const int SIZE = 100;
char s1[SIZE];
char s2[SIZE];
char s3[SIZE*2];

int main() {
	cout << "Enter a string of no more than " << (SIZE - 1) << " characters: ";
	cin.getline(s1, SIZE);

	cout << "Enter a string of no more than " << (SIZE - 1) << " characters: ";
	cin.getline(s2, SIZE);

	/* Part 1 */
	int comparison = part1();

	if (comparison == 0) {
		cout << endl << "There are no differences between the two CStrings" << endl << endl;
	}
	else {
		cout << endl << "ASCII difference between the first two different characters: " << comparison << endl << endl;
	}

	/* Part 2 */
	part2();

	/* Part 3 */
	part3();
	

	cout << endl;
	system("PAUSE");
	return 0;
}

int part1() {
	int compare, count, size1, size2;
	size1 = 0; size2 = 0; compare = 0; count = 0;
	while (s1[size1] != '\0') {
		size1++;
	}
	while (s2[size2] != '\0') {
		size2++;
	}
	if (size1 > size2){
		while (s1[count] != '\0') {
			compare = compare + (s1[count] - s2[count]);
			count++;
			if (compare != 0) {
				break;
			}
		}
	}
	else {
		while (s2[count] != '\0') {
			compare = compare + (s1[count] - s2[count]);
			count++;
			if (compare != 0) {
				break;
			}
		}
	}
	return compare;
}

void part2() {
	int counter = 0;
	int lower = 0;
	int upper = 0;
	while (s1[counter] != '\0') {
		cout << s1[counter];
		if (islower(s1[counter])) {
			lower++;
		}
		else if (s1[counter] != 32) {
			upper++;
		}
		counter++;
	}
	counter = 0;
	cout << endl << "Uppercase Letters: " << upper;
	cout << endl << "Lowercase Letter: " << lower << endl << endl;
	upper = 0;
	lower = 0;
	while(s2[counter] != '\0') {
		cout << s2[counter];
		if (islower(s2[counter])) {
			lower++;
		}
		else if (s2[counter] != 32) {
			upper++;
		}
		counter++;
	}
	cout << endl << "Uppercase Letters: " << upper;
	cout << endl << "Lowercase Letter: " << lower;
}

void part3() {
	cout << endl << endl;
	int count = 0;
	int count2 = 0;
	while (s1[count] != '\0') {
		s3[count] = s1[count];
		count++;
	}
	while (s2[count2] != '\0') {
		s3[count + count2] = s2[count2];
		count2++;
	}
	count = 0;
	while (s3[count] != '\0') {
		cout << s3[count];
		count++;
	}
}