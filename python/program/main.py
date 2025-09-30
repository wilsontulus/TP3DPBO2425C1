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
from proyek import Proyek
from aset import Aset
from kantor import Kantor

# Deklarasi fungsi utama (main) #

def main():
    # Deklarasi variabel list kantor yang tersedia
    listKantor: list[Kantor] = []

    # Masukkan minimal 2 data dummy untuk tiap kelas #

    # Data dummy untuk kantor A
    kantorA: Kantor = Kantor("K001", "GETech ID", "Jakarta")
    
    kantorA.addAset(Aset("GA001", "GE PC e9-200", "PC Desktop", 10))
    kantorA.addAset(Aset("GA002", "GE 3Dshape e1-10", "3D Printer", 2))

    kantorA.addProyek(Proyek("GP001", "Pembuatan graf pemetaan lapang ruko", "Outdoor", "15/10/2025"))
    kantorA.addProyek(Proyek("GP002", "Analisis arsitektur pemrosesan RISC-V", "Analisa", "28/10/2025"))

    kantorA.addManager(Manager("000301", "Astec", "08100011", "GM002", "Head Management", "5 Tahun"));
    kantorA.addManager(Manager("000341", "Chendy", "08400030", "GM003", "Human Resources", "2 Tahun"))

    kantorA.addKaryawan(Karyawan("000980", "Asep", "08950001200", "GK012", "Tetap", "Administrasi", kantorA.getManager()[0]))
    kantorA.addKaryawan(Karyawan("000991", "Ghea", "08950001250", "GK016", "Tetap", "Resepsionis", kantorA.getManager()[1]))
    
    # Data dummy untuk kantor B
    kantorB: Kantor = Kantor("K002", "IC Tek BDG", "Bandung");
    
    kantorB.addAset(Aset("IA001", "ITM PC M70H", "PC Desktop", 50));
    kantorB.addAset(Aset("IA002", "Supervision KD1-CF", "Interactive Boardd", 2));
    kantorB.addAset(Aset("IA003", "eP Grandlion ae200cs", "Laptop", 5));

    kantorB.addProyek(Proyek("IP001", "Analisis pemasaran produk berbasis PC-AI untuk para konsumen", "Outdoor", "12/10/2025"));
    kantorB.addProyek(Proyek("IP002", "Perancangan prototipe untuk desain sirkuit IC-A001", "Analisa", "09/11/2025"));

    kantorB.addManager(Manager("000299", "Erza", "08100019", "AM003", "Head Management", "4 Tahun"));
    kantorB.addManager(Manager("000482", "Dezky", "08200099", "AM005", "Stock Management", "3 Tahun"));

    kantorB.addKaryawan(Karyawan("000976", "Jakob", "08890001280", "AK010", "Tetap", "Administrasi", kantorA.getManager()[0]));
    kantorB.addKaryawan(Karyawan("0001152", "Reva", "08830001500", "AK016", "Tetap", "Asisten Produksi", kantorA.getManager()[1]));
    kantorB.addKaryawan(Karyawan("000948", "Kobi", "08820001290", "AK017", "Tetap", "Resepsionis", kantorA.getManager()[0]));
    
    # Masukkan ke list kantor
    listKantor.append(kantorA)
    listKantor.append(kantorB)
    
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
                    if len(listKantor) > 0:
                        print("List kantor yang tersedia:\n")
                        for kantor in listKantor:
                            # Tampilkan informasi kantor
                            print("[ " + kantor.getNama() + " ]\n")
                            print("Kode: " + kantor.getKode())
                            print("Nama: " + kantor.getNama())
                            print("Lokasi: " + kantor.getLokasi())
                            
                            # Tampilkan daftar manager kantor
                            print("Manager: ", end="")
                            if len(kantor.getManager()) > 0:
                                tempIterator = 0
                                for manager in kantor.getManager():
                                    print(manager.getNama() + " (" + manager.getKode() + ")", end="")
                                    tempIterator += 1
                                    if len(kantor.getManager()) != tempIterator:
                                        print(", ", end="")
                                        
                                print("")
                                
                            # Tampilkan daftar karyawan kantor
                            print("Karyawan: ", end="")
                            if len(kantor.getKaryawan()) > 0:
                                tempIterator = 0
                                for karyawan in kantor.getKaryawan():
                                    print(karyawan.getNama() + " (" + karyawan.getKode() + ")", end="")
                                    tempIterator += 1
                                    if len(kantor.getKaryawan()) != tempIterator:
                                        print(", ", end="")
                                        
                                print("")
                                
                            # Tampilkan daftar proyek kantor
                            print("Proyek: ", end="")
                            if len(kantor.getProyek()) > 0:
                                tempIterator = 0
                                for proyek in kantor.getProyek():
                                    print(proyek.getNama() + " (" + proyek.getKode() + ")", end="")
                                    tempIterator += 1
                                    if len(kantor.getProyek()) != tempIterator:
                                        print(", ", end="")
                                        
                                print("")
                                
                            # Tampilkan daftar aset kantor
                            print("Karyawan: ", end="")
                            if len(kantor.getAset()) > 0:
                                tempIterator = 0
                                for aset in kantor.getAset():
                                    print(aset.getNama() + " (" + aset.getKode() + ")", end="")
                                    tempIterator += 1
                                    if len(kantor.getAset()) != tempIterator:
                                        print(", ", end="")
                                        
                                print("")
                                
                            # Selesaikan dengan newline
                            print("")
                            
                    else: # Jika tidak ada kantor tersedia, tampilkan bahwa tidak ada kantor yang tersedia.
                        print("List kantor tidak tersedia.")
                case 4: # Tampilkan seluruh data yang terkait dari suatu kantor
                    # Tampilkan kode kantor yang tersedia
                    print("Kantor tersedia:")
                    for kantor in listKantor:
                        print("[" + kantor.getKode() + "] " + kantor.getNama())
                        
                    print("")
                    # Minta input kode kantor untuk melanjutkan tampilan informasi kantor
                    tempOfficeCode: str = input("Masukkan kode kantor: ")
                    
                    officeFound = False
                    for kantor in listKantor:
                        if kantor.getKode() == tempOfficeCode:
                            print("Kode: " + kantor.getKode())
                            print("Nama: " + kantor.getNama())
                            print("Lokasi: " + kantor.getLokasi() + "\n")
                            
                            # Tampilkan daftar manager kantor
                            print("[ Daftar Manager ]\n")
                            if len(kantor.getManager()) > 0:
                                for manager in kantor.getManager():
                                    print("Kode: " + manager.getKode())
                                    print("NIK: " + manager.getNik())
                                    print("Nama: " + manager.getNama())
                                    print("No. HP: " + manager.getNomorHP())
                                    print("Bidang: " + manager.getBidang())
                                    print("Periode: " + manager.getPeriode())
                                    print("")
                            else:
                                print("Kosong")
                                
                            # Tampilkan daftar karyawan kantor
                            print("[ Daftar Karyawan ]\n")
                            if len(kantor.getKaryawan()) > 0:
                                for karyawan in kantor.getKaryawan():
                                    print("Kode: " + karyawan.getKode())
                                    print("NIK: " + karyawan.getNik())
                                    print("Nama: " + karyawan.getNama())
                                    print("No. HP: " + karyawan.getNomorHP())
                                    print("Status: " + karyawan.getBidang())
                                    print("Bidang: " + karyawan.getBidang())
                                    
                                    # Jika data manager terkait masih tersedia, tampilkan nama manager tersebut
                                    if karyawan.getManager():
                                        print("Manager: " + karyawan.getManager().getNama())
                                    else:
                                        print("Manager: (Tidak tersedia)")
                                        
                                    print("")
                            else:
                                print("Kosong")
                            
                            # Tampilkan daftar proyek kantor
                            print("[ Daftar Proyek ]\n")
                            if len(kantor.getProyek()) > 0:
                                for proyek in kantor.getProyek():
                                    print("Kode: " + proyek.getKode())
                                    print("Nama: " + proyek.getNama())
                                    print("Jenis: " + proyek.getJenis())
                                    print("Deadline: " + proyek.getDeadline())                                      
                                    print("")
                            else:
                                print("Kosong")
                            
                            # Tampilkan daftar aset kantor
                            print("[ Daftar Aset ]\n")
                            if len(kantor.getAset()) > 0:
                                for aset in kantor.getAset():
                                    print("Kode: " + aset.getKode())
                                    print("Nama: " + aset.getNama())
                                    print("Jenis: " + aset.getJenis())
                                    print("Jumlah: " + str(aset.getJumlah))                                      
                                    print("")
                            else:
                                print("Kosong")
                            
                            # Tandai bahwa kode kantor sudah ditemukan
                            officeFound = True                            
                            
                    # Peringatkan jika kode kantor tidak ditemukan
                    if officeFound == False:
                        print("Kode kantor tidak ditemukan.")
                        
                case 0:
                    print("Program selesai digunakan.")
                case _:
                    print("Masukan harus sesuai dengan menu yang ditentukan (0-4).")
        else:
            print("Masukan harus berupa angka.")

# Eksekusi otomatis untuk main
if __name__ == "__main__":
    main()
