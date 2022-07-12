#include <iostream>
#include <sstream>
using namespace std;

int sum = 2;
int num_1 = 1;
int num_2 = 2;
bool step = 0;
int main() {
	while (num_1 < 4000000 && num_2 < 4000000) {
		if (step == 0) {
			num_1 += num_2;
			step = 1;
			if (num_1 % 2 == 0 && num_1 < 4000000) {
				sum += num_1;
			}
		}
		else {
			num_2 += num_1;
			if (num_2 % 2 == 0 && num_2 < 4000000) {
				sum += num_2;
			}
			step = 0;
		}
	}
	cout << sum;
return 0;
}