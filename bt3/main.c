#include <stdio.h>

int main() {
    int stt[100];
    int tuoi[100];
    int bhyt[100];

    int n = 0;
    int k = 0;

    printf("Nhap so luong benh nhan (0 - 100): ");
    scanf("%d", &n);

    if (n < 0 || n > 100) {
        printf("So luong khong hop le!\n");
        return 0;
    }

    // 1. Nhap danh sach
    for (int i = 0; i < n; i++) {
        printf("\nBenh nhan %d:\n", i + 1);
        stt[i] = 1001 + i;

        printf("Nhap tuoi: ");
        scanf("%d", &tuoi[i]);

        printf("Co BHYT khong (1: Co, 0: Khong): ");
        scanf("%d", &bhyt[i]);
    }

    // 2. In danh sach ban dau
    float tong_doanh_thu = 0;
    int so_uu_tien = 0;

    printf("\n--- DANH SACH BAN DAU ---\n");
    for (int i = 0; i < n; i++) {
        float gia_tien = 150000;
        if (bhyt[i] == 1) {
            gia_tien = 30000;
        }

        tong_doanh_thu = tong_doanh_thu + gia_tien;

        printf("Vi tri %d | STT: %d | Tuoi: %d | Gia: %.2f VND", i, stt[i], tuoi[i], gia_tien);
        
        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
            so_uu_tien++;
        } else {
            printf(" | THUONG\n");
        }
    }

    printf("Tong doanh thu: %.2f VND\n", tong_doanh_thu);
    printf("So ca uu tien: %d\n", so_uu_tien);

    // 3. Huy luot kham
    if (n == 0) {
        return 0;
    }

    printf("\nNhap vi tri K can huy: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Vi tri K khong hop le!\n");
        return 0;
    }

    // Don dich mang de xoa K
    for (int i = k; i < n - 1; i++) {
        stt[i] = stt[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
    }
    n = n - 1;

    // 4. In lai danh sach sau khi huy
    tong_doanh_thu = 0;
    so_uu_tien = 0;

    printf("\n--- DANH SACH SAU KHI HUY ---\n");
    for (int i = 0; i < n; i++) {
        float gia_tien = 150000;
        if (bhyt[i] == 1) {
            gia_tien = 30000;
        }

        tong_doanh_thu = tong_doanh_thu + gia_tien;

        printf("Vi tri %d | STT: %d | Tuoi: %d | Gia: %.2f VND", i, stt[i], tuoi[i], gia_tien);
        
        if (tuoi[i] >= 70) {
            printf(" | UU TIEN\n");
            so_uu_tien++;
        } else {
            printf(" | THUONG\n");
        }
    }

    printf("Tong doanh thu moi: %.2f VND\n", tong_doanh_thu);
    printf("So ca uu tien moi: %d\n", so_uu_tien);

    return 0;
}