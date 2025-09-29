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

    // Deklarasi variabel list kantor yang tersedia
    list<Kantor> listKantor;

    /* Masukkan minimal 2 data dummy untuk tiap kelas */

    // Data dummy untuk kantor A
    Kantor kantorA = Kantor("K001", "GETech ID", "Jakarta");
    
    kantorA.addAset(Aset("GA001", "GE PC e9-200", "PC Desktop", 10));
    kantorA.addAset(Aset("GA002", "GE 3Dshape e1-10", "3D Printer", 2));

    kantorA.addProyek(Proyek("GP001", "Pembuatan graf pemetaan lapang ruko", "Outdoor", "15/10/2025"));
    kantorA.addProyek(Proyek("GP002", "Analisis arsitektur pemrosesan RISC-V", "Analisa", "28/10/2025"));

    kantorA.addManager(Manager("000301", "Astec", "08100011", "Head Management", "5 Tahun"));
    kantorA.addManager(Manager("000341", "Chendy", "08400030", "Human Resources", "2 Tahun"));

    kantorA.addKaryawan(Karyawan("000980", "Asep", "08950001200", "Tetap", "Administrasi", kantorA.getManager().front()));
    kantorA.addKaryawan(Karyawan("000991", "Ghea", "08950001250", "Tetap", "Resepsionis", kantorA.getManager().back()));

    // Data dummy untuk kantor B
    Kantor kantorB = Kantor("K002", "IC Tek BDG", "Bandung");
    
    kantorB.addAset(Aset("IA001", "ITM PC M70H", "PC Desktop", 50));
    kantorB.addAset(Aset("IA002", "Supervision KD1-CF", "Interactive Boardd", 2));
    kantorB.addAset(Aset("IA003", "eP Grandlion ae200cs", "Laptop", 5));

    kantorB.addProyek(Proyek("IP001", "Analisis pemasaran produk konsumsi berbasis PC-AI", "Outdoor", "12/10/2025"));
    kantorB.addProyek(Proyek("IP002", "Perancangan prototipe untuk desain sirkuit IC-A001", "Analisa", "09/11/2025"));

    kantorB.addManager(Manager("000299", "Erza", "08100019", "Head Management", "4 Tahun"));
    kantorB.addManager(Manager("000482", "Dezky", "08200099", "Stock Management", "3 Tahun"));

    kantorB.addKaryawan(Karyawan("000976", "Jakob", "08890001280", "Tetap", "Administrasi", kantorA.getManager().front()));
    kantorB.addKaryawan(Karyawan("0001152", "Reva", "08830001500", "Tetap", "Asisten Produksi", kantorA.getManager().back()));
    kantorB.addKaryawan(Karyawan("000948", "Kobi", "08820001290", "Tetap", "Resepsionis", kantorA.getManager().front()));
    
    // Masukkan ke list kantor
    listKantor.push_back(kantorA);
    listKantor.push_back(kantorB);

    // Variabel pilihan menu (angka)
    int choiceNum = -1;

    // Variabel sementara untuk inputan pilihan dibawah
    string tempNik, tempName, tempNoHP, tempStatus, tempLocation, 
           tempBidang, tempIndexCode, tempOfficeCode, tempType,
           tempDeadline;
    
    int tempJumlah;

    // Variabel sementara untuk bagian dari proses fungsi dibawah
    int tempIterator = 0;
    bool officeFound = false;

    // Tampilkan menu hingga angka 0

    while (choiceNum != 0) {
        // Kumpulan menu
        cout << "Menu Pilihan: " << endl;
        cout << "1. Tambahkan data kantor" << endl;
        cout << "2. Tambahkan kantor baru" << endl;
        cout << "3. Tampilkan daftar kantor yang tersedia" << endl;
        cout << "4. Tampilkan data kantor" << endl;
        cout << "0. Keluar dari program" << endl << endl;
        cout << "Masukkan angka pilihan: ";

        // Minta input masukan menu
        cin >> choiceNum;


        // Pilihan menu
        switch(choiceNum) {
            case 1: // Tambah data baru pada suatu kantor.

                break;
            case 2: // Tambah objek kantor baru.

                break;
            case 3: // Tampilkan seluruh kantor yang tersedia
                if (listKantor.empty() == true) {
                    // Jika tidak ada kantor tersedia, tampilkan bahwa tidak ada kantor yang tersedia.
                    cout << "List kantor tidak tersedia." << endl;
                } else {
                    cout << "List kantor yang tersedia:" << endl << endl;
                    for (Kantor kantor : listKantor) {
                        cout << "[ " << kantor.getNama() << " ]" << endl << endl;
                        cout << "Kode: " << kantor.getKode() << endl;
                        cout << "Nama: " << kantor.getNama() << endl;
                        cout << "Lokasi: " << kantor.getLokasi() << endl;

                        cout << "Manager: ";
                        if (kantor.getManager().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            tempIterator = 0;
                            for (Manager manager : kantor.getManager()) {
                                cout << manager.getNama();
                                tempIterator++;
                                if (kantor.getManager().size() != tempIterator) {
                                    cout << ", ";
                                };
                            };
                            cout << endl;
                        };

                        cout << "Karyawan: ";
                        if (kantor.getKaryawan().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            tempIterator = 0;
                            for (Karyawan karyawan : kantor.getKaryawan()) {
                                cout << karyawan.getNama();
                                tempIterator++;
                                if (kantor.getKaryawan().size() != tempIterator) {
                                    cout << ", ";
                                };
                            };
                            cout << endl;
                        };

                        cout << "Proyek: ";
                        if (kantor.getProyek().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            tempIterator = 0;
                            for (Proyek proyek : kantor.getProyek()) {
                                cout << proyek.getNama() << " (" << proyek.getKode() << ")";
                                tempIterator++;
                                if (kantor.getProyek().size() != tempIterator) {
                                    cout << ", ";
                                };
                            };
                            cout << endl;
                        };

                        cout << "Aset: ";
                        if (kantor.getAset().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            tempIterator = 0;
                            for (Aset aset : kantor.getAset()) {
                                cout << aset.getNama() << " (" << aset.getKode() << ")";
                                tempIterator++;
                                if (kantor.getAset().size() != tempIterator) {
                                    cout << ", ";
                                };
                            };
                            cout << endl;
                        };
                        cout << endl;
                    };
                }
                break;
            case 4: // Tampilkan seluruh data yang terkait dari suatu kantor
                cout << "Masukkan kode kantor: ";
                cin >> tempOfficeCode;

                officeFound = false;
                for (Kantor kantor : listKantor) {
                    if (kantor.getKode() == tempOfficeCode) {
                        cout << "Kode: " << kantor.getKode() << endl;
                        cout << "Nama: " << kantor.getNama() << endl;
                        cout << "Lokasi: " << kantor.getLokasi() << endl;

                        cout << endl;
                        cout << "[ Daftar Manager ]" << endl << endl;
                        if (kantor.getManager().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            for (Manager manager : kantor.getManager()) {
                                cout << "NIK: " << manager.getNik() << endl;
                                cout << "Nama: " << manager.getNama() << endl;
                                cout << "No. HP: " << manager.getNomorHP() << endl;
                                cout << "Bidang: " << manager.getBidang() << endl;
                                cout << "Periode: " << manager.getPeriode() << endl;
                                cout << endl;
                            };
                        };

                        cout << endl;
                        cout << "[ Daftar Karyawan ]" << endl << endl;
                        if (kantor.getKaryawan().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            for (Karyawan karyawan : kantor.getKaryawan()) {
                                cout << "NIK: " << karyawan.getNik() << endl;
                                cout << "Nama: " << karyawan.getNama() << endl;
                                cout << "No. HP: " << karyawan.getNomorHP() << endl;
                                cout << "Status: " << karyawan.getStatus() << endl;
                                cout << "Bidang: " << karyawan.getBidang() << endl;
                                cout << "Manager: " << karyawan.getManager().getNama() << endl;
                                cout << endl;
                            };
                        };

                        cout << endl;
                        cout << "[ Daftar Proyek ]" << endl << endl;
                        if (kantor.getProyek().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            for (Proyek proyek : kantor.getProyek()) {
                                cout << "Kode: " << proyek.getKode() << endl;
                                cout << "Nama: " << proyek.getNama() << endl;
                                cout << "Jenis: " << proyek.getJenis() << endl;
                                cout << "Deadline: " << proyek.getDeadline() << endl;
                                cout << endl;
                            };
                        };

                        cout << endl;
                        cout << "[ Daftar Aset ]" << endl << endl;
                        if (kantor.getAset().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            for (Aset aset : kantor.getAset()) {
                                cout << "Kode: " << aset.getKode() << endl;
                                cout << "Nama: " << aset.getNama() << endl;
                                cout << "Jenis: " << aset.getJenis() << endl;
                                cout << "Jumlah: " << aset.getJumlah() << " pcs" << endl;
                                cout << endl;
                            };
                        };
                        cout << endl;
                        officeFound = true;
                    }
                }

                if (officeFound == false) {
                    cout << "Kode kantor tidak ditemukan." << endl;
                }
                break;
            case 0: // Keluar program
                cout << "Program selesai digunakan." << endl;
                break;

            default:
                cout << "Masukan harus sesuai dengan menu yang ditentukan (0-4)." << endl;
                break;
        }
    };

    // Selesai
    return 0;
}
