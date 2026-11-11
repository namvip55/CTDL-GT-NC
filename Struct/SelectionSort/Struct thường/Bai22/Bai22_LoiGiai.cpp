#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct SinhVien {
    int maSV;
    string tenSV, lop;
    float diemTK;
};

void Nhap(SinhVien *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap sinh vien thu " << i + 1 << ":\n";
        cout << "Ma SV: "; cin >> a[i].maSV; cin.ignore();
        cout << "Ten SV: "; getline(cin, a[i].tenSV);
        cout << "Lop: "; getline(cin, a[i].lop);
        cout << "Diem tong ket: "; cin >> a[i].diemTK;
    }
}

void Xuat(SinhVien *a, int n) {
    cout << left << setw(10) << "Ma SV" << setw(25) << "Ten SV" << setw(15) << "Lop" << setw(10) << "Diem TK" << "\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << a[i].maSV << setw(25) << a[i].tenSV << setw(15) << a[i].lop << setw(10) << a[i].diemTK << "\n";
    }
}

void SelectionSort(SinhVien *a, int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].diemTK < a[min].diemTK) min = j;
        }
        SinhVien x = a[min]; a[min] = a[i]; a[i] = x;
    }
}

int BinarySearch(float X, SinhVien *a, int n) {
    int m, bottom = 0, top = n - 1;
    while (bottom <= top) {
        m = (bottom + top + 1) / 2;
        if (X == a[m].diemTK) return m;
        else if (X < a[m].diemTK) top = m - 1;
        else bottom = m + 1;
    }
    return -1;
}

void HienThiKetQuaTimKiem(float X, SinhVien *a, int n) {
    int idx = BinarySearch(X, a, n);
    if (idx == -1) {
        cout << "Khong co sinh vien nao co diem TK = " << X << "\n"; 
        return;
    }
    cout << "Danh sach sinh vien tim thay:\n";
    cout << left << setw(10) << "Ma SV" << setw(25) << "Ten SV" << setw(15) << "Lop" << setw(10) << "Diem TK" << "\n";
    
    int left_idx = idx; while (left_idx >= 0 && a[left_idx].diemTK == X) left_idx--;
    int right_idx = idx + 1; while (right_idx < n && a[right_idx].diemTK == X) right_idx++;
    
    for (int i = left_idx + 1; i < right_idx; i++) {
        cout << left << setw(10) << a[i].maSV << setw(25) << a[i].tenSV << setw(15) << a[i].lop << setw(10) << a[i].diemTK << "\n";
    }
}

int main() {
    int n; cout << "Nhap so luong sinh vien: "; cin >> n;
    SinhVien *a = new SinhVien[n];
    
    Nhap(a, n);
    cout << "\nDanh sach vua nhap:\n"; 
    Xuat(a, n);
    
    SelectionSort(a, n);
    cout << "\nDanh sach sau khi sap xep:\n"; 
    Xuat(a, n);
    
    float X; cout << "\nNhap diem TK can tim: "; cin >> X;
    HienThiKetQuaTimKiem(X, a, n);
    
    delete[] a; return 0;
}