/*
Author: Ben Nichols
Assignment 4: Files and Exceptions
Date: February 4th, 2019
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void createFile() {
	int userInput;
	string fileName;
	string fileLocation = R"(C:\Users\300277739\Desktop\as4\)";
	cout << "Enter file name to create: ";
	cin >> fileName;

	ifstream newFile;

	newFile.open(fileLocation+fileName+".dat");
	if (newFile.fail()) {
		newFile.close();
		ofstream newFile;
		newFile.open(fileLocation + fileName + ".dat");
		if (newFile.fail()) {
			cout << endl << "There was an error creating the file!";
		}
		else {
			cout << endl << "File has been created successfuly!";
		}
	}
	else {
		newFile.close();
		ofstream newFile;
		cout << endl << "A file with the name "+fileName+".dat already exists!";
		cout << endl << "Press 1 to remove the file and create a new one" << endl << "Press 2 to keep the file and return to menu" << endl << endl;
		cout << "Enter here: ";
		cin >> userInput;

		if (userInput == 1) {
			newFile.open(fileLocation + fileName + ".dat");
			if (newFile.fail()) {
				cout << endl << "There was an error creating the file!";
			}
			else {
				cout << endl << "File has been created successfuly!";
			}
		}
		else if (userInput != 2) {
			cout << endl << "Invalid input!";
		}
	}

	newFile.close();

	cout << endl << endl;
}

void searchStudent() {
	int userInput;
	string fileName;
	string fileLocation = R"(C:\Users\300277739\Desktop\as4\)";

	cout << "Enter the name of the file to open: ";
	cin >> fileName;

	ifstream file;

	file.open(fileLocation + fileName + ".dat");
	if (file.fail()) {
		cout << endl << "A file with the name " + fileName + ".dat could not be found!";
	}
	else {
		string studentN;
		string search;
		bool found = false;
		cout << "Enter a student ID to search for: ";
		cin >> studentN;
		cout << endl;

		while (file >> search) {
			if (search == studentN) {
				getline(file, search);
				cout << "Student number " + studentN + " was found! Retrieving grade." << endl;
				cout << studentN + ":" + search;
				found = true;
				break;
			}
		}

		if (found == false) {
			cout << "Could not find student number " + studentN + " in file " + fileName + ".dat";
		}

	}

	file.close();

	cout << endl << endl;
}

void addStudent() {
	int userInput;
	string fileName;
	string fileLocation = R"(C:\Users\300277739\Desktop\as4\)";

	cout << "Enter name of file to open: ";
	cin >> fileName;
	cout << endl;

	ofstream file;

	file.open(fileLocation + fileName + ".dat", ios::app);
	if (file.fail()) {
		cout << "A file with the name " + fileName + ".dat does not exist!" << endl;
	}
	else {
		string studentID;
		string firstN;
		string lastN;
		string gradeL;
		string search;
		bool found = false;
		int gradeP;
		int length;
		bool valid = false;

		while (valid == false) {
			while (found == false) {
				found = true;
				cout << "Enter students' student ID: ";
				cin >> studentID;
				length = studentID.length();

				ifstream searchFile;
				searchFile.open(fileLocation + fileName + ".dat");

				while (searchFile >> search) {
					if (search == studentID) {
						cout << "A student with number " + studentID + " already exists!" << endl;
						found = false;
						break;
					}
				}

				if (length != 9) {
					cout << "Error! Student ID must be 9 digits long!" << endl;
					valid = false;
				}
				else {
					valid = true;
				}

				searchFile.close();

			}
			if (valid == false) {
				found = false;
			}
		}
		cout << "Enter students' first name: ";
		cin >> firstN;
		cout << "Enter students' last name: ";
		cin >> lastN;
		valid = false;
		while (valid == false) {

			cout << "Enter students' percentage: ";
			cin >> gradeP;
			if (gradeP > 100 || gradeP < 0) {
				cout << "Error! Student percentage must be between 0 and 100" << endl;
			}
			else {
				valid = true;
			}
		}

		if (gradeP <= 100 && gradeP >= 86) {
			gradeL = "A";
		}
		else if (gradeP <= 85 && gradeP >= 73) {
			gradeL = "B";
		}
		else if (gradeP <= 72 && gradeP >= 67) {
			gradeL = "C+";
		}
		else if (gradeP <= 66 && gradeP >= 60) {
			gradeL = "C";
		}
		else if (gradeP <= 59 && gradeP >= 50) {
			gradeL = "C-";
		}
		else {
			gradeL = "F";
		}

		file << studentID << " " << firstN << " " << lastN << " - " << gradeP << "% | " << gradeL << endl;
		cout << endl << "File has been updated!";
	}

	cout << endl << endl;

	file.close();
}

int main() {
	int userInput;
	bool run = true;

	while (run == true) {
		cout << "Press 1 to create a new gradebook file" << endl << "Press 2 to search a student in an existing gradebook file" << endl << "Press 3 to add a student record" << endl << "Press 4 to end program" << endl;
		cout << endl << "Enter here: ";
		cin >> userInput;
		cout << endl;

		if (userInput == 1) {
			createFile();
		}
		else if (userInput == 2) {
			searchStudent();
		}
		else if (userInput == 3) {
			addStudent();
		}
		else if (userInput == 4) {
			cout << "Program terminating" << endl;
			run = false;
		}
		else {
			cout << "Error! Must select a valid option" << endl << endl;
		}

	}

	system("PAUSE");
	return 0;
}

/*
int main() {
	ifstream inputFile;

	inputFile.open();

	if (inputFile.fail()) {
		cout << "Error! "+fileN+" could not be found in directory "+fileL+"!" << endl;
	}

	string thing;

		inputFile >> thing;

		inputFile.close();

*/