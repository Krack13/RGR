#include <iostream>
#include <string>
using namespace std;

class people {
private:
	string name, surname, number;
public:
	string getName() {return name;}
	string getSurname() {return surname;}
	string getNumber() {return number;}
	people() {name = "Руслан";surname = "Семенов";number = "89137776655";}
	people(string name, string surname, string number) {this->name = name;this->surname = surname;this->number = number;}
	void print() {cout << surname << " " << name << " - " << number << endl;}
};

