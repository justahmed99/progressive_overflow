#include <iostream>
#include <iomanip>
using namespace std;

int mod(int x, int y);		//fungsi modulus
int prime_maker(int x);		//fungsi mementukan nilai p
int main() {
	cout << "Progressive Overflow" << endl << endl;
	int n = 0;
	cout << "Input Jumlah data : ";
	cin >> n;

    int input[n];
	int p = n;

	//p merupakan penentu jumlah baris pada tabel, p merupakan bilangan prima terdekat
	//dari n
	while(true) {
		p++;
		if(prime_maker(p) == 1) {
			break;
		}
	}

	cout << "p = " << p << endl;
    int record[p];
	//nilai dari setiap elemen p diinisiasi dulu agar bernilai nol
	for(int i = 0; i < p; i++) {
		record[i] = 0;
	}

	cout << "------------------------------" << endl;
    for(int i = 0; i < n; i++) {
        cout << "input[" << i+1 << "] = ";
        cin >> input[i];
    }
    cout << endl << "kunci : ";
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

	cout << "-----------------------------" << endl;
	cout << "Hashing kunci :" << endl;
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
		temp = mod(temp, p);
        record[temp] = input[i];
    }

	cout << "-------------------------------" << endl;
    cout << endl << "Hasil" <<endl;;
    for(int i = 0; i < p; i++) {
        cout << setw(2) << i << setw(5) << record[i] << setw(1)<< endl;
    }

}

//fungsi modulus
int mod(int x, int y) {
    return ((x % y) + y) % y;
}

//fungsing untuk menentukan p
int prime_maker(int x) {
	for(int i = 2; i <= (x/2); ++i) {
		if(mod(x, i) == 0) {
			return 0;
		}
	}
	return 1;
}
