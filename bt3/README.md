# PHAN TICH TRADE-OFF VA QUAN LY HANG CHO KIOSK MEDCARE CLINIC

---

## 1. Phan Tich Dau Vao & Dau Ra (Input / Output)

### DAU VAO (INPUT)
- So luong benh nhan ban dau `n` ($0 \le n \le 100$).
- Mang `stt[100]`: Luu ma so thu tu cua benh nhan.
- Mang `tuoi[100]`: Luu do tuoi cua benh nhan ($1 \le tuoi \le 120$).
- Mang `bhyt[100]`: Luu trang thai BHYT (1: Co, 0: Khong).
- Chi so `K`: Vi tri can huy luot kham ($0 \le K < n$).

### DAU RA (OUTPUT)
- Danh sach hang cho ban dau, tong doanh thu va so benh nhan uu tien.
- Danh sach hang cho sau khi huy, tong doanh thu va so benh nhan uu tien da cap nhat.

---

## 2. De Xuat Cac Giai Phap Ky Thuat Xu Ly Huy Luot Kham (Index K)

1. **Giai phap 1: Don dich mang (Shift Array / Hard Delete)**
   - Xoa phan tu tai chi so K, sau do quyet va don tat ca phan tu phia sau sang trai 1 vi tri (tu K den n-2).
   - Giam so luong `n` đi 1.

2. **Giai phap 2: Đanh dau trang thai (Soft Delete / Lazy Deletion)**
   - Khong xoa phan tu khoi mang, chi danh dau mot mảng phu `da_huy[K] = 1`.
   - Khi in hoac tinh doanh thu thi bo qua cac phan tu da bi danh dau huy.

3. **Giai phap 3: Doi cho voi phan tu cuoi (Swap with Last)**
   - Lay phan tu cuoi cung `[n-1]` de vao vi tri `K`, sau do giam `n` đi 1.

---

## 3. Bang So Sanh Cac Giai Phap

| Tieu chi | Giai phap 1: Don dich mang | Giai phap 2: Danh dau trang thai | Giai phap 3: Doi cho phan tu cuoi |
| :--- | :---: | :---: | :---: |
| **Do phuc tap thoi gian (Time)** | $O(N)$ (Can doi mảng) | $O(1)$ (Chi ghi chuyen trang thai) | $O(1)$ (Ghi de 1 phan tu) |
| **Dung luong bo nho (Space)** | $O(1)$ (Khong ton bo nho phu) | $O(N)$ (Can them mang trang thai) | $O(1)$ (Khong ton bo nho phu) |
| **Bao toan thu tu FIFO** | **CO** (Giu nguyen thu tu) | **CO** (Giu nguyen thu tu) | **KHONG** (Pha vo thu tu xep hang) |
| **Do phuc tap cai dat** | Don gian | Trung binh | Rất don gian |

---

## 4. Lua Chon Giai Phap Toi Uu

* **Giai phap duoc chon:** **Giai phap 1 (Don dich mang / Shift Array)**.
* **Ly do:**
  - Ngành y tế bắt buộc phải đảm bảo đúng thứ tự cấp số lượt khám (FIFO - Bệnh nhân đến trước khám trước). Giải pháp 3 làm đảo lộn thứ tự gọi số nên bị loại.
  - Số lượng bệnh nhân tối đa trong một ca chỉ là $N = 100$ (rất nhỏ), chi phí dồn dịch $O(N)$ mất chưa tới $1$ microgiây trên máy tính, không ảnh hưởng tới hiệu năng.
  - Giúp mảng luôn liên tục, quản lý chỉ số đơn giản và tiết kiệm bộ nhớ hơn Giải pháp 2.