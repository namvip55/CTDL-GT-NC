#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct KhachHang {
    int maKH;
    string tenKH, sdt;
    float tongTien;
};

void Nhap(KhachHang *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap khach hang thu " << i + 1 << ":\n";
        cout << "Ma KH: "; cin >> a[i].maKH; cin.ignore();
        cout << "Ten KH: "; getline(cin, a[i].tenKH);
        cout << "SDT: "; cin >> a[i].sdt;
        cout << "Tong tien: "; cin >> a[i].tongTien;
    }
}

void Xuat(KhachHang *a, int n) {
    cout << left << setw(10) << "Ma KH" << setw(25) << "Ten khach hang" << setw(15) << "SDT" << setw(15) << "Tong tien" << "\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << a[i].maKH << setw(25) << a[i].tenKH << setw(15) << a[i].sdt << setw(15) << a[i].tongTien << "\n";
    }
}

void InsertionSort(KhachHang *a, int n) {
    int pos; KhachHang x;
    for (int i = 1; i < n; i++) {
        x = a[i]; pos = i - 1;
        while (pos >= 0 && a[pos].tongTien > x.tongTien) {
            a[pos + 1] = a[pos]; pos--;
        }
        a[pos + 1] = x;
    }
}

int BinarySearch(float X, KhachHang *a, int n) {
    int m, bottom = 0, top = n - 1;
    while (bottom <= top) {
        m = (bottom + top + 1) / 2;
        if (X == a[m].tongTien) return m;
        else if (X < a[m].tongTien) top = m - 1;
        else bottom = m + 1;
    }
    return -1;
}

void HienThiKetQuaTimKiem(float X, KhachHang *a, int n) {
    int idx = BinarySearch(X, a, n);
    if (idx == -1) {
        cout << "Khong co khach hang nao co tong tien = " << X << "\n";
        return;
    }
    cout << "Danh sach khach hang tim thay:\n";
    cout << left << setw(10) << "Ma KH" << setw(25) << "Ten khach hang" << setw(15) << "SDT" << setw(15) << "Tong tien" << "\n";
    
    int left_idx = idx; while (left_idx >= 0 && a[left_idx].tongTien == X) left_idx--;
    int right_idx = idx + 1; while (right_idx < n && a[right_idx].tongTien == X) right_idx++;
    
    for (int i = left_idx + 1; i < right_idx; i++) {
        cout << left << setw(10) << a[i].maKH << setw(25) << a[i].tenKH << setw(15) << a[i].sdt << setw(15) << a[i].tongTien << "\n";
    }
}

int main() {
    int n; 
    cout << "Nhap so luong khach hang: "; cin >> n;
    KhachHang *a = new KhachHang[n];
    
    Nhap(a, n);
    
    cout << "\nDanh sach vua nhap:\n";
    Xuat(a, n);
    
    InsertionSort(a, n);
    cout << "\nDanh sach sau khi sap xep:\n";
    Xuat(a, n);
    
    float X; cout << "\nNhap tong tien can tim: "; cin >> X;
    HienThiKetQuaTimKiem(X, a, n);
    
    delete[] a; 
    return 0;
}