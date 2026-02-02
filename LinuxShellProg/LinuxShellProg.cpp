#include "LinuxShellProg.h"
//#include <conio.h>
#include <csignal>
#include <limits.h>
bool ShellRun=true;
using namespace std;
int main()
{
	while (ShellRun) {
		string s = "";
		cout << "\033[32mMyShell#\033[0m ";
		show_cwd();
		cin >> s;
		if (s == "quit" or s == "exit") {
			cout << "\033[31mExiting The Console\033[0m" << endl;
			ShellRun = false;
		}
		else if (s == "time") show_time();
		else if (s == "date") show_date();
		else if (s == "hello") hello_World();
	}
}
