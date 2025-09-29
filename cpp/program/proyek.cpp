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
Proyek::Proyek() {
    this->kode = "";
    this->nama = "";
    this->jenis = "";
    this->deadline = "";
};

// Konstruktor untuk membuat objek baru oleh fungsi luar
Proyek::Proyek(string kode, string nama, string jenis, string deadline) {
    this->kode = kode;
    this->nama = nama;
    this->jenis = jenis;
    this->deadline = deadline;
};

// Fungsi setter untuk menentukan kode proyek
void Proyek::setKode(string kode) {
    this->kode = kode;
};

// Fungsi setter untuk menentukan nama proyek
void Proyek::setNama(string nama) {
    this->nama = nama;
};

// Fungsi setter untuk menentukan jenis proyek
void Proyek::setJenis(string jenis) {
    this->jenis = jenis;
};

// Fungsi setter untuk menentukan deadline proyek
void Proyek::setDeadline(string deadline) {
    this->deadline = deadline;
};

// Fungsi getter untuk mendapatkan kode proyek
string Proyek::getKode() {
    return this->kode;
};

// Fungsi getter untuk mendapatkan nama proyek
string Proyek::getNama() {
    return this->nama;
};

// Fungsi getter untuk mendapatkan jenis proyek
string Proyek::getJenis() {
    return this->jenis;
};

// Fungsi getter untuk mendapatkan deadline proyek
string Proyek::getDeadline() {
    return this->deadline;
};

// Deklarasi destruktor
Proyek::~Proyek() {};
