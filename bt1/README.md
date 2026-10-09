# PHAN TICH ROI VA KHAC PHUC LOI VUOT BIEN CHI SO MANG (BUFFER OVERFLOW)

---

## 1. Phan Tich Loi Ky Thuat

* **Vi tri dong lenh loi:**
  - `queue_numbers[patient_position] = new_queue_number;`
* **Phan loai loi:**
  - **Loi truy cap ngoai pham vi mang (Out-of-bounds array access / Off-by-one error)**.
* **Nguyen nhan ky thuat:**
  - Mang `queue_numbers` duoc khai bao voi kich thuoc 4 phan tu (`int queue_numbers[4]`), nghia la chi so hop le trong ngon ngu C chay tu `0` den `3` (0-based index).
  - Bien `patient_position` luu vi tri thuc te theo goc nhan con nguoi (1-based index) va dang co gia tri bang `4`.
  - Khi thuc hien `queue_numbers[4] = 1099`, he thong ghi gia tri `1099` vao chi so `4` - day la vung nho nam ngoai pham vi duoc cap phat cua mang.
  - Vi vay, `queue_numbers[3]` (vi tri benh nhan thu 4) van giu nguyen gia tri cu `1004`, trong khi vung nho lân cap bi ghi de sai du lieu.
* **Giai phap khac phuc:**
  - Chuyen doi vi tri 1-based sang chi so mang 0-based bang cach tru di 1: `queue_numbers[patient_position - 1] = new_queue_number;`.

---

## 2. Bang Kiem Thu Test Cases

| Ma STT | Truong hop kiem thu | Du lieu dau vao | Ket qua sai thuc te | Ket qua dung mong doi |
| :---: | :--- | :--- | :--- | :--- |
| **TC-01** | Cap nhat benh nhan vi tri 4 | `patient_position = 4`<br>`new_queue_number = 1099` | Benh nhan 4 (Index 3): **1004**<br>*(Du lieu bi ghi out-of-bounds)* | Benh nhan 4 (Index 3): **1099**<br>*(Cap nhat thanh cong)* |
| **TC-02** | Cap nhat benh nhan vi tri 1 | `patient_position = 1`<br>`new_queue_number = 1000` | Benh nhan 1 (Index 0): **1000**<br>*(Loi tru 1 neu khong xu ly)* | Benh nhan 1 (Index 0): **1000**<br>*(Chuyen doi chi so chinh xac)* |