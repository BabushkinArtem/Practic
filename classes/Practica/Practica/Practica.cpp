#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>
#define DEBUG_FLG
using namespace std;

class Author {
private:
	string dateBirth, lastName, firstName;

public:
	void set_firstName() {
		while (!regex_match(firstName, regex("[A-Z][a-z]{1,32}"))) {
			cout << "Enter a first name > 3 characters:\n";
			getline(cin, firstName);
			if (firstName == "")
				cout << "\nERROR 5: Is empty!\n\n";
		}
	}

	string get_firstName() {
		return firstName;
	}

	void set_lastName() {
		while (!regex_match(lastName, regex("[A-Z][a-z]{1,32}"))) {
			cout << "Enter a last name > 3 characters:\n";
			getline(cin, lastName);
			if (lastName == "")
				cout << "\nERROR 5: Is empty!\n\n";
		}
	}

	string get_lastName() {
		return lastName;
	}
	void set_dateBirth() {
		while (!regex_match(dateBirth, regex("^(([0][1-9])|([1][0-2]))[.]((([0][1-9])|([1-2][0-9]))|([3][01]))[.](([1][9][0-9][0-9])|([2][0][0-2][0-3]))$"))) {
			cout << "Enter Date mm.dd.yyyy: \n";
			getline(cin, dateBirth);
		}
	}
	string get_dateBirth() {
		return(dateBirth);
	}
};


class Publishing {
private:
	string Title;
	int yearPublishing;
	char tmp_yearPublishing[255];



public:
	void set_Title() {
		while (!regex_match(Title, regex("[A-Z][a-z]{1,32}"))) {
			cout << "Enter a title > 3 characters:\n";
			getline(cin, Title);
			if (Title == "")
				cout << "\nERROR 5: Is empty!\n\n";
		}
	}

	string get_Title() {
		return Title;
	}

	void set_yearPublishing() {
		while ((yearPublishing < 1900) || (yearPublishing > 2023)) {	// 1900 > Year < 2023
			cout << "Enter the year of publication:\n";
			cin >> tmp_yearPublishing;
			yearPublishing = atoi(tmp_yearPublishing); //Year is entered as a char, converted to int
		}
	}

	int get_yearPublishing() {
		return yearPublishing;
	}

};


int main() {

	Author test;
	Publishing test2;
	test.set_dateBirth();
	test.set_firstName();
	test2.set_yearPublishing();
	cout << test.get_dateBirth() << "\n"<<test.get_firstName()<<"\n"<<test2.get_yearPublishing();
	return 0;
}