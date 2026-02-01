#include <iostream>
#include <ctime>
using namespace std;
void hello_World() {
	cout << "Hello World From My New Console" << endl;
}

void show_time() {
	time_t tt;
	time(&tt);
	tm *lt = localtime(&tt);
	cout << "The Time is: " << lt->tm_hour%12 << ":" << lt->tm_min;
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