#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <memory>
#include <memory.h>
#include <windows.h>
#include <fstream>
#include <vector>
#define endl "\n"

using namespace std;

int main() {
	ifstream input("H:\\Dev\\C++\\graphicsTest01\\raw\\test.avi", ios::binary);
	if (!input) {
		cerr << "input failed" << endl;
		return 1;
	}
	vector<char> data((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());
	input.close();
	ofstream file("broken.avi", ios::binary);
	if (!file) {
		cerr << "output failed" << endl;
	}
	for (char c : data) {
		file << (char)((int)c + 1);
	}
	file.close();
	//int esq = 0;
	//int edq = 0;
	//int eq = 0;
	//int es = 0;
	//int ea = 0;
	//int eb = 0;
	//int ef = 0;
	//int en = 0;
	//int er = 0;
	//int et = 0;
	//int ev = 0;
	//for (char i : buffer) {
	//	switch (i) {
	//		case "\'"[0]:
	//			esq++;
	//			break;
	//		case "\""[0]:
	//			edq++;
	//			break;
	//		case "\?"[0]:
	//			eq++;
	//			break;
	//		case "\\"[0]:
	//			es++;
	//			break;
	//		case "\a"[0]:
	//			ea++;
	//			break;
	//		case "\b"[0]:
	//			eb++;
	//			break;
	//		case "\f"[0]:
	//			ef++;
	//			break;
	//		case "\n"[0]:
	//			en++;
	//			break;
	//		case "\r"[0]:
	//			er++;
	//			break;
	//		case "\t"[0]:
	//			et++;
	//			break;
	//		case "\v"[0]:
	//			ev++;
	//			break;
	//	}

	//	//file << i;
	//}
	//cout << esq << "\n" << edq << "\n" << eq << "\n" << es << "\n" << ea << "\n" << eb << "\n" << ef << "\n" << en << "\n" << er << "\n" << et << "\n" << ev;
}
