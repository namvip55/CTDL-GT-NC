# 📘 BÀI 11: ĐỒ THỊ TRỌNG SỐ & ĐƯỜNG ĐI NGẮN NHẤT (CHUẨN FORM THI)

> **Tài liệu nguồn**: Trang 11 - `Baitap_TH_CTDLDT_NC.pdf`

---

## 📌 1. ĐỀ BÀI (CHUẨN FORM THẦY/CÔ)
Cho đồ thị đầu vào $G$ gồm **8 đỉnh**: `A, B, C, D, E, F, G, H`.

- **Câu 1 (2.0 điểm)**: Biểu diễn đồ thị $G$ dưới dạng ma trận trọng số và lưu vào file `Grap.txt` (hoặc `INPUT.txt`).
- **Câu 2 (3.0 điểm)**: Cài đặt hàm `Nhap(Dijsktra &d)` nhập đồ thị từ file, lưu vào cấu trúc `struct Dijsktra`.
- **Câu 3 (1.5 điểm)**: Cài đặt hàm `HienThi(Dijsktra d)` hiển thị ma trận đồ thị ra màn hình (các ô không cạnh hiển thị số 0).
- **Câu 4 (2.0 điểm)**: Cài đặt hàm `RunDijsktra(Dijsktra &d)` và `HienThiDuongDiNganNhat(Dijsktra d)` tìm đường đi ngắn nhất.
- **Câu 5 (1.5 điểm)**: Cài đặt hàm `main()` tìm đường từ **A** đến **H**.

---

## 🎨 2. SƠ ĐỒ ĐỒ THỊ (ASCII ART)

```text
(A) ---5--- (B) ---5--- (D) ---4--- (F)
      | \                      |           |
      7  12                   10           8
      |    \                   |           |
      (C)   '---- (E) ---------'          (H)
       \          / \                      ^
        8        4   6                     |
         \      /     \                    |
          '- (G) ------'------14-----------'
```

---

## 📝 3. NỘI DUNG FILE `Grap.txt` (HOẶC `INPUT.txt`)

Tạo file **`Grap.txt`** nằm cùng thư mục code và dán nội dung sau vào:

```text
8
0 7
 0  5  7  0 12  0  0  0
 5  0  0  5  0  0  0  0
 7  0  0  0  0  0  8  0
 0  5  0  0 10  4  0  0
12  0  0 10  0  0  4  6
 0  0  0  4  0  0  0  8
 0  0  8  0  4  0  0 14
 0  0  0  0  6  8 14  0
```

### 💡 Cấu trúc file:
- **Dòng 1**: Số đỉnh $N = 8$.
- **Dòng 2**: Đỉnh đầu và đỉnh cuối (`0 7` = `A H`).
- **8 dòng tiếp theo**: Ma trận trọng số (8x8). Không có cạnh ghi số 0 (hàm `Nhap` sẽ tự động chuyển 0 thành `VOCUNG = 10000000`).

---

## 🚀 4. KẾT QUẢ ĐẦU RA MẪU (CHUẨN FORM THI)

```text
Do thi vua nhap la:
- So dinh cua do thi: 8
- Ma tran trong so cua do thi:
...
Duong di ngan nhat tu A den H la
H<=E<=A
Do dai duong di la : 18
```
