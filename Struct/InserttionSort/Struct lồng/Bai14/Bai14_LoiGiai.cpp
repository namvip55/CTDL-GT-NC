#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct NgayThang { int ngay, thang, nam; };
struct HangHoa {
    string maHang, tenHang;
    NgayThang ngayXuat;
    float giaXuat;
};

void Nhap(HangHoa *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap hang hoa thu " << i + 1 << ":\n";
        cout << "Ma hang: "; cin >> a[i].maHang; cin.ignore();
        cout << "Ten hang: "; getline(cin, a[i].tenHang);
        cout << "Ngay xuat (ngay thang nam): "; cin >> a[i].ngayXuat.ngay >> a[i].ngayXuat.thang >> a[i].ngayXuat.nam;
        cout << "Gia xuat: "; cin >> a[i].giaXuat;
    }
}

void Xuat(HangHoa *a, int n) {
    cout << left << setw(10) << "Ma" << setw(25) << "Ten hang" << setw(15) << "Ngay xuat" << setw(10) << "Gia xuat" << "\n";
    for (int i = 0; i < n; i++) {
        string ngay = to_string(a[i].ngayXuat.ngay) + "/" + to_string(a[i].ngayXuat.thang) + "/" + to_string(a[i].ngayXuat.nam);
        cout << left << setw(10) << a[i].maHang << setw(25) << a[i].tenHang << setw(15) << ngay << setw(10) << a[i].giaXuat << "\n";
    }
}

void InsertionSort(HangHoa *a, int n) {
    int pos; HangHoa x;
    for (int i = 1; i < n; i++) {
        x = a[i]; pos = i - 1;
        while (pos >= 0 && a[pos].giaXuat > x.giaXuat) {
            a[pos + 1] = a[pos]; pos--;
        }
        a[pos + 1] = x;
    }
}

int BinarySearch(float X, HangHoa *a, int n) {
    int m, bottom = 0, top = n - 1;
    while (bottom <= top) {
        m = (bottom + top + 1) / 2;
        if (X == a[m].giaXuat) return m;
        else if (X < a[m].giaXuat) top = m - 1;
        else bottom = m + 1;
    }
    return -1;
}

void HienThiKetQuaTimKiem(float X, HangHoa *a, int n) {
    int idx = BinarySearch(X, a, n);
    if (idx == -1) {
        cout << "Khong co hang hoa nao co gia xuat = " << X << "\n";
        return;
    }
    cout << "Danh sach hang hoa tim thay:\n";
    cout << left << setw(10) << "Ma" << setw(25) << "Ten hang" << setw(15) << "Ngay xuat" << setw(10) << "Gia xuat" << "\n";
    
    int left_idx = idx; while (left_idx >= 0 && a[left_idx].giaXuat == X) left_idx--;
    int right_idx = idx + 1; while (right_idx < n && a[right_idx].giaXuat == X) right_idx++;
    
    for (int i = left_idx + 1; i < right_idx; i++) {
        string ngay = to_string(a[i].ngayXuat.ngay) + "/" + to_string(a[i].ngayXuat.thang) + "/" + to_string(a[i].ngayXuat.nam);
        cout << left << setw(10) << a[i].maHang << setw(25) << a[i].tenHang << setw(15) << ngay << setw(10) << a[i].giaXuat << "\n";
    }
}

int main() {
    int n; 
    cout << "Nhap so luong hang hoa: "; cin >> n;
    HangHoa *a = new HangHoa[n];
    
    Nhap(a, n);
    
    cout << "\nDanh sach vua nhap:\n";
    Xuat(a, n);
    
    InsertionSort(a, n);
    cout << "\nDanh sach sau khi sap xep:\n";
    Xuat(a, n);
    
    float X; cout << "\nNhap gia xuat can tim: "; cin >> X;
    HienThiKetQuaTimKiem(X, a, n);
    
    delete[] a; 
    return 0;
}