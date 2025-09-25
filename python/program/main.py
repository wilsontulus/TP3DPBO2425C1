#!/bin/python3

# LICENSE: All Rights Reserved
# (c) 2025 Willsoon Tulus P. Simanjuntak
# (c) 2025 Universitas Pendidikan Indonesia
#
# Saya Willsoon Tulus Parluhutan Simanjuntak mengerjakan evaluasi
# Tugas Praktikum 3 dalam mata kuliah Desain Pemrograman
# Berorientasi Objek untuk keberkahanNya maka saya tidak
# melakukan kecurangan seperti yang telah dispesifikasikan.
# Aamiin.

# Deklarasi kelas objek #
from tipe import Tipe

# Deklarasi fungsi utama (main) #

def main():
    # Deklarasi variabel list
    list = []

    # Variabel pilihan menu (angka)
    choiceNum = -1

    # Tampilan menu hingga angka 0
    while (choiceNum != 0):
        print("Menu Pilihan: ")
        print("1. Tambah Barang")
        print("2. Tampilkan List Barang")
        print("0. Keluar dari program")
        choiceNum = input("Masukkan pilihan: ")

        if (choiceNum.isdigit()):
            choiceNum = int(choiceNum)

            match choiceNum:
                case 1: # Tambah data baru
                    print("not implemented")
                case 2: # Tampilkan list
                    print("not implemented")
                case 0:
                    print("Program selesai digunakan.")
                case _:
                    print("Masukan harus sesuai dengan menu yang ditentukan (0-2).")
        else:
            print("Masukan harus berupa angka.")

# Eksekusi otomatis untuk main
if __name__ == "__main__":
    main()
