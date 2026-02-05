#include "LinuxShellProg.h"
using namespace std;

string whiteSpace_remover(string s) {
	stringstream reader(s);
	string output;
	reader >> output;
	//cout << output;
	return output;
}
void hello_World() {
	cout << "Hello World From My New Console" << endl;
}
  
void show_time() {
	time_t tt;
	time(&tt);
	tm *lt = localtime(&tt);
	cout << "The Time is: " << setw(2) << setfill('0') << lt->tm_hour % 12 << ":" << setw(2) << setfill('0') << lt->tm_min << ":" << setw(2) << setfill('0') << lt->tm_sec;
	if (lt->tm_hour >= 12 and lt->tm_hour <= 23) cout << " PM";
	else cout << " AM";
	cout << endl;
}

void show_date() {
	time_t tt;
	time(&tt);
	tm* ld = localtime(&tt);
	cout << "The Date is: " << ld->tm_mday << "/" << 1+ld->tm_mon << "/" << 1900+ld->tm_year;
	cout << endl;
}

void show_cwd() {
	char path[PATH_MAX];
	char* result = getcwd(path, sizeof(path));
	if (result) {
		cout << "\033[1;34m" << path << "\033[0m$ ";
	}
	else perror("getcwd() function error");
}

void change_dir(string s) {
	string dir = s.substr(3, s.length() - 3);
	dir = whiteSpace_remover(dir);
	if (dir[0] != '/') {
		char inpath[PATH_MAX];
		char* check = getcwd(inpath, sizeof(inpath));
		string path(inpath);
		path += '/';
		if (check) {
			dir = path + dir;
		}
		//dir.insert(0, 1, '/');
	}
	if (chdir(dir.c_str()) == -1) cout << dir << ": File ya Directory nahi hai" << endl;
}

void show_list() {
	string currentPath = ".";
	DIR* dir = opendir(currentPath.c_str());
	if (!dir) {
		perror("ls cannot access path");
		return;
	}

	struct dirent* entry;
	while ((entry = readdir(dir)) != nullptr) {
		string fullpath = currentPath + "/" + entry->d_name;
		struct stat info;

		if (lstat(fullpath.c_str(), &info) == -1) {
			perror("lstat failed");
			continue;
		}
		if (S_ISLNK(info.st_mode)) cout << "\033[1;36m" << entry->d_name << "\033[0m    ";
		else if (S_ISDIR(info.st_mode)) cout << "\033[1;34m" << entry->d_name << "\033[0m    ";
		else if (info.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) cout << "\033[1;32m" << entry->d_name << "*\033[0m    ";
		else cout << entry->d_name << "    ";
	}

	cout << endl;
	closedir(dir);

}