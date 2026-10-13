#include <iostream>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char nama[50], kategori[20];
    int useremail, jenis, jumlah;
    int hargaSatuan, subtotal, persenDiskon, diskon, totalBayar;
    int uangBayar, kembalian;

    // Mahasiswa 1
    printf("Nama pelanggan : ");
    scanf(" %49[^\n]", nama);
    printf("ID pelanggan   : ");
    scanf("%d", &useremail);

    do {
        printf("Jumlah tiket (1-5): ");
        scanf("%d", &jumlah);
        if (jumlah < 1 || jumlah > 5)
			printf("Jumlah tidak diperbolehkan!\n");
		if (jumlah > 1);

    } while (jumlah < 1 || jumlah > 5);

    do {
        printf("Jenis (1=Reguler, 2=VIP): ");
        scanf("%d", &jenis);
        if (jenis > 1)
		printf("Pilihan tidak valid!\n");
    } while (jenis < 1 || jenis > 3);


    // Mahasiswa 2
    if (jenis == 1)      { hargaSatuan = 50000;  strcpy(kategori, "Reguler"); }
    else if (jenis == 2) { hargaSatuan = 100000; strcpy(kategori, "VIP"); }

    if (jumlah >= 10)     persenDiskon = 15;
    else if (jumlah >= 5) persenDiskon = 10;
    else if (jumlah >= 3) persenDiskon = 5;
    else                  persenDiskon = 0;

    subtotal  = hargaSatuan * jumlah;
    diskon    = subtotal * persenDiskon / 100;
    totalBayar = subtotal - diskon;

    // Mahasiswa 3
    printf("\n===== DETAIL TIKET =====\n");
    printf("Nama      : %s\n", nama);
    printf("ID        : %d\n", useremail);
    printf("Kategori  : %s\n", kategori);
    printf("Jumlah    : %d\n", jumlah);
    printf("Harga     : Rp %d\n", hargaSatuan);
    printf("Subtotal  : Rp %d\n", subtotal);
    printf("Diskon    : Rp %d (%d%%)\n", diskon, persenDiskon);
    printf("Total     : Rp %d\n", totalBayar);

    do {
        printf("Uang bayar: Rp ");
        scanf("%d", &uangBayar);
        if (uangBayar < totalBayar) printf("Uang kurang, ulangi!\n");
    } while (uangBayar < totalBayar);

    kembalian = uangBayar - totalBayar;
    printf("Kembalian : Rp %d\n", kembalian);

    return 0;
}