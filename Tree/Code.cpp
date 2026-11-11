#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Câu 1: Ð?nh nghia c?u trúc Sinh vien
struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float diemTK;
    string hanhKiem;
};

// C?u trúc Nút c?a Cây nh? phân tìm ki?m
struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};

typedef Node* BSTree;

// Câu 2: Các thao tác trên Cây nh? phân tìm ki?m
void InitTree(BSTree &root) {
    root = NULL;
}

Node* CreateNode(SinhVien sv) {
    Node* p = new Node;
    if (p == NULL) exit(1);
    p->data = sv;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InsertNode(BSTree &root, SinhVien sv) {
    if (root == NULL) {
        root = CreateNode(sv);
    } else {
        if (sv.maSV < root->data.maSV) {
            InsertNode(root->left, sv);
        } else if (sv.maSV > root->data.maSV) {
            InsertNode(root->right, sv);
        }
    }
}

Node* SearchNode(BSTree root, int searchMaSV) {
    if (root == NULL || root->data.maSV == searchMaSV) {
        return root;
    }
    if (searchMaSV < root->data.maSV) {
        return SearchNode(root->left, searchMaSV);
    } else {
        return SearchNode(root->right, searchMaSV);
    }
}

// Hàm in tiêu d? b?ng
void InTieuDeBang() {
    cout << left 
         << setw(12) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(12) << "Lop"
         << setw(12) << "Diem TK"
         << setw(12) << "Hanh Kiem" << endl;
}

// Hàm in 1 sinh viên theo dòng d?nh d?ng setw
void Xuat1SV(SinhVien sv) {
    cout << left 
         << setw(12) << sv.maSV
         << setw(25) << sv.tenSV
         << setw(12) << sv.lop
         << setw(12) << fixed << setprecision(1) << sv.diemTK
         << setw(12) << sv.hanhKiem << endl;
}

void Traverse(BSTree root) {
    if (root != NULL) {
        Traverse(root->left);
        Xuat1SV(root->data);
        Traverse(root->right);
    }
}

// Hàm ph? tr? nh?p d? li?u
SinhVien Nhap1SV() {
    SinhVien sv;
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    
    cin.ignore();
    cout << "Nhap ten sinh vien: ";
    getline(cin, sv.tenSV);
    
    cout << "Nhap lop: ";
    getline(cin, sv.lop);
    
    cout << "Nhap diem tong ket: ";
    cin >> sv.diemTK;
    
    cin.ignore();
    cout << "Nhap hanh kiem: ";
    getline(cin, sv.hanhKiem);
    
    return sv;
}

int main() {
    BSTree root;
    InitTree(root);

    // Câu 3: Nh?p n sinh viên
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
        SinhVien sv = Nhap1SV();
        InsertNode(root, sv);
    }

    // Câu 4: Hi?n th? danh sách sinh viên d?ng b?ng
    cout << "\nDANH SACH SINH VIEN TRONG CAY:\n";
    InTieuDeBang();
    Traverse(root);

    // Câu 5: Tìm ki?m sinh viên theo mã
    int key;
    cout << "\nNhap ma sinh vien can tim: ";
    cin >> key;

    Node* result = SearchNode(root, key);
    if (result != NULL) {
        cout << "\nTHONG TIN SINH VIEN CAN TIM:\n";
        InTieuDeBang();
        Xuat1SV(result->data);
    } else {
        cout << "\nKhong co sinh vien trong cay.\n";
    }

    return 0;
}
