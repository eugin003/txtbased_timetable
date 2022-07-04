#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

using std::string;
using namespace std;

void HUB();
void SearchModule();
void Lesson();
void Details();
void ERRlogs();
void TTdetails();
void ShowLessons(int null);

vector<int> daycheck;
int t = 1;
string days[] = { "Sun","Mon","Tues","Wednes","Thurs","Fri","Satur" };
string timetable[10][10];
vector<string>_modules, _lecturer, _hour, _type, _room, _building, _description;
vector<int> _day, _duration;;
bool start = false;

// https://stackoverflow.com/users/760453/user760453 Wanted to output text with color in the terminal
namespace ansi {
	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& reset(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[0m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& foreground_black(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[30m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& foreground_red(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[31m";
	}

	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& foreground_gold(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[33m";
	}
	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& foreground_blue(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[34m";
	}
	template < class CharT, class Traits >
	constexpr
		std::basic_ostream< CharT, Traits >& foreground_green(std::basic_ostream< CharT, Traits >& os)
	{
		return os << "\033[32m";
	}
}

class Modules {
public:
	string Module, Description, Lecturer, Hour, Type, Room, Building;
	int Day, Duration;

	void Add() {
		bool check = false;
		if (std::count(daycheck.begin(), daycheck.end(), Day)) {
			check = true;
		}
		else {
			daycheck.push_back(Day);
			check = false;
		}
		if (check) {
			if (Type == "FC") {
				timetable[Day - 1][t] = Module + " (FC)";
			}
			else {
				timetable[Day - 1][t] = Module;
			}
			t++;
		}
		else {
			if (Type == "FC") {
				timetable[Day - 1][0] = Module + " (FC)";
			}
			else {
				timetable[Day - 1][0] = Module;
			}
		}
		
		_modules.push_back(Module);
		_lecturer.push_back(Lecturer);
		_description.push_back(Description);
		_day.push_back(Day);
		_hour.push_back(Hour);
		_duration.push_back(Duration);
		_type.push_back(Type);
		_room.push_back(Room);
		_building.push_back(Building);

	}
	Modules(string module, string lecturer, string description, int day, string hour, int duration, string type, string room, string building) {
		Module = module;
		Lecturer = lecturer;
		Description = description;
		Day = day;
		Hour = hour;
		Duration = duration;
		Type = type;
		Room = room;
		Building = building;
	}
};

void AddModules() {
	// 1st semester modules
	Modules m1001a = Modules("1001", "John", "OO Programming A", 2, "9:00", 2, "", "101A", "Jaguar Sport");
	m1001a.Add();
	Modules m1001b = Modules("1001", "John", "OO Programming A", 6, "9:00", 1, "FC", "----", "----------");
	m1001b.Add();
	Modules m1002a = Modules("1002", "Toni", "Database Development A", 2, "14:00", 2, "", "303-C", "Simon Pierre");
	m1002a.Add();
	Modules m1002b = Modules("1002", "Toni", "Database Development A", 6, "14:00", 2, "FC", "----", "----------");
	m1002b.Add();
	Modules m1003 = Modules("1003", "Phil", "Software Design", 3, "10:00", 2, "", "101A", "Jaguar Sport");
	m1003.Add();
	Modules m1004 = Modules("1004", "Dave", "Web Development", 4, "11:00", 2, "", "303-C", "Simon Pierre");
	m1004.Add();
	// 2nd semester modules
	Modules m2001a = Modules("2001", "Carl", "OO Programming B", 2, "9:00", 2, "", "101A", "Jaguar Sport");
	m2001a.Add();
	Modules m2001b = Modules("2001", "Carl", "OO Programming B", 6, "9:00", 1, "FC", "----", "----------");
	m2001b.Add();
	Modules m2002a = Modules("2002", "Gil", "Database Development B", 2, "14:00", 2, "", "303-C", "Simon Pierre");
	m2002a.Add();
	Modules m2002b = Modules("2002", "Gil", "Database Development B", 6, "14:00", 2, "FC", "----", "----------");
	m2002b.Add();
	Modules m2003 = Modules("2073", "Lemon", "Programming Project", 3, "10:00", 2, "", "201-A", "Bulldog Pho");
	m2003.Add();
	Modules m2004 = Modules("2014", "Jane", "Front End Projects", 5, "11:00", 2, "FC", "----", "----------");
	m2004.Add();

}

void SearchModule() {
	system("cls");
	std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable\n\n" << ansi::reset;
	string smodule;
	std::cout << " Type the module number your looking for (Ex. 1001)\n ";
	std::cin >> smodule;
	if (std::count(_modules.begin(), _modules.end(), smodule)) {
		for (int i = 0; i < (int)_modules.size(); i++)
		{
			if (_modules[i] == smodule) {
				system("cls");
				std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable" << ansi::reset;
				std::cout << "\n\n Module " << _modules[i] << " - " << _description[i] << "\n Lecturer - " << _lecturer[i] << std::endl << "\n ";
				system("pause");
				HUB();
			}
		}
	}
	else {
		std::cout << ansi::foreground_red << " Error 101" << ansi::reset << std::endl;
		std::cout << " Redirecting";Sleep(200);std::cout << '.';Sleep(300);std::cout << '.';Sleep(300);std::cout << '.';
		Sleep(1000);
		ERRlogs();
	}
}

void ERRlogs() {
	system("cls");
	std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable -- " << ansi::reset << ansi::foreground_red << "Error logs\n" << ansi::reset << std::endl;
	std::cout << ansi::foreground_red << " ERROR 101 --- " << ansi::reset << "The module does not exist or it's not available for your stage course" << std::endl;
	std::cout << ansi::foreground_red << " ERROR 109 --- " << ansi::reset << "The day you seek does not has lessons" << std::endl << "\n ";
	system("pause");
	Details();
}

void TTdetails() {
	system("cls");
	std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable Explained\n\n " << ansi::reset;
	std::cout << ansi::foreground_green << "All text in green represents the days of the week (shorted)" << std::endl;
	std::cout << ansi::foreground_blue << " All text in blue represents all your modules along the week" << ansi::reset << std::endl;
	std::cout << ansi::foreground_red << " All text in red represents errors" << ansi::reset << std::endl;
	std::cout << " All text in white represents information which you need to interact with in order to have the information you seek" << std::endl;
	std::cout << " The '(FC)' represents the lesson that are on-line, the rest are on campus\n   (see lesson details for room information and more)" << std::endl;
	std::cout << "\n Examples:\n " << ansi::foreground_blue << "1001 " << ansi::reset << "- Number of module which lesson will take place on the 1st semester (ON CAMPUS)" << std::endl;
	std::cout << ansi::foreground_blue << " 2001 " << ansi::reset << "- Number of module which lesson will take place on the 2nd semester (ON CAMPUS)" << std::endl;
	std::cout << ansi::foreground_blue << " 1001 (FC)" << ansi::reset << "- Number of module which lesson will take place on the 1st semester (ONLINE)" << std::endl;
	std::cout << ansi::foreground_blue << " 2001 (FC)" << ansi::reset << "- Number of module which lesson will take place on the 2nd semester (ONLINE)" << std::endl << "\n ";
	system("pause");
	Details();
}

void Details() {
	system("cls");
	int opt;
	std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable\n" << ansi::reset;
	std::cout << "\n Your classes are the same every week for both semesters (except in holidays)\n   Check Timetable details for more information";
	std::cout << "\n\n ====== MENU ======\n ";
	std::cout << "1 - See error logs\n 2 - See Timetables details* \n Any key to return\n ";
	std::cin >> opt;
	do {
		if (opt == 1)
			ERRlogs();
		if (opt == 2)
			TTdetails();
	} while (opt == 1 || opt == 2);
	HUB();
}

void ShowLessons(int day) {
	system("cls");
	bool bounce = false;
	std::cout << ansi::foreground_gold << "\n\t\t\t\t\tEugenio's " << days[day - 1] << "days TextBased Timetable\n\n\n" << ansi::reset;

	for (int i = 0; i < _modules.size();i++) {
		if (day == _day[i]) {
			if (bounce) {
				std::cout << ' ' << _modules[i] << " - " << _description[i] << "\t\t" << _lecturer[i] << "\t\t" << _type[i] << "\t" << _hour[i] << "\t" << _duration[i] << " hour(s)\t" << _building[i] << "\t" << _room[i] << "\t";
			}
			else {
				std::cout << ansi::foreground_green << "   Module Number & Name\t\t\tLecturer\tType\tTime\tDuration\tBuilding\tRoom\n\n " << ansi::reset;
				std::cout << ' ' << _modules[i] << " - " << _description[i] << "\t\t" << _lecturer[i] << "\t\t" << _type[i] << "\t" << _hour[i] << "\t" << _duration[i] << " hour(s)\t" << _building[i] << "\t" << _room[i] << "\t";
				bounce = true;
			}
			std::cout << "\n ";
		}
	}
	std::cout << "\n ";
	system("pause");
	Lesson();
}

void Lesson() {
	int opt;
	int c = 0;
	system("cls");
	std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable\n\n" << ansi::reset;
	for (int i = 0;i < 7;i++) {
		std::cout << ansi::foreground_green << " " << i + 1 << " - " << days[i] << "\t" << ansi::reset;
		for (int j = 0; j < t; j++) {
			if (timetable[i][j] != "") {
				if (c != 0) {
					std::cout << ansi::foreground_blue << ", " << timetable[i][j] << ansi::reset;
				}
				else {
					std::cout << ansi::foreground_blue << timetable[i][j] << ansi::reset;
				}
				c++;
			}
		}
		c = 0;
		std::cout << "\n";
	}
	std::cout << "\n Choose the day of the week which the lesson will take place (1-7)\n ";
	std::cin >> opt;
	do {
		if (opt == 2)
			ShowLessons(opt);
		if (opt == 3)
			ShowLessons(opt);
		if (opt == 4)
			ShowLessons(opt);
		if (opt == 5)
			ShowLessons(opt);
		if (opt == 6)
			ShowLessons(opt);
	} while (opt == 2 || opt == 3 || opt == 4 || opt == 5 || opt == 6);
	std::cout << ansi::foreground_red << " Error 109" << ansi::reset << std::endl;
	std::cout << " Redirecting";Sleep(200);std::cout << '.';Sleep(300);std::cout << '.';Sleep(300);std::cout << '.';
	Sleep(2000);
	ERRlogs();
}

void HUB() {
	int op;
	int c = 0;
	system("cls");
	std::cout << ansi::foreground_gold << "\n\tEugenio's TextBased Timetable\n\n" << ansi::reset;
	for (int i = 0;i < 7;i++) {
		std::cout << ansi::foreground_green << " " << days[i] << "\t" << ansi::reset;
		for (int j = 0; j < t; j++) {
			if (timetable[i][j] != "") {
				if (c != 0) {
					std::cout << ansi::foreground_blue << ", " << timetable[i][j] << ansi::reset;
				}
				else {
					std::cout << ansi::foreground_blue << timetable[i][j] << ansi::reset;
				}
				c++;
			}
		}
		c = 0;
		std::cout << "\n";

	}
	if (!start) {
		Sleep(1200);
		string menu = "\n\n ====== MAIN MENU ======";
		for (int i = 0; i < menu.size();i++) {
			std::cout << menu[i];
			Sleep(75);
		}
		start = true;
	}
	else {
		std::cout << "\n\n ====== MAIN MENU ======";
	}

	std::cout << "\n 1 - See module details\n 2 - See lesson details\n 3 - See timetable details*\n Any key to exit\n ";
	std::cin >> op;
	do {
		if (op == 1)
			SearchModule();
		if (op == 2)
			Lesson();
		if (op == 3)
			Details();
	} while (op == 1 || op == 2 || op == 3);
	exit(0);
}

int main()
{
	AddModules();
	HUB();
	return 0;
}
