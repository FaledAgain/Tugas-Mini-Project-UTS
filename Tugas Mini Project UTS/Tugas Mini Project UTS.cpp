#include <stdio.h>
#include <string.h>

int main(void)
{
    char nama[50], kategori[20], email[50];
    int jenis, jumlah;
    int hargaSatuan, subtotal, persenDiskon, diskon, totalBayar;
    int uangBayar, kembalian;

    char pilihanUlang;     // Variabel untuk menampung jawaban user (y/t)
    int idCounter = 1;     // Variabel auto-increment untuk ID tiket

    // Perulangan utama program (akan terus mengulang jika user memilih 'y' atau 'Y')
    do {
        printf("\n========================================\n");
        printf("           TRANSAKSI TIKET #%d          \n", idCounter);
        printf("========================================\n");

		// Mahasiswa Ke-1

        // Input Data Pelanggan //
        printf("Nama pelanggan : ");
        scanf(" %[^\n]", nama);
        printf("Email          : ");
        scanf(" %[^\n]", email);

        // Input Pembelian Tiket //
        do {
            printf("\nJenis Tiket: \n");
            printf("1. Tiket Reguler \n");
            printf("2. Tiket VIP \n");
            printf("Pilih Jenis Tiket (1 / 2): ");
            scanf("%d", &jenis);

            if (jenis < 1 || jenis > 2) {
                printf("Pilihan tidak valid!\n");
            }
        } while (jenis < 1 || jenis > 2);

        do {
            printf("Jumlah tiket (1-5): ");
            scanf("%d", &jumlah);
            if (jumlah < 1 || jumlah > 5) {
                printf("Jumlah tidak valid!\n");
            }
        } while (jumlah < 1 || jumlah > 5);


        // Mahasiswa Ke-2

        // Fungsi Logika Harga Tiket & Mendeklarasi Nama Kategori Tiket //
        if (jenis == 1) {
            hargaSatuan = 5000;
            strcpy(kategori, "Reguler");
        }
        else if (jenis == 2) {
            hargaSatuan = 10000;
            strcpy(kategori, "VIP");
        }

        // Sistem Diskon //
        if (jumlah >= 5)      persenDiskon = 15;
        else if (jumlah >= 3) persenDiskon = 10;
        else if (jumlah >= 2) persenDiskon = 5;
        else                  persenDiskon = 0;

        // Rumus Diskon //
        subtotal   = hargaSatuan * jumlah;
        diskon     = subtotal * persenDiskon / 100;
        totalBayar = subtotal - diskon;

        // Mahasiswa Ke-3

        // Output Detail Tiket serta Harga //
        printf("\n===== DETAIL TIKET =====\n");
        printf("Nama             : %s\n", nama);
        printf("Email            : %s\n", email);
        printf("ID               : %d\n", idCounter); // ID otomatis bertambah
        printf("Kategori         : %s\n", kategori);
        printf("Jumlah           : %d\n", jumlah);
        printf("Harga 1 Tiket    : Rp %d\n", hargaSatuan);
        printf("Subtotal         : Rp %d\n", subtotal);
        printf("Diskon           : Rp %d (%d%%)\n", diskon, persenDiskon);
        printf("Total            : Rp %d\n", totalBayar);

        do {
            printf("Uang bayar: Rp ");
            scanf("%d", &uangBayar);
            if (uangBayar < totalBayar) {
                printf("Uang kurang, ulangi!\n");
            }
        } while (uangBayar < totalBayar);

        kembalian = uangBayar - totalBayar;
        printf("Kembalian : Rp %d\n", kembalian);
        printf("========================================\n");

        // Pertanyaan untuk pembeli berikutnya
        do {

        printf("\nIngin membeli tiket sebagai pembeli baru? (y/t): ");
        scanf(" %c", &pilihanUlang);

        // Jika user menjawab 'y' atau 'Y', ID naik 1 tingkat, lalu program mengulang dari atas
        if (pilihanUlang == 'y' || pilihanUlang == 'Y') {
            idCounter++;
            break;
        }

        else if (pilihanUlang == 't' || pilihanUlang == 'T') {
			printf("\nTerima kasih telah menggunakan program pembelian tiket!\n");
			break;
		}

		else { (pilihanUlang != 't' || pilihanUlang != 'T');
			printf("\nInput tidak Valid! Mohon Diulang\n");
		}

	} while (1);

    } while (pilihanUlang == 'y' || pilihanUlang == 'Y');





    return 0;
}