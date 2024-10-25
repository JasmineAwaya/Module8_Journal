//Jasmine Awaya
//September 17th, 2024

#include <iostream>
#include <iomanip>
using namespace std;

class Clock {
//Inputs of time are integers
private:
	int hours;
	int minutes;
	int seconds;
//Inputs are in this specific format
public:
	Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
//If hour is added, it adds 1 hour to time 
	void addHour() {
		hours = (hours + 1) % 24;
	}
	//If minute is added, it adds 1 minute to time 
	void addMinute() {
		minutes = (minutes + 1) % 60;
		//1 hour is added if minute is 0 
		if (minutes == 0) {
			addHour();
		}
	}
	//If second is added, it adds 1 second to time 
	void addSecond() {
		seconds = (seconds + 1) % 60;
		// if seconds is 0 a minute is added
		if (seconds == 0) {
			addMinute();
		}
	}
//Display 12 hour clock
	void display12HourFormat() {
		int displayHour = hours % 12;
		// 12pm and 12am are both 12
		if (displayHour == 0) displayHour = 12;
		//display if its morning or night
		std::string period = (hours < 12) ? "AM" : "PM";
		//set width to 2 places, place a 0 infront of one digit input, with a colon between
		std::cout << std::setw(2) << std::setfill('0') << displayHour << ":"
			<< std::setw(2) << std::setfill('0') << minutes << ":"
			<< std::setw(2) << std::setfill('0') << seconds << " "
			<< period << std::endl;
	}
//Display 24 hour clock
	void display24HourFormat() {
		// /set width to 2 places, place a 0 infront of one digit input, with a colon between
		std::cout << std::setw(2) << std::setfill('0') << hours << ":"
			<< std::setw(2) << std::setfill('0') << minutes << ":"
			<< std::setw(2) << std::setfill('0') << seconds << std::endl;
	}
};
//Menu with choices
void displayMenu() {
	std::cout << "1. Add Hour" << std::endl;
	std::cout << "2. Add Minute" << std::endl;
	std::cout << "3. Add Second" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "Enter your choice: ";
}
//Main
int main() {
	int initialHours, initialMinutes, initialSeconds;

// Input initial time
	std::cout << "Enter initial time (hours, minutes, seconds): ";
	std::cin >> initialHours >> initialMinutes >> initialSeconds;
	Clock clock(initialHours, initialMinutes, initialSeconds);

//Display both 12hr and 24hr clock
	int choice;
	while (true) {
		std::cout << "12-Hour Clock: ";
		clock.display12HourFormat(); 
		std::cout << "24-Hour Clock: ";
		clock.display24HourFormat(); 
	
//Display menu
		displayMenu(); // Display the menu options
		std::cin >> choice;
		switch (choice) {
		//Add hour
		case 1:
			clock.addHour(); 
			break;
		//Add minute
		case 2:
			clock.addMinute(); 
			break;
		//Add second
		case 3:
			clock.addSecond(); 
			break;
		//Exit
		case 4:
			return 0; 
		default:
			std::cout << "Invalid choice. Please try again." << std::endl; // Handle invalid choice
		}
	}
	return 0;
};