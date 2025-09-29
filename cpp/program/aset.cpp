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
Aset::Aset() {
    this->kode = "";
    this->nama = "";
    this->jenis = "";
    this->jumlah = 0;
};

// Konstruktor untuk membuat objek baru oleh fungsi luar
Aset::Aset(string kode, string nama, string jenis, int jumlah) {
    this->kode = kode;
    this->nama = nama;
    this->jenis = jenis;
    this->jumlah = jumlah;
};

// Fungsi setter untuk menentukan kode aset
void Aset::setKode(string kode) {
    this->kode = kode;
};

// Fungsi setter untuk menentukan nama aset
void Aset::setNama(string nama) {
    this->nama = nama;
};

// Fungsi setter untuk menentukan jenis aset
void Aset::setJenis(string jenis) {
    this->jenis = jenis;
};

// Fungsi setter untuk menentukan jumlah aset
void Aset::setJumlah(int jumlah) {
    this->jumlah = jumlah;
};

// Fungsi getter untuk mendapatkan kode aset
string Aset::getKode() {
    return this->kode;
};

// Fungsi getter untuk mendapatkan nama aset
string Aset::getNama() {
    return this->nama;
};

// Fungsi getter untuk mendapatkan jenis aset
string Aset::getJenis() {
    return this->jenis;
};

// Fungsi getter untuk mendapatkan jumlah dari aset yang tersedia
int Aset::getJumlah() {
    return this->jumlah;
};

// Deklarasi destruktor
Aset::~Aset() {};
