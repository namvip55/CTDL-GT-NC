# 📘 BÀI 6: ĐỒ THỊ TRỌNG SỐ & ĐƯỜNG ĐI NGẮN NHẤT (CHUẨN FORM THI)

> **Tài liệu nguồn**: Trang 6 - `Baitap_TH_CTDLDT_NC.pdf`

---

## 📌 1. ĐỀ BÀI (CHUẨN FORM THẦY/CÔ)
Cho đồ thị đầu vào $G$ gồm **6 đỉnh**: `V1, V2, V3, V4, V5, V6`.

- **Câu 1 (2.0 điểm)**: Biểu diễn đồ thị $G$ dưới dạng ma trận trọng số và lưu vào file `Grap.txt` (hoặc `INPUT.txt`).
- **Câu 2 (3.0 điểm)**: Cài đặt hàm `Nhap(Dijsktra &d)` nhập đồ thị từ file, lưu vào cấu trúc `struct Dijsktra`.
- **Câu 3 (1.5 điểm)**: Cài đặt hàm `HienThi(Dijsktra d)` hiển thị ma trận đồ thị ra màn hình (các ô không cạnh hiển thị số 0).
- **Câu 4 (2.0 điểm)**: Cài đặt hàm `RunDijsktra(Dijsktra &d)` và `HienThiDuongDiNganNhat(Dijsktra d)` tìm đường đi ngắn nhất.
- **Câu 5 (1.5 điểm)**: Cài đặt hàm `main()` tìm đường từ **V1** đến **V6**.

---

## 🎨 2. SƠ ĐỒ ĐỒ THỊ (ASCII ART)

```text
(V1) -----9----- (V2) -----10----- (V4)
            |                |                / |
            9                4               3  | 5
            |                |              /   |
           (V3) -----2----- (V5) ----------'   (V6)
                             \                 /
                              '-------5-------'
```

---

## 📝 3. NỘI DUNG FILE `Grap.txt` (HOẶC `INPUT.txt`)

Tạo file **`Grap.txt`** nằm cùng thư mục code và dán nội dung sau vào:

```text
6
0 5
 0  9  9  0  0  0
 9  0  0 10  4  0
 9  0  0  0  2  0
 0 10  0  0  3  5
 0  4  2  3  0  5
 0  0  0  5  5  0
```

### 💡 Cấu trúc file:
- **Dòng 1**: Số đỉnh $N = 6$.
- **Dòng 2**: Đỉnh đầu và đỉnh cuối (`0 5` = `V1 V6`).
- **6 dòng tiếp theo**: Ma trận trọng số (6x6). Không có cạnh ghi số 0 (hàm `Nhap` sẽ tự động chuyển 0 thành `VOCUNG = 10000000`).

---

## 🚀 4. KẾT QUẢ ĐẦU RA MẪU (CHUẨN FORM THI)

```text
Do thi vua nhap la:
- So dinh cua do thi: 6
- Ma tran trong so cua do thi:
...
Duong di ngan nhat tu V1 den V6 la
V6<=V5<=V3<=V1
Do dai duong di la : 16
```
