#include <iostream>  
using namespace std;

struct PhanSo {
    int tuSo;  
    int mauSo;  
};

 
void nhapPhanSo(PhanSo& ps) {
    cout << "Nhập tử số: ";
    cin >> ps.tuSo;
    do {
        cout << "Nhập mẫu số (không được bằng 0): ";
        cin >> ps.mauSo;
        if (ps.mauSo == 0) {
            cout << "Mẫu số không được bằng 0. Vui lòng nhập lại." << endl;
        }
    } while (ps.mauSo == 0);
}

 
void xuatPhanSo(const PhanSo& ps) {
    cout << ps.tuSo << "/" << ps.mauSo;
}

 
void rutGon(PhanSo& ps) {
    int a = ps.tuSo;
    int b = ps.mauSo;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    ps.tuSo /= a;
    ps.mauSo /= a;
    if (ps.mauSo < 0) {  
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
}

 
void xuatPhanSoMaUu(PhanSo* mang, int n) {
    cout << "Các phân số có mẫu > tử là:\n";
    for (int i = 0; i < n; i++) {
        if (mang[i].mauSo > mang[i].tuSo) {
            xuatPhanSo(mang[i]);
            cout << endl;
        }
    }
}


PhanSo tinhTich(PhanSo* mang, int n) {
    PhanSo tich = { 1, 1 };   
    for (int i = 0; i < n; i++) {
        tich.tuSo *= mang[i].tuSo;
        tich.mauSo *= mang[i].mauSo;
    }
    rutGon(tich);
    return tich;
}

 
PhanSo timPhanTuLonNhat(PhanSo* mang, int n) {
    PhanSo lonNhat = mang[0];
    for (int i = 1; i < n; i++) {
        if (lonNhat.tuSo * mang[i].mauSo < mang[i].tuSo * lonNhat.mauSo) {
            lonNhat = mang[i];
        }
    }
    return lonNhat;
}


void timPhanSoLonNhatVaNhoNhat(PhanSo* mang, int n, PhanSo& lonNhat, PhanSo& nhoNhat) {
    lonNhat = nhoNhat = mang[0];
    for (int i = 1; i < n; i++) {
        if (lonNhat.tuSo * mang[i].mauSo < mang[i].tuSo * lonNhat.mauSo) {
            lonNhat = mang[i];
        }
        if (nhoNhat.tuSo * mang[i].mauSo > mang[i].tuSo * nhoNhat.mauSo) {
            nhoNhat = mang[i];
        }
    }
}


void xoaPhanTu(PhanSo*& mang, int& n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vị trí không hợp lệ!" << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        mang[i] = mang[i + 1];
    }
    n--;
}


void themPhanTu(PhanSo*& mang, int& n, PhanSo x, int k) {
    if (k < 0 || k > n) {
        cout << "Vị trí không hợp lệ!" << endl;
        return;
    }
  
    PhanSo* mangMoi = new PhanSo[n + 1];

    for (int i = 0; i < k; i++) {
        mangMoi[i] = mang[i];
    }
    mangMoi[k] = x; 
    for (int i = k; i < n; i++) {
        mangMoi[i + 1] = mang[i];
    }

    delete[] mang;  
    mang = mangMoi; 
    n++;  
}

int main() {
    int n;
    cout << "Nhập số lượng phân số: ";
    cin >> n;

    PhanSo* mangPhanSo = new PhanSo[n];

    // Nhập các phân số  
    for (int i = 0; i < n; i++) {
        cout << "Phân số thứ " << i + 1 << ":" << endl;
        nhapPhanSo(mangPhanSo[i]);
        rutGon(mangPhanSo[i]);
    }

    // Xuất các phân số  
    cout << "Các phân số vừa nhập là:" << endl;
    for (int i = 0; i < n; i++) {
        xuatPhanSo(mangPhanSo[i]);
        cout << endl;
    }

    // Xuất các phân số có mẫu > tử  
    xuatPhanSoMaUu(mangPhanSo, n);

    // Tính tích các phần tử  
    PhanSo tich = tinhTich(mangPhanSo, n);
    cout << "Tích các phân số là: ";
    xuatPhanSo(tich);
    cout << endl;

    // Tìm phần tử lớn nhất  
    PhanSo lonNhat = timPhanTuLonNhat(mangPhanSo, n);
    cout << "Phân số lớn nhất là: ";
    xuatPhanSo(lonNhat);
    cout << endl;

    // Tìm phân số lớn nhất và nhỏ nhất  
    PhanSo nhoNhat;
    timPhanSoLonNhatVaNhoNhat(mangPhanSo, n, lonNhat, nhoNhat);
    cout << "Phân số nhỏ nhất là: ";
    xuatPhanSo(nhoNhat);
    cout << endl;

    // Xóa phần tử tại vị trí k  
    int k;
    cout << "Nhập vị trí cần xóa (0 đến " << n - 1 << "): ";
    cin >> k;
    xoaPhanTu(mangPhanSo, n, k);
    cout << "Sau khi xóa, các phân số còn lại là:" << endl;
    for (int i = 0; i < n; i++) {
        xuatPhanSo(mangPhanSo[i]);
        cout << endl;
    }

    // Thêm phần tử x tại vị trí k  
    PhanSo x;
    cout << "Nhập phân số cần thêm:" << endl;
    nhapPhanSo(x);
    cout << "Nhập vị trí cần thêm (0 đến " << n << "): ";
    cin >> k;
    themPhanTu(mangPhanSo, n, x, k);
    cout << "Sau khi thêm, các phân số là:" << endl;
    for (int i = 0; i < n; i++) {
        xuatPhanSo(mangPhanSo[i]);
        cout << endl;
    }

    // Giải phóng bộ nhớ  
    delete[] mangPhanSo;

    return 0;
}