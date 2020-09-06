#include<iostream>

using namespace std;

int main() {
	int input;
	cin >> input;
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			if (i == 0 || i == input - 1) {
				cout << i + 1<<" ";
			}
			else {
				if (j == 0 || j == input - 1) {
					cout << i + 1<<" ";
				}
				else {
					cout << "  ";
				}
			}
		}
		cout << "\n";
	}
}