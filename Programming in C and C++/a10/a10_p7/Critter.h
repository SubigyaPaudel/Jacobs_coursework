/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a10_p07.c
*/

#include <string> // defines standard C++ string class

class Critter
{
private:  // data members are private
	std::string name;
	double hunger;
	int boredom;
	double height;
	double thirst;		// Note: information hiding is used to work with thirst
	int percenttoint(double x);
	double inttopercent(int x);

public: // business logic methods are public
	// setter methods
	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setheight(double newheight);
	void setthirst(int newthirst);
	double getheight();
	int getthirst(); //thirst is internally stored as a double, but in the user interface it is shown as an int
	// getter method
	int getHunger();
	// service method
	void print();
	Critter();
	Critter(std::string s);
	Critter(std::string newname, int newhunger, int newboredom, double newheight=10.0);
	Critter(std::string newname, int newhunger, int newboredom, double newheight, int newthirst);
};