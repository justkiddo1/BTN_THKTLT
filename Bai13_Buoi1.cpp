#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void divideArrays(const vector<int>& a, const vector<int>& b) {
	if (a.size() != b.size()) {
		throw invalid_argument("Hai mảng phải có cùng kích thước !");
	}
	for (size_t i = 0; i < a.size(); i++) {
		cout << "Phép chia a[" << i << "] /b[" << i << "]=";
		if (b[i] == 0) {
			cout << "Lối:chia cho 0." << endl;
		}
		else {
			double result = static_cast<double>(a[i]) / b[i];
			cout << result << endl;
		}
	}
}
int main() {
	try {
		vector<int>a = { 10,20,30,40,50 };
		vector<int>b = { 2,0,5,4,0 };
		divideArrays(a, b);
	}
	catch (const exception& e) {
		cerr << "Ngoại lệ : " << e.what() << endl;
	}
	return 0;
}