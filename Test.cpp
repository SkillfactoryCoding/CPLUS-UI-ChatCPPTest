#include <iostream>
#include "CommandLineInterface.h"
using namespace std;

int main()
{
	cout << "Usage:" << endl;
	cout << "!login[username][password] - log in" << endl;
	cout << "!logout - log out" << endl;
	cout << "!register[username][password] - register new user" << endl;
	cout << "!exit for exit" << endl;
	cout << "!pm[(username)] message - write private message" << endl;
	cout << "!getPM - receive private messages" << endl;
	CommandLineInterface cli{};
	cout << "chat ver. 0.1beta" << endl;
	while (!cli.shouldExit())
	{
		cli.parseCommand();
	}
	return 0;
}