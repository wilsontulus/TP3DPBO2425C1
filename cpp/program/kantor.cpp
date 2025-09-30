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

/* Deklarasi header custom */
#include "header.hpp"

/* Deklarasi kelas */

// Deklarasi konstruktor awal untuk inisialisasi
Kantor::Kantor() {
    // Inisialisasi Atribut
    this->kode = "";
    this->nama = "";
    this->lokasi = "";

    // Inisialisasi List
    this->manager = new list<Manager>;
    this->karyawan = new list<Karyawan>;
    this->proyek = new list<Proyek>;
    this->aset = new list<Aset>;
};

// Konstruktor untuk membuat objek baru oleh fungsi luar
Kantor::Kantor(string kode, string nama, string lokasi) {
    // Tentukan atribut
    this->kode = kode;
    this->nama = nama;
    this->lokasi = lokasi;

    // Inisialisasi List
    this->manager = new list<Manager>;
    this->karyawan = new list<Karyawan>;
    this->proyek = new list<Proyek>;
    this->aset = new list<Aset>;
};

// Fungsi setter untuk menentukan kode kantor
void Kantor::setKode(string kode) {
    this->kode = kode;
};

// Fungsi setter untuk menentukan nama kantor
void Kantor::setNama(string nama) {
    this->nama = nama;
};

// Fungsi setter untuk menentukan lokasi kantor
void Kantor::setLokasi(string lokasi) {
    this->lokasi = lokasi;
};

// Fungsi adder untuk menambahkan manager kantor
void Kantor::addManager(Manager manager) {
    this->manager->push_back(manager);
};

// Fungsi adder untuk menambahkan karyawan kantor
void Kantor::addKaryawan(Karyawan karyawan) {
    this->karyawan->push_back(karyawan);
};

// Fungsi adder untuk menambahkan proyek kantor
void Kantor::addProyek(Proyek proyek) {
    this->proyek->push_back(proyek);
};

// Fungsi adder untuk menambahkan aset kantor
void Kantor::addAset(Aset aset) {
    this->aset->push_back(aset);
};

// Fungsi getter untuk mendapatkan kode kantor
string Kantor::getKode() {
    return this->kode;
};

// Fungsi getter untuk mendapatkan nama kantor
string Kantor::getNama() {
    return this->nama;
};

// Fungsi getter untuk mendapatkan jenis kantor
string Kantor::getLokasi() {
    return this->lokasi;
};

// Fungsi getter untuk mendapatkan list dari manager kantor
list<Manager> Kantor::getManager() {
    return *this->manager;
};

// Fungsi getter untuk mendapatkan list dari karyawan kantor
list<Karyawan> Kantor::getKaryawan() {
    return *this->karyawan;
};

// Fungsi getter untuk mendapatkan list dari proyek kantor
list<Proyek> Kantor::getProyek() {
    return *this->proyek;
};

// Fungsi getter untuk mendapatkan list dari aset kantor
list<Aset> Kantor::getAset() {
    return *this->aset;
};

// Deklarasi destruktor
Kantor::~Kantor() {};
