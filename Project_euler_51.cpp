#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;

bool check_prime(long int n) {
	bool is_prime = 1;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				i = n;
				is_prime = 0;
			}
		}
	return is_prime;
}

int low_than_100(long int n) {
	int j, k, condition;
	bool lowest;

	condition = 0;

	for (j = 1; j <= 9; j++) {
		k = 1 * j + 10 * j;
		lowest = check_prime(k);
		if (lowest == 0) {
			condition += 1;
			if (condition > 1) {
				j = 10;
			}
		}
		if (j == 9 && condition <= 1) {
			cout << n << " is lowest prime making codnitions!" << endl;
			n = 1000000;
		}
	}
	return 0;
}

int low_than_1000(long int n) { //MOZNA UZNAC, ZE OSTATNIEJ CYFRY NIE ZMIENIAMY (NIE BEDZIE 8x PIERWSZA BO POLOWA JEST PARZYSTA)
	int j, k, num_1, num_10, num_100, condition;
	bool lowest;

	condition = 0;

	num_100 = floor(n / 100) * 100;
	num_1 = (n - num_100 - ((floor((n - num_100) / 10)) * 10));
	num_10 = n - num_100 - num_1;

		for (j = 1; j <= 9; j++) {
			k = 100 * j + 10 * j + num_1;
			lowest = check_prime(k);
			if (lowest == 0) {
				condition += 1;
				if (condition > 1) {
					j = 10;
				}
			}
			if (j == 9 && condition <= 1) {
				cout << n << " is lowest prime making codnitions!" << endl;
				n = 1000000;
			}	
		}
		return 0;
	}

int low_than_10000(long int n) { //MOZNA UZNAC, ZE OSTATNIEJ CYFRY NIE ZMIENIAMY (NIE BEDZIE 8x PIERWSZA BO POLOWA JEST PARZYSTA)
	int j, k, l, m, l1, m1, num_1, num_10, num_100, num_1000, n1, condition;
	bool lowest;
	vector <int> v;

	condition = 0;

	num_1000 = floor(n / 1000) * 1000;
	v.push_back(num_1000);
	num_100 = floor((n - num_1000) / 100) * 100;
	v.push_back(num_100);
	num_10 = (((floor((n - num_1000 - num_100) / 10)) * 10));
	v.push_back(num_10);
	num_1 = n - num_1000 - num_100 - num_10;
	v.push_back(num_1);

	n1 = 0;

	for (l = 0; l <= 1; l++) {
		l1 = pow(10, l + 1);
		for (m = 0; m < 2 - l; m++) {
			m1 = pow(10, m + l + 2);
				for (j = 1; j <= 9; j++) {
					k = l1 * j + m1 * j + v[n1] + num_1;
					lowest = check_prime(k);
					if (lowest == 0) {
						condition += 1;
						if (condition > 1) {
							j = 10;
						}
					}
					if (j == 9) {
						cout << n << " is lowest prime making codnitions!" << endl;
						n = 1000000;
					}
				}
				n1 += 1;
				condition = 0;
		}
	}

	//ZMIANA TRZECH CYFR
		for (j = 1; j <= 9; j++) {
			k = pow(10,3) * j + pow(10, 2) * j + pow(10, 1) * j + num_1;
			lowest = check_prime(k);
			if (lowest == 0) {
				condition += 1;
				if (condition > 1) {
					j = 10;
				}
			}
			if (j == 9) {
				cout << n << " is lowest prime making codnitions!" << endl;
				n = 1000000;
			}
		}
		condition = 0;
	return 0;
}

int low_than_100000(long int n) { //MOZNA UZNAC, ZE OSTATNIEJ CYFRY NIE ZMIENIAMY (NIE BEDZIE 8x PIERWSZA BO POLOWA JEST PARZYSTA)
	int j, k, l, m, l1, m1, o, num_1, num_10, num_100, num_1000, num_10000, n1, n2, condition;
	bool lowest;
	vector <int> v;

	condition = 0;

	num_10000 = floor(n / 10000) * 10000;
	v.push_back(num_10000);
	num_1000 = floor((n - num_10000) / 1000) * 1000;
	v.push_back(num_1000);
	num_100 = floor((n - num_10000 - num_1000) / 100) * 100;
	v.push_back(num_100);
	num_10 = floor((n - num_10000 - num_1000 - num_100) / 10) * 10;
	v.push_back(num_10);
	num_1 = n - num_10000 - num_1000 - num_100 - num_10;
	v.push_back(num_1);

	n1 = 0;
	n2 = 1;

	for (l = 0; l <= 1; l++) {
		for (m = 0; m < 2 - l; m++) {
			l1 = pow(10, m + l * 2 + 1);
			for (o = 0; o < 3 - m - l * 2; o++) {
				m1 = pow(10, o + m + l * 2 + 2);
				for (j = 1; j <= 9; j++) {
					k = l1 * j + m1 * j + v[n1] + v[n2] + num_1;
					lowest = check_prime(k);
					if (lowest == 0) {
						condition += 1;
						if (condition > 1) {
							j = 10;
						}
					}
					if (j == 9) {
						cout << n << " is lowest prime making codnitions!" << endl;
						n = 1000000;
					}
				}
				if (n1 == 1 && n2 == 2) {
					n2 = 3;
					n1 = -1;
				}
				if (n2 - n1 == 1) {
					n2 += 1;
				}
				else {
					n1 += 1;
				}
				condition = 0;
			}
		}
	}

	//ZMIANA TRZECH CYFR
	int x1;
	vector <int> x2;
	bool arr[4][4] =
	{ {0,1,1,1},
	{1,0,1,1},
	{1,1,0,1},
	{1,1,1,0}};

	for (l = 0; l <= 3; l++) {
		for (m = 0; m <= 3; m++) {
			if (arr[l][m] == 0) {
				x1 = v[m];
			}
			else {
				x2.push_back(pow(10, 4 - m));
			}
		}
			for (j = 1; j <= 9; j++) {
				k = x2[0] * j + x2[1] * j + x2[2] * j + x1 + num_1;
				lowest = check_prime(k);
				if (lowest == 0) {
					condition += 1;
					if (condition > 1) {
						j = 10;
					}
				}
				if (j == 9) {
					cout << n << " is lowest prime making codnitions!" << endl;
					n = 1000000;
				}
			}
			condition = 0;
			x1 = 0;
			x2.erase(x2.begin(), x2.begin() + 3);
	}

	//ZMIANA CZTERECH CYFR
	for (j = 1; j <= 9; j++) {
		k = pow(10, 4) * j + pow(10, 3) * j + pow(10, 2) * j + pow(10, 1) * j + num_1;
		lowest = check_prime(k);
		if (lowest == 0) {
			condition += 1;
			if (condition > 1) {
				j = 10;
			}
		}
		if (j == 9) {
			cout << n << " is lowest prime making codnitions!" << endl;
			n = 1000000;
		}
	}
	condition = 0;
	return 0;
}

int low_than_1000000(long int n) { //MOZNA UZNAC, ZE OSTATNIEJ CYFRY NIE ZMIENIAMY (NIE BEDZIE 8x PIERWSZA BO POLOWA JEST PARZYSTA)
	int j, k, l, m, l1, m1, o, p, num_1, num_10, num_100, num_1000, num_10000, num_100000, n1, n2, n3, condition, condition_2;
	bool lowest;
	vector <int> v;

	condition = 0;
	condition_2 = 0;

	num_100000 = floor(n / 100000) * 100000;
	v.push_back(num_100000);
	num_10000 = floor((n - num_100000) / 10000) * 10000;
	v.push_back(num_10000);
	num_1000 = floor((n - num_100000 - num_10000) / 1000) * 1000;
	v.push_back(num_1000);
	num_100 = floor((n - num_100000 - num_10000 - num_1000) / 100) * 100;
	v.push_back(num_100);
	num_10 = floor((n - num_100000 - num_10000 - num_1000 - num_100) / 10) * 10;
	v.push_back(num_10);
	num_1 = n - num_100000 - num_10000 - num_1000 - num_100 - num_10;
	v.push_back(num_1);

	n1 = 0;
	n2 = 1;
	n3 = 2;

	for (m = 0; m < 2; m++) {
		for (o = 0; o < 3 - m * 2; o++) {
			l1 = pow(10, o + m * 3 + 1);
			for (p = 0; p < 4 - o - m * 3; p++) {
				m1 = pow(10, p + o + m * 3 + 2);
				for (j = 1; j <= 9; j++) {
					k = l1 * j + m1 * j + v[n1] + v[n2] + v[n3] + num_1;
					lowest = check_prime(k);
					if (lowest == 0) {
						condition += 1;
						if (condition > 1) {
							j = 10;
						}
					}
					if (j == 9) {
						cout << n << " is lowest prime making codnitions!" << endl;
						n = 1000000;
						exit(0);
					}
				}
				if (n1 == 1 && n2 == 2 && n3 == 3) {
					n1 = 0;
					n2 = 1;
					n3 = 4;
					condition_2 = 1;
				}
				if (n1 == 1 && n2 == 2 && n3 == 4) {
					n1 = 0;
					n2 = 3;
					n3 = 4;
					condition_2 = 1;
				}

				if (condition_2 == 0) {
					if (n2 >= 2 && (n2 + n3) >= 5) {
						n1 += 1;
					}
					else if (n3 - n2 >= 2) {
						n2 += 1;
					}
					else {
						n3 += 1;
					}
				}
				condition_2 = 0;
				condition = 0;
			}
		}
	}

	//ZMIANA TRZECH CYFR
	vector <int> x1;
	vector <int> x2;
	bool arr[6][5] =
	{ {0,0,1,1,1},
	{0,1,0,1,1},
	{1,0,0,1,1},
	{0,1,1,0,1},
	{1,0,1,0,1},
	{1,1,1,0,0} };

	for (l = 0; l <= 5; l++) {
		for (m = 0; m <= 4; m++) {
			if (arr[l][m] == 0) {
				x1.push_back(v[m]);
			}
			else {
				x2.push_back(pow(10, 5 - m));
			}
		}
			for (j = 1; j <= 9; j++) {
				k = x2[0] * j + x2[1] * j + x2[2] * j + x1[0] + x1[1] + num_1;
				lowest = check_prime(k);
				if (lowest == 0) {
					condition += 1;
					if (condition > 1) {
						j = 10;
					}
				}
				if (j == 9) {
					cout << n << " is lowest prime making codnitions!" << endl;
					exit(0);
				}
			}
			condition = 0;
			x1.erase(x1.begin(), x1.begin() + 2);
			x2.erase(x2.begin(), x2.begin() + 3);
	}
	return 0;

}

int main() {
	long int n;
	bool var;
	for (n = 1; n < 1000000; n++) {

		var = check_prime(n);
		if (n > 99999 && var == 1) {
			int a;
			a = low_than_1000000(n);
		}
		else if (n > 9999 && var == 1) {
			int a;
			a = low_than_100000(n);
		}
		else if (n > 999 && var == 1) {
			int a;
			a = low_than_10000(n);
		}
		else if (n > 99 && var == 1) {
			int a;
			a = low_than_1000(n);
		}
		else if (n <= 99 && var == 1) {
			int a;
			a = low_than_100(n);
		}
		}

	return 0;
}