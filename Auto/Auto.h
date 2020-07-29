#pragma once
#include<iostream>
#include<string>
using namespace std;
class Exception {
public:
	Exception(const string& massege = "Some error") :massege(massege) {

	}
	string massege;
	const string& what() {
		return massege;
	}
	
};
class WrongMaxSpeedException :public Exception {
public:
	WrongMaxSpeedException(const string& massege="Bad max speed") :Exception(massege) {

	}
};
class WrongSpeedException :public Exception {
public:
	WrongSpeedException(const string& massege="Bad speed") :Exception(massege) {

	}
};
class InvalidNumberException :public Exception {
public:
	InvalidNumberException(const string& massege="Bad car number") :Exception(massege) {

	}
};
class Auto {
public:
	void checkNumber(const string& number) {
		if (number.size() > 8||number.size()<8) {
			throw InvalidNumberException("Number has mor or lass then 8 sumbols");
		}
		for (size_t i = 0; i < number.size(); i++)
		{
		    if (!isalpha(number[i]) || !isalpha(number[number.size() - i - 1])){
				throw InvalidNumberException("Invalid number");
			}
			
		}
		this->number = number;
		
	}
	void checkMaxSpeed(size_t mSpeed) {
		if (mSpeed > 360) {
			throw WrongMaxSpeedException("Wrong max speed");
		}
		this->maxSpeed = mSpeed;
        
	}
	void checkSpeed(size_t speed) {
		if (speed >maxSpeed) {
			throw WrongSpeedException("Wrong speed");
		}
		this->speed = speed;
		
	}
	const string& getNumber() {
		return number;
	}
	size_t getMaxSpeed() {
		return maxSpeed;
	}
	size_t getSpeed() {
		return speed;
	}
	void plus() {
		if (speed + 5 > maxSpeed) {
			throw WrongSpeedException("Wrong speed");
		}
		speed += 5;
	}
	void minus() {
		speed -= 5;
	}
private:
	string number;
    size_t maxSpeed ;
	size_t speed;
};