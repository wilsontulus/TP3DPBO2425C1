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

    kantorA.addManager(Manager("000301", "Astec", "08100011", "GM002", "Head Management", "5 Tahun"));
    kantorA.addManager(Manager("000341", "Chendy", "08400030", "GM003", "Human Resources", "2 Tahun"));

    kantorA.addKaryawan(Karyawan("000980", "Asep", "08950001200", "GK012", "Tetap", "Administrasi", kantorA.getManager().front()));
    kantorA.addKaryawan(Karyawan("000991", "Ghea", "08950001250", "GK016", "Tetap", "Resepsionis", kantorA.getManager().back()));

    // Data dummy untuk kantor B
    Kantor kantorB = Kantor("K002", "IC Tek BDG", "Bandung");
    
    kantorB.addAset(Aset("IA001", "ITM PC M70H", "PC Desktop", 50));
    kantorB.addAset(Aset("IA002", "Supervision KD1-CF", "Interactive Board", 2));
    kantorB.addAset(Aset("IA003", "eP Grandlion ae200cs", "Laptop", 5));

    kantorB.addProyek(Proyek("IP001", "Analisis pemasaran produk berbasis PC-AI untuk para konsumen", "Outdoor", "12/10/2025"));
    kantorB.addProyek(Proyek("IP002", "Perancangan prototipe untuk desain sirkuit IC-A001", "Analisa", "09/11/2025"));

    kantorB.addManager(Manager("000299", "Erza", "08100019", "AM003", "Head Management", "4 Tahun"));
    kantorB.addManager(Manager("000482", "Dezky", "08200099", "AM005", "Stock Management", "3 Tahun"));

    kantorB.addKaryawan(Karyawan("000976", "Jakob", "08890001280", "AK010", "Tetap", "Administrasi", kantorB.getManager().front()));
    kantorB.addKaryawan(Karyawan("0001152", "Reva", "08830001500", "AK016", "Tetap", "Asisten Produksi", kantorB.getManager().back()));
    kantorB.addKaryawan(Karyawan("000948", "Kobi", "08820001290", "AK017", "Tetap", "Resepsionis", kantorB.getManager().front()));
    
    // Masukkan ke list kantor
    listKantor.push_back(kantorA);
    listKantor.push_back(kantorB);

    // Variabel pilihan menu (angka)
    int choiceNum = -1, tempAddDataSelection = -1;

    // Variabel sementara untuk inputan pilihan dibawah
    string tempNik, tempName, tempNoHP, tempStatus, tempLocation, 
           tempBidang, tempPeriode, tempIndexCode, tempOfficeCode, 
           tempEmployeeManagerCode, tempType, tempDeadline;
    
    int tempJumlah;

    // Variabel sementara untuk bagian dari proses fungsi dibawah
    unsigned long tempIterator = 0; // unsigned long digunakan untuk mencocokan dengan tipe data dari metode .size() dari list
    bool officeFound = false, dataFound = false, employManagerFound = false;

    // Tampilkan menu hingga angka 0

    while (choiceNum != 0) {
        // Kumpulan menu
        cout << "Menu Pilihan:" << endl;
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
                // Tampilkan list menu atribut
                cout << "Menu Penambahan Data Kantor:" << endl;
                cout << "1. Aset" << endl;
                cout << "2. Proyek" << endl;
                cout << "3. Karyawan" << endl;
                cout << "4. Manager" << endl;
                cout << "Pilih data untuk ditambahkan: ";

                // Minta nomor untuk pilihan data yang ditambahkan
                cin >> tempAddDataSelection;


                if (tempAddDataSelection >= 1 && tempAddDataSelection <= 4) {

                    // Tampilkan kode kantor yang tersedia
                    cout << "Kantor tersedia:" << endl;
                    for (Kantor kantor: listKantor) {
                        cout << "[" << kantor.getKode() << "] " << kantor.getNama() << endl;
                    };
                    cout << endl;

                    // Minta input kode kantor untuk melanjutkan penambahan data kantor
                    cout << "Masukkan kode kantor: ";
                    cin >> tempOfficeCode;

                    // Periksa apakah ada kantor dengan kode yang sama

                    officeFound = false;
                    // Reference pointer digunakan agar atribut dari kelas dalam list bisa ditambahkan/diupdate
                    for (Kantor &kantor : listKantor) {
                        if (kantor.getKode() == tempOfficeCode && officeFound != true) {
                            officeFound = true;
                            switch(tempAddDataSelection) {
                                // Untuk nama, getline digunakan untuk menerima spasi
                                // cin.ignore() digunakan sebelum getline pertama untuk mencegah double newline di beberapa sistem.
                                case 1: // Penambahan aset baru
                                    cout << "Masukkan kode aset: ";
                                    cin >> tempIndexCode;

                                    // Periksa apakah kode aset yang dimasukkan sudah digunakan oleh aset lain
                                    dataFound = false;
                                    for (Aset aset: kantor.getAset()) {
                                        if (aset.getKode() == tempIndexCode) {
                                            dataFound = true;
                                            tempName = aset.getNama();
                                        }
                                    }

                                    // Lanjutkan jika kode belum digunakan
                                    if (dataFound == false) {
                                        cout << "Masukkan nama aset: ";
                                        cin.ignore();
                                        getline(cin, tempName);

                                        cout << "Masukkan jenis aset: ";
                                        cin >> tempType;

                                        cout << "Masukkan jumlah aset: ";
                                        cin >> tempJumlah;

                                        // Tambahkan sebagai baris terakhir list
                                        kantor.addAset(Aset(tempIndexCode, tempName, tempType, tempJumlah));

                                        // Tampilkan bahwa proses penambahan aset baru sudah selesai
                                        cout << "Sukses menambahkan aset baru dengan kode " << tempIndexCode << endl;
                                    } else { // Batalkan proses jika kode sudah digunakan
                                        cout << "Kode aset " << tempIndexCode << " sudah digunakan oleh aset bernama " << tempName << "." << endl;
                                    }
                                    break;
                                case 2: // Penambahan proyek baru
                                    cout << "Masukkan kode proyek: ";
                                    cin >> tempIndexCode;

                                    // Periksa apakah kode proyek yang dimasukkan sudah digunakan oleh proyek lain
                                    dataFound = false;
                                    for (Proyek proyek: kantor.getProyek()) {
                                        if (proyek.getKode() == tempIndexCode) {
                                            dataFound = true;
                                            tempName = proyek.getNama();
                                        }
                                    }

                                    // Lanjutkan jika kode belum digunakan
                                    if (dataFound == false)  {
                                        cout << "Masukkan nama proyek: ";
                                        cin.ignore();
                                        getline(cin, tempName);

                                        cout << "Masukkan jenis proyek: ";
                                        cin >> tempType;

                                        cout << "Masukkan deadline proyek (DD/MM/YYYY): ";
                                        cin >> tempDeadline;

                                        // Tambahkan sebagai baris terakhir list
                                        kantor.addProyek(Proyek(tempIndexCode, tempName, tempType, tempDeadline));

                                        // Tampilkan bahwa proses penambahan proyek baru sudah selesai
                                        cout << "Sukses menambahkan proyek baru dengan kode " << tempIndexCode << endl;
                                    } else { // Batalkan proses jika kode sudah digunakan
                                        cout << "Kode proyek " << tempIndexCode << " sudah digunakan oleh proyek bernama " << tempName << "." << endl;
                                    }
                                    break;
                                case 3: // Penambahan karyawan baru
                                    cout << "Masukkan kode karyawan: ";
                                    cin >> tempIndexCode;
                                    
                                    // Periksa apakah kode karyawan yang dimasukkan sudah digunakan oleh karyawan lain
                                    dataFound = false;
                                    for (Karyawan karyawan: kantor.getKaryawan()) {
                                        if (karyawan.getKode() == tempIndexCode) {
                                            dataFound = true;
                                            tempName = karyawan.getNama();
                                        }
                                    }

                                    // Lanjutkan jika kode belum digunakan
                                    if (dataFound == false) {
                                        // Kelas "Penduduk"
                                        cout << "Masukkan NIK karyawan: ";
                                        cin >> tempNik;

                                        cout << "Masukkan nama karyawan: ";
                                        cin.ignore();
                                        getline(cin, tempName);

                                        cout << "Masukkan nomor HP karyawan: ";
                                        getline(cin, tempNoHP);

                                        // Kelas "Karyawan"
                                        cout << "Masukkan status kerja karyawan: ";
                                        getline(cin, tempStatus);

                                        cout << "Masukkan bidang karyawan: ";
                                        getline(cin, tempBidang);

                                        // Tampilkan list manager
                                        cout << "List manager tersedia:" << endl;
                                        for (Manager manager : kantor.getManager()) {
                                            cout << "[" << manager.getKode() << "] " << manager.getNama() << " - " << manager.getBidang() << endl;
                                        };
                                        cout << endl;

                                        // Minta input kode manager untuk asosiasi dengan karyawan
                                        cout << "Masukkan kode manager untuk karyawan: ";
                                        cin >> tempEmployeeManagerCode;

                                        // Periksa manager tersedia
                                        employManagerFound = false;
                                        for (Manager &managerPilihan: kantor.getManager()) {
                                            if (tempEmployeeManagerCode == managerPilihan.getKode() && employManagerFound != true) {
                                                // Lanjutkan jika sesuai dengan manager yang dipilih
                                                employManagerFound = true;
                                                
                                                // Tambahkan sebagai baris terakhir list
                                                kantor.addKaryawan(Karyawan(tempNik, tempName, tempNoHP, tempIndexCode, tempStatus, tempBidang, managerPilihan));

                                                // Tampilkan bahwa proses penambahan aset baru sudah selesai
                                                cout << "Sukses menambahkan karyawan baru dengan kode " << tempIndexCode << endl;
                                            }
                                        }

                                        // Peringatkan jika kode manager tidak ditemukan
                                        if (employManagerFound == false) {
                                            cout << "Kode manager " << tempEmployeeManagerCode << " tidak ditemukan." << endl;
                                        };
                                    } else { // Batalkan proses jika kode sudah digunakan
                                        cout << "Kode karyawan " << tempIndexCode << " sudah digunakan oleh " << tempName << "." << endl;
                                    }
                                    break;
                                case 4: // Penambahan manager baru
                                    cout << "Masukkan kode manager: ";
                                    cin >> tempIndexCode;
                                    
                                    // Periksa apakah kode manager yang dimasukkan sudah digunakan oleh manager lain
                                    dataFound = false;
                                    for (Manager manager: kantor.getManager()) {
                                        if (manager.getKode() == tempIndexCode) {
                                            dataFound = true;
                                            tempName = manager.getNama();
                                        }
                                    }

                                    // Lanjutkan jika kode belum digunakan
                                    if (dataFound == false) {
                                        // Kelas "Penduduk"
                                        cout << "Masukkan NIK manager: ";
                                        cin >> tempNik;

                                        cout << "Masukkan nama manager: ";
                                        cin.ignore();
                                        getline(cin, tempName);

                                        cout << "Masukkan nomor HP manager: ";
                                        getline(cin, tempNoHP);

                                        // Kelas "Manager"
                                        cout << "Masukkan bidang manager: ";
                                        getline(cin, tempBidang);

                                        cout << "Masukkan periode manager: ";
                                        getline(cin, tempPeriode);

                                        // Tambahkan sebagai baris terakhir list
                                        kantor.addManager(Manager(tempNik, tempName, tempNoHP, tempIndexCode, tempBidang, tempPeriode));

                                        // Tampilkan bahwa proses penambahan aset baru sudah selesai
                                        cout << "Sukses menambahkan manager baru dengan kode " << tempIndexCode << endl;
                                    } else { // Batalkan proses jika kode sudah digunakan
                                        cout << "Kode manager " << tempIndexCode << " sudah digunakan oleh " << tempName << "." << endl;
                                    }
                                    break;
                                default:
                                    cout << "Masukan harus sesuai dengan menu yang ditentukan (1-4)." << endl;
                                    break;
                            }
                        }
                    }

                    // Peringatkan jika kode kantor tidak ditemukan
                    if (officeFound == false) {
                        cout << "Kode kantor tidak ditemukan." << endl;
                    }
                } else { // Batalkan jika pilihan tidak sesuai
                    cout << "Masukan harus sesuai dengan menu yang ditentukan (1-4)." << endl;
                }
                break;
            case 2: // Tambah objek kantor baru.

                // Untuk nama dan lokasi, getline digunakan untuk menerima spasi
                // cin.ignore() digunakan sebelum getline pertama untuk mencegah double newline di beberapa sistem.

                cout << "Masukkan kode kantor baru: ";
                cin.ignore();
                getline(cin, tempOfficeCode);

                // Periksa apakah ada kantor dengan kode yang sama

                officeFound = false;
                for (Kantor kantor : listKantor) {
                    if (kantor.getKode() == tempOfficeCode) {
                        tempName = kantor.getNama();
                        officeFound = true;
                    }
                }

                // Lanjutkan pembuatan kantor baru jika kode belum digunakan
                if (officeFound == false) {
                    cout << "Masukkan nama kantor: ";
                    getline(cin, tempName);

                    cout << "Masukkan lokasi kantor: ";
                    getline(cin, tempLocation);

                    // Tambahkan sebagai baris terakhir list

                    listKantor.push_back(Kantor(tempOfficeCode, tempName, tempLocation));

                    // Tampilkan bahwa proses penambahan kantor baru sudah selesai
                    cout << "Sukses menambahkan kantor dengan kode " << tempOfficeCode << endl;
                } else { // Batalkan proses jika kode sudah digunakan
                    cout << "Kode kantor " << tempOfficeCode << " sudah digunakan oleh kantor bernama " << tempName << "." << endl;
                };
                break;
            case 3: // Tampilkan seluruh kantor yang tersedia
                if (listKantor.empty() == true) {
                    // Jika tidak ada kantor tersedia, tampilkan bahwa tidak ada kantor yang tersedia.
                    cout << "List kantor tidak tersedia." << endl;
                } else { // Lanjutkan jika kantor tersedia
                    cout << "List kantor yang tersedia:" << endl << endl;
                    for (Kantor kantor : listKantor) {
                        // Tampilkan informasi kantor
                        cout << "[ " << kantor.getNama() << " ]" << endl << endl;
                        cout << "Kode: " << kantor.getKode() << endl;
                        cout << "Nama: " << kantor.getNama() << endl;
                        cout << "Lokasi: " << kantor.getLokasi() << endl;

                        // Tampilkan daftar manager kantor
                        cout << "Manager: ";
                        if (kantor.getManager().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            tempIterator = 0;
                            for (Manager manager : kantor.getManager()) {
                                cout << manager.getNama() << " (" << manager.getKode() << ")";
                                tempIterator++;
                                if (kantor.getManager().size() != tempIterator) {
                                    cout << ", ";
                                };
                            };
                            cout << endl;
                        };

                        // Tampilkan daftar karyawan kantor
                        cout << "Karyawan: ";
                        if (kantor.getKaryawan().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            tempIterator = 0;
                            for (Karyawan karyawan : kantor.getKaryawan()) {
                                cout << karyawan.getNama() << " (" << karyawan.getKode() << ")";
                                tempIterator++;
                                if (kantor.getKaryawan().size() != tempIterator) {
                                    cout << ", ";
                                };
                            };
                            cout << endl;
                        };

                        // Tampilkan daftar proyek kantor
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

                        // Tampilkan daftar aset kantor
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

                    // Tampilkan menu utama jika pengguna menekan Enter, 
                    // dikarenakan jumlah tampilan yang banyak
                    cout << "Tekan ENTER untuk kembali ke menu utama.";
                    cin.ignore(); // mencegah cin.get tidak berfungsi di beberapa sistem
                    cin.get();
                }
                break;
            case 4: // Tampilkan seluruh data yang terkait dari suatu kantor
                // Tampilkan kode kantor yang tersedia
                cout << "Kantor tersedia:" << endl;
                for (Kantor kantor: listKantor) {
                    cout << "[" << kantor.getKode() << "] " << kantor.getNama() << endl;
                };
                cout << endl;

                // Minta input kode kantor untuk melanjutkan tampilan informasi kantor
                cout << "Masukkan kode kantor: ";
                cin >> tempOfficeCode;

                officeFound = false;
                for (Kantor kantor : listKantor) {
                    if (kantor.getKode() == tempOfficeCode) {
                        // Tampilkan informasi kantor
                        cout << "Kode: " << kantor.getKode() << endl;
                        cout << "Nama: " << kantor.getNama() << endl;
                        cout << "Lokasi: " << kantor.getLokasi() << endl;
                        cout << endl;

                        // Tampilkan daftar manager kantor
                        cout << "[ Daftar Manager ]" << endl << endl;
                        if (kantor.getManager().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            for (Manager manager : kantor.getManager()) {
                                cout << "Kode: " << manager.getKode() << endl;
                                cout << "NIK: " << manager.getNik() << endl;
                                cout << "Nama: " << manager.getNama() << endl;
                                cout << "No. HP: " << manager.getNomorHP() << endl;
                                cout << "Bidang: " << manager.getBidang() << endl;
                                cout << "Periode: " << manager.getPeriode() << endl;
                                cout << endl;
                            };
                        };

                        // Tampilkan daftar karyawan kantor
                        cout << "[ Daftar Karyawan ]" << endl << endl;
                        if (kantor.getKaryawan().empty() == true) {
                            cout << "(Kosong)" << endl;
                        } else {
                            for (Karyawan karyawan : kantor.getKaryawan()) {
                                cout << "Kode: " << karyawan.getKode() << endl;
                                cout << "NIK: " << karyawan.getNik() << endl;
                                cout << "Nama: " << karyawan.getNama() << endl;
                                cout << "No. HP: " << karyawan.getNomorHP() << endl;
                                cout << "Status: " << karyawan.getStatus() << endl;
                                cout << "Bidang: " << karyawan.getBidang() << endl;

                                // Jika data manager terkait masih tersedia, tampilkan nama manager tersebut
                                if (karyawan.getManager().getNama() != "") {
                                    cout << "Manager: " << karyawan.getManager().getNama() << endl;
                                } else {
                                    cout << "Manager: (Tidak tersedia)" << endl;
                                }
                                cout << endl;
                            };
                        };

                        // Tampilkan daftar proyek kantor
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

                        // Tampilkan daftar aset kantor
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

                        // Tandai bahwa kode kantor sudah ditemukan
                        officeFound = true;
                    }
                }

                // Peringatkan jika kode kantor tidak ditemukan
                if (officeFound == false) {
                    cout << "Kode kantor tidak ditemukan." << endl;
                } else {
                    // Jika kode kantor ditampilkan, tunggu hingga pengguna menekan Enter, 
                    // dikarenakan jumlah tampilan yang banyak
                    cout << "Tekan ENTER untuk kembali ke menu utama.";
                    cin.ignore(); // mencegah cin.get tidak berfungsi di beberapa sistem
                    cin.get();
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
