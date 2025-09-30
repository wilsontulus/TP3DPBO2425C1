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
    tempName = ""
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
                    # Tampilkan list menu atribut
                    print("Menu Penambahan Data Kantor:")
                    print("1. Aset")
                    print("2. Proyek")
                    print("3. Karyawan")
                    print("4. Manager")
                    tempAddDataSelection = input("Pilih data untuk ditambahkan: ")
                    
                    # Periksa masukan angka
                    if tempAddDataSelection.isdigit():
                        tempAddDataSelection = int(tempAddDataSelection)
                        
                        # Periksa angka masukan
                        if (tempAddDataSelection >= 1 and tempAddDataSelection <= 4):
                            # Tampilkan kode kantor yang tersedia
                            print("Kantor tersedia:")
                            for kantor in listKantor:
                                print("[" + kantor.getKode() + "] " + kantor.getNama())
                                
                            print("")
                            
                            # Minta input kode kantor untuk melanjutkan penambahan data kantor
                            tempOfficeCode = input("Masukkan kode kantor: ")
                            
                            # Periksa apakah ada kantor dengan kode yang sama

                            officeFound = False
                            
                            for kantor in listKantor:
                                if kantor.getKode() == tempOfficeCode:
                                    officeFound = True
                                    match(tempAddDataSelection):
                                        case 1: # Penambahan aset baru
                                            tempIndexCode = input("Masukkan kode aset: ")
                                            
                                            # Periksa apakah kode aset yang dimasukkan sudah digunakan oleh aset lain
                                            dataFound = False
                                            for aset in kantor.getAset():
                                                if aset.getKode() == tempIndexCode:
                                                    dataFound = True
                                                    tempName = aset.getNama()
                                                    
                                            # Lanjutkan jika kode belum digunakan
                                            if dataFound == False:
                                                tempName = input("Masukkan nama aset: ")
                                                tempType = input("Masukkan jenis aset: ")
                                                tempJumlah = input("Masukkan jumlah aset: ")
                                                
                                                if tempJumlah.isdigit():
                                                    tempJumlah = int(tempJumlah)
                                                    
                                                    # Tambahkan sebagai baris terakhir list
                                                    kantor.addAset(Aset(tempIndexCode, tempName, tempType, tempJumlah))
                                                    
                                                    # Tampilkan bahwa proses penambahan aset baru sudah selesai
                                                    print("Sukses menambahkan aset baru dengan kode " + tempIndexCode)
                                                else:
                                                    print("Masukan jumlah harus berupa angka.")
                                                print("Sukses menambahkan aset baru dengan kode " + tempIndexCode)
                                            else: # Batalkan proses jika kode sudah digunakan
                                                print("Kode aset " + tempIndexCode + " sudah digunakan oleh aset bernama " + tempName + ".")
                                                
                                        case 2: # Penambahan proyek baru
                                            tempIndexCode = input("Masukkan kode proyek: ")
                                            
                                            # Periksa apakah kode proyek yang dimasukkan sudah digunakan oleh proyek lain
                                            dataFound = False
                                            for proyek in kantor.getProyek():
                                                if proyek.getKode() == tempIndexCode:
                                                    dataFound = True
                                                    tempName = proyek.getNama()
                                                    
                                            # Lanjutkan jika kode belum digunakan
                                            if dataFound == False:
                                                tempName = input("Masukkan nama proyek: ")
                                                tempType = input("Masukkan jenis proyek: ")
                                                tempDeadline = input("Masukkan deadline proyek: ")
                                                    
                                                # Tambahkan sebagai baris terakhir list
                                                kantor.addProyek(Proyek(tempIndexCode, tempName, tempType, tempDeadline))
                                                    
                                                # Tampilkan bahwa proses penambahan proyek baru sudah selesai
                                                print("Sukses menambahkan proyek baru dengan kode " + tempIndexCode)
                                            else: # Batalkan proses jika kode sudah digunakan
                                                print("Kode proyek " + tempIndexCode + " sudah digunakan oleh proyek bernama " + tempName + ".")
                                        case 3: # Penambahan karyawan baru
                                            tempIndexCode = input("Masukkan kode karyawan: ")
                                            
                                            # Periksa apakah kode karyawan yang dimasukkan sudah digunakan oleh karyawan lain
                                            dataFound = False
                                            for karyawan in kantor.getKaryawan():
                                                if karyawan.getKode() == tempIndexCode:
                                                    dataFound = True
                                                    tempName = karyawan.getNama()
                                                    
                                            # Lanjutkan jika kode belum digunakan
                                            if dataFound == False:
                                                # Kelas "Penduduk"
                                                tempNik = input("Masukkan NIK karyawan: ")
                                                tempName = input("Masukkan nama karyawan: ")
                                                tempNoHP = input("Masukkan nomor HP karyawan: ")
                                                
                                                # Kelas "Karyawan"
                                                tempStatus = input("Masukkan status kerja karyawan: ")
                                                tempBidang = input("Masukkan bidang karyawan: ")
                                                
                                                # Tampilkan list manager
                                                print("List manager tersedia:")
                                                for manager in kantor.getManager():
                                                    print("[" + manager.getKode() + "] " + manager.getNama())
                                                    
                                                print("")
                                                
                                                # Minta input kode manager
                                                tempEmployeeManagerCode = input("Masukkan kode manager untuk karyawan: ")
                                                
                                                # Periksa manager tersedia
                                                employManagerFound = False
                                                for manager in kantor.getManager():
                                                    if tempEmployeeManagerCode == manager.getKode():
                                                        employManagerFound = True
                                                        
                                                        # Tambahkan sebagai baris terakhir list
                                                        kantor.addKaryawan(Karyawan(tempNik, tempName, tempNoHP, tempIndexCode, tempStatus, tempBidang, manager))
                                                        
                                                        # Tampilkan bahwa proses penambahan aset baru sudah selesai
                                                        print("Sukses menambahkan karyawan baru dengan kode " + tempIndexCode)
                                                        
                                                
                                                # Peringatkan jika kode manager tidak ditemukan
                                                if employManagerFound == False:
                                                    print("Kode manager " + tempEmployeeManagerCode + " tidak ditemukan.")
                                            else: # Batalkan proses jika kode sudah digunakan
                                                print("Kode karyawan " + tempIndexCode + " sudah digunakan oleh " + tempName + ".")
                                        case 4: # Penambahan manager baru
                                            tempIndexCode = input("Masukkan kode manager: ")
                                            
                                            # Periksa apakah kode manager yang dimasukkan sudah digunakan oleh manager lain
                                            dataFound = False
                                            for manager in kantor.getManager():
                                                if manager.getKode() == tempIndexCode:
                                                    dataFound = True
                                                    tempName = manager.getNama()
                                                    
                                            # Lanjutkan jika kode belum digunakan
                                            if dataFound == False:
                                                # Kelas "Penduduk"
                                                tempNik = input("Masukkan NIK manager: ")
                                                tempName = input("Masukkan nama manager: ")
                                                tempNoHP = input("Masukkan nomor HP manager: ")
                                                
                                                # Kelas "Manager"
                                                tempBidang = input("Masukkan bidang manager: ")
                                                tempPeriode = input("Masukkan periode manager: ")
                                                
                                                # Tambahkan sebagai baris terakhir list
                                                kantor.addManager(Manager(tempNik, tempName, tempNoHP, tempIndexCode, tempBidang, tempPeriode))
                                                        
                                                # Tampilkan bahwa proses penambahan aset baru sudah selesai
                                                print("Sukses menambahkan manager baru dengan kode " + tempIndexCode)
                                                
                                            else: # Batalkan proses jika kode sudah digunakan
                                                print("Kode manager " + tempIndexCode + " sudah digunakan oleh " + tempName + ".")
                                            
                                        case _:
                                            print("Masukan harus sesuai dengan menu yang ditentukan (1-4).")
                                    
                            # Peringatkan jika kode kantor tidak ditemukan
                            if officeFound == False:
                                print("Kode kantor tidak ditemukan.")
                        else:
                            print("Masukan harus sesuai dengan menu yang ditentukan (1-4).")
                    else:
                        print("Masukan harus berupa angka.")
                    
                    
                case 2: # Tambah objek kantor baru.
                    tempOfficeCode = input("Masukkan kode kantor baru: ")
                    
                    # Periksa apakah ada kantor dengan kode yang sama

                    officeFound = False
                    for kantor in listKantor:
                        if (kantor.getKode() == tempOfficeCode):
                            tempName = kantor.getNama()
                            officeFound = True
                            
                    # Lanjutkan pembuatan kantor baru jika kode belum digunakan
                    
                    if officeFound == False:
                        tempName = input("Masukkan nama kantor: ")
                        tempLocation = input("Masukkan lokasi kantor: ")
                        
                        # Tambahkan sebagai baris terakhir list
                        listKantor.append(Kantor(tempOfficeCode, tempName, tempLocation))
                        
                        # Tampilkan bahwa proses penambahan kantor baru sudah selesai
                        print("Sukses menambahkan kantor dengan kode " + tempOfficeCode)
                    else: # Batalkan proses jika kode sudah digunakan
                        print("Kode kantor " + tempOfficeCode + " sudah digunakan oleh kantor bernama " + tempName + ".")
                        
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
                            else:
                                print("(Kosong)")
                                
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
                            else:
                                print("(Kosong)")
                                
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
                            else:
                                print("(Kosong)")
                                
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
                            else:
                                print("(Kosong)")
                                
                            # Selesaikan dengan newline
                            print("")
                        
                        # Jeda menu hingga menekan Enter
                        _ = input("Tekan ENTER untuk kembali ke menu utama.")                            
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
                    else:
                        # Jeda menu hingga menekan Enter
                        _ = input("Tekan ENTER untuk kembali ke menu utama.")
                        
                case 0:
                    print("Program selesai digunakan.")
                case _:
                    print("Masukan harus sesuai dengan menu yang ditentukan (0-4).")
        else:
            print("Masukan harus berupa angka.")

# Eksekusi otomatis untuk main
if __name__ == "__main__":
    main()
