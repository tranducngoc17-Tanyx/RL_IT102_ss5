#include <stdio.h>
#include <string.h>

int main() {
    // Khai bao 7 mang song song quan ly toi da 100 benh nhan
    int stt[100];
    char ten[100][30];
    int tuoi[100];
    int uu_tien[100];
    int bhyt[100];
    int phi_kham[100];
    int bac_si[100];

    int n = 0; // So luong benh nhan hien tai
    int ma_stt_tiep = 1001; // Ma STT tu dong tang
    int chon = 0;

    do {
        printf("\n================ MENU KIOSK MEDCARE ================\n");
        printf("1. Tiep nhan benh nhan moi\n");
        printf("2. Hien thi danh sach hang cho\n");
        printf("3. Cap nhat thong tin benh nhan\n");
        printf("4. Huy so thu tu (Xoa khoi hang cho)\n");
        printf("5. Tim kiem benh nhan\n");
        printf("0. Thoat chuong trinh\n");
        printf("----------------------------------------------------\n");
        printf("Chon chuc nang (0-5): ");
        scanf("%d", &chon);

        // Xoa bo dem ban phim sau khi nhap so
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        switch (chon) {
            case 1: { // 1. TIEP NHAN BENH NHAN MOI
                if (n >= 100) {
                    printf("Loi: Hang cho da day (toi da 100 benh nhan)!\n");
                    break;
                }

                printf("\n--- TIEP NHAN BENH NHAN MOI ---\n");

                printf("Nhap ho va ten: ");
                // Nhap chuoi an toan bang fgets()
                fgets(ten[n], sizeof(ten[n]), stdin);
                // Xoa ký tu '\n' do fgets() ghi nhan lai
                ten[n][strcspn(ten[n], "\n")] = '\0';

                printf("Nhap tuoi: ");
                scanf("%d", &tuoi[n]);

                int mang_thai = 0;
                printf("Co mang thai khong (1: Co, 0: Khong): ");
                scanf("%d", &mang_thai);

                printf("Co BHYT khong (1: Co, 0: Khong): ");
                scanf("%d", &bhyt[n]);

                printf("Chon Bac si chuyen khoa (1: Phong 101, 2: Phong 102, 3: Phong 103): ");
                scanf("%d", &bac_si[n]);

                // Kiem tra tai cua Bac si (Toi da 5 benh nhan / bac si)
                int dem_bac_si = 0;
                for (int i = 0; i < n; i++) {
                    if (bac_si[i] == bac_si[n]) {
                        dem_bac_si++;
                    }
                }

                if (dem_bac_si >= 5) {
                    printf("Loi: Bac si phong %d da nhan du 5 benh nhan! Tu choi dang ky.\n", bac_si[n]);
                    break;
                }

                // Gan STT
                stt[n] = ma_stt_tiep;
                ma_stt_tiep = ma_stt_tiep + 1;

                // Phan loai uu tien (> 70 tuoi hoac mang thai)
                if (tuoi[n] > 70 || mang_thai == 1) {
                    uu_tien[n] = 1;
                } else {
                    uu_tien[n] = 0;
                }

                // Tinh phi kham
                if (bhyt[n] == 1) {
                    phi_kham[n] = 40000;
                } else {
                    phi_kham[n] = 200000;
                }

                n = n + 1; // Tang so luong benh nhan
                printf("Dang ky thanh cong! STT cua ban la: %d\n", stt[n - 1]);
                break;
            }

            case 2: { // 2. HIEN THI DANH SACH HANG CHO
                if (n == 0) {
                    printf("Hang cho dang rong!\n");
                    break;
                }

                printf("\n--- DANH SACH HANG CHO KHAM BENH (%d benh nhan) ---\n", n);
                for (int i = 0; i < n; i++) {
                    printf("Vi tri %d | STT: %d | Ten: %s | Tuoi: %d | BHYT: ", i, stt[i], ten[i], tuoi[i]);
                    if (bhyt[i] == 1) {
                        printf("Co");
                    } else {
                        printf("Khong");
                    }

                    printf(" | Phi: %d VND | BS: Phong %d | Doi tuong: ", phi_kham[i], bac_si[i]);
                    if (uu_tien[i] == 1) {
                        printf("UU TIEN\n");
                    } else {
                        printf("THUONG\n");
                    }
                }
                break;
            }

            case 3: { // 3. CAP NHAT THONG TIN
                if (n == 0) {
                    printf("Hang cho rong!\n");
                    break;
                }

                int tim_stt = 0;
                printf("Nhap ma STT benh nhan can sua: ");
                scanf("%d", &tim_stt);
                
                // Xoa bo dem ban phim
                while ((c = getchar()) != '\n' && c != EOF);

                int vi_tri = -1;
                for (int i = 0; i < n; i++) {
                    if (stt[i] == tim_stt) {
                        vi_tri = i;
                        break;
                    }
                }

                if (vi_tri == -1) {
                    printf("Khong tim thay benh nhan co STT %d!\n", tim_stt);
                } else {
                    printf("Sua ho ten moi: ");
                    fgets(ten[vi_tri], sizeof(ten[vi_tri]), stdin);
                    ten[vi_tri][strcspn(ten[vi_tri], "\n")] = '\0';

                    printf("Sua tuoi moi: ");
                    scanf("%d", &tuoi[vi_tri]);

                    printf("Sua BHYT (1: Co, 0: Khong): ");
                    scanf("%d", &bhyt[vi_tri]);

                    // Tinh lai phi kham va uu tien
                    if (bhyt[vi_tri] == 1) {
                        phi_kham[vi_tri] = 40000;
                    } else {
                        phi_kham[vi_tri] = 200000;
                    }

                    if (tuoi[vi_tri] > 70) {
                        uu_tien[vi_tri] = 1;
                    } else {
                        uu_tien[vi_tri] = 0;
                    }

                    printf("Cap nhat thong tin thanh cong!\n");
                }
                break;
            }

            case 4: { // 4. HUY SO THU TU (XOA PHAN TU)
                if (n == 0) {
                    printf("Hang cho rong!\n");
                    break;
                }

                int tim_stt = 0;
                printf("Nhap ma STT can huy: ");
                scanf("%d", &tim_stt);

                int vi_tri = -1;
                for (int i = 0; i < n; i++) {
                    if (stt[i] == tim_stt) {
                        vi_tri = i;
                        break;
                    }
                }

                if (vi_tri == -1) {
                    printf("Khong tim thay STT %d de xoa!\n", tim_stt);
                } else {
                    // Don dich mang va dung strcpy de sao chep chuoi
                    for (int i = vi_tri; i < n - 1; i++) {
                        stt[i] = stt[i + 1];
                        strcpy(ten[i], ten[i + 1]);
                        tuoi[i] = tuoi[i + 1];
                        uu_tien[i] = uu_tien[i + 1];
                        bhyt[i] = bhyt[i + 1];
                        phi_kham[i] = phi_kham[i + 1];
                        bac_si[i] = bac_si[i + 1];
                    }
                    n = n - 1; // Giam so luong
                    printf("Da huy STT %d thanh cong!\n", tim_stt);
                }
                break;
            }

            case 5: { // 5. TIM KIEM BENH NHAN
                if (n == 0) {
                    printf("Hang cho rong!\n");
                    break;
                }

                char tim_ten[30];
                printf("Nhap ten benh nhan can tim: ");
                fgets(tim_ten, sizeof(tim_ten), stdin);
                tim_ten[strcspn(tim_ten, "\n")] = '\0';

                int tim_thay = 0;
                for (int i = 0; i < n; i++) {
                    // So sanh 2 chuoi bang strcmp()
                    if (strcmp(ten[i], tim_ten) == 0) {
                        printf("-> Tim thay: Vi tri %d | STT: %d | Ten: %s | Tuoi: %d | Phi: %d VND | BS: Phong %d\n",
                               i, stt[i], ten[i], tuoi[i], phi_kham[i], bac_si[i]);
                        tim_thay = 1;
                    }
                }

                if (tim_thay == 0) {
                    printf("Khong tim thay benh nhan co ten '%s'!\n", tim_ten);
                }
                break;
            }

            case 0:
                printf("Da thoat chuong trinh Kiosk!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai (0-5).\n");
                break;
        }

    } while (chon != 0);

    return 0;
}