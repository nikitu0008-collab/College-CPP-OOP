#include <iostream>
#include <string>
struct Person {
	std::string name, familiya, zodiac;
	int day, month, year;
};
void dataPerson(Person& person) {
	std::cin >> person.name >> person.familiya >> person.day >> person.month >> person.year;	
}
int main() {
	Person person;
	std::string name, familiya, zodiac;
	int day = 0, month = 0, year = 0;
    std::cout << "writing name, fam, data create: " << std::endl;
	dataPerson(person);

    if (person.month < 1 || person.month > 12 || person.day < 1 || person.day > 31) {
        zodiac = "Incorected date";
    }
    else {
        if ((person.month == 1 && person.day >= 20) || (person.month == 2 && person.day <= 18)) {
    zodiac = "Aquarius";
        }
        else if ((person.month == 2 && person.day >= 19) || (person.month == 3 && person.day <= 20)) {
            zodiac = "Pisces";
        }
        else if ((person.month == 3 && person.day >= 21) || (person.month == 4 && person.day <= 19)) {
            zodiac = "Aries";
        }
        else if ((person.month == 4 && person.day >= 20) || (person.month == 5 && person.day <= 20)) {
            zodiac = "Taurus";
        }
        else if ((person.month == 5 && person.day >= 21) || (person.month == 6 && person.day <= 20)) {
            zodiac = "Gemini";
        }
        else if ((person.month == 6 && person.day >= 21) || (person.month == 7 && person.day <= 22)) {
            zodiac = "Cancer";
        }
        else if ((person.month == 7 && person.day >= 23) || (person.month == 8 && person.day <= 22)) {
            zodiac = "Leo";
        }
        else if ((person.month == 8 && person.day >= 23) || (person.month == 9 && person.day <= 22)) {
            zodiac = "Virgo";
        }
        else if ((person.month == 9 && person.day >= 23) || (person.month == 10 && person.day <= 22)) {
            zodiac = "Libra";
        }
        else if ((person.month == 10 && person.day >= 23) || (person.month == 11 && person.day <= 21)) {
            zodiac = "Scorpio";
        }
        else if ((person.month == 11 && person.day >= 22) || (person.month == 12 && person.day <= 21)) {
            zodiac = "Sagittarius";
        }
        else {
            zodiac = "Capricorn";
        }
    }
    std::cout << "Hello " << person.name << " " << person.familiya << " " << person.day << "." << person.month << "." << person.year << " d.t., your age: " << 2025 - person.year << ", and your zodiac: " << zodiac;

    return EXIT_SUCCESS;
}
