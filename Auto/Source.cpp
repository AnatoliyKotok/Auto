#include<iostream>
#include"Auto.h"

using namespace std;

int main() {
	Auto aut;
	try {
		aut.checkNumber("AM2345MH");
		cout << "Number->" << aut.getNumber() << endl;
	}
	catch (InvalidNumberException & ex) {
		cout << ex.what() << endl;
	}
	try {
		aut.checkMaxSpeed(360);
		cout << "Max speed->" << aut.getMaxSpeed() << endl;

	}
	catch (WrongMaxSpeedException & ex) {
		cout << ex.what() << endl;
	}
	try {
		aut.checkSpeed(56);
		//aut.plus();
		aut.minus();
		cout << "Speed->" << aut.getSpeed() << endl;
	}
	catch (WrongSpeedException & ex) {
		cout << ex.what() << endl;
	}
}
