# 📘 BÀI 12: ĐỒ THỊ TRỌNG SỐ & ĐƯỜNG ĐI NGẮN NHẤT (CHUẨN FORM THI)

> **Tài liệu nguồn**: Trang 12 - `Baitap_TH_CTDLDT_NC.pdf`

---

## 📌 1. ĐỀ BÀI (CHUẨN FORM THẦY/CÔ)
Cho đồ thị đầu vào $G$ gồm **7 đỉnh**: `A, B, C, D, E, G, H`.

- **Câu 1 (2.0 điểm)**: Biểu diễn đồ thị $G$ dưới dạng ma trận trọng số và lưu vào file `Grap.txt` (hoặc `INPUT.txt`).
- **Câu 2 (3.0 điểm)**: Cài đặt hàm `Nhap(Dijsktra &d)` nhập đồ thị từ file, lưu vào cấu trúc `struct Dijsktra`.
- **Câu 3 (1.5 điểm)**: Cài đặt hàm `HienThi(Dijsktra d)` hiển thị ma trận đồ thị ra màn hình (các ô không cạnh hiển thị số 0).
- **Câu 4 (2.0 điểm)**: Cài đặt hàm `RunDijsktra(Dijsktra &d)` và `HienThiDuongDiNganNhat(Dijsktra d)` tìm đường đi ngắn nhất.
- **Câu 5 (1.5 điểm)**: Cài đặt hàm `main()` tìm đường từ **A** đến **H**.

---

## 🎨 2. SƠ ĐỒ ĐỒ THỊ (ASCII ART)

```text
(A) ---5--- (B) ---5--- (D) ---8--- (H)
       |         / |                      ^
       7       12  10                    /
       |       /   |                    /
      (C)     /   (E) --------6--------'
       \     /     |
        8   /      4
         \ /       |
         (G) ------'
```

---

## 📝 3. NỘI DUNG FILE `Grap.txt` (HOẶC `INPUT.txt`)

Tạo file **`Grap.txt`** nằm cùng thư mục code và dán nội dung sau vào:

```text
7
0 6
 0  5  7  0  0  0  0
 5  0  0  5 10 12  0
 7  0  0  0  0  8  0
 0  5  0  0  0  0  8
 0 10  0  0  0  4  6
 0 12  8  0  4  0 14
 0  0  0  8  6 14  0
```

### 💡 Cấu trúc file:
- **Dòng 1**: Số đỉnh $N = 7$.
- **Dòng 2**: Đỉnh đầu và đỉnh cuối (`0 6` = `A H`).
- **7 dòng tiếp theo**: Ma trận trọng số (7x7). Không có cạnh ghi số 0 (hàm `Nhap` sẽ tự động chuyển 0 thành `VOCUNG = 10000000`).

---

## 🚀 4. KẾT QUẢ ĐẦU RA MẪU (CHUẨN FORM THI)

```text
Do thi vua nhap la:
- So dinh cua do thi: 7
- Ma tran trong so cua do thi:
...
Duong di ngan nhat tu A den H la
H<=D<=B<=A
Do dai duong di la : 18
```
