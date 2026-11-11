# Tổng hợp các thuật toán sắp xếp (và tìm kiếm) trong C++

Dưới đây là các hàm sắp xếp mảng cấu trúc `SinhVien` dựa trên trường dữ liệu `diemTK` được tổng hợp từ các hình ảnh cung cấp.

*Lưu ý: Các đoạn code dưới đây giả định rằng bạn đã định nghĩa sẵn một `struct SinhVien` có chứa thuộc tính `diemTK` (kiểu số, có thể là float hoặc int).*

## 1. Interchange Sort (Sắp xếp đổi chỗ trực tiếp)

```cpp
/// Câu 4 (Các hàm sắp xếp khác nhau đối với các Bài tập khác nhau)
void InterchangeSort(SinhVien *a, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[j].diemTK < a[i].diemTK)
            {
                SinhVien x = a[j];
                a[j] = a[i];
                a[i] = x;
            }
        }
    }
}
```

## 2. Selection Sort (Sắp xếp chọn)

```cpp
void SelectionSort(SinhVien *a, int n)
{
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j].diemTK < a[min].diemTK)
                min = j;
        }
        SinhVien x = a[min];
        a[min] = a[i];
        a[i] = x;
    }
}
```

## 3. Bubble Sort (Sắp xếp nổi bọt)

```cpp
void BubbleSort(SinhVien *a, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (a[j].diemTK < a[j-1].diemTK)
            {
                SinhVien x = a[j];
                a[j] = a[j-1];
                a[j-1] = x;
            }
        }
    }
}
```

## 4. Insertion Sort (Sắp xếp chèn)

```cpp
void InsertionSort(SinhVien *a, int n)
{
    int pos;
    SinhVien x;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while ((pos >= 0) && (a[pos].diemTK > x.diemTK))
        {
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}
```

## 5. Quick Sort (Sắp xếp nhanh)

```cpp
void QuickSort(SinhVien *a, int left, int right)
{
    SinhVien x = a[(left + right) / 2];
    int i = left, j = right;
    while (i < j)
    {
        while (a[i].diemTK < x.diemTK) i++;
        while (a[j].diemTK > x.diemTK) j--;
        if (i <= j)
        {
            SinhVien tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;

            i++;
            j--;
        }
    }
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}
/// Hết Câu 4
```

## 6. Merge Sort (Sắp xếp trộn)

Thuật toán này cần 2 hàm: Hàm `Merge` để trộn và hàm `MergeSort` để chia để trị.

```cpp
/// Merge sort
void Merge(SinhVien *a, int left, int mid, int right)
{
    // Cap phat dong - chua gia tri da sap xep cua hai mang
    SinhVien *temp = new SinhVien[right - left + 1];
    int n = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid || j <= right)
    {
        if ((i <= mid && j <= right && a[i].diemTK < a[j].diemTK) || j > right)
            temp[n++] = a[i++];
        else
            temp[n++] = a[j++];
    }
    for (i = 0; i < n; i++)
        a[left + i] = temp[i];

    delete [] temp;
}

void MergeSort(SinhVien *a, int left, int right){
    if (left < right)
    {
        int mid = (left + right) / 2;
        // Sap xep mang tu chi so left den mid
        MergeSort(a, left, mid);
        // Sap xep mang tu chi so mid + 1 den right
        MergeSort(a, mid + 1, right);

        // Tron hai mang da duoc sap xep lai voi nhau
        Merge(a, left, mid, right);
    }
}
/// End Merge sort
```

## 7. Heap Sort (Sắp xếp vun đống)

Thuật toán này bao gồm các hàm để duy trì tính chất đống (`ShipDown`), tạo đống ban đầu (`CreateHeap`) và hàm gọi chính (`HeapSort`). *(Lưu ý: Tên hàm giữ nguyên là `ShipDown` như trong ảnh gốc)*.

```cpp
/// Heap sort
void ShipDown(SinhVien *a, int i, int n)
{
    int Max = i;
    int left = 2 * i + 1;    //Danh sach a bat dau tu 0
    int right = 2 * i + 2;
    if (left < n && a[left].diemTK > a[i].diemTK)
        Max = left;
    if (right < n && a[right].diemTK > a[Max].diemTK)
        Max = right;
    if (Max != i){
        SinhVien temp = a[i];
        a[i] = a[Max];
        a[Max] = temp;
        ShipDown(a, Max, n);
    }
}

void CreateHeap(SinhVien *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        ShipDown(a, i, n);
    }
}

void HeapSort(SinhVien *a, int n){
    CreateHeap(a, n);
    for (int size = n - 1; size >= 0; size--)
    {
        SinhVien temp = a[0];
        a[0] = a[size];
        a[size] = temp;
        ShipDown(a, 0, size);
    }
}
/// End Heap sort
```

## 8. Binary Search (Tìm kiếm nhị phân)
*Mặc dù không phải là thuật toán sắp xếp, nhưng hình ảnh bạn gửi có bao gồm Câu 5 là thuật toán tìm kiếm.*

```cpp
/// Câu 5
// Tim kiem mot phan tu trong danh sach
int BinarySearch(float diemTK, SinhVien *a, int N)
{
    int m, bottom, top;
    bottom = 0;
    top = N - 1;
    while (bottom <= top)
    {
        m = (bottom + top + 1) / 2;
        if (diemTK == a[m].diemTK)
            return m;
        else if (diemTK < a[m].diemTK) top = m - 1;
        else bottom = m + 1;
    }
    
    return -1;
}
```