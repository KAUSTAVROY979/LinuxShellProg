// LinuxShellProg.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <limits.h>
#include <iomanip>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
// TODO: Reference additional headers your program requires here.
void hello_World();
void show_time();
void show_date();
void show_date();
void show_cwd();
void change_dir(std::string s); 
void show_list();
void print_working_directory();
void change_perm(std::string perm, std::string file);