# HƯỚNG DẪN DẠNG BÀI 49 - 50 (QUICKSORT & BINARY SEARCH)

## I. TỔNG QUAN DẠNG BÀI 49 VÀ 50

Hai bài cuối cùng trong bộ đề tập trung vào các thuật toán **Chia để trị (Divide and Conquer)** thao tác trực tiếp trên mảng cơ bản:

1. **Bài 49:** Thao tác trên **Mảng số nguyên** (`int`).
2. **Bài 50:** Thao tác trên **Mảng số thực** (`float` / `double`).

### Yêu cầu cố định của 2 bài:
* **Câu 1:** Hàm nhập mảng $n$ phần tử.
* **Câu 2:** Hàm xuất mảng $n$ phần tử ra màn hình.
* **Câu 3:** Hàm kiểm tra xem mảng đã cho có đang sắp xếp tăng dần hay không.
* **Câu 4:** Hàm sắp xếp nhanh **QuickSort** (theo chiến lược chia để trị).
* **Câu 5:** Áp dụng chiến lược chia để trị (bằng thuật toán **Binary Search**) viết hàm tìm kiếm **tất cả** các vị trí có giá trị bằng $X$.
* **Câu 6:** Hàm `main()` thực hiện nhập, xuất, kiểm tra thứ tự mảng (nếu chưa tăng dần thì gọi QuickSort), và hiển thị tất cả các vị trí của $X$.

---

## II. MÃ NGUỒN C++ BÀI 49 (MẢNG SỐ NGUYÊN)

```cpp
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Câu 1: Hàm nhập mảng n số nguyên
void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}

// Câu 2: Hàm xuất mảng n số nguyên
void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(8) << a[i];
    }
    cout << endl;
}

// Câu 3: Hàm kiểm tra mảng có sắp xếp tăng dần hay không
bool KiemTraTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

// Câu 4: Thuật toán Sắp xếp nhanh (QuickSort) theo chiến lược chia để trị
void QuickSort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

// Hàm phụ trợ: Tìm vị trí xuất hiện bất kỳ của X bằng Binary Search (Chia để trị)
int BinarySearch(int a[], int left, int right, int x) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (a[mid] == x) return mid;
    if (a[mid] > x) return BinarySearch(a, left, mid - 1, x);
    return BinarySearch(a, mid + 1, right, x);
}

// Câu 5: Hàm tìm kiếm và hiển thị TẤT CẢ các vị trí bằng X trong mảng đã sắp xếp
void TimKiemTatCa(int a[], int n, int x) {
    int pos = BinarySearch(a, 0, n - 1, x);

    if (pos == -1) {
        cout << "Khong tim thay gia tri " << x << " trong mang.\n";
        return;
    }

    // Vì mảng đã sắp xếp, các phần tử trùng nhau sẽ đứng liền kề
    // Tìm vị trí đầu tiên
    int left_bound = pos;
    while (left_bound > 0 && a[left_bound - 1] == x) {
        left_bound--;
    }

    // Tìm vị trí cuối cùng
    int right_bound = pos;
    while (right_bound < n - 1 && a[right_bound + 1] == x) {
        right_bound++;
    }

    // In tất cả các vị trí tìm được
    cout << "Tim thay gia tri " << x << " tai cac vi tri index: ";
    for (int i = left_bound; i <= right_bound; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Câu 6: Hàm main thực thi chương trình
int main() {
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    int a[1000];

    // Nhập và hiển thị mảng
    cout << "\nNHAP MANG SO NGUYEN:\n";
    NhapMang(a, n);

    cout << "\nMANG VUA NHAP:\n";
    XuatMang(a, n);

    // Kiểm tra và sắp xếp nếu chưa tăng dần
    if (KiemTraTangDan(a, n)) {
        cout << "\nMang da duoc sap xep tang dan tu truoc.\n";
    } else {
        cout << "\nMang chua duoc sap xep. Tien hanh sap xep bang QuickSort...\n";
        QuickSort(a, 0, n - 1);
        cout << "MANG SAU KHI SAP XEP TANG DAN:\n";
        XuatMang(a, n);
    }

    // Tìm kiếm phần tử X
    int x;
    cout << "\nNhap gia tri X can tim: ";
    cin >> x;

    TimKiemTatCa(a, n, x);

    return 0;
}
```

---

## III. MÃ NGUỒN C++ BÀI 50 (MẢNG SỐ THỰC)

```cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

// Câu 1: Hàm nhập mảng n số thực
void NhapMang(float a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
}

// Câu 2: Hàm xuất mảng n số thực dạng bảng định dạng setw
void XuatMang(float a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(10) << fixed << setprecision(2) << a[i];
    }
    cout << endl;
}

// Câu 3: Hàm kiểm tra mảng có sắp xếp tăng dần hay không
bool KiemTraTangDan(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

// Câu 4: Thuật toán Sắp xếp nhanh (QuickSort) cho số thực
void QuickSort(float a[], int left, int right) {
    int i = left;
    int j = right;
    float pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

// Hàm phụ trợ so sánh 2 số thực
bool bangNhau(float x, float y) {
    return fabs(x - y) < 1e-5;
}

// Tìm vị trí xuất hiện bất kỳ của X bằng Binary Search
int BinarySearch(float a[], int left, int right, float x) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (bangNhau(a[mid], x)) return mid;
    if (a[mid] > x) return BinarySearch(a, left, mid - 1, x);
    return BinarySearch(a, mid + 1, right, x);
}

// Câu 5: Hàm tìm kiếm và hiển thị TẤT CẢ các vị trí bằng X trong mảng số thực
void TimKiemTatCa(float a[], int n, float x) {
    int pos = BinarySearch(a, 0, n - 1, x);

    if (pos == -1) {
        cout << "Khong tim thay gia tri " << fixed << setprecision(2) << x << " trong mang.\n";
        return;
    }

    // Mở rộng tìm ranh giới trái
    int left_bound = pos;
    while (left_bound > 0 && bangNhau(a[left_bound - 1], x)) {
        left_bound--;
    }

    // Mở rộng tìm ranh giới phải
    int right_bound = pos;
    while (right_bound < n - 1 && bangNhau(a[right_bound + 1], x)) {
        right_bound++;
    }

    // In tất cả vị trí tìm được
    cout << "Tim thay gia tri " << fixed << setprecision(2) << x << " tai cac vi tri index: ";
    for (int i = left_bound; i <= right_bound; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Câu 6: Hàm main thực thi chương trình
int main() {
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    float a[1000];

    // Nhập và hiển thị mảng
    cout << "\nNHAP MANG SO THUC:\n";
    NhapMang(a, n);

    cout << "\nMANG VUA NHAP:\n";
    XuatMang(a, n);

    // Kiểm tra và sắp xếp nếu chưa tăng dần
    if (KiemTraTangDan(a, n)) {
        cout << "\nMang da duoc sap xep tang dan tu truoc.\n";
    } else {
        cout << "\nMang chua duoc sap xep. Tien hanh sap xep bang QuickSort...\n";
        QuickSort(a, 0, n - 1);
        cout << "MANG SAU KHI SAP XEP TANG DAN:\n";
        XuatMang(a, n);
    }

    // Tìm kiếm phần tử X
    float x;
    cout << "\nNhap gia tri X can tim: ";
    cin >> x;

    TimKiemTatCa(a, n, x);

    return 0;
}
```