//Gets the console size
#include "cmdsize.h"
//Output
#include <iostream>
//These both for cross-platform 
#include <chrono>
#include <thread>

using namespace std;

int main() {
	cout << "CMSize: The Cross-Plattform console size one file header.\nInfo: the rows/collumns are updating themselves every 100 milliseconds.\n";
	while(true) {
		cout << "Rows: " << rows() << " Collumns:" << columns() << "    \r";
		this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

