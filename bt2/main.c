#include <stdio.h>

int main() {
    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    float phi_kham[4];

    float tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;

    printf("=== HE THONG TIEP NHAN KHAM BENH MEDCARE CLINIC ===\n");

    // 1. Nhap va xu ly du lieu cho 4 benh nhan
    for (int i = 0; i < 4; i++) {
        printf("\nNhap thong tin benh nhan thu %d:\n", i + 1);

        printf("Nhap tuoi: ");
        scanf("%d", &tuoi_benh_nhan[i]);

        printf("Co BHYT khong (1: Co, 0: Khong): ");
        scanf("%d", &co_bao_hiem[i]);

        // Xu ly loi BHYT sai quy chuan
        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            printf("BHYT khong hop le, tu dong dua ve 0 (Khong BHYT)\n");
            co_bao_hiem[i] = 0;
        }

        // Xu ly loi tuoi va tinh phi kham
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            printf("Tuoi khong hop le! Gan phi kham = 0 VND\n");
            phi_kham[i] = 0;
        } else {
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = 40000;
            } else {
                phi_kham[i] = 200000;
            }

            tong_doanh_thu = tong_doanh_thu + phi_kham[i];

            if (tuoi_benh_nhan[i] > 70) {
                so_ca_uu_tien++;
            }
        }
    }

    // 2. In danh sach va phan loai benh nhan
    printf("\n--- DANH SACH TIEP NHAN ---\n");
    for (int i = 0; i < 4; i++) {
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            printf("Benh nhan %d: Tuoi %d | Phi: %.0f VND | LOI DU LIEU\n", i + 1, tuoi_benh_nhan[i], phi_kham[i]);
        } else if (tuoi_benh_nhan[i] > 70) {
            printf("Benh nhan %d: Tuoi %d | Phi: %.0f VND | UU TIEN\n", i + 1, tuoi_benh_nhan[i], phi_kham[i]);
        } else {
            printf("Benh nhan %d: Tuoi %d | Phi: %.0f VND | THUONG\n", i + 1, tuoi_benh_nhan[i], phi_kham[i]);
        }
    }

    // 3. In bao cao tong hop ca truc
    printf("\n--- BAO CAO TONG HOP CA TRUC ---\n");
    printf("Tong doanh thu: %.0f VND\n", tong_doanh_thu);
    printf("Tong so ca uu tien: %d\n", so_ca_uu_tien);

    return 0;
}