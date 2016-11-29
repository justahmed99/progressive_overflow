#include <iostream>
#include <iomanip>
using namespace std;

int mod(int x, int y);
int prime_checker(int x);
int main() {
	cout << "Progressive Overflow" << endl << endl;
	int n = 0;
	cout << "Input Jumlah data : ";
	cin >> n;

    int input[n];
	int p = n;

	while(true) {
		p++;
		if(prime_checker(p) == 1) {
			break;
		}
	}

	cout << "p = " << p << endl;
    int record[p];
	for(int i = 0; i < p; i++) {
		record[i] = 0;
	}

    for(int i = 0; i < n; i++) {
        cout << "input[" << i+1 << "] = ";
        cin >> input[i];
    }
    cout << endl << "key : ";
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "Hash(" << input[i] << ") = " << mod(input[i], p) << endl;
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        int temp = 0;
        temp = mod(input[i], p);
        while(record[temp] != 0) {
            temp++;
        }
        record[temp] = input[i];
    }
    cout << endl << "Result" <<endl;;
    for(int i = 0; i < p; i++) {
        cout << setw(2) << i << setw(5) << record[i] << setw(1)<< endl;
    }

}

int mod(int x, int y) {
    return ((x % y) + y) % y;
}
int prime_checker(int x) {
	for(int i = 2; i <= (x/2); ++i) {
		if(mod(x, i) == 0) {
			return 0;
		}
	}
	return 1;
}
