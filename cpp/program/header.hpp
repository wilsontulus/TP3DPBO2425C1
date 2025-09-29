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

/* Deklarasi header */
#include <bits/stdc++.h>

/* Deklarasi tipe namespace */

using namespace std;

/* Deklarasi kelas */

class Penduduk {
    private:
        string nik;
        string nama;
        string nomorHP;

    public:
        // Konstruktor
        Penduduk();
        Penduduk(string nik, string nama, string nomorHP);

        // Fungsi setter (write)
        void setNik(string nik);
        void setNama(string nama);
        void setNomorHP(string nomorHP);

        // Fungsi getter (read)
        string getNik();
        string getNama();
        string getNomorHP();

        // Destruktor
        ~Penduduk();
};

class Manager : public Penduduk {
    private:
        string bidang;
        string periode;

    public:
        // Konstruktor
        Manager();
        Manager(string nik, string nama, 
                string nomorHP, string bidang, string periode);

        // Fungsi setter (write)
        void setBidang(string bidang);
        void setPeriode(string periode);

        // Fungsi getter (read)
        string getBidang();
        string getPeriode();

        // Destruktor
        ~Manager();
};

class Karyawan : public Penduduk {
    private:
        string status;
        string bidang;
        Manager manager;

    public:
        // Konstruktor
        Karyawan();
        Karyawan(string nik, string nama, string nomorHP, 
                 string status, string bidang, Manager manager);

        // Fungsi setter (write)
        void setStatus(string status);
        void setBidang(string bidang);
        void setManager(Manager manager);

        // Fungsi getter (read)
        string getStatus();
        string getBidang();
        Manager getManager();

        // Destruktor
        ~Karyawan();
};

class Proyek {
    private:
        string kode;
        string nama;
        string jenis;
        string deadline;

    public:
        // Konstruktor
        Proyek();
        Proyek(string kode, string nama, string jenis, string deadline);

        // Fungsi setter (write)
        void setKode(string kode);
        void setNama(string nama);
        void setJenis(string jenis);
        void setDeadline(string deadline);

        // Fungsi getter (read)
        string getKode();
        string getNama();
        string getJenis();
        string getDeadline();

        // Destruktor
        ~Proyek();
};

class Aset {
    private:
        string kode;
        string nama;
        string jenis;
        int jumlah;

    public:
        // Konstruktor
        Aset();
        Aset(string kode, string nama, string jenis, int jumlah);

        // Fungsi setter (write)
        void setKode(string kode);
        void setNama(string nama);
        void setJenis(string jenis);
        void setJumlah(int jumlah);

        // Fungsi getter (read)
        string getKode();
        string getNama();
        string getJenis();
        int getJumlah();

        // Destruktor
        ~Aset();
};

class Kantor {
    private:
        string kode;
        string nama;
        string lokasi;

        list<Manager> manager;
        list<Karyawan> karyawan;
        list<Proyek> proyek;
        list<Aset> aset;

    public:
        // Konstruktor
        Kantor();
        Kantor(string kode, string nama, string lokasi);

        // Fungsi setter (write)
        void setKode(string kode);
        void setNama(string nama);
        void setLokasi(string lokasi);

        // Fungsi adder (write to list)
        void addManager(Manager manager);
        void addKaryawan(Karyawan karyawan);
        void addProyek(Proyek proyek);
        void addAset(Aset aset);

        // Fungsi getter (read)
        string getKode();
        string getNama();
        string getLokasi();


        list<Manager> getManager();
        list<Karyawan> getKaryawan();
        list<Proyek> getProyek();
        list<Aset> getAset();

        // Destruktor
        ~Kantor();
};