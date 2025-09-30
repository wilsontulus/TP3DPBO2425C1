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
from manager import Manager
from karyawan import Karyawan

# Deklarasi fungsi utama (main) #

def main():
    # Deklarasi variabel list kantor yang tersedia
    listKantor = []

    # Masukkan minimal 2 data dummy untuk tiap kelas #

    # Data dummy untuk kantor A

    # Data dummy untuk kantor B

    # Masukkan ke list kantor

    # Variabel pilihan menu (angka)
    choiceNum = -1
    tempAddDataSelection = -1

    # Variabel sementara untuk bagian dari proses fungsi dibawah
    tempIterator = 0
    officeFound = False
    employManagerFound = False

    # Tampilkan menu hingga angka 0
    while (choiceNum != 0):
        print("Menu Pilihan: ")
        print("1. Tambahkan data kantor")
        print("2. Tambahkan kantor baru")
        print("3. Tampilkan daftar kantor yang tersedia")
        print("4. Tampilkan data kantor")
        print("0. Keluar dari program\n")
        choiceNum = input("Masukkan angka pilihan: ")

        if (choiceNum.isdigit()):
            choiceNum = int(choiceNum)

            match choiceNum:
                case 1: # Tambah data baru pada suatu kantor.
                    print("not implemented")
                case 2: # Tambah objek kantor baru.
                    print("not implemented")
                case 3: # Tampilkan seluruh kantor yang tersedia
                    print("not implemented")
                case 4: # Tampilkan seluruh data yang terkait dari suatu kantor
                    print("not implemented")
                case 0:
                    print("Program selesai digunakan.")
                case _:
                    print("Masukan harus sesuai dengan menu yang ditentukan (0-4).")
        else:
            print("Masukan harus berupa angka.")

# Eksekusi otomatis untuk main
if __name__ == "__main__":
    main()
