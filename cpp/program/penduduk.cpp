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
Penduduk::Penduduk() {
    this->nik = "";
    this->nama = "";
    this->nomorHP = "";
};

// Konstruktor untuk membuat objek baru oleh fungsi luar
Penduduk::Penduduk(string nik, string nama, string nomorHP) {
    this->nik = nik;
    this->nama = nama;
    this->nomorHP = nomorHP;
};

// Fungsi setter untuk menentukan NIK penduduk
void Penduduk::setNik(string nik) {
    this->nik = nik;
};

// Fungsi setter untuk menentukan nama penduduk
void Penduduk::setNama(string nama) {
    this->nama = nama;
};

// Fungsi setter untuk menentukan nomor HP penduduk
void Penduduk::setNomorHP(string nomorHP) {
    this->nomorHP = nomorHP;
};

// Fungsi getter untuk mendapatkan NIK penduduk
string Penduduk::getNik() {
    return this->nik;
};

// Fungsi getter untuk mendapatkan nama penduduk
string Penduduk::getNama() {
    return this->nama;
};

// Fungsi getter untuk mendapatkan nomor HP penduduk
string Penduduk::getNomorHP() {
    return this->nomorHP;
};

// Deklarasi destruktor
Penduduk::~Penduduk() {};
