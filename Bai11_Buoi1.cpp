#include <iostream>
#include <conio.h>

using namespace std;

void nhapM1C(int*& a, int& n) {
	a = (int*)malloc(10 * sizeof(int));
	n = 10;
	for (int i = 0; i < n; i++) {
		*(a + 1) = rand() % 100;
	}
}
void xuatM1C(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Phan tu thu " << i << "co gia tri " << *(a + 1) << "dia chi o nho la " << a + 1;
		cout << "Phan tu thu " << i << "co gia tri " << a[i] << "dia chi o nho la " << a + 1;
	}
}

void xuatCucTieu(int* a, int n) {
    cout << "Cac so cuc tieu trong mang: ";
    for (int i = 0; i < n; i++) {
        if ((i == 0 && a[i] < a[i + 1]) ||
            (i == n - 1 && a[i] < a[i - 1]) ||
            (a[i] < a[i - 1] && a[i] < a[i + 1])) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

 
void xoaPhanTu(int*& a, int& n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
    a = (int*)realloc(a, n * sizeof(int));   
}


void themPhanTu(int*& a, int& n, int k, int x) {
    if (k < 0 || k > n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    n++;
    a = (int*)realloc(a, n * sizeof(int)); 
    for (int i = n - 1; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;  
}

 
void sapXepChanLe(int* a, int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int idx = 0;

    // Chuyển số chẵn lên trước  
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[idx++] = a[i];
        }
    }

    // Chuyển số lẻ xuống sau  
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[idx++] = a[i];
        }
    }

    // Sao chép lại từ temp vào a  
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    free(temp);
}

bool kiemTraChanLeXenKe(int* a, int n) {
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 == 0 && a[i - 1] % 2 == 0) || (a[i] % 2 != 0 && a[i - 1] % 2 != 0)) {
            return false;
        }
    }
    return true; 
}
void main() {
	int* a = new int, n = 0;
	nhapM1C(a, n);
	xuatM1C(a, n);
    xuatCucTieu(a, n);

    
    int k;
    cout << "Nhap vi tri k de xoa phan tu: ";
    cin >> k;
    xoaPhanTu(a, n, k);
    cout << "Mang sau khi xoa phan tu tai vi tri " << k << ": " << endl;
    xuatM1C(a, n);

    int x;
    cout << "Nhap vi tri k de them phan tu: ";
    cin >> k;
    cout << "Nhap gia tri phan tu x: ";
    cin >> x;
    themPhanTu(a, n, k, x);
    cout << "Mang sau khi them phan tu tai vi tri " << k << ": " << endl;
    xuatM1C(a, n);

     
    sapXepChanLe(a, n);
    cout << "Mang sau khi sap xep chan le: " << endl;
    xuatM1C(a, n);

     
    if (kiemTraChanLeXenKe(a, n)) {
        cout << "Mang co chua chan le xen ke." << endl;
    }
    else {
        cout << "Mang khong chua chan le xen ke." << endl;
    }

    free(a); 
	getch();
}