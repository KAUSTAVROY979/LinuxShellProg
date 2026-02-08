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
		cout << "\033[1;32mMyShell\033[0m:";
		show_cwd();
		getline(cin, s);
		if (s == "quit" or s == "exit") {
			cout << "\033[31mExiting The Console\033[0m" << endl;
			ShellRun = false;
		}
		else if (s == "time" or s == "Time") show_time();
		else if (s == "date" or s == "Date") show_date();
		else if (s == "hello" or s == "Hello") hello_World();
		else if (s == "clear") {
			std::cout << "\033[2J\033[H";
		}
		else if (s == "ls") show_list();
		else if (s[0] == 'c' and s[1] == 'd') change_dir(s);
		else if (s == "pwd") print_working_directory();
		else if (s.substr(0, 5) == "chmod") {
			stringstream ss(s);
			string cmd, perm, file;
			ss >> cmd >> perm >> file;
			change_perm(perm, file);
		}
		else cout << s << ": Unknown Command" << endl;
	}
}
