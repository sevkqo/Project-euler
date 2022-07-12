#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int i, terms, max_terms, result;
	unsigned int n;
	max_terms = 0;
	for (i = 2; i < 1000000; i++) {
		terms = 1;
		n = i;
		while (n != 1) {
				if (n % 2 == 0) {
					n = n / 2;
				}
				else {
					n = 3 * n + 1;
				}
				terms += 1;
		}
		if (terms > max_terms) {
			max_terms = terms;
			result = i;
		}
	}
	cout << result;
	return 0;
}