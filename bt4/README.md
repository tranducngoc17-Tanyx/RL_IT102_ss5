# THIET KE KIEN TRUC KIOSK DANG KY KHAM BENH TU DONG MEDCARE

---

## 1. SO DO TO CHUC DU LIEU (PARALLEL ARRAYS)

He thong su dung 7 mang song song de quan ly thong tin cua toi da 100 benh nhan (chi so tu 0 den n-1):

1. `stt[100]` (int): Ma so thu tu cua benh nhan (1001, 1002, ...).
2. `ten[100][30]` (char array): Ho va ten cua benh nhan (toi da 29 ky tu).
3. `tuoi[100]` (int): Do tuoi cua benh nhan.
4. `uu_tien[100]` (int): Trang thai uu tien (1: Uu tien - tren 70 tuoi hoac mang thai, 0: Thuong).
5. `bhyt[100]` (int): Trang thai BHYT (1: Co BHYT, 0: Khong BHYT).
6. `phi_kham[100]` (int): So tien kham so bo phai thu (VND).
7. `bac_si[100]` (int): Ma so bac si chuyen khoa duoc dang ky (VD: 1, 2, 3).

Bien quan ly do dai: `int n = 0;` (so luong benh nhan hien tai trong hang cho).

---

## 2. LUONG DU LIEU XU LY NGHIEP VU (DATA FLOW)

1. **Vong lap dieu khien Kiosk:**
   - Su dung vong lap `do...while (chon != 0)` de hien thi menu, nhap lua chon va thuc hien chuc nang cho den khi nguoi dung chon 0 de thoat.

2. **Tiep nhan benh nhan moi:**
   - Kiem tra `n < 100`, neu n >= 100 thi tu choi tiep nhan.
   - Nhap thong tin: Ten, Tuoi, Co mang thai khong (1/0), BHYT (1/0), Chon Bac si (1-3).
   - Kiem tra tai bac si: Dem trong mang `bac_si[]` xem ma bac si duoc chon da xuat hien bao nhieu lan. Neu da du 5 benh nhan thi thong bao qua tai va tu choi.
   - Tu dong phan loai: Neu `tuoi > 70` hoac `mang_thai == 1` -> `uu_tien = 1`, nguoc lai `uu_tien = 0`.
   - Tu dong tinh phi: Neu `bhyt == 1` -> `phi_kham = 40000`, nguoc lai `phi_kham = 200000`.
   - Cap nhat mang tai vi tri `n` va tang `n = n + 1`.

3. **Huy so thu tu (Xoa benh nhan):**
   - Nhap ma STT hoac vi tri K can xoa.
   - Thuc hien vong lap don dich tat ca cac mang tu vi tri K den `n - 2` sang trai 1 nac:
     + Don dich mang so: `mang[i] = mang[i + 1]`.
     + Don dich mang chuoi `ten` bang vong lap copy ky tu thu cong.
   - Giam `n = n - 1`.

4. **Cap nhat & Tim kiem:**
   - Tra cuu vi tri benh nhan bang cach so sanh STT hoac dung ham so sanh chuoi thu cong.
   - Cap nhat lai thong tin va tinh lai `phi_kham` neu thay doi BHYT.