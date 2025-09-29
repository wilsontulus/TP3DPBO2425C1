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
Manager::Manager() {
    this->bidang = "";
    this->periode = "";
};

// Konstruktor untuk membuat objek baru oleh fungsi luar
Manager::Manager(string nik, string nama, string nomorHP, string bidang, string periode) 
                : Penduduk(nik, nama, nomorHP) 
{
    this->bidang = bidang;
    this->periode = periode;
};

// Fungsi setter untuk menentukan bidang manager
void Manager::setBidang(string bidang) {
    this->bidang = bidang;
};

// Fungsi setter untuk menentukan periode manager
void Manager::setPeriode(string periode) {
    this->periode = periode;
};
// Fungsi getter untuk mendapatkan bidang manager
string Manager::getBidang() {
    return this->bidang;
};

// Fungsi getter untuk mendapatkan periode manager
string Manager::getPeriode() {
    return this->periode;
};

// Deklarasi destruktor
Manager::~Manager() {};
