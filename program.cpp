#include <iostream>
#include <iomanip>
using namespace std;

int mod(int x, int y);
int main() {
    int p = 11;
    int input[7];
    int record[p] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "Progressive Overflow" << endl << endl;

    for(int i = 0; i < 7; i++) {
        cout << "input[" << i+1 << "] = ";
        cin >> input[i];
    }
    cout << endl << "key : ";
    for(int i = 0; i < 7; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 7; i++) {
        cout << "Hash(" << input[i] << ") = " << mod(input[i], p) << endl;
    }
    cout << endl;
    for(int i = 0; i < 7; i++) {
        int temp = 0;
        temp = mod(input[i], p);
        while(record[temp] != 0) {
            temp++;
        }
        record[temp] = input[i];
    }
    cout << endl << "Result" <<endl;;
    for(int i = 0; i < 11; i++) {
        cout << setw(2) << i << setw(5) << record[i] << setw(1)<< endl;
    }

}

int mod(int x, int y) {
    return ((x % y) + y) % y;
}
