# PHAN TICH VA THIET KE MODULE TIEP NHAN KHAM BENH MEDCARE CLINIC

---

## 1. Phan Tich Dau Vao & Dau Ra (Input / Output)

### MANG DU LIEU LUU TRU
- `tuoi_benh_nhan[4]`: Mang kieu int luu do tuoi cua 4 benh nhan.
- `co_bao_hiem[4]`: Mang kieu int luu trang thai BHYT (1: Co, 0: Khong).
- `phi_kham[4]`: Mang kieu float luu tien kham thuc te phai thu.

### BIEN TONG HOP DAU RA
- `tong_doanh_thu`: Kieu float luu tong tien kham thuc te thu duoc.
- `so_ca_uu_tien`: Kieu int luu tong so benh nhan thuoc luong UU TIEN.

---

## 2. De Xuat Giai Phap Kiêm Soat Loi Du Lieu

- Khi `tuoi_benh_nhan[i] <= 0` hoac `tuoi_benh_nhan[i] > 120`: Gan `phi_kham[i] = 0`, phan loai luong la "LOI DU LIEU", khong tinh vao doanh thu va so ca uu tien.
- Khi `co_bao_hiem[i]` nhap khac 0 va khac 1: Tu dong dua `co_bao_hiem[i] = 0` (Khong co BHYT).
- Khi `co_bao_hiem[i] == 1` va tuoi hop le: `phi_kham[i] = 40000`.
- Khi `co_bao_hiem[i] == 0` va tuoi hop le: `phi_kham[i] = 200000`.
- Khi `tuoi_benh_nhan[i] > 70` va tuoi hop le: Thuoc luong "UU TIEN".

---

## 3. Cac Buoc Thuc Hien

- Buoc 1: Khai bao cac mang `tuoi_benh_nhan[4]`, `co_bao_hiem[4]`, `phi_kham[4]` va hai bien `tong_doanh_thu = 0`, `so_ca_uu_tien = 0`.
- Buoc 2: Dung vong lap `for` tu `i = 0` den `3` de nhap tuoi va BHYT cho tung benh nhan.
- Buoc 3: Trong vong lap, kiem tra va chuan hoa BHYT sai quy chuan ve 0. Kiem tra tuoi hop le de tinh `phi_kham[i]`, cong don `tong_doanh_thu` va dem `so_ca_uu_tien`.
- Buoc 4: Dung vong lap `for` thu hai de in danh sach, tuoi, phi kham va luong phan loai.
- Buoc 5: In tong doanh thu va tong so ca uu tien.