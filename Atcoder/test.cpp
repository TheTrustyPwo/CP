#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    string v5 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{};:,.<>?";
    srand(time(0));
    string s = "";
    for (int i = 0; i < 254; i++) {
		s += v5[rand() & 87];
	}
	cout << s;
}
