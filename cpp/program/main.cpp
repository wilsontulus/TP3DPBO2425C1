/*
 * LICENSE: All Rights Reserved
 * (c) 2025 Willsoon Tulus P. Simanjuntak
 * (c) 2025 Universitas Pendidikan Indonesia
 *
 * Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
 * Tugas Praktikum 3 dalam mata kuliah Desain Pemrograman
 * Berorientasi Objek untuk keberkahanNya maka saya tidak
 * melakukan kecurangan seperti yang telah dispesifikasikan.
 * Aamiin.
 */

/* Deklarasi file header custom */
#include "header.hpp"

/* Main driver */

int main() {

    // Variabel pilihan menu (angka)
    int choiceNum = -1;

    // Tampilkan menu hingga angka 0
    while (choiceNum != 0) {
        // Kumpulan menu
        cout << "Menu Pilihan: " << endl;
        cout << "1. Tambah data" << endl;
        cout << "2. Tampilkan data" << endl;
        cout << "0. Keluar dari program" << endl << endl;
        cout << "Masukkan angka pilihan: ";

        // Minta input masukan menu
        cin >> choiceNum;


        // Pilihan menu
        switch(choiceNum) {
            case 1: // Tambah data baru.

                break;
            case 2: // Tampilkan seluruh list produk yang tersedia di listProduk

                break;
            case 0: // Keluar program
                cout << "Program selesai digunakan." << endl;
                break;

            default:
                cout << "Masukan harus sesuai dengan menu yang ditentukan (0-2)." << endl;
                break;
        }
    };

    // Selesai
    return 0;
}
