#include <iostream>  
#include <algorithm>  

using namespace std;

struct Fraction {
    int integerPart;  
    int numerator;   
    int denominator;  
};

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Tìm hỗn số x theo Linear Search\n";
    cout << "2. Sắp xếp mảng b\n";
    cout << "3. Tìm hỗn số x theo Binary Search\n";
    cout << "4. Chia mảng b thành s1 (phần nguyên) và s2 (phân số)\n";
    cout << "5. Xóa phần tử thứ k trong mảng b\n";
    cout << "6. Thêm hỗn số x vào mảng b tại vị trí\n";
    cout << "7. Tạo mảng c chứa các phần tử phân số\n";
    cout << "8. Tính tổng các phần tử của mảng b\n";
    cout << "9. Tìm phần tử lớn nhất / nhỏ nhất của b\n";
    cout << "0. Thoát\n";
}

void inputFraction(Fraction& frac) {
    cout << "Nhập phần nguyên: ";
    cin >> frac.integerPart;
    cout << "Nhập tử số: ";
    cin >> frac.numerator;
    cout << "Nhập mẫu số: ";
    cin >> frac.denominator;
}

void printFraction(const Fraction& frac) {
    cout << frac.integerPart << " " << frac.numerator << "/" << frac.denominator << endl;
}

int linearSearch(const Fraction b[], int size, const Fraction& x) {
    for (int i = 0; i < size; ++i) {
        if (b[i].integerPart == x.integerPart && b[i].numerator == x.numerator && b[i].denominator == x.denominator) {
            return i;
        }
    }
    return -1; // Không tìm thấy  
}

void sortFractions(Fraction b[], int size) {
    stable_sort(b, b + size, [](const Fraction& a, const Fraction& b) {
        return (a.integerPart % 2 == 0 && b.integerPart % 2 != 0); // Phần nguyên chẵn trước, lẻ sau  
        });
}

int binarySearch(const Fraction b[], int size, const Fraction& x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (b[mid].integerPart == x.integerPart && b[mid].numerator == x.numerator && b[mid].denominator == x.denominator) {
            return mid;
        }
        if (b[mid].integerPart < x.integerPart ||
            (b[mid].integerPart == x.integerPart && b[mid].numerator < x.numerator)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Không tìm thấy  
}

void splitFractions(const Fraction b[], int size, Fraction s1[], Fraction s2[], int& s1Size, int& s2Size) {
    s1Size = s2Size = 0;

    for (int i = 0; i < size; i++) {
        if (b[i].numerator == 0) { // phân số bằng 0 nghĩa là phần số nguyên đầy đủ  
            s1[s1Size++] = b[i];
        }
        else {
            s2[s2Size++] = b[i];
        }
    }
}

void deleteFraction(Fraction b[], int& size, int k) {
    if (k < 0 || k >= size) {
        cout << "K không hợp lệ.\n";
        return;
    }
    for (int i = k; i < size - 1; i++) {
        b[i] = b[i + 1];
    }
    size--; // Giảm kích thước mảng  
}

void insertFraction(Fraction b[], int& size, const Fraction& x, int position) {
    if (position < 0 || position > size) {
        cout << "Vị trí không hợp lệ.\n";
        return;
    }
    for (int i = size; i > position; i--) {
        b[i] = b[i - 1];
    }
    b[position] = x;
    size++; // Tăng kích thước mảng  
}

void createFractionArray(const Fraction b[], Fraction c[], int size) {
    for (int i = 0; i < size; i++) {
        c[i].numerator = b[i].integerPart * b[i].denominator + b[i].numerator; // Chuyển đổi thành phân số  
        c[i].denominator = b[i].denominator;
        c[i].integerPart = 0; // Tạo ra phân số vì không cần phần nguyên  
    }
}

void calculateTotal(const Fraction b[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += b[i].integerPart + static_cast<double>(b[i].numerator) / b[i].denominator;
    }
    cout << "Tổng các phần tử trong mảng b là: " << total << endl;
}

void findMinMax(const Fraction b[], int size) {
    if (size == 0) {
        cout << "Mảng rỗng.\n";
        return;
    }
    Fraction minFraction = b[0];
    Fraction maxFraction = b[0];

    for (int i = 1; i < size; i++) {
        double currentValue = b[i].integerPart + static_cast<double>(b[i].numerator) / b[i].denominator;
        double minValue = minFraction.integerPart + static_cast<double>(minFraction.numerator) / minFraction.denominator;
        double maxValue = maxFraction.integerPart + static_cast<double>(maxFraction.numerator) / maxFraction.denominator;

        if (currentValue < minValue) {
            minFraction = b[i];
        }
        if (currentValue > maxValue) {
            maxFraction = b[i];
        }
    }

    cout << "Phần tử nhỏ nhất là: ";
    printFraction(minFraction);
    cout << "Phần tử lớn nhất là: ";
    printFraction(maxFraction);
}

int main() {
    const int MAX_SIZE = 100;
    Fraction b[MAX_SIZE];
    int size = 0;
    int choice;

    while (true) {
        displayMenu();
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Fraction x;
            inputFraction(x);
            int index = linearSearch(b, size, x);
            if (index != -1) {
                cout << "Hỗn số tìm thấy tại vị trí: " << index << endl;
            }
            else {
                cout << "Không tìm thấy hỗn số.\n";
            }
            break;
        }
        case 2:
            sortFractions(b, size);
            cout << "Đã sắp xếp mảng b.\n";
            break;
        case 3: {
            Fraction x;
            inputFraction(x);
            int index = binarySearch(b, size, x);
            if (index != -1) {
                cout << "Hỗn số tìm thấy tại vị trí: " << index << endl;
            }
            else {
                cout << "Không tìm thấy hỗn số.\n";
            }
            break;
        }
        case 4: {
            Fraction s1[MAX_SIZE], s2[MAX_SIZE];
            int s1Size, s2Size;
            splitFractions(b, size, s1, s2, s1Size, s2Size);
            cout << "Mảng s1 (phần nguyên):\n";
            for (int i = 0; i < s1Size; i++) {
                printFraction(s1[i]);
            }
            cout << "Mảng s2 (phân số):\n";
            for (int i = 0; i < s2Size; i++) {
                printFraction(s2[i]);
            }
            break;
        }
        case 5: {
            int k;
            cout << "Nhập chỉ số k để xóa: ";
            cin >> k;
            deleteFraction(b, size, k);
            cout << "Đã xóa phần tử tại vị trí " << k << ".\n";
            break;
        }
        case 6: {
            Fraction x;
            inputFraction(x);
            int position;
            cout << "Nhập vị trí để chèn: ";
            cin >> position;
            insertFraction(b, size, x, position);
            cout << "Đã chèn hỗn số vào vị trí " << position << ".\n";
            break;
        }
        case 7: {
            Fraction c[MAX_SIZE];
            createFractionArray(b, c, size);
            cout << "Mảng c (phân số):\n";
            for (int i = 0; i < size; i++) {
                printFraction(c[i]);
            }
            break;
        }
        case 8:
            calculateTotal(b, size);
            break;
        case 9:
            findMinMax(b, size);
            break;
        case 0:
            cout << "Thoát chương trình.\n";
            return 0;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    }

    return 0;
}