#include <iostream>
//1   86   172   256
using namespace std;

int main() {
	int length, count;
	string str;
	cin >> length;

	int* array = new int[length];

	count = 0;
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}

	count += 2;

	if (array[0] >= 0 && array[0] <= 43) {
		str = "00";
	}
	else if (array[0] >= 44 && array[0] <= 129) {
		str = "01";
	}
	else if (array[0] >= 130 && array[0] <= 215) {
		str = "10";
	}
	else if (array[0] >= 216 && array[0] <= 255) {
		str = "11";
	}
	else {
		cout << "입력오류";
		count = 0;
		return 0;
	}

	for (int i = 0; i < length; i++) {
		cout << array[i] << endl;
	}

	//   cin.ignore(256, '\n');
	delete[] array;
}