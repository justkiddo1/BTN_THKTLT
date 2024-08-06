#include <iostream>

using namespace std;

int main() {
	float a = 5.7, b = 4.8;
	float* pa = &a;
	float* pb = &b;
	cout << "Dia chi cua a : " << pa;
	cout << "Dia chi cua b : " << pb;

    float sum = *pa + *pb;       
    float difference = *pa - *pb; 
    float product = *pa * *pb;   
    float quotient = *pa / *pb;   

    
    cout << "Dia chi cua a : " << pa << endl;
    cout << "Dia chi cua b : " << pb << endl;
    cout << "Tong: " << sum << "\tDia chi: " << &sum << endl;
    cout << "Hieu: " << difference << "\tDia chi: " << &difference << endl;
    cout << "Tich: " << product << "\tDia chi: " << &product << endl;
    cout << "Thuong: " << quotient << "\tDia chi: " << &quotient << endl;

    return 0;
}