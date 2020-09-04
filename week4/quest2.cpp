#include<iostream>

using namespace std;

int main() {
	int day, order, one_hundred = 100, five_hundred = 50,one_thousand=25;
	cout << "INPUT DAY : ";
	cin >> day;
	int error[30] = { 0 };

	for (int i = 0; i < day; i++) {
		cout << "\n\nDAY " << i + 1 << " INPUT ORDER : ";
		cin >> order;
		for (int j = 0; j < order; j++) {
			int money, K_OH=0, K_FH=0, K_OT=0,STILL;
			bool pass = true,input=false;
			while (input != true) {
				cout << "\nORDER " << j + 1 << " : Want ";
				cin >> money;
				if (money % 100 == 0) {
					input = true;
				}
				else {
					cout << "You entered an incorrect amount.Please enter the amount again.\n";
				}
			}

			if (money / 1000 > one_thousand&&one_thousand==0) {
				//cout << money % 1000 << "    " << one_thousand << "\n";
				if (money / 500 > five_hundred&&five_hundred==0) {
					if (money / 100 > one_hundred&&one_hundred==0) {
						pass = false;
					}
					else {
						STILL = money / 100;
						if (STILL > one_hundred) {
							K_OH += one_hundred;
							money -= (one_hundred * 100);
						}
						else {
							K_OH += STILL;
							money -= (STILL * 100);
						}
					}
				}
				else {
					STILL = money / 500;
					if (STILL > five_hundred) {
						cout << "1"<<five_hundred;
						K_FH += five_hundred;
						money -= (five_hundred * 500);
					}
					else {
						K_FH += STILL;
						money -= (STILL * 500);
					}
				}
			}
			else {
				STILL= money / 1000;
				if (STILL > one_thousand) {
					K_OT += one_thousand;
					money -= (one_thousand * 1000);
				}
				else {
					K_OT += STILL;
					money -= (STILL * 1000);
				}
			}
			if (money / 500 > five_hundred&&five_hundred==0) {
				if (money / 100 > one_hundred) {
					pass = false;
				}
				else {
					STILL = money / 100;
					if (STILL > one_hundred) {
						K_OH += one_hundred;
						money -= (one_hundred * 100);
					}
					else {
						K_OH += STILL;
						money -= (STILL * 100);
					}
				}
			}
			else {
				STILL = money / 500;
				if (STILL > five_hundred) {
					K_FH += five_hundred;
					money -= (five_hundred * 500);
				}
				else if(five_hundred-K_FH>0){
					K_FH += STILL;
					money -= (STILL * 500);
				}
			}
			if (money / 100 > one_hundred||one_hundred==0) {
				pass = false;
			}
			else {
				STILL = money / 100;
				if (STILL > one_hundred) {
					K_OH += one_hundred;
					money -= (one_hundred * 100);
				}
				else {
					K_OH += STILL;
					money -= (STILL * 100);
				}
			}
			if (one_hundred - K_OH < 0) {
				pass = false;
			}


			if (pass == false) {
				error[i] += 1;
				cout << "Sorry. In the atm there are not enough banknotes for your requirements.\n";
				cout << "fill 1000 baht banknote = " << 25 - one_thousand << " ,500 baht banknote = " << 50 - five_hundred << " ,100 baht banknote = " << 100 - one_hundred<<"\n";
				one_hundred = 100; 
				five_hundred = 50;
				one_thousand = 25;
			}
			else {
				one_hundred -= K_OH;
				five_hundred -= K_FH;
				one_thousand -= K_OT;
				cout << "You get 1000 baht banknote = " << K_OT << " ,500 baht banknote = " << K_FH << " ,100 baht banknote = " << K_OH<<"\n";
				cout << "Now in ATM have 1000 bath bank note = " << one_thousand << " ,500 baht banknote = " << five_hundred << " ,100 baht banknote = " << one_hundred << "\n";
			}
		}
	}

	cout << "\nShow Result ATM Error\n";
	for (int i = 0; i < day; i++) {
		cout << "\nDay " << i + 1 << ": Error = " << error[i];
	}
}
